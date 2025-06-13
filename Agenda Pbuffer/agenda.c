// Arthur Trettin Bast | Turma m1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Funções
int exibir_menu_principal(void *dados_agenda);
void* adicionar_contato(void *dados_agenda);
void* remover_contato(void *dados_agenda);
void* buscar_contato(void *dados_agenda);
void listar_contatos(void *dados_agenda);

int main() {
    // [opção_menu (int), quantidade_pessoas (int), tamanho_buffer (int), dados_pessoas...]
    void *buffer = NULL;

    // Aloca espaço inicial para os três inteiros de controle.
    buffer = malloc(sizeof(int) * 3);



    int *ptr_opcao_menu = (int *)buffer;
    int *ptr_contagem_pessoas = (int *)((char *)buffer + sizeof(int));
    int *ptr_tamanho_buffer = (int *)((char *)buffer + 2 * sizeof(int));

    // Inicializa as variáveis de controle.
    *ptr_tamanho_buffer = sizeof(int) * 3; 
    *ptr_contagem_pessoas = 0;
    *ptr_opcao_menu = 0; 


    while (*ptr_opcao_menu != 5) {
       
        *ptr_opcao_menu = exibir_menu_principal(buffer);

      
        switch (*ptr_opcao_menu) {
            case 1:
                buffer = adicionar_contato(buffer);
                break;
            case 2:
                buffer = remover_contato(buffer);
                break;
            case 3:
                buffer = buscar_contato(buffer);
                break;
            case 4:
                listar_contatos(buffer);
                break;
            
        }

       
        // Garantir que os endereços não tenham mudadado.
        ptr_opcao_menu = (int *)buffer;
        ptr_contagem_pessoas = (int *)((char *)buffer + sizeof(int));
        ptr_tamanho_buffer = (int *)((char *)buffer + 2 * sizeof(int));
    }


    free(buffer);
    buffer = NULL;
    printf("\n Saindo!\n");
    return 0;   
}


int exibir_menu_principal(void *dados_agenda) {
    int *ptr_escolha = (int *)dados_agenda;

    
    do {
        printf("\n------ Menu ------\n");
        printf("  1 - Novo Contato\n");
        printf("  2 - Excluir Contato\n");
        printf("  3 - Achar Contato\n");
        printf("  4 - Mostrar todos os contatos\n");
        printf("  5- Sair\n");
        printf("------------------------------\n");
        
        
        printf("\n  Por favor, digite sua escolha: ");
        scanf("%d", ptr_escolha);

        while (getchar() != '\n'); 

        if (*ptr_escolha < 1 || *ptr_escolha > 5) {
            printf("\n  Digite Novamente \n");
        }
    } while (*ptr_escolha < 1 || *ptr_escolha > 5);

    return *ptr_escolha;
}

// Função para adicionar uma nova pessoa a agenda.
void* adicionar_contato(void *dados_agenda) {
    
    //tamanho total do buffer.
    int *ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));

    // Realoca o buffer para acomodar os novos dados da pessoa.
    // 100 bytes para strings + 3 inteiros para tamanhos/idade.
    dados_agenda = realloc(dados_agenda, *ptr_tamanho_buffer + (sizeof(char) * 100) + (sizeof(int) * 3));
  
    // Re-mapeia os ponteiros de controle após a realocação, pois o endereço base pode ter mudado.
    ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));
    int *ptr_contagem_pessoas = (int *)((char *)dados_agenda + sizeof(int));
    
    (*ptr_contagem_pessoas)++;


    int *ptr_tamanho_nome = (int *)((char *)dados_agenda + (*ptr_tamanho_buffer));
    *ptr_tamanho_buffer += sizeof(int); 


    char *ptr_nome_pessoa = (char *)dados_agenda + (*ptr_tamanho_buffer);
    printf("  Nome Completo: ");
    scanf(" %99[^\n]%*c", ptr_nome_pessoa); 
    *ptr_tamanho_nome = strlen(ptr_nome_pessoa);
    *ptr_tamanho_buffer += (*ptr_tamanho_nome + 1); 

  
    int *ptr_idade_pessoa = (int *)((char *)dados_agenda + (*ptr_tamanho_buffer));
    printf("  Idade: ");
    scanf("%d%*c", ptr_idade_pessoa); 
    *ptr_tamanho_buffer += sizeof(int); 

    int *ptr_tamanho_email = (int *)((char *)dados_agenda + (*ptr_tamanho_buffer));
    *ptr_tamanho_buffer += sizeof(int); 


    char *ptr_email_pessoa = (char *)dados_agenda + (*ptr_tamanho_buffer);
    printf("  Endereco de E-Mail: ");
    scanf(" %99[^\n]%*c", ptr_email_pessoa); 
    *ptr_tamanho_email = strlen(ptr_email_pessoa);
    *ptr_tamanho_buffer += (*ptr_tamanho_email + 1); 

    // Realoca o buffer para o tamanho exato necessário, liberando qualquer excesso.
    dados_agenda = realloc(dados_agenda, *ptr_tamanho_buffer);

    // Re-mapeia o ponteiro do tamanho do buffer novamente, caso o endereço base tenha mudado na realocação final.
    ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));
    printf("\n  Contato adicionado \n");
    return dados_agenda;
}

// Função para remover uma pessoa da agenda
void* remover_contato(void *dados_agenda) {
    // tamanho total do buffer.
    int *ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));
    
    if (*ptr_tamanho_buffer == (sizeof(int) * 3)) {
        printf("\n Não há contatos na agenda \n");
        return dados_agenda;
    }

    // Realoca o buffer para a string de busca.
    dados_agenda = realloc(dados_agenda, *ptr_tamanho_buffer + sizeof(char) * 104); // 100 para nome + 4 pra ter certeza

    // Re-mapeia os ponteiros de controle após a realocação.
    ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));
    int *ptr_contagem_pessoas = (int *)((char *)dados_agenda + sizeof(int));
    int *ptr_indice_atual = (int *)dados_agenda; 
    *ptr_indice_atual = 0;


    char *nome_para_remover = (char *)dados_agenda + *ptr_tamanho_buffer;
    printf("  Digite o NOME do registro a ser removido: ");
    scanf(" %99[^\n]%*c", nome_para_remover);

    // Ponteiro para o início dos dados das pessoas (após os 3 inteiros de controle).
    char *ptr_dados_atuais = (char *)dados_agenda + (3 * sizeof(int));


    while (*ptr_indice_atual < *ptr_contagem_pessoas) {
        // Salva o ponteiro para o início do registro atual para uso posterior (memmove).
        char *ptr_inicio_registro_atual = ptr_dados_atuais;

        int *ptr_tam_nome_lido = (int *)ptr_dados_atuais;
        ptr_dados_atuais += sizeof(int);

        char *nome_lido = ptr_dados_atuais;
        ptr_dados_atuais += (*ptr_tam_nome_lido + 1);

        ptr_dados_atuais += sizeof(int);

        int *ptr_tam_email_lido = (int *)ptr_dados_atuais;
        ptr_dados_atuais += sizeof(int);

        ptr_dados_atuais += (*ptr_tam_email_lido + 1);

        if (strcmp(nome_lido, nome_para_remover) == 0) {

            int tamanho_contanto_remover = (sizeof(int) + (*ptr_tam_nome_lido + 1) + sizeof(int) + sizeof(int) + (*ptr_tam_email_lido + 1));
            
            // Move os dados subsequentes para sobrescrever o registro removido.
            memmove(ptr_inicio_registro_atual, ptr_dados_atuais, ((char *)dados_agenda + *ptr_tamanho_buffer) - ptr_dados_atuais);

            (*ptr_contagem_pessoas)--;
            *ptr_tamanho_buffer -= tamanho_contanto_remover;
            *ptr_indice_atual = 0; 

            // Realoca o buffer para o novo tamanho, liberando o espaço do registro removido.
            dados_agenda = realloc(dados_agenda, *ptr_tamanho_buffer);

            // Re-mapeia o ponteiro do tamanho do buffer novamente.
            ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));
            printf("\n  Registro '%s' removido com sucesso!\n", nome_para_remover);
            return dados_agenda;
        }

        (*ptr_indice_atual)++;
    }

    printf("\n '%s' nao foi encontrado na agenda.\n", nome_para_remover);
    *ptr_indice_atual = 0; 

    // Realoca o buffer de volta ao seu tamanho original
    dados_agenda = realloc(dados_agenda, *ptr_tamanho_buffer);

    // Re-mapeia o ponteiro do tamanho do buffer novamente.
    ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));
    return dados_agenda;
}

// Função para buscar uma pessoa pelo nome.
void* buscar_contato(void *dados_agenda) {
    // tamanho total do buffer.
    int *ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));
    
    if (*ptr_tamanho_buffer == (sizeof(int) * 3)) {
        printf("\n Não há contatos salvos \n");
        return dados_agenda;
    }

    // Realoca o buffer para um espaço temporário para a string de busca.
    dados_agenda = realloc(dados_agenda, *ptr_tamanho_buffer + sizeof(char) * 100); 

    // Re-mapeia os ponteiros de controle após a realocação.
    ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));
    int *ptr_contagem_pessoas = (int *)((char *)dados_agenda + sizeof(int));
    int *ptr_indice_atual = (int *)dados_agenda;
    *ptr_indice_atual = 0;

    char *nome_para_buscar = (char *)dados_agenda + *ptr_tamanho_buffer;
    printf("  Digite o nome do contato a ser localizado: ");
    scanf(" %99[^\n]%*c", nome_para_buscar);

    // Ponteiro para o início dos dados das pessoas.
    char *ptr_dados_atuais = (char *)dados_agenda + (3 * sizeof(int));

    while (*ptr_indice_atual < *ptr_contagem_pessoas) {

        int *ptr_tam_nome_lido = (int *)ptr_dados_atuais;
        ptr_dados_atuais += sizeof(int);

        char *nome_lido = ptr_dados_atuais;
        ptr_dados_atuais += (*ptr_tam_nome_lido + 1);

        int *idade_lida = (int *)ptr_dados_atuais;
        ptr_dados_atuais += sizeof(int);

        int *ptr_tam_email_lido = (int *)ptr_dados_atuais;
        ptr_dados_atuais += sizeof(int);

        char *email_lido = ptr_dados_atuais;
        ptr_dados_atuais += (*ptr_tam_email_lido + 1);

        if (strcmp(nome_lido, nome_para_buscar) == 0) {
            printf("-------Contato-------\n");
            printf("  Nome: %s\n", nome_lido);
            printf("  Idade: %d\n", *idade_lida);
            printf("  E-Mail: %s\n", email_lido);
            printf("================================\n");

            *ptr_indice_atual = 0; // Reseta o contador.
            // Realoca o buffer de volta ao seu tamanho original
            dados_agenda = realloc(dados_agenda, *ptr_tamanho_buffer);
           

            // Re-mapeia o ponteiro do tamanho do buffer novamente.
            ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));
            return dados_agenda;
        }

        (*ptr_indice_atual)++;
    }

    printf("\n '%s' nao foi encontrado\n", nome_para_buscar);
    *ptr_indice_atual = 0;

    // Realoca o buffer de volta ao seu tamanho original
    dados_agenda = realloc(dados_agenda, *ptr_tamanho_buffer);

    // Re-mapeia o tamanho do buffer novamente.
    ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));
    return dados_agenda;
}

// Função para listar todos os contatos
void listar_contatos(void *dados_agenda) {
    // tamanho total do buffer.
    int *ptr_tamanho_buffer = (int *)((char *)dados_agenda + 2 * sizeof(int));
    

    if (*ptr_tamanho_buffer == (sizeof(int) * 3)) {
        printf("\n  Não há pessoas na agenda \n");
        return;
    }

    int *ptr_contagem_pessoas = (int *)((char *)dados_agenda + sizeof(int));
    int *ptr_contador_loop = (int *)dados_agenda;
    *ptr_contador_loop = 1;

    // Ponteiro para o início dos dados das pessoas.
    char *ptr_dados_atuais = (char *)dados_agenda + (3 * sizeof(int));

    printf("\n------- Contatos -------\n");
 
    while (*ptr_contador_loop <= *ptr_contagem_pessoas) {

        int *ptr_tam_nome_lido = (int *)ptr_dados_atuais;
        ptr_dados_atuais += sizeof(int);

        char *nome_lido = ptr_dados_atuais;
        ptr_dados_atuais += (*ptr_tam_nome_lido + 1);

        int *idade_lida = (int *)ptr_dados_atuais;
        ptr_dados_atuais += sizeof(int);

        int *ptr_tam_email_lido = (int *)ptr_dados_atuais;
        ptr_dados_atuais += sizeof(int);
     
        char *email_lido = ptr_dados_atuais;
        ptr_dados_atuais += (*ptr_tam_email_lido + 1);

        printf("================================\n");
        printf("    Registro Numero: %d\n", *ptr_contador_loop);
        printf("  Nome: %s\n", nome_lido);
        printf("  Idade: %d\n", *idade_lida);
        printf("  E-Mail: %s\n", email_lido);
        printf("================================\n");

        (*ptr_contador_loop)++;
    }

    *ptr_contador_loop = 0; 
}
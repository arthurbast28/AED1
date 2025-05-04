#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

void adicionar_nome(char nomes[200]);
void excluir_nome(char nomes[200]);
void listar(char nomes[200]);
void armazenar_nome(char palavra[TAM], char nomes[200]);

int main() {
    int escolha;
    char nomes[200] = "";

    while (1) {
        printf("\n--MENU--");
        printf("\n---------------");
        printf("\n 1) Adicionar Nome\n 2) Excluir nome\n 3) Listar\n 4) Sair");
        printf("\n---------------");
        printf("\n\n Escolha uma opção: ");
        scanf("%d", &escolha);
        getchar(); 

        switch (escolha) {
            case 1:
                adicionar_nome(nomes);
                break;

            case 2:
                excluir_nome(nomes);
                break;

            case 3:
                listar(nomes);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Escolha Novamente\n");
        }
    }

    return 0;
}

void adicionar_nome(char nomes[200]) {
    char palavra[TAM];

    printf("Digite um nome: ");
    scanf("%s", palavra);

    armazenar_nome(palavra, nomes);
}

void armazenar_nome(char palavra[TAM], char nomes[200]) {
    if (strlen(nomes) + strlen(palavra) + 1 >= 200) {
        printf("Sem espaço para adicionar mais nomes!\n");
        return;
    }

    if (strlen(nomes) > 0) {
        strcat(nomes, " "); 
    }
    strcat(nomes, palavra);
}

void listar(char nomes[200]) {
    int i;

    printf("\nLista de nomes:\n");
    for (i = 0; nomes[i] != '\0'; i++) {
        if (nomes[i] == ' ') {
            printf("\n");
        } else {
            printf("%c", nomes[i]);
        }
    }
    printf("\n");
}

void excluir_nome(char nomes[200]) {
    char palavra[TAM];
    char novos_nomes[200] = "";
    char *token;

    printf("Digite o nome que deseja excluir: ");
    scanf("%s", palavra);

    token = strtok(nomes, " ");

    while (token != NULL) {
        if (strcmp(token, palavra) != 0) {
            if (strlen(novos_nomes) > 0) {
                strcat(novos_nomes, " ");
            }
            strcat(novos_nomes, token);
        }
        token = strtok(NULL, " ");
    }

    strcpy(nomes, novos_nomes);
}

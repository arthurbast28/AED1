#include <stdio.h>
#include <string.h>

int romanToInteger( char num_romano[]);
int valor_romano(char letra_romana);

int main(){
    char palavra[15];

    printf("Digite o Número em romano: ");
    scanf("%s", palavra);
    printf("%d", romanToInteger(palavra));


}

int romanToInteger( char num_romano[]){
    int i, inteiroRomano = 0, tam = strlen(num_romano), carc_atual, carc_posterior;

    for(i = 0; i < tam; i++){
        carc_atual = valor_romano(num_romano[i]);
        carc_posterior = valor_romano(num_romano[i + 1]);
        if(carc_atual < carc_posterior ){
            inteiroRomano += (carc_posterior - carc_atual);
            i++;
        }
        else{
            inteiroRomano += carc_atual;
        }
    }
    return inteiroRomano;

    


}
int valor_romano( char letra_romana){

    switch (letra_romana)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    default:
        return 0;
        break;
    }
}
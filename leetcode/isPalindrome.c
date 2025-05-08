#include <stdio.h>
#include <string.h> 

#define MAX_DIGITS 11 

int isPalindrome(int numero);

int main() {
    int resultado;
    int numero;

    printf("Digite um número para verificar se é palíndromo: ");
    scanf("%d", &numero);

    resultado = isPalindrome(numero);

    if (resultado == 1) {
        printf("\nO número %d é um palíndromo!\n", numero);
    } else {
        printf("\nO número %d não é um palíndromo.\n", numero);
    }

    return 0;
}

int isPalindrome(int numero) {
    char digitos[MAX_DIGITS];
    int esquerda = 0;
    int direita;
    int metade;


    if (numero < 0) {
        return 0; 
    }
    if (numero < 10) {
        return 1; 
    }


    snprintf(digitos, MAX_DIGITS, "%d", numero);


    for (direita = 0; digitos[direita + 1] != '\0'; direita++);

    metade = direita / 2;

    for (; esquerda <= metade; esquerda++, direita--) {
        if (digitos[esquerda] != digitos[direita]) {
            return 0;
        }
    }

    return 1;
}
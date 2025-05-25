#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void contadorLetras(char* str, int* freq);
int check(int* plateFreq, char* word);
char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize);

int main() {
    char* license = "1s3 PSt";
    char* words[] = {"step", "steps", "stripe", "stepple"};
    int size = sizeof(words) / sizeof(words[0]);

    char* result = shortestCompletingWord(license, words, size);
    printf("Resultado: %s\n", result);

    return 0;
}

void contadorLetras(char* str, int* freq) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            freq[tolower(str[i]) - 'a']++;
        }
    }
}

int check(int* plateFreq, char* word) {
    int freqPalavra[26] = {0};
    contadorLetras(word, freqPalavra);

    for (int i = 0; i < 26; i++) {
        if (plateFreq[i] > freqPalavra[i]){
            return 0;
        }
    }
    return 1;
}

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int freqPlaca[26] = {0};
    contadorLetras(licensePlate, freqPlaca); 

    char* resultado = NULL;
    int tamanho_maximo = 1000;

    for (int i = 0; i < wordsSize; i++) {
        if (check(freqPlaca, words[i])) {
            int tam = strlen(words[i]);
            if (tam < tamanho_maximo) {
                tamanho_maximo = tam;
                resultado = words[i];
            }
        }
    }

    return resultado;
}



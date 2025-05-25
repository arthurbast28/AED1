char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int tamanho_maximo = 25;
    int freqPlaca[26] = 0;

    char* resultado = "";


    for (int i = 0; i < wordsSize; i++) {
        if (check(freqPlaca, words[i])) {
            int tam = strlen(words[i]);
            if (tam < tamanho) {
                tamanho = tam;
                resultado = words[i];
            }
        }
    }
}
int check(int* plateFreq, char* word) {
    int freqPalavra[26] = {0};

    for (int i = 0; i < 26; i++) {
        if (freqPlaca[i] > freqPalavra[i]) return 0;
    }
    return 1;
}

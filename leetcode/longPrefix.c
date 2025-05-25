#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) return "";

    for (int i = 0; ; i++) {
        char c = strs[0][i];
        if (c == '\0') return strs[0];

        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != c) {
                strs[0][i] = '\0'; 
                return strs[0];
            }
        }
    }
}

// Função main para testar localmente
int main() {
    char *strs[] = {"flower", "flow", "flight"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    char *prefix = longestCommonPrefix(strs, strsSize);
    printf("Maior prefixo comum: \"%s\"\n", prefix);

    return 0;
}

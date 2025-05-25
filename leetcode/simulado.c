#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int exist(char** board, int boardSize, int* boardColSize, char* word);

int main(){
   char board[4][3];
   char word[4] = "APKO";
   char* pboard = board;
   int boardSize = 4, col = 3;
   int* boardColSize;

   *boardColSize = col ;

   if(exist(board, boardSize, boardColSize, word )){
    printf("True");
   }
   else{
    printf("False");
   }
}

int exist(char** board, int boardSize, int* boardColSize, char* word){
    char palavra[boardSize][*boardColSize];
    int i = 0, j = 0, tam;

    for(; i < 4; i++){
        for(; j < 3; i++){
            scanf("%c", palavra[i][j]);
        }
    }
    printf("Digite a palavra: ");
    scanf("%s", word);
    tam = strlen(word);


    


}
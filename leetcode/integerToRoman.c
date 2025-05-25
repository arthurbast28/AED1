#include <stdio.h>
#include <string.h>

char* integerToRoman(int num);


int main(){
    int num =3888 ;
    char *palavra[] = {"flower", "flar", "flint"};
    char pe[30] = "";
    printf("%s",integerToRoman(num) );
    strcat(pe, palavra[0]);
    strcat(pe, palavra[2]);
    printf("%s", pe);

}

char* integerToRoman(int num){
    char *carac[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int num_carac[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static char roman[25];
    roman[0] = '\0';
    int i = 0;

    while(num > 0){
        if(num >= num_carac[i]){
            strcat(roman, carac[i]);
            num -= num_carac[i];
        }
        else{
            i++;
        }

    }
    return roman;

}
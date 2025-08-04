struct conteudo{
    char letra;
    int topo;
    int total;

};
typedef struct conteudo pilha;

int maximumGain(char* s, int x, int y) {
   int pontos = 0;

   if(x > y){
    pontos = pontos + trocarSubstring(s,'a', 'b', y);
    pontos = pontos + trocarSubstring(s,'b', 'a', x);
    }
    else{
    pontos = pontos + trocarSubstring(s,'b', 'a', x);
    pontos = pontos + trocarSubstring(s,'a', 'b', y);

    }

    return pontos;


    
}
int trocarSubstring(char*s, char a, char b, int pontos){
    int i = 0;
    int tam = strlen(s);
    struct pilha novaPilha;
    novaPilha = (pilha) malloc(sizeof(pilha) + tam);
    novaPilha -> letra = NULL;
    novaPilha -> topo = -1;
    int total = 0;

    for(i; s[i] != '\0'; i++){
        if(novaPilha -> topo >= 0 && pilha ->)
            novaPilha -> topo = (novaPilha -> topo) -1;
            total = total + pontos;

        
    }



    free(novaPilha);

    return total;
    


}
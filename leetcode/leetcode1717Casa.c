#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
	char	*letra;
	int		topo;
};

typedef struct stack pilha;

int trocarSubstring( char *s, char a, char b, int pontos );
int maximumGain( char *s, int x, int y );

int main() {
	char	s[100005];
	int		x, y;

	printf( "Digite a string s: " );
	if ( scanf( "%100000s", s ) != 1 ) {
		fprintf( stderr, "Erro na leitura da string.\n" );
		return 1;
	}

	printf( "Digite x e y: " );
	if ( scanf( "%d %d", &x, &y ) != 2 ) {
		fprintf( stderr, "Erro na leitura de x e y.\n" );
		return 1;
	}

	int pontos = maximumGain( s, x, y );

	printf( "\nPontuação total: %d\n", pontos );
	printf( "String restante: \"%s\"\n", s );

	return 0;
}

int maximumGain( char *s, int x, int y ) {
	int pontos = 0;

	if ( x > y ) {
		pontos += trocarSubstring( s, 'a', 'b', x );
		pontos += trocarSubstring( s, 'b', 'a', y );
	} else {
		pontos += trocarSubstring( s, 'b', 'a', y );
		pontos += trocarSubstring( s, 'a', 'b', x );
	}

	return pontos;
}

int trocarSubstring( char *s, char a, char b, int pontos ) {
	int		n = ( int )strlen( s );
	pilha	p;

	p.letra = ( char * )malloc( n );
	p.topo = -1;

	int total = 0;

	for ( int i = 0; i < n; i++ ) {
		if ( s[i] == b && p.topo >= 0 && p.letra[p.topo] == a ) {
			p.topo--;
			total += pontos;
		} else {
			p.letra[++p.topo] = s[i];
		}
	}

	for ( int i = 0; i <= p.topo; i++ ) {
		s[i] = p.letra[i];
	}

	s[p.topo + 1] = '\0';

	free( p.letra );
	return total;
}

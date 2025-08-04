#include <stdlib.h>
#include <stdio.h>

#define MOD 1000000007
#define MAX 1000

void pascal( long long comb[MAX][MAX] );
long long calculateWays( int *nums, int numsSize, long long comb[MAX][MAX] );
int numOfWays( int *nums, int numsSize );

int main() {
    int nums[] = { 3, 4, 5, 1, 2 };
    int result = numOfWays( nums, 5 );
    printf( "Resultado: %d\n", result );
    return 0;
}

void pascal( long long comb[MAX][MAX] ) {
    for ( int i = 0; i < MAX; i++ ) {
        comb[i][0] = 1;
        for ( int j = 1; j <= i; j++ ) {
            comb[i][j] = ( comb[i - 1][j - 1] + comb[i - 1][j] ) % MOD;
        }
    }
}

long long calculateWays( int *nums, int numsSize, long long comb[MAX][MAX] ) {
    if ( numsSize <= 2 ) {
        return 1;
    }

    int mid = nums[0];
    int *leftNodes = ( int * )malloc( sizeof( int ) * numsSize );
    int *rightNodes = ( int * )malloc( sizeof( int ) * numsSize );
    int countLeft = 0;
    int countRight = 0;

    for ( int i = 1; i < numsSize; i++ ) {
        if ( nums[i] < mid ) {
            leftNodes[countLeft++] = nums[i];
        } else {
            rightNodes[countRight++] = nums[i];
        }
    }

    long long leftWays = calculateWays( leftNodes, countLeft, comb );
    long long rightWays = calculateWays( rightNodes, countRight, comb );

    free( leftNodes );
    free( rightNodes );

    long long ways = ( comb[countLeft + countRight][countLeft] * leftWays ) % MOD;
    ways = ( ways * rightWays ) % MOD;

    return ways;
}

int numOfWays( int *nums, int numsSize ) {
    long long comb[MAX][MAX];
    long long res = 0;

    pascal( comb );
    res = calculateWays( nums, numsSize, comb );

    return ( res - 1 + MOD ) % MOD;
}

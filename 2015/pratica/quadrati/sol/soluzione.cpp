#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static FILE *fr, *fw;

int contaQuadrati(int A, int B) {
    int risposta = 0;

    for (int i = 1; i * i <= B; i++)
    	if (i * i >= A)
    		++risposta;
    
    return risposta;
}

int main() {
#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif

    int A, B;
    assert(2 == fscanf(fr, "%d%d", &A, &B));
    
    fprintf(fw, "%d\n", contaQuadrati(A, B));
    return 0;
}


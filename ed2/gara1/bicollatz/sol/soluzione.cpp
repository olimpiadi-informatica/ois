#include <stdio.h>
#include <assert.h>


int bicollatz(int A, int B) {
    int n=0;
    while (true) {
        if (A == 1 and B == 1)
            return n;
        if (A == 1 and B == 2)
            return -1;
        if (A == 1 and B == 7)
            return -1;
        if (A == 7 and B == 1)
            return -1;
        if (A%2 + B%2 == 0) {
            A /= 2;
            B /= 2;
        }
        else if (A%2 + B%2 == 2) {
            A = 3*A+1;
            B = 3*B+1;
        }
        else if (A%2 == 1)
            A += 3;
        else
            B += 3;
        n++;
    }
    return n;
}


int main() {
    FILE *fr, *fw;
    int A, B;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &A, &B));

    fprintf(fw, "%d\n", bicollatz(A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}

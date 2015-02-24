#include <stdio.h>
#include <assert.h>

int gioca(int N, int M) {
    return  N*M*11/20+1;
}


int main() {
    FILE *fr, *fw;
    int N, M;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &M));

    fprintf(fw, "%d\n", gioca(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}

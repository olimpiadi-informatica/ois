#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int mancanti(int R, int C, char** map) {
    // Mettete qui il codice della soluzione
    return 42;
}


int main() {
    FILE *fr, *fw;
    int R, C, i;
    char** map;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &R, &C));
    map = (char**) malloc(R * sizeof(char*));
    for(i=0; i<R; i++) {
        map[i] = (char*) malloc(C * sizeof(char*));
        assert(1 == fscanf(fr, "%s", map[i]));
    }

    fprintf(fw, "%d\n", mancanti(R, C, map));
    fclose(fr);
    fclose(fw);
    return 0;
}

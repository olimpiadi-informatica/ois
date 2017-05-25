#include <stdio.h>
#include <assert.h>

int vincente(char griglia[3][3]) {
    // Mettete qui il codice della soluzione
    return 0;
}


char griglia[3][3];

int main() {
    FILE *fr, *fw;
    int r, c;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    for (r=0; r<3; r++) {
        for (c=0; c<3; c++) {
            griglia[r][c] = fgetc(fr);
        }
        fgetc(fr);
    }

    fprintf(fw, "%d\n", vincente(griglia));
    fclose(fr);
    fclose(fw);
    return 0;
}

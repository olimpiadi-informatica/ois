#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXN 100000

int giraMagneti(int N, char descrizione[]) {
    int c_p = 0, c_m = 0;
    for (int i = 0; i < N/4; i++) {
        if (descrizione[4 * i + 1] == '+')
            ++c_p;
        else
            ++c_m;
    }

    return std::min(c_p, c_m);
}


char descrizione[MAXN];

int main() {
    FILE *fr, *fw;
    int N;
    
#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d\n", &N));
    assert(1 == fscanf(fr, "%s", descrizione));

    fprintf(fw, "%d\n", giraMagneti(N, descrizione));
    fclose(fr);
    fclose(fw);
    return 0;
}

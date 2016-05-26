/*
 * Simula la strategia "prendi sempre quello piu' a sinistra" per tutte
 * le possibili permutazioni.
 *
 * Tempo: O(N!)
 */

#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

int main() {
    FILE *fr, *fw;
    int N, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));

    std::vector<int> numeri(N);
    std::iota(numeri.begin(), numeri.end(), 0);

    double scosse = 0;

    do {
        std::vector<int> used(N);
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (used[j] == 0) {
                    if (numeri[j] != i) {
                        scosse += 1;
                    } else {
                        used[j] = true;
                        break;
                    }
                }
            }
        }
    } while (std::next_permutation(numeri.begin(), numeri.end()));

    // scosse /= factorial(N);
    for (int i=2; i<=N; i++) {
        scosse /= i;
    }

    fprintf(fw, "%.1f\n", scosse);
    fclose(fr);
    fclose(fw);
}

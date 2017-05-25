#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define MAXN 1000
int griglia[MAXN][MAXN];

int goali, goalj, goals;

void dfs(int i, int j, int s) {
    //~ printf("%d %d %d\n", i, j, s);
    int di = 0, dj = 0;

    if (goali > i)
        di = 1;
    else if (goali < i)
        di = -1;

    if (goalj > j)
        dj = 1;
    else if (goalj < j)
        dj = -1;

    if (di == 0 && dj == 0)  {
        // in the right tile
        if (s == goals) {
            return;
        }

        if (s == 0) {
            if (goals == 1 || goals == 2)
                dj = 1;
            if (goals == 3 || goals == 2)
                di = 1;
        } else if (s == 1) {
            if (goals == 0 || goals == 3)
                dj = -1;
            if (goals == 3 || goals == 2)
                di = 1;
        } else if (s == 2) {
            if (goals == 0 || goals == 1)
                di = -1;
            if (goals == 0 || goals == 3)
                dj = -1;
        } else {
            if (goals == 0 || goals == 1)
                di = -1;
            if (goals == 1 || goals == 2)
                dj = 1;
        }
    }

    if (di != 0 && dj != 0) {
        if (rand() % 2)
            di = 0;
        else
            dj = 0;
    }

    if (di == -1) {
        if (s == 0) {
            i = i - 1;
            s = 3;
        } else if (s == 1) {
            i = i - 1;
            s = 2;
        } else if (s == 2) {
            griglia[i][j] &= 15 - 2;
            s = 1;
        } else if (s == 3) {
            griglia[i][j] &= 15 - 8;
            s = 0;
        }
    } else if (di == 1) {
        if (s == 0) {
            griglia[i][j] &= 15 - 8;
            s = 3;
        } else if (s == 1) {
            griglia[i][j] &= 15 - 2;
            s = 2;
        } else if (s == 2) {
            i = i + 1;
            s = 1;
        } else if (s == 3) {
            i = i + 1;
            s = 0;
        }
    } else if (dj == -1) {
        if (s == 0) {
            j--;
            s = 1;
        } else if (s == 1) {
            griglia[i][j] &= 15 - 1;
            s = 0;
        } else if (s == 2) {
            griglia[i][j] &= 15 - 4;
            s = 3;
        } else if (s == 3) {
            j--;
            s = 2;
        }
    } else if (dj == 1) {
        if (s == 0) {
            griglia[i][j] &= 15 - 1;
            s = 1;
        } else if (s == 1) {
            j++;
            s = 0;
        } else if (s == 2) {
            j++;
            s = 3;
        } else if (s == 3) {
            griglia[i][j] &= 15 - 4;
            s = 2;
        }
    }

    dfs(i, j, s);
}

void usage(char* exe) {
    printf("usage: %s N M T S\n", exe);
    puts("T = 0 for no walls");
    puts("T = 1 for random walls (likely solvable)");
    puts("T = 2 for random walls (likely unsolvable)");
    puts("T = 3 for alternating walls");
    puts("T = 4 for dfs-based");
    exit(1);
}

int main(int argc, char** argv) {
    if (argc != 5) {
        usage(argv[0]);
    }

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int T = atoi(argv[3]);

    srand(atoi(argv[4]));

    printf("%d %d\n", N, M);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            griglia[i][j] = 15;

    if (T == 0) {

        memset(griglia, 0, sizeof griglia);

    } else if (T == 1) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (random() % 100 < 70)
                    griglia[i][j] ^= 1;
                if (random() % 100 < 60)
                    griglia[i][j] ^= 8;
                if (random() % 100 < 50)
                    griglia[i][j] ^= 4;
                if (random() % 100 < 40)
                    griglia[i][j] ^= 2;
            }
        }

        // forza la prima e ultima mattonella
        if (random() % 2)
            griglia[0][0] &= 14;
        else
            griglia[0][0] &= 7;

        if (random() % 2)
            griglia[N-1][M-1] &= 13;
        else
            griglia[N-1][M-1] &= 11;

    } else if (T == 2) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (random() % 100 < 50)
                    griglia[i][j] ^= 1;
                if (random() % 100 < 50)
                    griglia[i][j] ^= 8;
                if (random() % 100 < 50)
                    griglia[i][j] ^= 4;
                if (random() % 100 < 50)
                    griglia[i][j] ^= 2;
            }
        }

    } else if (T == 3) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                griglia[i][j] ^= 1 + 4;
                if (i % 2 == 0 && j == M - 1) {
                    griglia[i][j] ^= 2;
                } else if (i % 2 == 1 && j == 0) {
                    griglia[i][j] ^= 8;
                }
            }
        }

    } else {

        // definisci un po' di goal
        int num_goals = 1 + std::min((N + M) / 2, 50);

        for (int i=0; i<num_goals; i++) {
            int posi = goali;
            int posj = goalj;
            int poss = goals;

            if (i == num_goals - 1) {
                goali = N - 1;
                goalj = M - 1;
                goals = 2;
            } else {
                for (int ii=0; ii<(N+M)/2; ii++) {
                    int ngoali = rand() % N;
                    int ngoalj = rand() % M;
                    int ngoals = rand() % 4;
                    if (abs(ngoali - posi) + abs(ngoalj - posj) >
                            abs(goali - posi) + abs(goalj - posj)) {
                        goali = ngoali;
                        goalj = ngoalj;
                        goals = ngoals;
                    }
                }
            }

            //~ printf("going to %d %d %d\n", goali, goalj, goals);

            dfs(posi, posj, poss);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) printf(" ");
            printf("%d", griglia[i][j]);
        }
        printf("\n");
    }
}

#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <cstring>
#include <string>
#include <unordered_map>
#include <algorithm>

struct state_t {
    char g[3][3];

    state_t() {
        memset(g, '.', sizeof g);
    }

    state_t(char x[3][3]) {
        memcpy(g, x, sizeof g);
    }

    bool operator==(const state_t& o) const {
        return !memcmp(g, o.g, sizeof g);
    }

    std::string as_string() const {
        std::string ans;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++)
                ans += g[r][c];
            ans += '\n';
        }
        return std::move(ans);
    }

    int nsyms() const {
        int syms = 0;
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                syms += (g[r][c] != '.');
        return syms;        
    }

    char turn() const {
        if (nsyms() % 2)
            return 'O';
        else
            return 'X';
    }

    bool tris_row(int r) const {
        return (g[r][0] == g[r][1] && g[r][1] == g[r][2] && g[r][0] != '.');
    }

    bool tris_col(int c) const {
        return (g[0][c] == g[1][c] && g[1][c] == g[2][c] && g[0][c] != '.');
    }

    bool tris_diag1() const {
        return (g[0][0] == g[1][1] && g[1][1] == g[2][2] && g[0][0] != '.');
    }

    bool tris_diag2() const {
        return (g[0][2] == g[1][1] && g[1][1] == g[2][0] && g[0][2] != '.');
    }

    bool someone_won() const {
        return (
            tris_row(0) || tris_row(1) || tris_row(2) ||
            tris_col(0) || tris_col(1) || tris_col(2) ||
            tris_diag1() || tris_diag2()
        );
    }
};

namespace std {
    template<>
    struct hash<state_t> {
        size_t operator()(const state_t& o) const {
            return hash<string>()(o.as_string());
        }
    };
}

std::unordered_map<state_t, bool> memo;

bool dfs(const state_t& state) { // true = winning, false = losing
    if (memo.count(state))
        return memo[state];

    if (state.someone_won())
        return false;
    if (state.nsyms() == 9)
        return true; // Tie is a losing position for X, thus it is a winning position for O

    char turn = state.turn();
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (state.g[r][c] == '.') {
                state_t new_state(state);
                new_state.g[r][c] = turn;

                if (!dfs(new_state)){
                    return memo[state] = true;
                }
            }
        }
    }

    return memo[state] = false;
}

int vincente(char grid[3][3]) {
    state_t state(grid);

    assert(!state.someone_won());
    if (state.turn() == 'X' && dfs(state))
        return 1;
    if (state.turn() == 'O' && !dfs(state))
        return 1;
    return 0;
}


char griglia[3][3];

int main() {
    FILE *fr, *fw;
    int r, c;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif

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
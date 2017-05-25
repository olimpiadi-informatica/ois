/**
 * Visualizzatore degli input
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

void do_it(int x) {
    switch (x) {
    case 0:
        puts("");
        return;
    case 1:
        puts("╵");
        return;
    case 2:
        puts("╶");
        return;
    case 3:
        puts("└");
        return;
    case 4:
        puts("╷");
        return;
    case 5:
        puts("│");
        return;
    case 6:
        puts("┌");
        return;
    case 7:
        puts("├");
        return;
    case 8:
        puts("╴");
        return;
    case 9:
        puts("┘");
        return;
    case 10:
        puts("─");
        return;
    case 11:
        puts("┴");
        return;
    case 12:
        puts("┐");
        return;
    case 13:
        puts("┤");
        return;
    case 14:
        puts("┬");
        return;
    case 15:
        puts("┼");
        return;
    default:
        assert(false);
    }
}

int main() {
    int N, M;
    assert(2 == scanf("%d%d", &N, &M));

    int height = std::max((950 / N) - 30, 10);

    puts("<html>");
        puts("<head>");
            puts("<style>");
                puts("table {");
                    puts("border-collapse:collapse;");
                puts("}");
                puts("td {");
                    printf("height: %dpx;\n", height);
                    puts("border: 1px dotted;");
                    puts("font-family: monospace;");
                    puts("font-weight: bold;");
                    printf("font-size: %dpx;\n", height);
                puts("}");
            puts("</style>");
        puts("</head>");
        puts("<body>");
            puts("<table>");
            for(int i = 0; i < N; i++) {
                puts("<tr>");
                for(int j = 0; j < M; j++) {
                    int x;
                    assert(1 == scanf("%d", &x));
                    puts("<td>");
                        do_it(x);
                    puts("</td>");
                }
                puts("</tr>");
            }
            puts("</table>");
        puts("</body>");
    puts("</html>");
}

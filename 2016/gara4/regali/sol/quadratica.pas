const
    MAXN = 10000;
    MAXQ = 1000;
type
    matrix = array[0..MAXN-1] of array[0..MAXQ-1] of longint;


function lcp(var a: array of longint; var b: array of longint; var Q: longint): longint;
begin
    lcp := 0;
    while (lcp < Q) and (a[lcp] = b[lcp]) do
        inc(lcp);
end;

function compra(N, Q: longint; var V: matrix): longint;
var i, j, c: longint;
begin
    compra := 0;
    for i := 0 to N - 1 do
        for j := i + 1 to N - 1 do
        begin
            c := lcp(V[i], V[j], Q);
            if c > compra then
                compra := c;
        end;
end;


var
    N, Q, i, j  : longint;
    G           : matrix;
    fr, fw      : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, Q);
    for i:=0 to N-1 do begin
        for j:=0 to Q-1 do
            read(fr, G[i][j]);
        readln(fr);
    end;

    writeln(fw, compra(N, Q, G));
    close(fr);
    close(fw);
end.

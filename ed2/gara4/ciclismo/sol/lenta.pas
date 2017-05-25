const
    MAXN = 10000;
    MAXM = 100000;
var
    N, M, i : longint;
    H       : array[0..MAXN-1] of longint;
    da      : array[0..MAXM-1] of longint;
    a       : array[0..MAXM-1] of longint;
    visto   : array[0..MAXN-1] of boolean;
    fr, fw  : text;


function dfs(node, parent: longint): longint;
var i, c, best: longint;
begin
    if visto[node] then
    begin
        dfs := node;
        exit;
    end else
        visto[node] := True;

    best := -1;
    for i:=0 to M-1 do
    begin
        c := -1;
        if (node = a[i]) and (da[i] <> parent) then
            c := da[i]
        else if (node = da[i]) and (a[i] <> parent) then
            c := a[i];

        if (c <> -1) and ((best = -1) or (H[best] > H[c])) then
            best := c;
    end;

    if best = -1 then
        dfs := node
    else
        dfs := dfs(best, node);
end;

function pedala(N, M: longint; var H, da, a: array of longint): longint;
begin
    for i:=0 to N - 1 do
        visto[i] := False;

    pedala := dfs(0, -1);
end;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to N-1 do
        read(fr, H[i]);
    readln(fr);
    for i:=0 to M-1 do
        readln(fr, da[i], a[i]);

    writeln(fw, pedala(N, M, H, da, a));
    close(fr);
    close(fw);
end.

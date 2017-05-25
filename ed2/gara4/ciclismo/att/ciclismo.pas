function pedala(N, M: longint; var H, da, a: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    pedala := 42;
end;


const
    MAXN = 10000;
    MAXM = 100000;
var
    N, M, i : longint;
    H       : array[0..MAXN-1] of longint;
    da      : array[0..MAXM-1] of longint;
    a       : array[0..MAXM-1] of longint;
    fr, fw  : text;

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

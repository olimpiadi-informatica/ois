function compra(N, M, K: longint; var supermercati, da, a: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    compra := 42;
end;


const
    MAXK = 10000;
    MAXM = 100000;
var
    N, M, K, i  : longint;
    supermercati: array[0..MAXK-1] of longint;
    da, a       : array[0..MAXM-1] of longint;
    fr, fw      : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M, K);
    for i:=0 to K-1 do
        read(fr, supermercati[i]);
    readln(fr);
    for i:=0 to M-1 do
        readln(fr, da[i], a[i]);

    writeln(fw, compra(N, M, K, supermercati, da, a));
    close(fr);
    close(fw);
end.

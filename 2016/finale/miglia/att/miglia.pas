function vola(K, N, M: longint; var da, a, V: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    vola := 42;
end;


const
    MAXM = 10000;
var
    K,N,M,i : longint;
    da      : array[0..MAXM-1] of longint;
    a       : array[0..MAXM-1] of longint;
    V       : array[0..MAXM-1] of longint;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, K, N, M);
    for i:=0 to M-1 do
        readln(fr, da[i], a[i], V[i]);

    writeln(fw, vola(K, N, M, da, a, V));
    close(fr);
    close(fw);
end.

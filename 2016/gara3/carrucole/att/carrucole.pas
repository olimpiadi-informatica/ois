function conta(N, M: longint; var B, da, a: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    conta := 42;
end;


const
    MAXN = 10000;
    MAXM = 100000;
var
    N, M, i : longint;
    B     : array[0..MAXN-1] of longint;
    da, a : array[0..MAXM-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to N-1 do
        read(fr, B[i]);
    readln(fr);
    for i:=0 to M-1 do
        readln(fr, da[i], a[i]);

    writeln(fw, conta(N, M, B, da, a));
    close(fr);
    close(fw);
end.
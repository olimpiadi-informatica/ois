function recluta(N: longint; var B, C: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    recluta := 42;
end;


const
    MAXN = 10000;
var
    N, i  : longint;
    B, C  : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        readln(fr, B[i], C[i]);

    writeln(fw, recluta(N, B, C));
    close(fr);
    close(fw);
end.

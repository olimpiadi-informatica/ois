function accelera(N, M: longint; var da, a, V: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    accelera := 42;
end;


const
    MAXM = 100000;
var
    N, M, i  : longint;
    da, a, V : array[0..MAXM-1] of longint;
    fr, fw   : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to M-1 do
        readln(fr, da[i], a[i], V[i]);

    writeln(fw, accelera(N, M, da, a, V));
    close(fr);
    close(fw);
end.

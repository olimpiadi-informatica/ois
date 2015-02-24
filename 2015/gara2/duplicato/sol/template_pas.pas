function trova(N: longint; var P: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    trova := 42;
end;

const
    MAXN = 100000;
var
    N, i  : longint;
    P     : array[0..2*MAXN-2] of longint;
    fr, fw: text;
begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');

    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to 2*N-2 do
        read(fr, P[i]);
    writeln(fw, trova(N, P));
    close(fr);
    close(fw);
end.

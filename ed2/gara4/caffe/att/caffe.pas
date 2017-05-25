function pausa(N: longint; var A, B: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    pausa := 42;
end;


const
    MAXN = 100000;
var
    N, i  : longint;
    A, B  : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        readln(fr, A[i], B[i]);

    writeln(fw, pausa(N, A, B));
    close(fr);
    close(fw);
end.

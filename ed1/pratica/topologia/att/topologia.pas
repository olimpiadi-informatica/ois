procedure analizza(N, M: longint; var A, B, T: array of longint);
begin
    (* Mettete qui il codice della soluzione *)
    T[0] := 42;
    T[1] := 42;
    T[2] := 42;
end;


const
    MAXM = 100000;
var
    N, M, i: longint;
    A, B   : array[0..MAXM-1] of longint;
    T      : array[0..2] of longint;
    fr, fw : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to M-1 do
        readln(fr, A[i], B[i]);

    analizza(N, M, A, B, T);
    writeln(fw, T[0], ' ', T[1], ' ', T[2]);
    close(fr);
    close(fw);
end.

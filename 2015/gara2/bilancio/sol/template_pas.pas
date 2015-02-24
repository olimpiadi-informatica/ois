procedure bianchetta(N, K: longint; var U, C: array of longint);
begin
    (* Mettete qui il codice della soluzione *)
    C[0] := 4;
    C[1] := 2;
end;


const
    MAXN = 1000000;
var
    N, K, i: longint;
    U, C   : array[0..MAXN-1] of longint;
    fr, fw : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, K);
    for i:=0 to N-1 do
        read(fr, U[i]);

    bianchetta(N, K, U, C);
    for i:=0 to N-K-1 do
        write(fw, C[i], ' ');
    writeln(fw);
    close(fr);
    close(fw);
end.

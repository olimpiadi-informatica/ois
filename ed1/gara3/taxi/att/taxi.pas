function viaggia(N: longint; var C: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    viaggia := 42;
end;


const
    MAXN = 10000;
var
    N, i  : longint;
    C     : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, C[i]);

    writeln(fw, viaggia(N, C));
    close(fr);
    close(fw);
end.

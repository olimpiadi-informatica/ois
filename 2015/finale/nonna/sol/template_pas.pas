function mangia(N, K: longint; var P: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    mangia := 42;
end;


const
    MAXN = 5000;
    MAXK = 5000;
    MAXP = 1000000;
var
    N, K, i : longint;
    P       : array[0..MAXN-1] of longint;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, K);
    for i:=0 to N-1 do
        read(fr, P[i]);

    writeln(fw, mangia(N, K, P));
    close(fr);
    close(fw);
end.

function cadi(N: longint; var L, P: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    P[0] := 42;
    cadi := 1;
end;


const
    MAXN = 100000;
    MAXM = 2*MAXN;
var
    N, M, i: longint;
    L      : array[0..MAXN-1] of longint;
    P      : array[0..MAXM-1] of longint;
    fr, fw : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, L[i]);

    M := cadi(N, L, P);
    writeln(fw, M);
    for i:=0 to M-2 do
        write(fw, P[i], ' ');
    writeln(fw, P[M-1]);
    close(fr);
    close(fw);
end.

function raccogli(N, M: longint; var monete, A, B: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    raccogli := 42;
end;


const
    MAXN = 10000;
    MAXM = 100000;
var
    N, M, i : longint;
    monete  : array[0..MAXN-1] of longint;
    A, B    : array[0..MAXM-1] of longint;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to N-1 do
        read(fr, monete[i]);
    readln;
    for i:=0 to M-1 do
        readln(fr, A[i], B[i]);

    writeln(fw, raccogli(N, M, monete, A, B));
    close(fr);
    close(fw);
end.

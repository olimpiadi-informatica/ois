function ricarica(N, M: longint; var A, B: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    ricarica := 42;
end;


const
    MAXN = 100000;
var
    N, M, i : longint;
    A, B    : array[0..MAXN-1] of longint;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to N-1 do
        readln(fr, A[i], B[i]);

    writeln(fw, ricarica(N, M, A, B));
    close(fr);
    close(fw);
end.
uses math;

const
    MAXN = 100000;
    MAXM = 10000000;
var
    N, M, i : longint;
    A, B    : array[0..MAXN-1] of longint;
    C       : array[1..MAXM] of longint;
    fr, fw  : text;

function ricarica(N, M: longint; var A, B: array of longint): longint;
var i, j, carica : longint;
begin
    for i:=1 to M do C[i] := -1;
    for i:=0 to N-1 do begin
        for j:=A[i] to B[i] do C[j] := 1;
    end;
    ricarica := 0;
    carica := 0;
    for i:=1 to M do begin
        carica := carica + C[i];
        ricarica := min(ricarica, carica);
    end;
    ricarica := 1-ricarica;
end;



begin
{$ifdef EVAL}
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
{$else}
    fr := input;
    fw := output;
{$endif}
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to N-1 do
        readln(fr, A[i], B[i]);

    writeln(fw, ricarica(N, M, A, B));
    close(fr);
    close(fw);
end.

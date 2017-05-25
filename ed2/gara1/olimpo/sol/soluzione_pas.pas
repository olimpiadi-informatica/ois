uses math;

function visita(x: longint; var Q: array of char; var A: array of longint): longint;
begin
    if x = 0 then visita := 0
    else begin
        visita := visita(A[x], Q, A);
        if (Q[x] = 'P') then visita := visita +1;
        if (Q[x] = 'N') then visita := visita +2;
        if (Q[x] = 'B') then visita := visita +3;
    end;
end;

function falsifica(N: longint; var Q: array of char; var A: array of longint): longint;
var i: longint;
begin
    falsifica := 0;
    for i:=1 to N-1 do
        falsifica := max(falsifica, visita(i,Q,A));
end;


const
    MAXN = 1000000;
var
    N, i  : longint;
    Q     : array[0..MAXN-1] of char;
    A     : array[0..MAXN-1] of longint;
    fr, fw: text;

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
    readln(fr, N);
    Q[0] := 'X';
    A[0] := -1;
    for i:=1 to N-1 do
        readln(fr, Q[i], A[i]);

    writeln(fw, falsifica(N, Q, A));
    close(fr);
    close(fw);
end.

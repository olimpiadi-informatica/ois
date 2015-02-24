uses math;

function demolisci(N, K: longint; var V: array of longint): longint;
var i: longint;
begin
    for i:=1 to N-1 do V[i] := V[i] + V[i-1];
    demolisci := V[K-1];
    for i:=K to N-1 do demolisci := min(demolisci, V[i] - V[i-K]);
end;


const
    MAXN = 100000;
var
    N, K, i : longint;
    V       : array[0..MAXN-1] of longint;
    fr, fw  : text;

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
    readln(fr, N, K);
    for i:=0 to N-1 do
        read(fr, V[i]);

    writeln(fw, demolisci(N, K, V));
    close(fr);
    close(fw);
end.

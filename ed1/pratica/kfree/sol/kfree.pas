const
    MAXN = 100000;
var
    insieme : array[0..MAXN-1] of longint;
    usable: array[1..MAXN] of boolean;
    N, K, i : longint;
    fr, fw  : text;

function Trova(N, K: longint; var A: array of longint): longint;
var i, excluded: longint;
begin
    for i:=0 to N-1 do
        usable[A[i]] := True;
    excluded := 0;
    for i:=1 to MAXN do
    begin
        if not usable[i] then continue;
        if K*i > MAXN then continue;
        if not usable[K*i] then continue;
        usable[K*i] := false;
        inc(excluded);
    end;
    Trova := N - excluded;
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
    readln(fr, N, K);
    for i:=0 to N-1 do
        readln(fr, insieme[i]);

    writeln(fw, Trova(N, K, insieme));
    close(fr);
    close(fw);
end.

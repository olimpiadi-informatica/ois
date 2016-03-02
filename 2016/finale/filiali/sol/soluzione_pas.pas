const
    MAXN = 1000000;
    MAXF = 1000;

function possible(test, N, F: longint; var K: array of longint): boolean;
var i, last : longint;
begin
    last := -1;

    for i:=0 to N-1 do
        if (last = -1) or (K[i] - K[last] >= test) then
        begin
            dec(F);
            last := i;
        end;

    possible := (F <= 0);
end;

function apri(N, F: longint; var K: array of longint): longint;
var
    left, right, middle : longint;
begin
    left := 0;
    right := K[N-1];

    while left + 1 < right do
    begin
        middle := left;
        inc(middle, (right - left) div 2);

        if possible(middle, N, F, K) then
            left := middle
        else
            right := middle - 1;
    end;

    if possible(right, N, F, K) then
        apri := right
    else
        apri := left;
end;


var
    N, F, i : longint;
    K       : array[0..MAXN-1] of longint;
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
    readln(fr, N, F);
    for i:=0 to N-1 do
        read(fr, K[i]);

    writeln(fw, apri(N, F, K));
    close(fr);
    close(fw);
end.

const
    MAXM = 10000;
var
    K,N,M,i : longint;
    da      : array[0..MAXM-1] of longint;
    a       : array[0..MAXM-1] of longint;
    V       : array[0..MAXM-1] of longint;
    fr, fw  : text;

function max(a, b: longint): longint;
begin
    if a > b then
        max := a
    else
        max := b;
end;

function vola(u, d, acc : longint): longint;
var i : longint;
begin
    vola := 0;

    if d > 0 then
    begin
        for i := 0 to M-1 do
            if da[i] = u then
                vola := max(vola, vola(a[i], d - 1, acc + V[i]));
    end
    else
        if u = 0 then
            vola := acc
        else
            vola := 0;
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
    readln(fr, K, N, M);
    for i:=0 to M-1 do
        readln(fr, da[i], a[i], V[i]);

    writeln(fw, vola(0, K, 0));
    close(fr);
    close(fw);
end.

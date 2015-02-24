uses math;

const
    MAXN = 100000;
var
    Sums, Inz, Fin  : array[0..MAXN+1] of longint;

function porziona(N: longint; var mandorle, cannella: array of longint): longint;
var i, j, k : longint;
begin
    for i:=0 to N-1 do Sums[i+1] := Sums[i] + cannella[i] - mandorle[i];
    j := 0;
    Inz[0] := 0;
    for i:=1 to N do if Sums[i] < Sums[Inz[j]] then begin
        inc(j);
        Inz[j] := i;
    end;
    k := 0;
    Fin[0] := N;
    for i:=N-1 downto 1 do if Sums[i] > Sums[Fin[k]] then begin
        inc(k);
        Fin[k] := i;
    end;
    j := 0;
    porziona := 0;
    for k:=k downto 0 do begin
        while Sums[Inz[j]] > Sums[Fin[k]] do inc(j);
        porziona := max(porziona, Fin[k] - Inz[j]);
    end;
end;


var
    N, i                : longint;
    mandorle, cannella  : array[0..MAXN-1] of longint;
    fr, fw              : text;

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
    for i:=0 to N-1 do
        read(fr, mandorle[i]);
    readln(fr);
    for i:=0 to N-1 do
        read(fr, cannella[i]);

    writeln(fw, porziona(N, mandorle, cannella));
    close(fr);
    close(fw);
end.

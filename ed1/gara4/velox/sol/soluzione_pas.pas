uses math;

const
    MAXN = 10240;
    MAXM = 102400;
var
    N, M, i             : longint;
    da, a, V            : array[0..MAXM-1] of longint;
    Next,  vNext, rNext : array[0..2*MAXM-1] of longint;
    iNext, nNext        : array[0..MAXN-1] of longint;
    fr, fw              : text;


function visita(n, v: longint): longint; forward;

function valore(n, i: longint): longint;
begin
    if (rNext[iNext[n]+i] = 0) then rNext[iNext[n]+i] := visita(Next[iNext[n]+i], vNext[iNext[n]+i])+1;
    valore := rNext[iNext[n]+i];
end;

function visita(n, v: longint): longint;
var l, i: longint;
begin
    l := 0;
    for i := 0 to nNext[n]-1 do if (vNext[iNext[n]+i] > v) then l := max(l, valore(n, i));
    visita := l;
end;


function accelera(N, M: longint; var da, a, V: array of longint): longint;
var i: longint;
begin
    for i:=0 to M-1 do begin
        inc(nNext[da[i]]);
    end;
    for i:=1 to N do begin
        iNext[i] := iNext[i-1] + nNext[i-1];
        nNext[i-1] := 0;
    end;
    for i:=0 to M-1 do begin
        Next[ iNext[da[i]]+nNext[da[i]]] := a[i];
        vNext[iNext[da[i]]+nNext[da[i]]] := V[i];
        inc(nNext[da[i]]);
    end;
    accelera := 0;
    for i:=0 to N-1 do accelera := max(accelera, visita(i, 0));
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
    for i:=0 to M-1 do
        readln(fr, da[i], a[i], V[i]);

    writeln(fw, accelera(N, M, da, a, V));
    close(fr);
    close(fw);
end.

uses math;

const
    MAXN = 10240;
    MAXM = 102400;
var
    N, M, i         : longint;
    da, a           : array[0..MAXM-1] of longint;
    Next            : array[0..2*MAXM-1] of longint;
    iNext, nNext, V : array[0..MAXN-1] of longint;
    fr, fw          : text;


procedure visita(x: longint);
var i : longint;
begin
    if V[x] = 0 then begin
        V[x] := 1;
        for i:=0 to nNext[x]-1 do visita(Next[iNext[x]+i]);
    end;
end;


function costruisci(N, M: longint; var da, a: array of longint): longint;
var i: longint;
begin
    for i:=0 to M-1 do begin
        inc(nNext[da[i]]);
        inc(nNext[a[i]]);
    end;
    for i:=1 to N-1 do begin
        iNext[i] := iNext[i-1] + nNext[i-1];
        nNext[i-1] := 0;
        V[i] := 0;
    end;
    V[0] := 0;
    nNext[N-1] := 0;
    for i:=0 to M-1 do begin
        Next[iNext[da[i]]+nNext[da[i]]] := a[i];
        Next[iNext[a[i]]+nNext[a[i]]] := da[i];
        inc(nNext[da[i]]);
        inc(nNext[a[i]]);
    end;
    costruisci := -1;
    for i:=0 to N-1 do
        if V[i] = 0 then begin
            visita(i);
            inc(costruisci);
        end;
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
        readln(fr, da[i], a[i]);

    writeln(fw, costruisci(N, M, da, a));
    close(fr);
    close(fw);
end.

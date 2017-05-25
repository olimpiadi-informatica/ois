uses math;

const
    MAXN = 10240;
    MAXM = 102400;
var
    N, M, nS, i              : longint;
    conoscenzeA, conoscenzeB : array[0..MAXM-1] of longint;
    Next                     : array[0..2*MAXM-1] of longint;
    iNext, nNext, Stack      : array[0..MAXN-1] of longint;
    fr, fw                   : text;

function invita(N, M: longint; var da, a: array of longint): longint;
var t, i : longint;
begin
    for i:=0 to M-1 do begin
        inc(nNext[da[i]]);
        inc(nNext[a[i]]);
    end;
    for i:=1 to N do begin
        iNext[i] := iNext[i-1] + nNext[i-1];
        nNext[i-1] := 0;
    end;
    for i:=0 to M-1 do begin
        Next[iNext[da[i]]+nNext[da[i]]] := a[i];
        Next[iNext[a[i]]+nNext[a[i]]] := da[i];
        inc(nNext[da[i]]);
        inc(nNext[a[i]]);
    end;
    nS := 0;
    for i:=0 to N-1 do
        if (nNext[i] < 2) then begin
            Stack[nS] := i;
            inc(nS);
        end;
    invita := N;
    while nS > 0 do begin
        dec(invita);
        dec(nS);
        t := Stack[nS];
        for i:=iNext[t] to iNext[t+1]-1 do begin
            if (nNext[Next[i]] = 2) then begin
                Stack[nS] := Next[i];
                inc(nS);
            end;
            dec(nNext[Next[i]]);
        end;
        nNext[t] := 2*MAXN;
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
        readln(fr, conoscenzeA[i], conoscenzeB[i]);

    writeln(fw, invita(N, M, conoscenzeA, conoscenzeB));
    close(fr);
    close(fw);
end.

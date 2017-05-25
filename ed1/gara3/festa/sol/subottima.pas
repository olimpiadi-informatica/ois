uses math;

const
    MAXN = 10240;
    MAXM = 102400;
var
    N, M, i                  : longint;
    conoscenzeA, conoscenzeB : array[0..MAXM-1] of longint;
    Next                     : array[0..2*MAXM-1] of longint;
    iNext, nNext             : array[0..MAXN-1] of longint;
    fr, fw                   : text;

function invita(N, M: longint; var da, a: array of longint): longint;
var finito, t, i, j : longint;
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
    invita := N;
    finito := 0;
    while finito = 0 do begin
        finito := 1;
        for j:=0 to N-1 do
            if (nNext[j] < 2) then begin
                finito := 0;
                dec(invita);
                for i:=iNext[j] to iNext[j+1]-1 do dec(nNext[Next[i]]);
                nNext[j] := 2*MAXN;
            end;
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

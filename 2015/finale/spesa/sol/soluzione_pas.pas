uses math;

const
    MAXK = 10240;
    MAXN = 10240;
    MAXM = 102400;
var
    N, M, K, i          : longint;
    supermercati        : array[0..MAXK-1] of longint;
    strada_da, strada_a : array[0..MAXM-1] of longint;
    Next                : array[0..2*MAXM-1] of longint;
    iNext, nNext, dg, dn: array[0..MAXN-1] of longint;
    fr, fw              : text;


procedure bfs(v: longint; var dist: array of longint);
var queue           : array[0..MAXM-1] of longint;
    len, x, i, k    : longint;
begin
    dist[v] := 1;
    queue[0] := v;
    len := 1;
    k := 0;
    while len > k do begin
        x := queue[k];
        inc(k);
        for i:=0 to nNext[x]-1 do if dist[Next[iNext[x]+i]] = 0 then begin
            dist[Next[iNext[x]+i]] := dist[x]+1;
            queue[len] := Next[iNext[x]+i];
            inc(len);
        end;
    end;
end;

function compra(N, M, K: longint; var supermercati, da, a: array of longint): longint;
var i: longint;
begin
    for i:=0 to M-1 do begin
        inc(nNext[a[i]-1]);
        inc(nNext[da[i]-1]);
    end;
    for i:=1 to N do begin
        iNext[i] := iNext[i-1] + nNext[i-1];
        nNext[i-1] := 0;
    end;
    for i:=0 to M-1 do begin
        Next[iNext[ a[i]-1]+nNext[ a[i]-1]] := da[i]-1;
        Next[iNext[da[i]-1]+nNext[da[i]-1]] :=  a[i]-1;
        inc(nNext[a[i]-1]);
        inc(nNext[da[i]-1]);
    end;
    bfs(0, dg);
    bfs(N-1, dn);
    compra := dg[supermercati[0]-1] + dn[supermercati[0]-1] - 2;
    for i:=1 to K-1 do begin
        compra := min(compra, dg[supermercati[i]-1]+dn[supermercati[i]-1]-2);
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
    readln(fr, N, M, K);
    for i:=0 to K-1 do
        read(fr, supermercati[i]);
    readln(fr);
    for i:=0 to M-1 do
        readln(fr, strada_da[i], strada_a[i]);

    writeln(fw, compra(N, M, K, supermercati, strada_da, strada_a));
    close(fr);
    close(fw);
end.

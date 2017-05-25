uses math;

const
    MAXN = 10240;
    MAXM = 102400;
var
    N, M, i                  : longint;
    conoscenzeA, conoscenzeB : array[0..MAXM-1] of longint;
    nNext                    : array[0..MAXN-1] of longint;
    fr, fw                   : text;

function invita(N, M: longint; var da, a: array of longint): longint;
var t, i : longint;
begin
    for i:=0 to M-1 do begin
        inc(nNext[da[i]]);
        inc(nNext[a[i]]);
    end;
    invita := N;
    for i:=0 to N-1 do
        if (nNext[i] < 2) then begin
            dec(invita);
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

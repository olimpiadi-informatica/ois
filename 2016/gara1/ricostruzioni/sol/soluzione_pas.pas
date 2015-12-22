uses math;

function spiana(N, K: longint; var A: array of longint): longint;
var i, j, mn, mx: longint;
begin
    spiana := 1000000;
    for i:=0 to N-K do begin
        mn := A[i];
        mx := A[i];
        for j:=1 to K-1 do begin
            mn := min(mn, A[i+j]);
            mx := max(mx, A[i+j]);
        end;
        spiana := min(spiana, mx-mn);
    end;
end;


const
    MAXN = 100000;
var
    N, K, i : longint;
    A       : array[0..MAXN-1] of longint;
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
    readln(fr, N, K);
    for i:=0 to N-1 do
        read(fr, A[i]);

    writeln(fw, spiana(N, K, A));
    close(fr);
    close(fw);
end.

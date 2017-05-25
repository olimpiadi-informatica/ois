uses math;

function viaggia(N: longint; var C: array of longint): longint;
var i, K : longint;
begin
    viaggia := 0;
    K := 100000;
    for i:=0 to N-1 do begin
        K := min(K+1, C[i]);
        viaggia := viaggia + K;
    end;
end;


const
    MAXN = 10000;
var
    N, i  : longint;
    C     : array[0..MAXN-1] of longint;
    fr, fw: text;

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
        read(fr, C[i]);

    writeln(fw, viaggia(N, C));
    close(fr);
    close(fw);
end.

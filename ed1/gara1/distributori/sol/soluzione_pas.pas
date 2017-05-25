function rifornisci(N, M, K: longint; var D: array of longint): longint;
var
    last, i : longint;
begin
    last := 0;
    rifornisci := 0;
    D[N] := K;
    for i:=0 to N-1 do
        if D[i+1] > (last+M) then begin
            last := D[i];
            inc(rifornisci);
        end;
end;


const
    MAXN = 102400;
var
    N, M, K, i : longint;
    D          : array[0..MAXN-1] of longint;
    fr, fw     : text;

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
    for i:=0 to N-1 do
        read(fr, D[i]);

    writeln(fw, rifornisci(N, M, K, D));
    close(fr);
    close(fw);
end.

uses math;

function salta(N: longint; var E: array of longint): longint;
var pos, reach : integer;
begin
    salta := 0;
    pos := -1;
    reach := 0;
    while reach < N do begin
        for pos := pos+1 to reach do reach := max(reach, pos + E[pos]);
        inc(salta);
    end;
end;


const
    MAXN = 100000;
var
    N, i  : longint;
    E     : array[0..MAXN-1] of longint;
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
        read(fr, E[i]);

    writeln(fw, salta(N, E));
    close(fr);
    close(fw);
end.

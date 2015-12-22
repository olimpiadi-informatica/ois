uses math;

const
    MAXN = 1000000;

function premi(N: longint; var B: array of longint): int64;
var bprev, iprev, bnext, inext, i, j: longint;
begin
    premi := 0;
    bprev := MAXN;
    iprev := 0;
    for i:=0 to N-1 do begin
        bnext := 0;
        inext := -1;
        for j:=0 to N-1 do begin
            if (B[j] < bprev) and (B[j] > bnext) then begin
                bnext := B[j];
                inext := j;
            end;
        end;
        premi := premi + abs(inext - iprev);
        bprev := bnext;
        iprev := inext;
    end;
end;


var
    N, i  : longint;
    B     : array[0..MAXN-1] of longint;
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
        read(fr, B[i]);

    writeln(fw, premi(N, B));
    close(fr);
    close(fw);
end.

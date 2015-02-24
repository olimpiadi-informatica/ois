uses math;

function passeggia(N: longint; var H: array of longint): longint;
var i : longint;
begin
    passeggia := 1;
    for i:=1 to N-1 do if (i = N-1) or ((H[i] > H[i-1]) and (H[i] > H[i+1])) or ((H[i] < H[i-1]) and (H[i] < H[i+1])) then inc(passeggia);
end;


const
    MAXN = 10000;
var
    N, i  : longint;
    H     : array[0..MAXN-1] of longint;
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
        read(fr, H[i]);

    writeln(fw, passeggia(N, H));
    close(fr);
    close(fw);
end.

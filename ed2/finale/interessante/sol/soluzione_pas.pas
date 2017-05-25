function popcount(x : longint): longint;
begin
    popcount := 0;

    while x > 0 do
    begin
        if x and 1 = 1 then
            inc(popcount);

        x := x shr 1;
    end;
end;

function b(i, x : longint): longint;
begin
    b := (x shr i) and 1;
end;

function conta(N, K : longint): longint;
var mask, x, i : longint;
label esci;
begin
    conta := 0;

    for mask := 0 to (1 shl N) - 1 do
    begin
        if popcount(mask) <> K then
            continue;

        for x := 1 to 10 do
            for i := 0 to N - 3 * x - 1 do
                if ((b(i, mask) = b(i + x, mask))
                        and (b(i + x, mask) = b(i + 2 * x, mask))
                        and (b(i + 2 * x, mask) = b(i + 3 * x, mask))) then
                    goto esci;

        inc(conta);

        esci:
    end;
end;


var
    N, K  : longint;
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
    readln(fr, N, K);

    writeln(fw, conta(N, K));
    close(fr);
    close(fw);
end.

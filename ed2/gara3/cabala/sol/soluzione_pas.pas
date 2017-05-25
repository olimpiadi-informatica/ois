uses math;

function occulta(N, M: longint): int64;
var i, x, mx : int64;
    check : boolean;
begin
    occulta := 0;
    mx := 1;
    for i:=0 to N-1 do mx := mx*10;
    for i:=3 to mx-1 do begin
        check := true;
        x := i;
        while x > 0 do begin
            if (((x mod 10) mod 3) <> 0) or ((x mod 10) = 0) then check := false;
            if (x mod 10) = ((x div 10) mod 10) then check := false;
            x := x div 10;
        end;
        if check then occulta := max(occulta, i mod M);
    end;
end;


var
    T, N, M, i : longint;
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
    readln(fr, T);
    for i:=0 to T-1 do begin
        readln(fr, N, M);
        write(fw, occulta(N, M), ' ');
    end;

    writeln(fw);
    close(fr);
    close(fw);
end.

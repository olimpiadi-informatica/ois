uses math;

function rimedia(N: longint): longint;
var T, M, c: longint;
begin
    T := N;
    M := 0;
    repeat
        c := T mod 10;
        if (c = 3) or (c = 4) or (c = 7) or ((c = 0) and (M = 0)) then begin
            M := N;
            break;
        end;
        if (c = 6) or (c = 9) then c := 15 - c;
        M := M * 10 + c;
        T := T div 10;
    until T = 0;
    rimedia := min(N, M);
end;


var
    N     : longint;
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

    writeln(fw, rimedia(N));
    close(fr);
    close(fw);
end.

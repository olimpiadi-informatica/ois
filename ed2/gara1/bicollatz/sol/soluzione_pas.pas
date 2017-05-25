function bicollatz(A, B: longint): longint;
var n, quit : longint;
begin
    n := -1;
    quit := 0;
    while (quit = 0) do begin
        n := n+1;
        if       ((A = 1) and (B = 1)) then quit := 1
        else if (((A = 1) and (B = 2)) or ((A = 1) and (B = 7)) or ((A = 7) and (B = 1))) then begin
            n := -1;
            quit := 1;
        end
        else if (A mod 2 + B mod 2 = 0) then begin
            A := A div 2;
            B := B div 2;
        end
        else if (A mod 2 + B mod 2 = 2) then begin
            A := 3*A + 1;
            B := 3*B + 1;
        end
        else if (A mod 2 = 1) then A := A+3
        else B := B+3;
    end;
    bicollatz := n;
end;


var
    A, B  : longint;
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
    readln(fr, A, B);

    writeln(fw, bicollatz(A, B));
    close(fr);
    close(fw);
end.

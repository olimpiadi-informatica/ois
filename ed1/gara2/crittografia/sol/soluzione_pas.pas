function codifica(N: longint): longint;
var T, R: longint;
begin
    T := N;
    R := 0;
    repeat
        R := R * 10 + (T mod 10);
        T := T div 10;
    until T = 0;
    codifica := N + R;
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

    writeln(fw, codifica(N));
    close(fr);
    close(fw);
end.

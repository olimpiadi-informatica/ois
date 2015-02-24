function enumera(N, M: longint): longint;
var
    i : longint;
    G : array[0..3] of longint;
begin
    G[0] := -1;
    G[1] := 0;
    G[2] := 1;
    for i:=3 to N do begin
        G[i mod 4] := (i * G[(i-1) mod 4] + (M+1-(i mod M)) * G[(i-2) mod 4]) mod M;
    end;
    enumera := G[N mod 4];
end;


var
    N, M   : longint;
    fr, fw : text;

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
    readln(fr, N, M);

    writeln(fw, enumera(N, M));
    close(fr);
    close(fw);
end.

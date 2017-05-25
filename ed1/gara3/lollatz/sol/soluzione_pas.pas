function afaikdiyrotfl(N: longint): longint;
begin
    if ((N mod 10) = 0) then afaikdiyrotfl := N
    else
        afaikdiyrotfl := afaikdiyrotfl((N * ((N mod 10) - 1)) div 2);
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

    writeln(fw, afaikdiyrotfl(N));
    close(fr);
    close(fw);
end.

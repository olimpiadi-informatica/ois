uses math;

function alloca(N: longint): longint;
var M, p: longint;
begin
    alloca := 1;
    for M:=2 to N do begin
        if M * M > N then break;
        p := M;
        repeat
            p := p * M;
        until p > N;
        alloca := max(alloca, p div M);
    end;
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
    writeln(fw, alloca(N));
    close(fr);
    close(fw);
end.

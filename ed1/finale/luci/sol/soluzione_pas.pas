function spegni(N: Int64): Int64;
var c : Int64;
begin
    c := 2;
    while c*c<=N do c:=c+1;
    spegni := N-c+1;
end;


var
    N     : Int64;
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

    writeln(fw, spegni(N));
    close(fr);
    close(fw);
end.

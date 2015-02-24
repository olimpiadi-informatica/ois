function contaQuadrati(A, B: longint): longint;
var i, cnt: longint;
begin
    cnt := 0;
    i := 1;
    while i * i <= B do
    begin
        if (i * i >= A) then
            inc(cnt);
    inc(i);
    end;
    contaQuadrati := cnt;
end;

var A, B: longint;
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

    readln(fr, A, B);
    close(fr);

    writeln(fw, contaQuadrati(A, B));
    close(fw);
end.

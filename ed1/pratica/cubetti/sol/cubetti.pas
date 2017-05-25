const
    MAXN = 100000;
var
    conta: array[1..MAXN] of longint;
    stack: array[1..MAXN] of longint;
    stack_size: longint;
    i: longint;

function Diversifica(N: longint; var C: array of longint): longint;
begin
    Diversifica := 0;
    fillchar(conta, sizeof(conta), 0);
    stack_size := 0;

    for i:=0 to N-1 do
        inc(conta[C[i]]);

    for i:=1 to N do
        if conta[i] = 0 then
        begin
            inc(stack_size);
            stack[stack_size] := i;
        end;

    for i:=0 to N-1 do
        if conta[C[i]] > 1 then
        begin
            (* se ci sono altri cubetti di colore i, rivernicio i con un colore tra quelli ancora disponibili *)
            Diversifica := Diversifica + 1;
            dec(stack_size);
            dec(conta[C[i]]);
        end;
end;


var
    C      : array[0..MAXN-1] of longint;
    N      : longint;
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

    readln(fr, N);
    for i:=0 to N-1 do
        readln(fr, C[i]);

    writeln(fw, Diversifica(N, C));
    close(fr);
    close(fw);
end.

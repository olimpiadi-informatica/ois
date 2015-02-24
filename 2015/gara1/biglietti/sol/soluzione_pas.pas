uses math;

function compra(N, M, A, B: longint): longint;
begin
    compra := min(B * (N div M) + (N mod M) * A, min(A*N, B * (N div M + 1)));
end;


var
    N, M, A, B, i : longint;
    fr, fw        : text;

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
    readln(fr, N, M, A, B);

    writeln(fw, compra(N, M, A, B));
    close(fr);
    close(fw);
end.

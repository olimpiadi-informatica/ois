function porziona(N: longint; var mandorle, cannella: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    porziona := 42;
end;


const
    MAXN = 100000;
var
    N, i                : longint;
    mandorle, cannella  : array[0..MAXN-1] of longint;
    fr, fw              : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, mandorle[i]);
    readln(fr);
    for i:=0 to N-1 do
        read(fr, cannella[i]);

    writeln(fw, porziona(N, mandorle, cannella));
    close(fr);
    close(fw);
end.

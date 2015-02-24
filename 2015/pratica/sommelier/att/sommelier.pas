function degusta(N: longint; var V: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    degusta := 42;
end;


const
    MAXN = 10000;
var
    N, i  : longint;
    V     : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        readln(fr, V[i]);

    writeln(fw, degusta(N, V));
    close(fr);
    close(fw);
end.

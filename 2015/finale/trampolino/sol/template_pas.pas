function salta(N: longint; var E: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    salta := 42;
end;


const
    MAXN = 100000;
var
    N, i  : longint;
    E     : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, E[i]);

    writeln(fw, salta(N, E));
    close(fr);
    close(fw);
end.

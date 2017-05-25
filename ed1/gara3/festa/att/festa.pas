function invita(N, M: longint; var conoscenzeA, conoscenzeB: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    invita := 42;
end;


const
    MAXM = 100000;
var
    N, M, i: longint;
    conoscenzeA, conoscenzeB : array[0..MAXM-1] of longint;
    fr, fw : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to M-1 do
        readln(fr, conoscenzeA[i], conoscenzeB[i]);

    writeln(fw, invita(N, M, conoscenzeA, conoscenzeB));
    close(fr);
    close(fw);
end.

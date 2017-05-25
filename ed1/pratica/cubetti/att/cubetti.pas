function diversifica(N: longint; var colore: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
	diversifica := 42;
end;


const
    MAXN = 100000;
var
    C      : array[0..MAXN-1] of longint;
    N, i   : longint;
    fr, fw : text;
begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);

    readln(fr, N);
    for i:=0 to N-1 do
        readln(fr, C[i]);

    writeln(fw, diversifica(N, C));
    close(fr);
    close(fw);
end.

function confronta(N: longint; var G, W: array of char): longint;
begin
    (* Mettete qui il codice della soluzione *)
    confronta := 42;
end;


const
    MAXN = 5000;
var
    N: longint;
    G, W: array[0..MAXN] of char;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    readln(fr, G);
    readln(fr, W);

    writeln(fw, confronta(N, G, W));
    close(fr);
    close(fw);
end.

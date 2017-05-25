function gira(N: longint; var descrizione: array of char): longint;
begin
    (* Mettete qui il codice della soluzione *)
    gira := 42;
end;


const
    MAXN = 100000;
var
    N           : longint;
    descrizione : array[0..MAXN] of char;
    fr, fw      : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    readln(fr, descrizione);

    writeln(fw, gira(N, descrizione));
    close(fr);
    close(fw);
end.

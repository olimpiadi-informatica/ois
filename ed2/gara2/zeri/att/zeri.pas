function zeri(N: longint; var S: array of char): longint;
begin
    (* Mettete qui il codice della soluzione *)
    zeri := 42;
end;


const
    MAXN = 100000;
var
    N     : longint;
    S     : array[0..MAXN] of char;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, S);

    writeln(fw, zeri(length(S), S));
    close(fr);
    close(fw);
end.

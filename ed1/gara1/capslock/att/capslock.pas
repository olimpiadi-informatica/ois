procedure aggiusta(N: longint; var S: array of char);
begin
    (* Mettete qui il codice della soluzione *)
end;

const
    MAXN = 10000;
var
    N  : longint;
    S  : array[0..MAXN] of char;
    fr, fw: text;
begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    readln(fr, S);
    aggiusta(N, S);
    writeln(fw, S);
    close(fr);
    close(fw);
end.

procedure ripulisci(N: longint; var remix, testo: array of char);
begin
    (* Mettete qui il codice della soluzione *)
end;


const
    MAXN = 100000;
var
    N               : longint;
    remix, testo    : array[0..MAXN] of char;
    fr, fw          : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    readln(fr, remix);
    ripulisci(N, remix, testo);
    writeln(fw, testo);
    close(fr);
    close(fw);
end.

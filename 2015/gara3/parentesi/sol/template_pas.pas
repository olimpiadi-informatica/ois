function controlla(N: longint; var E: array of char): longint;
begin
    (* Mettete qui il codice della soluzione *)
    controlla := 0;
end;


const
    MAXN = 10000;
var
    N     : longint;
    E     : array[0..MAXN] of char;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    readln(fr, E);

    if (controlla(N, E) < 0) then
        writeln(fw, 'malformata')
    else
        writeln(fw, 'corretta');
    close(fr);
    close(fw);
end.

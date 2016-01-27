function unescape(N: longint; var S: array of char): longint;
var i: longint;
begin
    (* Mettete qui il codice della soluzione *)
    for i:=0 to N - 1 do
        S[i] := 'x';

    unescape := 42;
end;


const
    MAXN = 1000010;
var
    N, i  : longint;
    S     : array[0..MAXN-1] of char;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);

    readln(fr, N);
    for i:=0 to N - 1 do
        read(fr, S[i]);

    N := unescape(N, S);
    writeln(fw, N);

    for i:=0 to N - 1 do
        write(fw, S[i]);

    close(fr);
    close(fw);
end.

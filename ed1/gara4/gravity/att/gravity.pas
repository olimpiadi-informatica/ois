function passeggia(N: longint; var H: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    passeggia := 42;
end;


const
    MAXN = 10000;
var
    N, i  : longint;
    H     : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, H[i]);

    writeln(fw, passeggia(N, H));
    close(fr);
    close(fw);
end.

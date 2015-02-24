function trova(N, K: longint; var insieme: array of longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    trova := 42;
end;


const
    MAXN = 100000;
var
    insieme : array[0..MAXN-1] of longint;
    N, K, i : longint;
    fr, fw  : text;
begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, K);
    for i:=0 to N-1 do
        readln(fr, insieme[i]);

    writeln(fw, trova(N, K, insieme));
    close(fr);
    close(fw);
end.

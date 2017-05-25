function premi(N: longint; var B: array of longint): int64;
begin
    (* Mettete qui il codice della soluzione *)
    premi := 42;
end;


const
    MAXN = 100000;
var
    N, i  : longint;
    B     : array[0..MAXN-1] of longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, B[i]);

    writeln(fw, premi(N, B));
    close(fr);
    close(fw);
end.

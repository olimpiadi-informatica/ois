function gioca(N: longint; var M: array of integer): longint;
begin
    (* Mettete qui il codice della soluzione *)
    gioca := 42;
end;


const
    MAXN = 100000;
var
    N, i  : longint;
    M     : array[0..MAXN-1] of integer;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, M[i]);

    writeln(fw, gioca(N, M));
    close(fr);
    close(fw);
end.

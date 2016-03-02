function conta(N, K: longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    conta := 42;
end;


var
    N, K  : longint;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, K);

    writeln(fw, conta(N, K));
    close(fr);
    close(fw);
end.

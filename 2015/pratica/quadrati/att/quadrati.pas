function conta(A, B: longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    conta := 42;
end;


var
    A, B   : longint;
    fr, fw : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, A, B);

    writeln(fw, conta(A, B));
    close(fr);
    close(fw);
end.

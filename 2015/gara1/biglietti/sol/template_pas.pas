function compra(N, M, A, B: longint): longint;
begin
    (* Mettete qui il codice della soluzione *)
    compra := 42;
end;


var
    N, M, A, B, i : longint;
    fr, fw        : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M, A, B);

    writeln(fw, compra(N, M, A, B));
    close(fr);
    close(fw);
end.

function energia(K: int64): int64;
begin
    (* Mettete qui il codice della soluzione *)
    energia := 42;
end;


var
    K: int64;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, K);

    writeln(fw, energia(K));
    close(fr);
    close(fw);
end.

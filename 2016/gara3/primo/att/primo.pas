function primi(var S: string): longint;
begin
    (* Mettete qui il codice della soluzione *)
    primi := 42;
end;


var
    S : string;
    fr, fw : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, S);

    writeln(fw, primi(S));
    close(fr);
    close(fw);
end.

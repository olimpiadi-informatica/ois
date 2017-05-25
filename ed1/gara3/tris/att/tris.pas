type
    table = array [0..2,0..2] of char;

function vincente(var griglia: table): longint;
begin
    (* Mettete qui il codice della soluzione *)
    vincente := 1;
end;


var
    griglia : table;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, griglia[0,0], griglia[0,1], griglia[0,2]);
    readln(fr, griglia[1,0], griglia[1,1], griglia[1,2]);
    readln(fr, griglia[2,0], griglia[2,1], griglia[2,2]);

    writeln(fw, vincente(griglia));
    close(fr);
    close(fw);
end.

const
    MAXR = 1000;
    MAXC = 1000;
type matrix = array[0..MAXR] of array[0..MAXC] of char;

function mancanti(R, C: longint; var M: matrix): longint;
begin
    (* Mettete qui il codice della soluzione *)
    mancanti := 42;
end;


var
    R, C, i: longint;
    M: array[0..MAXR] of array[0..MAXC] of char;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, R, C);
    for i:=0 to R-1 do
        readln(fr, M[i]);

    writeln(fw, mancanti(R, C, M));
    close(fr);
    close(fw);
end.

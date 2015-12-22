const
    MAXN = 512;
type matrix = array[0..MAXN-1] of array[0..MAXN-1] of char;

function osserva(N, M: longint; var T: matrix): longint;
begin
    (* Mettete qui il codice della soluzione *)
    if T[0][0] = 'X' then osserva := -1
    else osserva := 42;
end;


var
    N, M, i : longint;
    T       : matrix;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to N-1 do
        readln(fr, T[i]);

    writeln(fw, osserva(N, M, T));
    close(fr);
    close(fw);
end.
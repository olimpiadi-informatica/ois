const
    MAXN = 512;
type matrix = array[0..MAXN-1] of array[0..MAXN-1] of char;

procedure muovi(var N, M, x, y, dir, c: longint);
begin
    dir := (dir+4) mod 4;
    if dir mod 2 = 0 then x := x + 1 - dir else y := y + dir - 2;
    x := (x+M) mod M;
    y := (y+N) mod N;
    c := c+1;
end;

function osserva(N, M: longint; var T: matrix): longint;
var x, y, dir, c: longint;
begin
    x := 0;
    y := 0;
    dir := 0;
    c := 0;
    while (T[y][x] <> 'X') and not ((x = 0) and (y = 0) and (dir = 0) and (c > 0)) do begin
        {writeln(x, ',', y, ' ~ ', T[y][x], ',', c);}
        if T[y][x] = 'L' then dir := dir + 1;
        if T[y][x] = 'R' then dir := dir - 1;
        if T[y][x] = 'O' then muovi(N, M, x, y, dir, c);
        muovi(N, M, x, y, dir, c);
    end;
    if T[y][x] = 'X' then osserva := -1
    else osserva := c;
end;


var
    N, M, i : longint;
    T       : matrix;
    fr, fw  : text;

begin
{$ifdef EVAL}
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
{$else}
    fr := input;
    fw := output;
{$endif}
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    for i:=0 to N-1 do
        readln(fr, T[i]);

    writeln(fw, osserva(N, M, T));
    close(fr);
    close(fw);
end.

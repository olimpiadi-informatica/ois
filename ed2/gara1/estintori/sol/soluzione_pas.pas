const
    MAXR = 1000;
    MAXC = 1000;
type matrix = array[0..MAXR] of array[0..MAXC] of char;

function spigolo(i, j, R, C: longint; var M: matrix): boolean;
begin
    spigolo := (M[i-1][j] = '#') and (M[i][j-1] = '#') and (M[i-1][j-1] = '#');
end;

function manca_estintore(i, j, R, C: longint; var M: matrix): longint;
var jj: longint;
begin
    manca_estintore := 0;
    while M[i][j] <> '#' do
    begin
        jj := j;
        while M[i][jj] <> '#' do
        begin
            if M[i][jj] = '@' then
                exit;
            inc(jj);
        end;
        inc(i);
    end;
    manca_estintore := 1;
end;

function mancanti(R, C: longint; var M: matrix): longint;
var i, j: longint;
begin
    mancanti := 0;
    for i:=1 to R-1 do
    begin
        for j:=1 to C-1 do
        begin
            if spigolo(i, j, R, C, M) then
                inc(mancanti, manca_estintore(i, j, R, C, M));
        end;
    end;
end;


var
    R, C, i: longint;
    M: array[0..MAXR] of array[0..MAXC] of char;
    fr, fw: text;

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
    readln(fr, R, C);
    for i:=0 to R-1 do
        readln(fr, M[i]);

    writeln(fw, mancanti(R, C, M));
    close(fr);
    close(fw);
end.

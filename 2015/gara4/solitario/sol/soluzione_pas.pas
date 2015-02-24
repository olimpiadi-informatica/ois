uses math;

var
    Grid    : array[1..16, 1..16] of boolean;
    N, M, R : longint;
    fr, fw  : text;


function check(x, y: longint) : boolean;
begin
    if (x < 0) or (y < 0) or (x >= N) or (y >= M) then check := false
    else check := Grid[x,y];
end;

procedure rec_gioca(x, y, c : longint);
var i, j : longint;
    quit : boolean;
begin
    quit := false;
    if Grid[x, y] then quit := true;
    for i:=1 downto 0 do
        for j:=1 downto 0 do
            if (i > 0) or (j > 0) then begin
                if (check(x+i, y+j) and check(x+2*i, y+2*j)) then quit := true;
                if (check(x-i, y-j) and check(x-2*i, y-2*j)) then quit := true;
                if (check(x-i, y-j) and check(x+i, y+j)) then quit := true;
            end else begin
                if (check(x+1, y-1) and check(x+2, y-2)) then quit := true;
                if (check(x-1, y+1) and check(x-2, y+2)) then quit := true;
                if (check(x-i, y+1) and check(x+1, y-1)) then quit := true;
            end;
    if not quit then begin
        Grid[x, y] := true;
        R := max(R, c);
        for j:=y+1 to M-1 do rec_gioca(x, j, c+1);
        for i:=x+1 to N-1 do
            for j:=0 to M-1 do
                rec_gioca(i, j, c+1);
        Grid[x, y] := false;
    end;
end;

function gioca(N, M: longint): longint;
var i, j : longint;
begin
    for i:=0 to N-1 do
        for j:=0 to M-1 do
            Grid[i, j] := false;
    for i:=0 to N-1 do
        for j:=0 to M-1 do
            rec_gioca(i, j, 1);
    gioca := R;
end;


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

    writeln(fw, gioca(N, M));
    close(fr);
    close(fw);
end.

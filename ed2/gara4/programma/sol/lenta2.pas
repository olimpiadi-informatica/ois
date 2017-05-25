type
	point = record
		x, y : longint;
	end;

var dx, dy: array[0..3] of longint;

function passeggia(N, M: longint; var P: array of char; var S, E: array of longint): point;
var orienta, i, j: longint;
begin
    passeggia.x := 0;
    passeggia.y := 0;
    orienta := 0;

    dx[0] := 1;  dy[0] := 0;
    dx[1] := 0;  dy[1] := 1;
    dx[2] := -1; dy[2] := 0;
    dx[3] := 0;  dy[3] := -1;

    for i:=0 to M-1 do
	for j:=S[i] to E[i] do
	begin
	    if P[j] = 'R' then
		orienta := (orienta + 3) mod 4
	    else if P[j] = 'L' then
		orienta := (orienta + 1) mod 4
	    else if P[j] = 'F' then
	    begin
		inc(passeggia.x, dx[orienta]);
		inc(passeggia.y, dy[orienta]);
	    end
	    else if P[j] = 'B' then
	    begin
		dec(passeggia.x, dx[orienta]);
		dec(passeggia.y, dy[orienta]);
	    end
	    else
		exit;
	end;
end;

const
    MAXN = 1000000;
    MAXM = 100000;
var
    N, M, i : longint;
    P       : array[0..MAXN+1] of char;
    S, E    : array[0..MAXM-1] of longint;
    res     : point;
    fr, fw  : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, M);
    readln(fr, P);
    for i:=0 to M-1 do
        readln(fr, S[i], E[i]);

    res := passeggia(N, M, P, S, E);
    writeln(fw, res.x, ' ', res.y);
    close(fr);
    close(fw);
end.

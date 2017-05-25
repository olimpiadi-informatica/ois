type
	point = record
		x, y : longint;
	end;

function passeggia(N, M: longint; var P: array of char; var S, E: array of longint): point;
var i, j, dir : longint;
begin
    with passeggia do begin
        x := 0;
        y := 0;
        dir := 0;
        for i:=0 to M-1 do begin
            for j:=S[i] to E[i] do begin
                if P[j] = 'X' then break;
                if P[j] = 'L' then dir := (dir+1) mod 4;
                if P[j] = 'R' then dir := (dir+3) mod 4;
                if P[j] = 'F' then begin
                    if (dir mod 2) = 0 then x := x + 1 - dir
                    else y := y + 2 - dir;
                end;
                if P[j] = 'B' then begin
                    if (dir mod 2) = 0 then x := x - 1 + dir
                    else y := y - 2 + dir;
                end;
            end;
            if P[j] = 'X' then break;
        end;
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
    readln(fr, P);
    for i:=0 to M-1 do
        readln(fr, S[i], E[i]);

    res := passeggia(N, M, P, S, E);
    writeln(fw, res.x, ' ', res.y);
    close(fr);
    close(fw);
end.

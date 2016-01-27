type
	point = record
		x, y : longint;
	end;

function passeggia(N, M: longint; var P: array of char; var S, E: array of longint): point;
begin
    (* Mettete qui il codice della soluzione *)
    passeggia.x := 42;
    passeggia.y := 42;
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

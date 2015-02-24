uses math;

const
    MAXN = 5000;
    MAXK = 5000;
    MAXP = 1000000;
var
    N, K, i : longint;
    P       : array[0..MAXN-1] of longint;
    U       : array[0..MAXK-1] of longint;
    fr, fw  : text;


function mangia(N, K: longint; var P: array of longint): longint;
var i, j : longint;
begin
    mangia := MAXP;
    U[0] := 1;
    for i:=0 to N-1 do for j:=MAXK-1 downto 0 do if (U[j] = 1) then begin
        if (j+P[i] >= K) then mangia := min(mangia, j+P[i])
        else U[j+P[i]] := 1;
    end;
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
    readln(fr, N, K);
    for i:=0 to N-1 do
        read(fr, P[i]);

    writeln(fw, mangia(N, K, P));
    close(fr);
    close(fw);
end.

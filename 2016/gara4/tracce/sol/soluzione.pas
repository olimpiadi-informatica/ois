var D, P: array[0..1000000] of int64;

function conteggio(K: longint; var S: ansistring): longint;
var L, i: longint;
begin
    L := length(S);
    P[L-1] := 1;
    for i:=0 to L do D[i] := 0;
    for i:=L to K do begin
        P[i] := (10*P[i-1]) mod 1000000007;
        D[i] := (10*D[i-1] + P[i-1] - D[i-L] + 1000000007) mod 1000000007;
    end;
    conteggio := D[K];
end;


var
    N : longint;
    S : ansistring;
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
    readln(fr, N);
    readln(fr, S);

    writeln(fw, conteggio(N, S));
    close(fr);
    close(fw);
end.

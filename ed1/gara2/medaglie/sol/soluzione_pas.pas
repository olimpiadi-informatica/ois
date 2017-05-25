const
    MAXN = 100000;
var
    N, i  : longint;
    M     : array[0..MAXN-1] of integer;
    Win   : array[0..MAXN, 0..1] of longint;
    Value : array[0..2] of integer;
    fr, fw: text;


function gioca(N: longint; var M: array of integer): longint;
var move, val, t, i, j: longint;
begin
    Value[0] := 100;
    Value[1] := 300;
    Value[2] := 500;
    Win[0, 0] := 0;
    Win[0, 1] := 0;
    for i:=1 to N do begin
        move := 0;
        val := 0;
        t := 0;
        for j:=1 to 3 do begin
            if j > i then break;
            t := t + Value[M[i-j]];
            if (Win[i-j, 1] + t > Win[i-move, 1] + val) then begin
                move := j;
                val := t;
            end;
            Win[i, 0] := Win[i-move, 1] + val;
            Win[i, 1] := Win[i-move, 0];
        end;
    end;
    gioca := Win[N][0];
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
    readln(fr, N);
    for i:=0 to N-1 do
        read(fr, M[i]);

    writeln(fw, gioca(N, M));
    close(fr);
    close(fw);
end.

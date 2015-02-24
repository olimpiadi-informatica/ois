uses math;

function gira(N: longint; var descrizione: array of char): longint;
var i, cm, cp : longint;
begin
    cm := 0;
    cp := 0;
    for i:=0 to (N div 4)-1 do begin
        if descrizione[4*i+1] = '-' then inc(cm)
        else inc(cp);
    end;
    gira := min(cm, cp);
end;


const
    MAXN = 100000;
var
    N           : longint;
    descrizione : array[0..MAXN] of char;
    fr, fw      : text;

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
    readln(fr, descrizione);

    writeln(fw, gira(N, descrizione));
    close(fr);
    close(fw);
end.

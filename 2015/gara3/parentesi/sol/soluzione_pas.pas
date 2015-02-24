uses math;

function open(c: char): longint;
begin
    if (c = '<') or (c = '(') or (c = '[') or (c = '{') then open := 1
    else open := 0;
end;

function match(c, d: char) : longint;
begin
    match := 0;
    if (c = '<') and (d = '>') then match := 1;
    if (c = '(') and (d = ')') then match := 1;
    if (c = '[') and (d = ']') then match := 1;
    if (c = '{') and (d = '}') then match := 1;
end;


function controlla(N: longint; var E: array of char): longint;
var i, ns, ok: longint;
begin
    ok := 1;
    ns := 0;
    for i:=0 to N-1 do begin
        if (ns > 0) and (match(E[ns-1], E[i]) > 0) then dec(ns)
        else if (open(E[i]) > 0) then begin
            E[ns] := E[i];
            inc(ns);
        end else begin
            ok := 0;
            break;
        end;
    end;
    if (ok = 1) and (ns = 0) then controlla := 0
    else controlla := -1;
end;


const
    MAXN = 100000;
var
    N     : longint;
    E     : array[0..MAXN] of char;
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
    readln(fr, E);

    if (controlla(N, E) < 0) then
        writeln(fw, 'malformata')
    else
        writeln(fw, 'corretta');
    close(fr);
    close(fw);
end.

procedure aggiusta(N: longint; var s: array of char);
var i: longint;
begin
    for i:=0 to N-1 do
        if s[i] = upcase(s[i]) then
            s[i] := lowercase(s[i])
        else
            s[i] := upcase(s[i]);
end;

const
    MAXN = 10000;
var
    N  : longint;
    s  : array[0..MAXN] of char;
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
    readln(fr, s);
    aggiusta(N, s);
    writeln(fw, s);
    close(fr);
    close(fw);
end.

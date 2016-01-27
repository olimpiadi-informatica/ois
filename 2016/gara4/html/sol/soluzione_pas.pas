function unescape(N: longint; var S: array of char): longint;
var i, j: longint;
begin
    i := 0;
    j := 0;
    while i<N do begin
        S[j] := S[i];
        i := i+1;
        j := j+1;
        if (S[i-1] = '&') then
            while ((i+3)<N) and (S[i] = 'a') and (S[i+1] = 'm') and (S[i+2] = 'p') and (S[i+3] = ';') do i := i+4;
    end;
    unescape := j;
end;


const
    MAXN = 1000010;
var
    N, i  : longint;
    S     : array[0..MAXN-1] of char;
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
    for i:=0 to N - 1 do
        read(fr, S[i]);

    N := unescape(N, S);
    writeln(fw, N);

    for i:=0 to N - 1 do
        write(fw, S[i]);

    close(fr);
    close(fw);
end.

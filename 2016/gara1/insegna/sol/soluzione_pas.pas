function confronta(N: longint; var G, W: array of char): longint;
var i, j: longint;
    ok: boolean;
begin
    confronta := 0;
    for i:=0 to N-1 do
    begin
        ok := true;
        for j:=0 to N-1 do
        begin
            if G[j] <> W[(i + j) mod N] then
            begin
                ok := false;
                break;
            end;
        end;
        if ok then
        begin
            confronta := 1;
            break;
        end;
    end;
end;


const
    MAXN = 5000;
var
    N: longint;
    G, W: array[0..MAXN] of char;
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
    readln(fr, G);
    readln(fr, W);

    writeln(fw, confronta(N, G, W));
    close(fr);
    close(fw);
end.

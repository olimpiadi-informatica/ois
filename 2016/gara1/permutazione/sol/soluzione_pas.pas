procedure permuta(K: longint; var P: array of char);
var i, dir, left, right: longint;
begin
    dir := -1;
    left := 0;
    right := 0;

    i:=0;
    while i < 26 do
    begin
        if K > 0 then
        begin
            if i mod 2 = 0 then
            begin
                P[i] := chr(ord('A') + left);
                inc(left);
            end else
            begin
                P[i] := chr(ord('Z') - right);
                inc(right);
            end;
            dec(K);
        end else if dir = 0 then
        begin
            P[i] := chr(ord('A') + left);
            inc(left);
        end else if dir = 1 then
        begin
            P[i] := chr(ord('Z') - right);
            inc(right);
        end else
        begin
            if i mod 2 = 0 then dir := 1 else dir := 0;
            dec(i);
        end;
        inc(i);
    end;
end;


var
    K: longint;
    P: array[0..25] of char;
    fr, fw: text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, K);

    permuta(K, P);

    writeln(fw, P);
    close(fr);
    close(fw);
end.

uses math;

(* FUNZIONI PRESE DAL WEB *)

procedure BubbleSort(var numbers : Array of longint; size : longint);
var i, j, temp : longint;
begin
 For i := size-1 DownTo 1 do
  For j := 1 to i do
   If (numbers[j-1] > numbers[j]) then
    Begin
     temp := numbers[j-1];
     numbers[j-1] := numbers[j];
     numbers[j] := temp;
    End;
end;

(* FINE FUNZIONI PRESE DAL WEB *)


function interroga(N, K: longint; var D: array of longint): longint;
var i: longint;
begin
    BubbleSort(D, N);
    interroga := D[N-1] - D[0];
    for i:=0 to N-K do
        interroga := min(interroga, D[i+K-1] - D[i]);
end;


const
    MAXN = 10000;
var
    N, K, i : longint;
    D       : array[0..MAXN-1] of longint;
    fr, fw  : text;

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
        read(fr, D[i]);

    writeln(fw, interroga(N, K, D));
    close(fr);
    close(fw);
end.

uses math;

(* FUNZIONI PRESE DAL WEB *)

Procedure QSort(var numbers : Array of longint;
                left : longint; right : longint);
Var pivot, l_ptr, r_ptr : longint;
Begin
 l_ptr := left;
 r_ptr := right;
 pivot := numbers[left];
 While (left < right) do
  Begin
   While ((numbers[right] >= pivot) AND (left < right)) do
    right := right - 1;
   If (left <> right) then
    Begin
     numbers[left] := numbers[right];
     left := left + 1;
    End;
   While ((numbers[left] <= pivot) AND (left < right)) do
    left := left + 1;
   If (left <> right) then
    Begin
     numbers[right] := numbers[left];
     right := right - 1;
    End;
  End;
 numbers[left] := pivot;
 pivot := left;
 left := l_ptr;
 right := r_ptr;
 If (left < pivot) then
  QSort(numbers, left, pivot-1);
 If (right > pivot) then
  QSort(numbers, pivot+1, right);
End;

Procedure QuickSort(var numbers : Array of longint; size : longint);
Begin
 QSort(numbers, 0, size-1);
End;

(* FINE FUNZIONI PRESE DAL WEB *)


function interroga(N, K: longint; var D: array of longint): longint;
var i: longint;
begin
    QuickSort(D, N);
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

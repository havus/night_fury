
### Naming in C
https://stackoverflow.com/questions/1722112/what-are-the-most-common-naming-conventions-in-c

### How to play around
gcc -o printer learn_function.c && ./printer && rm ./printer


https://www.youtube.com/watch?v=KJgsSFOSQv0


https://lmsspada.kemdikbud.go.id/course/view.php?id=3547

note: p -> q === !p || q

(p -> q) ∧ (q -> r) ∧ ~(p -> r)
ada 3 pernyataan tunggal pqr, sehingga table kebenaran 2 pangkat 3 = 8

p | q | r | ~p | ~r | (p -> q) | (q -> r) | (p -> r) | ~(p -> r) | (p -> q) ∧ (q -> r) ∧ ~(p -> r)
b | b | b | s  | s  | b        | b        | b        | s         | s
b | b | s | s  | b  | b        | s        | s        | s         | s
b | s | b | s  | s  | s        | b        | b        | b         | s
b | s | s | s  | b  | s        | b        | s        | b         | s
s | b | b | b  | s  | b        | b        | b        | s         | s
s | b | s | b  | b  | b        | s        | b        | s         | s
s | s | b | b  | s  | b        | b        | b        | s         | s
s | s | s | b  | b  | b        | b        | b        | s         | s

Tautologi adalah yg bernilai benar semua
Kontradiksi adalah yg bernilai salah semua
Kontingensi adalah yg tidak selalu bernilai benar atau salah
(p -> q) ∧ (q -> r) ∧ ~(p -> r) adalah kontradiksi



# Codeforces Round #770 (Div. 2) 

3/6

### D
[D. Finding Zero](https://codeforces.com/contest/1634/problem/D)
It's an interactive problem so it's hard to debug. 
**My Solution** Fix a1, a2 and rotate a3 from an to an first,(assuming the array is a1..an, and every query be lke "? a1 a2 ai"). During the query(n - 2 times), record the largest return value's ai as b1, then fix a1, b1 and rotate the third index from a3 to an(n - 3 times). Record the largest return value as the first turn as b2. Then the guess should be "! b1 b2".
b1, b2 should be either 0 or the maximum among the array.
Unfortunately, a1 can also be the answer. We have to think about the possibility in b1, b2, a1. So we should use the last 3 times at here -- query (b1,b2,ax),(b1,ax,a1),(ax,b2,a1) and get the answer.
-> This solution can pass at O(n)

**Official Solution**
Solve the problem for n. For n=4, notice that for any four numbers a,b,c,d we can locate at least two numbers among them that are certainly not zeroes using only four queries.
(the numbers with the two largest(same) complements will always be guaranteed non-zeroes, or not the minimum.)
Start with a "pile" of the first four numbers, apply the algorithm and throw two certain non-zeroes away. Add the next two numbers to the "pile" and drop two non-zeroes again. Repeat this until there are two or three numbers left in the "pile", depending on the parity of 𝑛. If there are three elements left, add some number that we have already dropped to the pile again and apply the algorithm the last time.
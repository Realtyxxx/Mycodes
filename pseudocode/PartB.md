# Part B: The knapsack problem [36 marks]

1. ```pseudocode
Greedy(S,s,v)
	Let vPerVolume[1..n] and R[1..n] be new float arrays
	for i <- 1 to n
		vPerVolume[i] <- v[i] / s[i]
		R[i] <- 0
	whiles S > 0
	  j <- 0
		for i <- 1 to n
			if vPerVolume[i] > vPerVolume[j] and R[i] = 0
				j <- i
		if S > vPerVolume[j]
			S <- S - s[j]
			R[j] <- 1
			else R[j] = S / vPerVolume[j]
				S <- 0
	return R
	```

2. Worst-case Analysis:

  - Line 4, 5 needs about $3 * n$ runtimes which includes  $2 * n$ times assignment and $1 * n$ times divison.(judgement-statement takes $1$ time and division-statement take $1$ time per operation) 

  - As to the line 6, because it could have many cases about the value of S. It could be a large number that we could fill all of the goods or a small number that we may not be able to take anything. And in our worst-case analysis, if the knapsack has infinite capacity which means it could finally take all goods, at that addition,I think the outer loop can be performed at most $n$ times.

- line 7 takes $1$ time per loop.

- In line 8 we create a inner loop, which performs $n$ times.

- Line 9 and 10 could perform no more than $3$ times per loop, so in the inner loop 8-10, it could takes about $3 * n$ times computation.

- From line 11 to line 14,it takes $4$ times either in after-if statement or in after-else statement.
  
- so we needs about :$O(3*n+n*(1+3*n+4))=O(3n^2+5n)$
  
  **So we needs $O(n^2)$**  

3. My answer aims to find the best combination that could get as much value as possible with the limited volume of the knapsack, Here we should consider concept most that names valuable-per-volume . We take as more as possible the most valuable-per-volume goods at every time, if we could take that item all, we take it all, or we will take enough parts of that item to fill the rest volume of knapsack.

  - 1<sup>st</sup> step:
    - we take the most valuable-per-volume item $j$ from the all goods, and the knapsack remains $S-s[j]$ ($S > s[j]$).
  - the i<sup>th</sup> step(from 2<sup>nd</sup> to n-1<sup>th</sup> step:
    - we should take a item from the $n-i$ goods, and we should take the most-valuable-per-volume item form the remaining goods except the item we have picked.
  - Final step(when the most valuable-per-volume item has the volume that  bigger or equal to the remaining volume of knapsack):
    - if the most valuable-per-volume item from the remaining goods has the same volume as the remaining volume of knapsack, then take the whole item, else take a part of that item to fill the the knapsack.

4. - **value-per-unit-volume:**![截屏2021-02-01 下午6.14.09](/Users/realtyxxx_mac/Desktop/截屏2021-02-01 下午6.14.09.png)
- **"plain value":**![截屏2021-02-01 下午6.14.16](/Users/realtyxxx_mac/Desktop/截屏2021-02-01 下午6.14.16.png)
5. ```pseudocode
Dynamic(S, s, v)
	Let m[1..n + 1][1..S + 1] be the 2 dimensional array
	Let r[1..n + 1] be the 1 dimensional array
	for w = 1 to S + 1
		m[1][w] = 0
	for i = 1 to n + 1 
		m[i][1] = 0
	for i = 2 to n + 1
		for w = 2 to S + 1
			if s[i] > S
				m[i][w] = m[i - 1][w]
			else
				m[i][w] = max{m[i - 1][w], v[i] + m[i - 1][w - s[i]]}
	return m[n + 1][S + 1]
	```
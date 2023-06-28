from random import randint

n = 10**5
k = randint(1, 10**9)
print(n, k)
print(*[randint(1, 10**4) for _  in range(n)])

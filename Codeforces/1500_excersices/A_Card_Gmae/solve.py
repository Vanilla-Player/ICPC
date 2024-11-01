def fact(n):
    return 1 if n == 0 else n * fact(n - 1)

def choose(n, k):
    return fact(n) // fact(k) // fact(n - k)

def calc(n):
    
    if n == 2:
        return [1, 0, 1]
    else:
        a = calc(n - 2)
        print("For ${n}",n)
        print(n-1)
        print(n//2)
        print(choose(n - 1, n // 2))
        return [choose(n - 1, n // 2) + a[1], choose(n - 2, n // 2) + a[0], 1]

t = int(input())
for i in range(t):
    mod = 998244353
    n = int(input())
    a = calc(n)
    a = list(map(lambda x: x % mod, a))
    print(*a)
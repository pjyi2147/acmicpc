n = int(input())

for i in range(n):
    s = " "*i+"*"*(2*(n-i)-1)
    print(s)

k = n-2
while (k >= 0):
    s = " "*k+"*"*(2*(n-k)-1)
    print(s)
    k -= 1
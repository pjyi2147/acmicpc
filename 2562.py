m = 0 
index = 0
for i in  range(9):
    k = int(input())
    if (k > m):
        index = i+1
        m = k
print(m)
print(index)

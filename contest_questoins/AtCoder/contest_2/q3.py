res = ""
k = int(input())
m = int(input())
for i in range(k):
    c = input()
    l = int(input())
    res = res + (c) * l
print(res)
n = int(res)
print((n // m) % 10007)

import sys

def input():
    return sys.stdin.readline().strip()

n = int(input())
d = dict()

for i in range(n):
    a = list(map(int, input().split()))
    
    if a[0]==1:
        d[a[2]] = a[1]
    else:
        print(d[a[1]])
        
import sys

n=int(sys.stdin.readline().rstrip())
m=int(sys.stdin.readline().rstrip())

cmt={i:i for i in range(1,n+1)}

count=0

def findparent(x):
    if cmt[x]==x:
        return x
    else:
        return findparent(cmt[x])

def union(x,y):
    x=findparent(x)
    y=findparent(y)
    if x!=y:
        cmt[y]=x

order=[]

for i in range(m):
    a,b,c=map(int,sys.stdin.readline().rstrip().split())
    if a==b:
        continue
    order.append((c,a,b))

order.sort(key=lambda x:x[0])

for c,a,b in order:
    if findparent(a)==findparent(b):
        continue
    else:
        union(a,b)
        count+=c

print(count)
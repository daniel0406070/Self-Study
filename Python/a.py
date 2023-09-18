import sys
input=sys.stdin.readline
cin=lambda:map(int, input().split())
p1=998244353
p2=2281701377
i, ii=253522377, -110916040#p1-1, p2-1
def pwowp(q, k, md):
    rs=1
    while k:
        if k&1:
            rs=rs*q%md
        q=q*q%md
        k>>=1
    return rs%md

def ntt(a, p, inv=False):
    n=len(a)
    j=0
    for i in range(1, n):
        bit=n>>1
        while j>=bit:
            j-=bit
            bit>>=1
        j+=bit
        if i<j:
            a[i], a[j]=a[j], a[i]
    s=2
    while s<=n:
        h=s//2
        u=pwowp(3, p//s, p)
        if inv:
            u=pwowp(u, p-2, p)
        for i in range(0, n, s):
            wp=1
            for j in range(i, i+h):
                v=a[j+h]*wp
                a[j+h]=(a[j]-v)%p
                a[j]=(a[j]+v)%p
                wp=wp*u%p
        s+=s
    if inv:
        ivsn=p-(p-1)//n
        for i in range(n):
            a[i]=(a[i]*ivsn)%p

def mul(vec1, vec2, p):
    l1, l2=len(vec1), len(vec2)
    n=1
    while n<l1+l2:
        n+=n
    n+=n
    vec1+=[0]*(n-l1)
    vec2+=[0]*(n-l2)
    vec3=[0 for _ in range(n)]
    ntt(vec1, p)
    ntt(vec2, p)
    for i in range(n):
        vec3[i]=vec1[i]*vec2[i]
    ntt(vec3, p, True)
    return vec3[:l1+l2-1]
def crt(x, y):
    return (x*p2*ii+y*p1*i)%(p1*p2)

n, m=cin()
f=list(cin())
g=list(cin())

rs, st=mul(f, g, p1), mul(f, g, p2)

ans=0
for r, rr in zip(rs, st):
    ans^=crt(r, rr)
print(ans)
import sys

n=int(sys.stdin.readline())

members={}
ac=0
wa=0


for i in range(n):
    _,a,b,_,_,_,_=sys.stdin.readline().split(" ")
    b=int(b)

    if a=='megalusion':
        continue

    if a not in members.keys():
        if b==4:
            ac+=1
            members[a]=-1
        else:
            members[a]=1

    else:
        if members[a]==-1:
            continue

        if b==4:
            ac+=1
            wa+=members[a]
            members[a]=-1
            
        else:
            members[a]+=1

if(ac==0 and wa==0):
    print(0)
else:
    print(ac/(ac+wa)*100)
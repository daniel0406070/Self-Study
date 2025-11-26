import sys
from collections import deque
m,n=map(int,sys.stdin.readline().split())


field=[]
for i in range(n):
    field.append(list(map(int,sys.stdin.readline().split())))

tmt=[]
for i in range(n):
    for j in range(m):
        if field[i][j]==1:
            tmt.append((i,j))

def bfs(tmt):
        queue=deque(tmt)
        while queue:
                x=queue.popleft()
                for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                    nx=x[0]+dx
                    ny=x[1]+dy
                    if nx>=0 and nx<n and ny>=0 and ny<m:
                        if field[nx][ny]==0:
                            field[nx][ny]=1+field[x[0]][x[1]]
                            queue.append((nx,ny))
        for i in field:
            if 0 in i:
                return -1
        return max(map(max,field))-1


print(bfs(tmt))
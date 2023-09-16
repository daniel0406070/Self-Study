
k=1

def aa():
    global k
    a=[1,2,3,4]
    a.append(k)
    k+=1
    return a


for i in aa():
    print(i)
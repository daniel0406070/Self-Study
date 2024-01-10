import sys

input = sys.stdin.readline

while 1:
    a, b = map(int, input().strip().split())
    cpya, cpyb = a, b
    if a == 0 and b == 0:
        break

    listA = [a]
    while a != 1:
        if a % 2 == 0:
            a /= 2
            listA.append(a)
        else:
            a = 3 * a + 1
            listA.append(a)

    listB = [b]
    if b in listA:
        print(f'{cpya} needs {len(listA)} steps, {cpyb} needs {len(listA)-listA.index(b)}, they meet at {b}')
    else:
        while b != 1:
            if b % 2 == 0:
                b //= 2
                listB.append(b)
                if b in listA:
                    print(f'{cpya} needs {listA.index(b)} steps, {cpyb} needs {listB.index(b)}, they meet at {b}')
                    break
            else:
                b = 3 * b + 1
                listB.append(b)
                if b in listA:
                    print(f'{cpya} needs {listA.index(b)} steps, {cpyb} needs {listB.index(b)}, they meet at {b}')
                    break
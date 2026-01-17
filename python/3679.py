import matplotlib.pyplot as plt
import os
import random
import time

random.seed(time.time())
flag=True
t=400
testcases = []
inputpoints = []
# with open('/home/daniel/code_space/test_case/input.txt', 'r') as f:
#     # 읽기
#     lines = f.readlines()
#     t = int(lines[0].strip())
#     for line in lines[1:]:
#         inputpoints = []
#         parts = list(map(int, line.strip().split()))
#         n = parts[0]
#         for i in range(n):
#             inputpoints.append((parts[2*i+1], parts[2*i+2]))
#         testcases.append(inputpoints)

with open('/home/daniel/code_space/test_case/input.txt', 'w') as f:
    # 초기화
    # x -10000<= x <= 10000
    # y -10000<= y <= 10000
    f.write(f"{t}\n") # 테스트 케이스 수
    for _ in range(t):
        n=random.randint(3, 400)
        f.write(str(n) + " ") # 점의 개수
        for i in range(n):
            inputpoints.append((random.randint(-100, 100), random.randint(-100, 100)))
            while inputpoints[-1] in inputpoints[:-1]:
                inputpoints.pop()
                inputpoints.append((random.randint(-100, 100), random.randint(-100, 100)))
        for i in range(n):
            p = inputpoints[i]
            f.write(f"{p[0]} {p[1]}")
            # if i != n - 1:
            f.write(" ")
        f.write("\n")
        testcases.append(inputpoints)
        inputpoints = []

c="/home/daniel/code_space/Self-Study/C/solved/3679"
os.system(f"gcc {c}.c -o {c} -lm && {c} < /home/daniel/code_space/test_case/input.txt > /home/daniel/code_space/test_case/output.txt")

graphs = []
with open('/home/daniel/code_space/test_case/output.txt', 'r') as f:
    lines = f.readlines()

idx=0
inputpoints = []
for line in lines:
    graphs.append([])
    inputpoints = testcases[idx]
    idx+=1
    # print(f"Test case {idx} with {len(inputpoints)} points", flush=True)
    for index in map(int, line.strip().split()):
        graphs[-1].append((index, inputpoints[index][0], inputpoints[index][1]))


    # #points 순서대로 점 연결

    # for points in graphs:
    #     # indexes = [p[0] for p in points]
    #     x_coords = [p[1] for p in points]
    #     y_coords = [p[2] for p in points]
    #     plt.plot(x_coords + [x_coords[0]], y_coords + [y_coords[0]], marker=',', linewidth=1)


    #     # for i, txt in enumerate(indexes):
    #     #     plt.annotate(txt, (x_coords[i], y_coords[i]), textcoords="offset points", xytext=(0,10), ha='center')
    #     plt.title('Polygon from Points')
    #     plt.xlabel('X-axis')
    #     plt.ylabel('Y-axis')
    #     plt.grid()
    #     #화질 높이기
    #     plt.savefig(f'python/3679_{time.time()}.png', dpi=1000)
    #     plt.show()

    # 검증 코드
    # 평면 위의 점의 집합이 주어졌을 때, 다각형을 만드는 프로그램을 작성하시오. 집합의 모든 점은 다각형의 꼭짓점이어야 하고, 집합에 없는 점을 다각형의 꼭짓점으로 가질 수 없다. 다각형의 두 선분은 연속하는 두 선분의 교점을 제외하고는 교차할 수 없다.

def ccw(a, b, c):
    return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])
def on_segment(a, b, c):
    return min(a[0], b[0]) <= c[0] <= max(a[0], b[0]) and min(a[1], b[1]) <= c[1] <= max(a[1], b[1])
def is_simple_polygon(points):
    n = len(points)
    for i in range(n):
        for j in range(i + 2, n):
            if (i == 0 and j == n - 1):
                continue
            a1 = points[i]
            a2 = points[(i + 1) % n]
            b1 = points[j]
            b2 = points[(j + 1) % n]

            d1 = ccw(a1, a2, b1)
            d2 = ccw(a1, a2, b2)
            d3 = ccw(b1, b2, a1)
            d4 = ccw(b1, b2, a2)

            if d1 * d2 < 0 and d3 * d4 < 0:
                print(f"Edges ({a1}, {a2}) and ({b1}, {b2}) intersect.")
                return False
            
            # 일직선 상에 있다면 겹치는지 확인
            if d1 == 0 and on_segment(a1, a2, b1):
                print(f"Edges ({a1}, {a2}) and ({b1}, {b2}) overlap.")
                return False
            if d2 == 0 and on_segment(a1, a2, b2):
                print(f"Edges ({a1}, {a2}) and ({b1}, {b2}) overlap.")
                return False
            if d3 == 0 and on_segment(b1, b2, a1):
                print(f"Edges ({a1}, {a2}) and ({b1}, {b2}) overlap.")
                return False
            if d4 == 0 and on_segment(b1, b2, a2):
                print(f"Edges ({a1}, {a2}) and ({b1}, {b2}) overlap.")
                return False
    return True

for points in graphs:
    coords = [(p[1], p[2]) for p in points]
    if not is_simple_polygon(coords):
        flag=False
        # print(len(points))
        # for p in points:
        #     print(f"{p[1]} {p[2]} ", end="")
        # print()
        break
    else:
        print("Valid polygon")
        
if flag:
    print("OK")
else:
    print("Wrong Answer")
            
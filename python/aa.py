import numpy as np
import matplotlib.pyplot as plt

#%matplotlib inline

# 멘델브로트 집합을 그리기 위한 함수
def mandelbrot_set(xmin, xmax, ymin, ymax, xn, yn, maxiter, horizon=2.0):
    # x, y 값 범위 설정
    x = np.linspace(xmin, xmax, xn, dtype=np.float32)
    y = np.linspace(ymin, ymax, yn, dtype=np.float32)
    # x, y 값으로 복소수 그리드 생성
    c = x + y[:, None]*1j
    # z 값 초기화
    z = c
    # 반복 횟수 초기화
    fractal = np.zeros(z.shape, dtype=np.int32)
    # 멘델브로트 집합 계산
    for i in range(maxiter):
        z = z**2 + c
        # 절대값이 horizon보다 큰 경우 멘델브로트 집합이 아님
        mask = (np.abs(z) > horizon) & (fractal == 0)
        fractal[mask] = i
        z[mask] = np.nan
    return fractal

# 멘델브로트 집합 그리기
xmin, xmax, xn = -2, 1, 1000
ymin, ymax, yn = -1.5, 1.5, 1000
maxiter = 1000
horizon = 2.0
fractal = mandelbrot_set(xmin, xmax, ymin, ymax, xn, yn, maxiter, horizon)
plt.imshow(fractal.T, cmap='hot', extent=[xmin, xmax, ymin, ymax])

# 확대 기능 추가
def onclick(event):
    global xmin, xmax, ymin, ymax
    if event.button == 1:
        # 좌클릭: 확대
        x_center, y_center = event.xdata, event.ydata
        x_range = xmax - xmin
        y_range = ymax - ymin
        xmin = x_center - x_range/4
        xmax = x_center + x_range/4
        ymin = y_center - y_range/4
        ymax = y_center + y_range/4
        fractal = mandelbrot_set(xmin, xmax, ymin, ymax, xn, yn, maxiter, horizon)
        plt.imshow(fractal.T, cmap='hot', extent=[xmin, xmax, ymin, ymax])
        plt.draw()
    elif event.button == 3:
        # 우클릭: 축소
        x_center, y_center = event.xdata, event.ydata
        x_range = xmax - xmin
        y_range = ymax - ymin
        xmin = x_center - x_range
        xmax = x_center + x_range
        ymin = y_center - y_range
        ymax = y_center + y_range
        fractal = mandelbrot_set(xmin, xmax, ymin, ymax, xn, yn, maxiter, horizon)
        plt.imshow(fractal.T, cmap='hot', extent=[xmin, xmax, ymin, ymax])
        plt.draw()

cid = plt.gcf().canvas.mpl_connect('button_press_event', onclick)
plt.show()
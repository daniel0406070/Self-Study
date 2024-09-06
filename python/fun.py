import numpy as np
import math
import matplotlib.pyplot as plt

def Q_rsqrt(number):
    threehalfs = 1.5
    x2 = number * 0.5
    y = number
    i = y.view('i')
    i = 0x5f3759df - (i >> 1)
    y = i.view('f')
    y = y * (threehalfs - (x2 * y * y))
    return y

def plot():
    x = np.linspace(0.1, 10, 100)
    y = [Q_rsqrt(i) for i in x]
    plt.plot(x, y)
    plt.show()

if __name__ == '__main__':
    plot()


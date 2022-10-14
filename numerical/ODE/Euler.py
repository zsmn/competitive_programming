# Método de Euler
# O método de Euler é um método numérico para resolver equações diferenciais ordinárias (EDO).
# dy/dt = f(y,t) no intervalo [a,b] e y(a) = y0

import numpy as np
import matplotlib.pyplot as plt

def f(y,t):
    return (y + t)

def Euler(f, y0, a, b, n):
    h = (b-a)/n
    y = np.zeros(n+1)
    y[0] = y0
    for i in range(n):
        y[i+1] = y[i] + h*f(y[i], a + i*h)
    return y

def show(y,t):
    fig, ax = plt.subplots()
    ax.plot(t, y, label='y(t)')
    ax.spines['left'].set_position('zero')
    ax.spines['right'].set_color('none')
    ax.spines['bottom'].set_position('zero')
    ax.spines['top'].set_color('none')
    ax.xaxis.set_ticks_position('bottom')
    ax.yaxis.set_ticks_position('left')
    ax.set_title('y(t)')
    ax.legend()
    plt.grid()
    plt.show()

def main():
    a = 0
    b = 3
    n = 1000
    y0 = 1
    t = np.linspace(a, b, n+1)
    y = Euler(f, y0, a, b, n)
    show(y,t)

if __name__ == '__main__':
    main()
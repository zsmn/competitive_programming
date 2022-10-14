# Método das Diferenças Finitas
# O método das diferenças finitas é um método numérico para resolver equações diferenciais parciais (EDP).
# -u''(x) = f(x) em [a,b] com u(a) = u(b) = K 

import matplotlib.pyplot as plt
import numpy as np
import math

def f(x):
    return np.log(x) * np.sin(x)

def FiniteDiff(f, n = 1000, a = 0, b = 1, K = 0):
    h =  (b - a) / (n + 1)
    x = np.linspace(a + h, b - h, n)
    F = f(x) * h**2
    F[0] += K
    F[-1] += K 
    A = np.diag(v = 2 * np.ones(n), k = 0) + np.diag(v = -np.ones(n - 1), k = 1) + np.diag(v = -np.ones(n - 1), k = -1)

    u = np.linalg.solve(A, F)
    u = np.append(K, u)
    u = np.append(u, K)
    x = np.append(a, x)
    x = np.append(x, b)
    
    return x, u

def show(x,u):
    fig, ax = plt.subplots()
    ax.plot(x, u, label='u(x)')
    ax.spines['left'].set_position('zero')
    ax.spines['right'].set_color('none')
    ax.spines['bottom'].set_position('zero')
    ax.spines['top'].set_color('none')
    ax.xaxis.set_ticks_position('bottom')
    ax.yaxis.set_ticks_position('left')
    ax.set_title('u(x)')
    ax.legend()
    plt.grid()
    plt.show()

def main():
    a = 0
    b = 1
    K = 0
    n = 1000
    x, u = FiniteDiff(f, n, a, b, K)
    show(x,u)


if __name__ == '__main__':
    main()
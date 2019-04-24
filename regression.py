import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
import math
import random
from scipy import stats

def log_array(arr):
    return np.array([math.log(e, 10) for e in arr])

def get_regression_line_coefficients(x, y):
    return np.polyfit(log_array(x), log_array(y), 1)

def linear_regression():
    def plot_size_vs_times_log_log():
        plt.subplot(2, 1, 1)
        plt.loglog(x, y1, 's', label='y1=x')
        plt.loglog(x, y2, 's', label='y2=x log(x)')
        plt.loglog(x, y3, 's', label='y3=x^2')
        plt.loglog(x, y4, 's', label='y4=x^3')
        plt.grid(which='both')
        plt.legend()

    def plot_regression_lines(): 
        plt.subplot(2, 1, 2)
        m, b = get_regression_line_coefficients(x, y1)
        x2 = np.array(range(5))
        plt.plot(x2, m*x2 + b, label=f'y1 ~ {round(m, 2)}x + {round(b, 2)}')
        m, b = get_regression_line_coefficients(x, y2)
        plt.plot(x2, m*x2 + b, label=f'y2 ~ {round(m, 2)}x + {round(b, 2)}')
        m, b = get_regression_line_coefficients(x, y3)
        plt.plot(x2, m*x2 + b, label=f'y3 ~ {round(m, 2)}x + {round(b, 2)}')
        m, b = get_regression_line_coefficients(x, y4)
        plt.plot(x2, m*x2 + b, label=f'y4 ~ {round(m, 2)}x + {round(b, 2)}')
        plt.legend()
        plt.grid(which='both')
        plt.xticks(x2)
        plt.yticks(np.arange(12))

    x = np.array([10**idx for idx in range(2, 21)])
    y1 = np.array([x for x in x]) 
    y2 = np.array([x*math.log(x, 10) for x in x]) 
    y3 = np.array([x**2 for x in x]) 
    y4 = np.array([x**3 for x in x])
    plot_size_vs_times_log_log()
    plot_regression_lines()
    plt.show()

linear_regression()

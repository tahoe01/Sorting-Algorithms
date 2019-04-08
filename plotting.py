import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import math
import scipy.interpolate as ip

def plot_polynomials_and_their_negations():
    x = np.linspace(0, 2, 100)

    plt.plot(x, x, label='linear')
    plt.plot(x, x**2, label='quadratic')
    plt.plot(x, x**3, label='cubic')

    plt.xlabel('x label')
    plt.ylabel('y label')

    plt.title("Simple Plot")
    plt.legend()
    plt.show()
    #plt.savefig('curves.png')

    plt.clf()
    x = np.linspace(0, 2, 100)

    plt.plot(x, -x, label='linear')
    plt.plot(x, -x**2, label='quadratic')
    plt.plot(x, -x**3, label='cubic')

    plt.xlabel('x label')
    plt.ylabel('y label')

    plt.title("Simple Plot")
    plt.legend()
    plt.show()
    #plt.savefig('curves_neg.png')
    plt.close()

def plot_timings_from_file(fname):
    timings = pd.read_csv(fname, sep=',')
    n = timings['n'].values
    seconds = timings['seconds'].values
    x = n
    y = seconds
    plt.loglog(x=x, y=y, basex=2, basey=2, 's')
    s = ip.UnivariateSpline(x, y, s = 0)
    xs = np.linspace(min(x), max(x), 1000)
    ys = s(xs)
    plt.plot(xs, ys)
    plt.xlabel('# of elements')
    plt.ylabel('time in seconds')
    plt.title('Performance of introsort')
    plt.show()
    plt.close()

plot_timings_from_file('timings.csv')
#plot_polynomials_and_their_negations()
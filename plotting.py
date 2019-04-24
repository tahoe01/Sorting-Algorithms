import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import math
import scipy.interpolate as ip

# def plot_polynomials_and_their_negations():
#     x = np.linspace(0, 2, 100)

#     plt.plot(x, x, label='linear')
#     plt.plot(x, x**2, label='quadratic')
#     plt.plot(x, x**3, label='cubic')

#     plt.xlabel('x label')
#     plt.ylabel('y label')

#     plt.title("Simple Plot")
#     plt.legend()
#     plt.show()
#     #plt.savefig('curves.png')

#     plt.clf() # Clear the current figure
#     x = np.linspace(0, 2, 100)

#     plt.plot(x, -x, label='linear')
#     plt.plot(x, -x**2, label='quadratic')
#     plt.plot(x, -x**3, label='cubic')

#     plt.xlabel('x label')
#     plt.ylabel('y label')

#     plt.title("Simple Plot")
#     plt.legend()
#     plt.show()
#     #plt.savefig('curves_neg.png')
#     plt.close()

def plot_timings_from_file(fname_list):
    for fname in fname_list:
        timings = pd.read_csv(fname, sep=',')

        n = timings['n'].values
        seconds = timings['seconds'].values

        x = n
        y = seconds
        plt.loglog(x=x, y=y, basex=2, basey=2)
        # s = ip.UnivariateSpline(x, y)
        # xs = np.linspace(min(x), max(x), 1000)
        # ys = s(xs)
        plt.plot(x, y, label=fname)


    plt.xlabel('# of elements')
    plt.ylabel('time in seconds')
    plt.title('Performance of sort')
    plt.legend()
    plt.show()
    #plt.savefig('sort.png')
    plt.close()

plot_timings_from_file(["bubble.csv", "insertion.csv", "shell1.csv", "shell2.csv", "spin.csv"]) # TODO: annealing1.csv, annealing2.csv
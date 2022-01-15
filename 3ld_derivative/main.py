from matplotlib import colors
import matplotlib.pyplot as plt
import numpy as np
import math

l, r, prec = [
    float(n)
    for n in input("Please enter left and right border and precision: ").split(" ")
]


def my_func(x):
    return math.sin(x / 2)


main_func = np.vectorize(my_func)


def my_deriv_func(x):
    return 0.5 * math.cos(x / 2)


deriv_func = np.vectorize(my_deriv_func)


def my_differential_func(x):
    return (my_func(x) - my_func(x - prec)) / prec


differential_func = np.vectorize(my_differential_func)


def my_deriv2_func(x):
    return -0.25 * math.sin(x / 2)


deriv2_func = np.vectorize(my_deriv2_func)


def my_differential2_func(x):
    return (my_differential_func(x) - my_differential_func(x - prec)) / prec


differential2_func = np.vectorize(my_differential2_func)

fig, axs = plt.subplots(3, 2)
fig.suptitle("y(x) = sin(x/2)")
x = np.arange(l, r, 0.001)

axs[0, 0].plot(x, main_func(x))
axs[0, 0].set_title("y(x)")

axs[0, 1].plot(x, deriv_func(x))
axs[0, 1].set_title("y'(x)")

axs[1, 0].plot(x, differential_func(x))
axs[1, 0].set_title("y'(x) (differential)")

axs[1, 1].plot(x, deriv2_func(x))
axs[1, 1].set_title("y''(x)")

axs[2, 0].plot(x, differential2_func(x))
axs[2, 0].set_title("y''(x) (differential)")

axs[2, 1].axis("off")

plt.show()
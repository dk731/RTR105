from matplotlib import colors
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import numpy as np
import math

l, r, prec = [
    float(n)
    for n in input("Please enter left and right border and precision: ").split(" ")
]


def my_func(x):
    return math.sin(x / 2)


def rect_to_center(x1, y1, x2, y2):
    return ((x1 + x2) / 2, (y1 + y2) / 2), abs(x2 - x1), abs(y2 - y1)


main_func = np.vectorize(my_func)

fig, axs = plt.subplots(2, 2)
fig.suptitle("y(x) = sin(x/2)")
x = np.arange(l, r, prec)

axs[0, 0].plot(x, main_func(x))
axs[0, 0].set_title("y(x)")

axs[0, 1].plot(x, main_func(x))
axs[0, 1].set_title("square rule")

axs[1, 0].plot(x, main_func(x))
axs[1, 0].set_title("trapezoidal rule")

axs[1, 1].plot(x, main_func(x))
axs[1, 1].set_title("Simpson's rule")

for i, x_start in enumerate(x[:-1]):
    if abs(my_func(x[i + 1])) > abs(my_func(x_start)):
        tmp = my_func(x_start)
    else:
        tmp = my_func(x[i + 1])

    axs[0, 1].add_patch(
        patches.Rectangle(
            (x_start, tmp),
            prec,
            -tmp,
            color=(1, 0, 0, 0.5),
        )
    )

    axs[1, 0].add_patch(
        patches.Polygon(
            [
                [x_start, 0],
                [x_start, my_func(x_start)],
                [x[i + 1], my_func(x[i + 1])],
                [x[i + 1], 0],
            ],
            color=(1, 0, 0, 0.5),
        )
    )

    axs[1, 1].add_patch(
        patches.Polygon(
            [
                [x_start, 0],
                [x_start, my_func(x_start)],
                [x[i + 1], my_func(x[i + 1])],
                [x[i + 1], 0],
            ],
            color=(1, 0, 0, 0.5),
        )
    )

plt.show()
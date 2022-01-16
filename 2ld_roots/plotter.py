from matplotlib import colors
import matplotlib.pyplot as plt
import numpy as np
import math

find_val = 0.5

x = np.arange(0, 4 * np.pi, 0.01)
y = np.sin(x / 2)

plt.plot(x, y, zorder=1)
plt.scatter(
    [1.05, 5.24],
    [find_val, find_val],
    color=["red"],
    zorder=2,
)
plt.show()

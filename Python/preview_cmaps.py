from numpy import linspace, sin, sqrt, meshgrid
import matplotlib.pyplot as plt
from mpl_toolkits.axes_grid1 import make_axes_locatable

cmaps = plt.colormaps()

res = 100
x = linspace(1, 10, res)
y = linspace(1, 5, res)

X, Y = meshgrid(x, y)
Z = sin(X) + sqrt(Y)

for i in range(len(cmaps)):
    fig, ax = plt.subplots(dpi=300)
    divider = make_axes_locatable(ax)
    cax = divider.append_axes('right', size='5%', pad=0.15)
    im = ax.pcolormesh(x, y, Z, shading='auto', cmap=cmaps[i])
    ax.set_title(str(cmaps[i]))
    fig.colorbar(im, cax=cax, orientation='vertical')











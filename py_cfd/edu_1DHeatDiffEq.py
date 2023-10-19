# Code will generate figure files in the existing directory. 
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import font_manager
import matplotlib

font_dirs = ['C:\Windows\Fonts']
font_files = font_manager.findSystemFonts(fontpaths=font_dirs)
 
for font_file in font_files:
    font_manager.fontManager.addfont(font_file)

plt.rcParams['font.family'] = 'Latin Modern Roman'
plt.rcParams['mathtext.fontset'] = 'custom'
plt.rcParams['mathtext.rm'] = 'Latin Modern Roman'
plt.rcParams['mathtext.it'] = 'Latin Modern Roman:italic'
plt.rcParams['mathtext.bf'] = 'Latin Modern Roman:bold'
plt.rcParams['font.size'] = '12'

L = 1.0 # Length
N = 99 # # of grid points
dx = L / (N + 1)
dt = 1e-4 # Time 
k = 0.25 # Diffusion constant
print(dx)

# --------------------------------------
# Boundary Conditions.
# --------------------------------------
t_l = 0.0
t_r = 0

# T in-between right and left conditions
t_m = 0

# --------------------------------------
Lambda = (k * dt) / (dx**2)
print(Lambda)

U = np.empty(N + 1, float)
U[0] = t_l
U[-1] = t_r
U[1:N] = t_m
U[int(N / 2)] = 100
t_snap = [0.1, 0.2, 0.3, 0.5, 1.0]

t = 0.0
tf = t_snap[4]

while t <= tf:
    for i in range(1,N):
        U[i] = U[i] + Lambda * (U[i + 1] + U[i - 1] - 2 * U[i])
        t = t + dt
        if np.abs(t - t_snap[0]) < 10e-6:
            plt.plot(U, '-', label = 't = ' +str(t), color = 'black')
        if np.abs(t - t_snap[1]) < 10e-6:
            plt.plot(U, '-', label = 't = ' +str(t))
        if np.abs(t - t_snap[2]) < 10e-6:
            plt.plot(U, '-', label = 't = ' +str(t))
        if np.abs(t - t_snap[3]) < 10e-6:
            plt.plot(U, '-', label = 't = ' +str(t))
        if np.abs(t - t_snap[4]) < 10e-6:
            plt.plot(U, '-', label = 't = ' +str(t))

plt.title('1D Heat Diffusion Equation')
plt.text(10, 13, '$K\\frac{\\partial^2 U(x,t)}{\\partial x^2}= \\frac{\\partial U(x,t)}{\\partial t}$', bbox={
        'facecolor': 'Grey', 'alpha': 0.2, 'pad': 7})
plt.legend(loc = 'best')
plt.savefig('edu_1DHeatDiffEq.png')
plt.savefig('edu_1DHeatDiffEq.pdf')
plt.show()
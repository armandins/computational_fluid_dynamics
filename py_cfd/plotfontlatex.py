# ************************************************************
# by Arman Dindar Safa
# date: 10 / 19 / 2023
# ************************************************************
import numpy as np
import matplotlib.pyplot as plt
# *
from matplotlib import font_manager
# *
import matplotlib

# ------------------------------------------------------------
# ------------- Font setup -----------------------------------
# ------------------------------------------------------------


# Path to the fonts directory, default setup for win 10 
# To find the path on your system: Win + E -> shell:fonts   
font_dirs = ['C:\Windows\Fonts']
font_files = font_manager.findSystemFonts(fontpaths=font_dirs)
 
for font_file in font_files:
    font_manager.fontManager.addfont(font_file)

# personal fav. font : Latin Modern Roman
plt.rcParams['font.family'] = 'Latin Modern Roman'
plt.rcParams['mathtext.fontset'] = 'custom'
plt.rcParams['mathtext.rm'] = 'Latin Modern Roman'
plt.rcParams['mathtext.it'] = 'Latin Modern Roman:italic'
plt.rcParams['mathtext.bf'] = 'Latin Modern Roman:bold'
plt.rcParams['font.size'] = '12'


# ------------------------------------------------------------
# ------------- Font setup -----------------------------------
# ------------------------------------------------------------

# Example function declaration
x1 = [0, 1, 2, 3, 4, 5]
y1 = [0, 6, 3, 8, 7, 5]
x2 = np.linspace(-3 * np.pi, 3 * np.pi)
y2 = np.cos(x2)

# Plot results using mathplotlib.pyplot.plot
plt.plot(x1, y1, label = "Data Points", marker = "o")
plt.plot(x2, y2, label = "$cos(x) ( -\\pi, \\pi)$", marker = "+")

# Testing LaTeX equation formatting for title
# Keep in mind to use \\ instead of \ for math symbols
plt.title('testing title: $\\frac{1}{x} + \\beta\\alpha\\gamma$')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.legend()
# Save figures to directory folder
# NOTE: always put mathplotlib.pyplot.savefig() 
# before mathplotlib.pyplot.show() 
# 1.savefig()
plt.savefig("plotlatexfont.pdf")
plt.savefig("plotlatexfont.png")
plt.savefig("plotlatexfont.eps")
# 2.show()
plt.show()
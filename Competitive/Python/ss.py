import numpy as np
import matplotlib.pyplot as plt


#Q2
#i
n = np.arange(0,0.01,0.001)
y = np.sin (200*np.pi*n)
plt.stem(n,y)
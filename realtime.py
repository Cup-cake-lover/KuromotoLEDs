import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from matplotlib.animation import FuncAnimation
import shutup

shutup.please()

plt.style.use('dark_background')


def animate(i):
	data = pd.read_csv('test.csv')
	k = data['k']
	b = data['b']


	plt.cla()
	#plt.plot(k,y,color='red', label='red')
	plt.plot(k,b,color='red', label='red')
	#plt.plot(m,x_g,color='green', label='green')
	#plt.plot(n,x_b,color='blue', label='blue')
	#plt.plot(n,a,color='blue', label='cyan')

	plt.legend(loc='upper left')
	#plt.tight_layout()

ani = FuncAnimation(plt.gcf(),animate,interval=100)

#plt.tight_layout()
plt.show()

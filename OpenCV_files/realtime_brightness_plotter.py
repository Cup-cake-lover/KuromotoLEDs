import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from matplotlib.animation import FuncAnimation
import shutup

# Suppress warnings
shutup.please()

# Use dark background style for the plot
plt.style.use('dark_background')

# Function to animate the plot
def animate(i):
    # Read data from the CSV file
    data = pd.read_csv('test.csv')
    k = data['k']
    b = data['b']

    # Clear the current plot
    plt.cla()

    # Plot the data
    plt.plot(k, b, color='red', label='Brightness')

    # Add legend
    plt.legend(loc='upper left')

# Create an animation
ani = FuncAnimation(plt.gcf(), animate, interval=100)

# Show the plot
plt.show()

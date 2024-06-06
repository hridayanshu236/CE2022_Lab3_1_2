import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import make_interp_spline

# Input sizes
sizes = np.array([500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500,
         6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000, 10500, 
         11000, 11500, 12000, 12500, 13000, 13500, 14000, 14500, 15000])

# Execution time for insertion sort
insertion_sort_times = np.array([0.816, 0.993, 4.01, 7.002, 12.375, 17.687, 20.859,
                        32.073, 36.913, 37.502, 52.219, 60.213, 61.586, 
                        70.698, 97.194, 94.307, 115.243, 137.051, 126.095, 
                        155.188, 169.86, 167.003, 212.763, 202.355, 258.134, 
                        252.873, 179.019, 284.114, 326.252, 288.332])

# Execution time for quick sort
quick_sort_times = np.array([0, 0, 3.096, 4.011, 7.015, 9.052, 10.53, 14.517, 12.597, 
                    16.085, 17.033, 19.143, 19.461, 20.042, 23.144, 23.548, 
                    27.238, 27.562, 30.33, 28.07, 31.29, 33.533, 35.579, 
                    35.928, 36.718, 40, 44.46, 42.353, 42.681, 51.564])

# Creating smooth curves using spline interpolation
smooth_sizes = np.linspace(sizes.min(), sizes.max(), 300)
insertion_sort_smooth = make_interp_spline(sizes, insertion_sort_times)(smooth_sizes)
quick_sort_smooth = make_interp_spline(sizes, quick_sort_times)(smooth_sizes)

# Plotting the data
plt.plot(smooth_sizes, insertion_sort_smooth, label='Insertion Sort', color='b')
plt.plot(smooth_sizes, quick_sort_smooth, label='Quick Sort', color='r')

# Adding titles and labels
plt.title('Execution Time for Insertion Sort and Quick Sort')
plt.xlabel('Input Size')
plt.ylabel('Time (milliseconds)')
plt.legend()

# Display the plot
plt.show()

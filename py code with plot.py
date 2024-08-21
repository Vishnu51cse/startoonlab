import numpy as np
import matplotlib.pyplot as plt
data1 = np.loadtxt('/content/Data_1.txt') 
data2 = np.loadtxt('/content/Data_2.txt')
def find_peaks(values):
    max_vals = []
    min_vals = []
    for i in range(1, len(values) - 1):
        if values[i] > values[i - 1] and values[i] > values[i + 1]:
            max_vals.append(i)
        elif values[i] < values[i - 1] and values[i] < values[i + 1]:
            min_vals.append(i)
    return max_vals, min_vals
max1, min1 = find_peaks(data1)
max2, min2 = find_peaks(data2)
plt.figure(figsize=(10, 6))
plt.plot(data1, label='Data 1')
plt.scatter(max1, data1[max1], color='red', label='Max', zorder=5)
plt.scatter(min1, data1[min1], color='blue', label='Min', zorder=5)
plt.title('Data 1 with Maxima and Minima')
plt.legend()
plt.show()
plt.figure(figsize=(10, 6))
plt.plot(data2, label='Data 2')
plt.scatter(max2, data2[max2], color='red', label='Max', zorder=5)
plt.scatter(min2, data2[min2], color='blue', label='Min', zorder=5)
plt.title('Data 2 with Maxima and Minima')
plt.legend()
plt.show()


print("Maxima in Data 1:", max1)
print("Minima in Data 1:", min1)
print("Maxima in Data 2:", max2)
print("Minima in Data 2:", min2)

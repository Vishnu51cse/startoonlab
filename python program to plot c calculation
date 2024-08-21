import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV files
data1 = pd.read_csv('/content/data_1.csv')
data2 = pd.read_csv('/content/data_2.csv')

# Plot for Data 1
plt.figure(figsize=(10, 6))
plt.plot(data1['Index'], data1['Value'], label='Signal')
plt.scatter(data1[data1['PeakType'] == 'Maxima']['Index'], data1[data1['PeakType'] == 'Maxima']['Value'], color='red', label='Maxima')
plt.scatter(data1[data1['PeakType'] == 'Minima']['Index'], data1[data1['PeakType'] == 'Minima']['Value'], color='blue', label='Minima')
plt.title('Data 1 Signal with Peaks')
plt.xlabel('Index')
plt.ylabel('Value')
plt.legend()
plt.show()

# Plot for Data 2
plt.figure(figsize=(10, 6))
plt.plot(data2['Index'], data2['Value'], label='Signal')
plt.scatter(data2[data2['PeakType'] == 'Maxima']['Index'], data2[data2['PeakType'] == 'Maxima']['Value'], color='red', label='Maxima')
plt.scatter(data2[data2['PeakType'] == 'Minima']['Index'], data2[data2['PeakType'] == 'Minima']['Value'], color='blue', label='Minima')
plt.title('Data 2 Signal with Peaks')
plt.xlabel('Index')
plt.ylabel('Value')
plt.legend()
plt.show()

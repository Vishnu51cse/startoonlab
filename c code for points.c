#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
void findPeaks(double arr[], int n, int max[], int *maxCount, int min[], int *minCount) {
    *maxCount = 0;
    *minCount = 0;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            max[*maxCount] = i;
            (*maxCount)++;
        } else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            min[*minCount] = i;
            (*minCount)++;
        }
    }
}
void writeCSV(const char* fileName, double arr[], int max[], int maxCount, int min[], int minCount, int n) {
    FILE *file = fopen(fileName, "w");
    fprintf(file, "Index,Value,PeakType\n");
    for (int i = 0; i < n; i++) {
        int isMax = 0, isMin = 0;
        for (int j = 0; j < maxCount; j++) {
            if (i == max[j]) {
                isMax = 1;
                break;
            }
        }
        for (int j = 0; j < minCount; j++) {
            if (i == min[j]) {
                isMin = 1;
                break;
            }
        }
        if (isMax) {
            fprintf(file, "%d,%lf,Max\n", i, arr[i]);
        } else if (isMin) {
            fprintf(file, "%d,%lf,Min\n", i, arr[i]);
        } else {
            fprintf(file, "%d,%lf,\n", i, arr[i]);
        }
    }
    fclose(file);
}
int main() {
    double data1[SIZE], data2[SIZE];
    int max1[SIZE], min1[SIZE], maxCount1, minCount1;
    int max2[SIZE], min2[SIZE], maxCount2, minCount2;
    FILE *file = fopen("Data_1.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file Data_1.txt\n");
        return 1;
    }
    int i = 0;
    while (i < SIZE && fscanf(file, "%lf", &data1[i]) == 1) {
        i++;
    }
    fclose(file);
    file = fopen("Data_2.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file Data_2.txt\n");
        return 1;
    }
    int j = 0;
    while (j < SIZE && fscanf(file, "%lf", &data2[j]) == 1) {
        j++;
    }
    fclose(file);
    findPeaks(data1, i, max1, &maxCount1, min1, &minCount1);
    findPeaks(data2, j, max2, &maxCount2, min2, &minCount2);
    writeCSV("data_1.csv", data1, max1, maxCount1, min1, minCount1, i);
    writeCSV("data_2.csv", data2, max2, maxCount2, min2, minCount2, j);
    printf("CSV files generated.\n");

    return 0;
}

#include<bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
     
    int i = 0; 
    int j = 0; 
    int k = l;
     
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int findMinWidth(int colors[], int start, int minWidth, int size)
{
    int width = colors[start + 2] - colors[start];
    if (start + 2 == size)
        return minWidth;
    if (width == 2)
        return 2;
    if (width < minWidth)
        minWidth = width;
    return findMinWidth(colors, start + 1, minWidth, size);
} 

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int cost, n, index = 0;
        cin >> n;
        cin >> cost;
        int *arr = new int[n];
        while (index < n)
        {
            int val = 0;
            cin >> val;
            arr[index] = val;
            index++;
        }
        mergeSort(arr, 0, n-1);

        // Not considering Fractional parts
        int minWidth = findMinWidth(arr, 0, INT_MAX, n);
        int minimumCost = 2 * cost * minWidth * (arr[n - 1] - arr[0]);
        cout << minimumCost << endl;

        // Considering Fractional parts
        double sum = 0.0;
        sum = (arr[n - 1] - arr[1] + arr[n - 2] - arr[0]) * 2.0;
        sum += (arr[n - 1] - arr[n - 2] + arr[1] - arr[0]) * sqrt(2.0);
        
        long long rounded = ceil(sum);
        cout << rounded * cost << endl;
    }
}
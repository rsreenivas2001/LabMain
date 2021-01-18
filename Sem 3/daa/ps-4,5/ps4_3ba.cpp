#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int end)
{
    int right = mid + 1;
    int counter = 0;

    if (arr[mid] <= arr[right])
        return;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            left++;

        }
        else
        {
            int value = arr[right];
            int index = right;

            while (index != left)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[left] = value;

            mid++;
            left++;
            right++;
        }
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

void print(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout<<A[i];
    cout<<"\n";
}

int main()
{
    int k,n;
    cout << "Enter the value of K : ";
    cin >> k;
    cout << "Enter the number of Elements : ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the Elements : ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    print(arr,n);
    int sum = 0;

    for(int i = 0; i < n - k; i++){
        sum += arr[i];
    }

    cout << "Speciality of the sequence is " << sum;
}
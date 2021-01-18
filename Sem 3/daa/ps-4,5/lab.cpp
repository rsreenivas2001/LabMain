#include <iostream>
#include<algorithm> 

using namespace std; 
  

int CountValue(int arr[], int n, int k) 
{ 
     
    int ans = 0; 
  
    for (int i = 1; i < n; i++) { 
        arr[i] += arr[i - 1]; 
        if (arr[i] > k or arr[i] < -1 * k) 
            ans++; 
    } 
  
    if (arr[0] > k || arr[0] < -1 * k) 
        ans++; 
  
    
    sort(arr, arr + n); 
  
    for (int i = 0; i < n; i++)
        {int zx;
        zx=(upper_bound(arr, arr + n, arr[i] + k) - arr);
        cout<<"\nzx : "<<zx;
        cout<<"\nans : "<<ans;
        ans += n -  (upper_bound(arr, arr + n, arr[i] + k) - arr);
        }
  
    return ans; 
} 
  

int main() 
{ 
   
    int n;
    cout<<"Enter size of Array : ";
    cin>>n; 
    int arr[n];
    int k = 0; 
    cout<<"\nEnter the value of M : ";
    cin>>k;
    int i;
    cout<<"\nEnter elements of array : ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"\n\n"<<CountValue(arr, n, k); 
} 
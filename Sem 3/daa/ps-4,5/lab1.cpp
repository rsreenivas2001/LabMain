#include<bits/stdc++.h>
 
using namespace std;
 
long long int subarray(long long int arr[], long long int n,long long int k){
 
	long long int i,c=0;
 
	for( i=1; i<n; i++){
 
		arr[i]+=arr[i-1];
 
		if(arr[i]>k or arr[i]< -1*k)
			c++;
	}
	if(arr[0]>k or arr[0]<-1*k)
		c++;
	
 
	sort(arr, arr+n);
     for(i=0; i<n; i++){
	 c+=n-
    (upper_bound(arr, arr + n, arr[i] + k) - arr); }
 
	return c;
}
 
int main(){
 
	long long int t ;   cin>>t;
	while(t--){
 
		long long int n, sum;
		cin>>n>>sum;
 
		long long int arr[n];
 
		for(long long int i=0; i<n; i++){
 
			cin>>arr[i];
		}
 
		cout<<subarray(arr, n, sum);
 
	    cout<<endl;
	}
	return 0;
}
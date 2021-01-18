#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a==0 || b==0)
        return 0;
    if(a == b)
        return a;
    
    else if(a > b)
        return gcd(a-b , b);
    
    else
        return gcd(a , b-a);
}

int main(){
    
    int n;

    cout<<"Enter the Number : ";
    cin >> n;
    int a = n-2;
    if(n%2 == 0){
        a=a-1;
        while(gcd(a,n) != 1)
        {  
            a=a-2;
        }
    }
    else{
        while(gcd(a,n) != 1)
        {   
            a--;
        }
    }
        
    cout <<a<<"is the largest co-prime less than n-1";
}
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    string new_order,input;
    cout<<"Enter the NEW order : ";
    cin >>new_order;
    cout<<"\nEnter the string to be sorted in new order : ";
    cin>>input;
    vector<pair<int,char>> v;
    for(int i = 0; i < input.length(); i++){
        for(int j = 0; j < 26; j++){
            if(input[i] == new_order[j]){
                v.push_back(make_pair(j,new_order[j]));
            }
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < input.length(); i++){
        cout << v[i].second;
    }
    return 0;
}
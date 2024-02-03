```cpp
#include <bits/stdc++.h> 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
#define f(i, x, y) for(ll i = x; i < y; i++) 
#define rf(i, x, y) for(ll i = x; i > y; i--) 
#define nl "\n" 
#define YES cout<<"YES"<<nl 
#define NO cout<<"NO"<<nl
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
typedef long long ll; 
using namespace std; 
int elimination(vector<int>& arr, int &LeftToRight){
    int n = arr.size();
    // cout << "Debug n = " << n << ", LeftToRight = " << LeftToRight << endl;
    if(n==1){
        return arr[0];
    }
    vector<int> newARR;
    // cout<< "array = ";
    // f(i,0,arr.size())cout<<arr[i]<<" ";
    if(LeftToRight == 1){
        for (int i = 1; i < n; i+=2)
        {
            newARR.pb(arr[i]);
        }
        LeftToRight = 0;
    }
    else if(LeftToRight == 0){
        for (int i = n-2; i > 0; i-=2)
        {
            newARR.pb(arr[i]);
        }
        sort(newARR.begin(),newARR.end());
        LeftToRight = 1;
        
    }
    return elimination(newARR,LeftToRight);
}
 int lastRemaining(int n) {
    // base case
    if(n==0||n==1){
        return 1;
    }
    vector<int> arr;
    f(i,1,n+1)arr.pb(i);
    int LeftToRight = 1;
    int ans = elimination(arr,LeftToRight);
    return ans;
}

int main(){ 
    fastio(); 
    int n = 100000000;
    int ans = lastRemaining(n);
    cout<<"hi"<<endl;
    cout<<"ans--"<<ans<<endl;
    return 0; 

}
```

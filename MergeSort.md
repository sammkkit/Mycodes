```cpp
#include <bits/stdc++.h> 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
#define f(i, x, y) for(ll i = x; i < y; i++) 
#define rf(i, x, y) for(ll i = x; i > y; i--) 
typedef long long ll; 
using namespace std; 
void merge(int *arr,int s, int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    int first[len1];
    int second[len2];
    f(i,0,len1)first[i]=arr[s+i];
    f(i,0,len2)second[i]=arr[mid+1+i];
    int index1=0;
    int index2=0;
    int mainIndex=0;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainIndex]=first[index1];
            mainIndex++;
            index1++;
        }
        else{
            arr[mainIndex]=second[index2];
            mainIndex++;
            index2++;
        }
    }
    while(index1<len1){
        arr[mainIndex++]=first[index1++];
    }
    while(index2<len2){
        arr[mainIndex++]=second[index2++];
    }
}
void mergeSort(int *arr , int s, int e){
    if(s>=e){
        return;
    }
    int mid =(s+e)/2;
    //left sort
    mergeSort(arr,s,mid);
    //right sort
    mergeSort(arr, mid+1,e);
    merge(arr,s,e);
}

int main(){ 

    int arr[9] = {10,9,8,7,6,5,4,3,2};
    mergeSort(arr,0,8);
    f(i,0,9)cout<<arr[i]<<" ";
    return 0; 

}
```

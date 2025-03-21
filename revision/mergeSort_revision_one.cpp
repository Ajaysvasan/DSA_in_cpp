#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& arr,int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1),R(n2);

    for(int i= 0;i<n1;++i){
        L[i] = arr[i+left];
    }
    for(int j = 0;j<n2;++j){
        R[j] = arr[j+mid +1 ];
    }

    int i = 0,j = 0, k = left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            ++i;
        }else{
            arr[k] = R[j];
            ++j;
        }
        ++k;
    } 
    while(i<n1){
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while(j<n2){
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>&arr,int left,int right){
    if(left>=right) return;
    int mid = left + (right - left) /2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

void print(vector<int>arr){
    for(int num:arr){
        cout<<num<<" ";
    }
    cout<<endl;
}

main(){
    vector<int> arr = {10,20,1,200,80,2,89,3,4,0,30};
    print(arr);
    mergeSort(arr,0,arr.size()-1);
    print(arr);
}
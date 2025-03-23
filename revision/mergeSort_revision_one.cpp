#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>&arr,int low,int mid,int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> L(n1) , R(n2);
    for(int i = 0;i<n1;i++)
        L[i] = arr[i+low];
    for(int j = 0;j<n2;j++)
        R[j] = arr[j+mid+1];
    
    int i = 0 , j = 0, k = low;
    while(i<n1 && j < n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            ++i;
        }
        else{
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

void mergeSort(vector<int>&arr,int low,int high){
    if(low>=high) return ;
    int mid = low + (high - low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid + 1,high);
    merge(arr,low,mid,high);
}

main(){
    vector<int> arr = {70,1,5,9,2,3,0,700};
    mergeSort(arr,0,arr.size()-1);
    for(int num:arr)
        cout<<num<<" ";
}
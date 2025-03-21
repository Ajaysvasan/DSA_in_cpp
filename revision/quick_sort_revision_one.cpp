#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>&arr,int low,int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low;j<=high;++j){
        if(arr[j]<pivot){
            ++i;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(vector<int>&arr,int low,int high){
    if(low<high){
    int pi = partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi,high);
    }
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
    quickSort(arr,0,arr.size()-1);
    print(arr);
}
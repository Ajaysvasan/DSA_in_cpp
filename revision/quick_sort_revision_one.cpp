#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>&arr,int low,int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low;j<=high;j++){
        if(arr[j]<pivot){
            ++i;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[high]);
    return arr[i+1];
}

void quickSort(vector<int>&arr,int low,int high){
    if(low>=high) return;
    int pi = partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi,high);

}

main(){
    vector<int> arr = {70,1,5,9,2,3,0,700};
    quickSort(arr,0,arr.size()-1);
    for(int num:arr){
        cout<<num<<" ";
    }
}
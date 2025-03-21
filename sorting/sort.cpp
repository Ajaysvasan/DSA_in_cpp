#include<iostream>
#include<vector>
using namespace std;

class SORT{
    public:
    // Merges two subarrays of arr[].
    // First subarray is arr[left..mid]
    // Second subarray is arr[mid+1..right]
    void merge(vector<int>&arr,int left,int mid,int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1),R(n2);
        // Copy data to temp vectors L[] and R[]
        for(int i = 0;i<n1;i++)
            L[i] = arr[i+left];
        for(int j = 0;j<n2;j++)
            R[j] = arr[mid + 1 +j];
        int i = 0,j = 0,k=left;
        while(i<n1 && j<n2){
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
    void mergeSort(vector<int>&arr,int left,int right){
        if(left>=right) return;
        int mid = left + (right - left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }

    int partion(vector<int>&arr,int low,int high){
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low;j<=high;j++){
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
            int pi = partion(arr,low,high);
            quickSort(arr,low,pi-1);
            quickSort(arr,pi+1,high);
        }
    }

    void printVector(vector<int>& arr)
    {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

main(){
    SORT s;
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();
    s.printVector(arr);
    s.mergeSort(arr, 0, n - 1);
    s.printVector(arr);

    vector<int> arr_two = {10, 7, 8, 9, 1, 5};
    s.printVector(arr_two);
    s.quickSort(arr_two,0,arr.size()-1);
    s.printVector(arr_two);
}
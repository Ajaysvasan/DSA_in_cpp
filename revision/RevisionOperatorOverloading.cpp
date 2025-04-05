#include <iostream>
#include <vector>

class Sorting {
private:
    std::vector<int> data;

    void merge(int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        std::vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++)
            L[i] = data[low + i];
        for (int j = 0; j < n2; j++)
            R[j] = data[mid + 1 + j];
        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                data[k++] = L[i++];
            } else {
                data[k++] = R[j++];
            }
        }
        while (i < n1) data[k++] = L[i++];
        while (j < n2) data[k++] = R[j++];
    }

    void mergeSort(int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }

public:
    Sorting(std::vector<int> &arr) {
        this->data = arr;
    }

 

    void operator+() {
        mergeSort(0, data.size() - 1);
    }   
    Sorting M(){
        mergeSort(0,data.size()-1);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &COUT, const Sorting &s) {
        for (int num : s.data)
            COUT << num << " ";
        return COUT;
    }
};

int main() {
    std::vector<int> arr = {20, 22, 10, 2, 0};
    Sorting s(arr);

    std::cout << "Before Sorting: " << s << std::endl;
    s = s.M();
    std::cout << "After Sorting: " << s << std::endl;

    return 0;
}

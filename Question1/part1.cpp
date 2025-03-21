#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    std::ifstream file("Question1/part1.txt");

    if (!file) {
        std::cerr << "Error: Unable to open file!" << std::endl;
        return 1;
    }

    std::vector<int> left, right; 

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int num1, num2;
        if (iss >> num1 >> num2) {
            left.push_back(num1);
            right.push_back(num2);
        } else {
            std::cerr << "Error: Invalid line format -> " << line << std::endl;
        }
    }
    file.close();

    merge_sort(left, 0, left.size() - 1);
    merge_sort(right, 0, right.size() - 1);
    int total = 0;
    for (int i=0;i<left.size();i++){
        int difference = left[i]-right[i];
        if (difference < 0){
            difference*=-1;
        }
        total+=difference; 
    }
    std::cout<<total;
    return 0;
}

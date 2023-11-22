#include<iostream>
#include<sstream>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    int salaries[n];
    cout << "Enter the salaries of the employees: ";
    for(int i = 0; i < n; i++) {
        cin >> salaries[i];
    }

    quickSort(salaries, 0, n-1);

    cout << "Top five salaries are: ";
    for(int i = n-1; i >= n-5 && i >= 0; i--) {
        cout << salaries[i] << " ";
    }
    cout << "\n";

    return 0;
}


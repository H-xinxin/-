#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// �鲢����
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// �鲢������
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    while (true) {
        // ����Ҫ���ɵ������������
        int numCount;
        cout << "Enter the number of random numbers to generate (or enter 0 to exit): ";
        cin >> numCount;

        if (numCount <= 0) {
            cout << "Exiting program..." << endl;
            break;
        }

        // ���������
        srand(time(0));
        vector<int> numbers;
        for (int i = 0; i < numCount; i++) {
            numbers.push_back(rand());
        }

        // ���δ����������
        cout << "Unsorted numbers:" << endl;
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;

        // ���������������
        mergeSort(numbers, 0, numCount - 1);

        // ��������Ľ��
        cout << "Sorted numbers:" << endl;
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

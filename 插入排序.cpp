#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ����������
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
        insertionSort(numbers);

        // ��������Ľ��
        cout << "Sorted numbers:" << endl;
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

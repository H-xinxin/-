#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ѡ��������
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
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
        selectionSort(numbers);

        // ��������Ľ��
        cout << "Sorted numbers:" << endl;
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

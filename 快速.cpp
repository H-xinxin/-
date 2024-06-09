#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ����������
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // ��������
        int pivot = arr[low]; // ѡ���һ��Ԫ����Ϊ��׼
        int i = low + 1; // ָ����ڻ�׼��Ԫ�ص���߽�
        int j = high; // ָ��С�ڻ�׼��Ԫ�ص��ұ߽�

        while (true) {
            // ���������ҵ���һ�����ڻ�׼��Ԫ��
            while (i <= j && arr[i] <= pivot) {
                i++;
            }
            // ���������ҵ���һ��С�ڻ�׼��Ԫ��
            while (i <= j && arr[j] > pivot) {
                j--;
            }
            // �������ָ��������������ѭ��
            if (i >= j) {
                break;
            }
            // ��������ָ����ָ���Ԫ��
            swap(arr[i], arr[j]);
        }
        // ����׼Ԫ�ط�����ȷ��λ��
        swap(arr[low], arr[j]);

        int partitionIndex = j; // ��������

        // �ݹ�ضԷ�����������
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
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

        // ����������п�������
        quickSort(numbers, 0, numbers.size() - 1);

        // ��������Ľ��
        cout << "Sorted numbers:" << endl;
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}


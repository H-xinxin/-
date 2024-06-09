#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 选择排序函数
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
        // 输入要生成的随机数的数量
        int numCount;
        cout << "Enter the number of random numbers to generate (or enter 0 to exit): ";
        cin >> numCount;

        if (numCount <= 0) {
            cout << "Exiting program..." << endl;
            break;
        }

        // 生成随机数
        srand(time(0));
        vector<int> numbers;
        for (int i = 0; i < numCount; i++) {
            numbers.push_back(rand());
        }

        // 输出未排序的随机数
        cout << "Unsorted numbers:" << endl;
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;

        // 对随机数进行排序
        selectionSort(numbers);

        // 输出排序后的结果
        cout << "Sorted numbers:" << endl;
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 快速排序函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // 分区操作
        int pivot = arr[low]; // 选择第一个元素作为基准
        int i = low + 1; // 指向大于基准的元素的左边界
        int j = high; // 指向小于基准的元素的右边界

        while (true) {
            // 从左向右找到第一个大于基准的元素
            while (i <= j && arr[i] <= pivot) {
                i++;
            }
            // 从右向左找到第一个小于基准的元素
            while (i <= j && arr[j] > pivot) {
                j--;
            }
            // 如果左右指针相遇，则跳出循环
            if (i >= j) {
                break;
            }
            // 交换左右指针所指向的元素
            swap(arr[i], arr[j]);
        }
        // 将基准元素放在正确的位置
        swap(arr[low], arr[j]);

        int partitionIndex = j; // 分区索引

        // 递归地对分区进行排序
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
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

        // 对随机数进行快速排序
        quickSort(numbers, 0, numbers.size() - 1);

        // 输出排序后的结果
        cout << "Sorted numbers:" << endl;
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}


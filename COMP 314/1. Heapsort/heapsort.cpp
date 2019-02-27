#include <iostream>
#include <vector>

using namespace std;

class Heap {
  private:
    vector<int> arr;
    int heapSize;

  public:
    Heap() {
      arr = {0};
      heapSize = 0;
    }

    void display() {
      for (int i = 1; i < arr.size(); i += 1) {
        cout << arr[i] << ", ";
      }
      cout << endl;
    }

    void insert(int num) {
      arr.push_back(num);
      heapSize += 1;
    }

    void insert(vector<int> nums) {
      for (int i = 0; i < nums.size(); i += 1) {
        insert(nums[i]);
      }
    }

    void maxHeapify(int n) {
      int left = 2 * n;
      int right = left + 1;
      int largest = n;
      if (left <= heapSize && arr[left] > arr[n]) {
        largest = left;
      }

      if (right <= heapSize && arr[right] > arr[largest]) {
        largest = right;
      }

      if (n != largest) {
        // Swap
        int temp = arr[n];
        arr[n] = arr[largest];
        arr[largest] = temp;
        maxHeapify(largest);
      }
    }

    void buildMaxHeap() {
      for (int i = heapSize / 2; i >= 1; i -= 1) {
        maxHeapify(i);
      }
    }

    void buildHeap() {
      for (int i = 0; i < arr.size(); i += 1) {
        insert(arr[i]);
      }
    }

    int getSize() {
      return heapSize;
    }

    void swap(int i, int j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }

    void decreaseSize() {
      this->heapSize -= 1;
    }

    vector<int> toArray() {
      return arr;
    }
};

vector<int> heapSort(vector<int> nums) {
  Heap heap;
  heap.insert(nums);
  heap.buildMaxHeap();
  while (heap.getSize() > 0) {
    heap.swap(1, heap.getSize());
    heap.decreaseSize();
    heap.maxHeapify(1);
  }
  return heap.toArray();
}

int main() {
  vector<int> nums = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
  vector<int> sorted = heapSort(nums);
  for (int i = 0 ; i < sorted.size(); i += 1) {
    cout << sorted[i] << endl;
  }
}
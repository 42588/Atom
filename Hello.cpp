#include <iostream>
#include <vector>

// 二分查找 力扣704
// 在一个有序无重复的数组Nums中，寻找一个元素target，如果找到了就返回了相应的下标，否则返回-1
using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    // 定义target在左闭右闭，的区间，即[left,right]
    int right = nums.size() - 1;
    while (left <= right) {
      // 防止溢出，等同于(left+right)/2
      int middle = left + ((right - left) / 2);
      if (nums[middle] > target) {
        right = middle - 1;
      } else if (nums[middle] < target) {
        left = middle + 1;
      } else {
        // nums[middle]=target;
        return middle;
      }
    }
    return -1;
  }
};
int main() {
  Solution *solution = new Solution();
  vector<int> *hh = new vector<int>();
  for (int i = 0; i < 10; i++) {
    int a;
    cin >> a;
    hh->push_back(a);
  }
  int b = solution->search(*hh, 2);
  cout << b << endl;
  delete solution;
  delete hh;
  return 0;
}

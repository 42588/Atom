//四数相加II
#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;
// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
//
// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;//用来记录a+b的值
        for (int itor1 : nums1) {
            for (int itor2 : nums2) {
                umap[itor1 + itor2]++;//寻找当前的key，然后加一，代表有多少个组合能够加起来等于这个数
            }
        }
        int count = 0;//统计有多少个值满足这个条件（a+b+c+d）等于零
        for (int itor3 : nums3) {
            for (int itor4 : nums4) {
                if (umap.find(0 - (itor3 + itor4)) != umap.end()) {
                    count += umap[0 - itor3 - itor4];
                }
            }
        }
        return count;
    }
};
int main() {
    unordered_map<int, int> map;
    map[10]++;
    for (auto iter = map.begin(); iter != map.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }//以上代码说明map容器也可以使用数组的形式，数组的下表代表着键值，数组的大小代表着值
    for (pair<int,int> test : map) {//pair或者使用auto效果相同
       cout<< test.first<<endl<<test.second;
    }
    for (auto test : map) {//pair或者使用auto效果相同
        cout << test.first << endl << test.second;
    }
}

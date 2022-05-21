//�������II
#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;
// �����ĸ��������� nums1��nums2��nums3 �� nums4 �����鳤�ȶ��� n ����������ж��ٸ�Ԫ�� (i, j, k, l) �����㣺
//
// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;//������¼a+b��ֵ
        for (int itor1 : nums1) {
            for (int itor2 : nums2) {
                umap[itor1 + itor2]++;//Ѱ�ҵ�ǰ��key��Ȼ���һ�������ж��ٸ�����ܹ����������������
            }
        }
        int count = 0;//ͳ���ж��ٸ�ֵ�������������a+b+c+d��������
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
    }//���ϴ���˵��map����Ҳ����ʹ���������ʽ��������±�����ż�ֵ������Ĵ�С������ֵ
    for (pair<int,int> test : map) {//pair����ʹ��autoЧ����ͬ
       cout<< test.first<<endl<<test.second;
    }
    for (auto test : map) {//pair����ʹ��autoЧ����ͬ
        cout << test.first << endl << test.second;
    }
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
/****
	* 1. 两数之和
	* 题目：给定一个target和数组nums，返回数组中相加之和为target的两个元素的位置（一个元素只能使用一次）
	* 思路：一开始往排序后二分的方向想，处理不了临界的位置。
			改变思路，排序后给出head指针和tail指针进行遍历，若head+tail>target,则tail--,否则head++，复杂度O（nlogn)
	  Tips：排序后数组元素位置发生改变，要copy一份原数组才能返回元素在原数组中的位置。
	  （n久以来刷的第一道算法题，WA了3次，写了一个小时左右，果然还是菜了^-^）
	*
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>result, copy;
		copy = nums;
		sort(nums.begin(), nums.end());
		int head = 0;
		int tail = nums.size() - 1;
		while (head < tail) {
			if (nums[head] + nums[tail] == target) {
				break;
			}
			else if (nums[head] + nums[tail] < target) {
				head++;
			}
			else {
				tail--;
			}
		}
		auto iter = find(copy.begin(), copy.end(), nums[head]);
		int a = iter - copy.begin();
		iter = find(copy.begin(), copy.end(), nums[tail]);
		if (nums[head] == nums[tail]) {
			iter = find(iter+1, copy.end(), nums[tail]);
		}
		int b = iter - copy.begin();
		result.push_back(a);
		result.push_back(b);
		return result;
	}
};
int main()
{
	Solution solution;
	vector<int>nums, result;
	int x, target;
	for (int i = 0;i < 2;i++) {
		scanf("%d", &x);
		nums.push_back(x);
	}
	scanf("%d", &target);
	result = solution.twoSum(nums, target);
	for (const auto& value : result) {
		printf("%d ", value);
	}
	return 0;
}
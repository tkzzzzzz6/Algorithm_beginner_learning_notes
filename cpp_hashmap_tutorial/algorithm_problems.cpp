#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class HashMapAlgorithms
{
public:
    // 1. 两数之和
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end())
            {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }

    // 2. 字母异位词分组
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> groups;

        for (string &str : strs)
        {
            string key = str;
            sort(key.begin(), key.end()); // 排序作为key
            groups[key].push_back(str);
        }

        vector<vector<string>> result;
        for (auto &group : groups)
        {
            result.push_back(group.second);
        }

        return result;
    }

    // 3. 最长无重复字符子串
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.length(); end++)
        {
            if (charIndex.find(s[end]) != charIndex.end() &&
                charIndex[s[end]] >= start)
            {
                start = charIndex[s[end]] + 1;
            }
            charIndex[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }

    // 4. 数组中的第K个最大元素（使用频率计数）
    int findKthLargest(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;

        // 统计每个数字的频率
        for (int num : nums)
        {
            count[num]++;
        }

        // 创建所有唯一数字的向量并排序
        vector<int> unique;
        for (auto &pair : count)
        {
            unique.push_back(pair.first);
        }
        sort(unique.rbegin(), unique.rend()); // 降序排序

        // 找到第k大的元素
        int totalCount = 0;
        for (int num : unique)
        {
            totalCount += count[num];
            if (totalCount >= k)
            {
                return num;
            }
        }

        return -1;
    }

    // 5. 四数相加II
    int fourSumCount(vector<int> &nums1, vector<int> &nums2,
                     vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> sumCount;

        // 计算前两个数组所有可能的和
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                sumCount[a + b]++;
            }
        }

        int count = 0;
        // 计算后两个数组的和，查找是否存在相反数
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                int target = -(c + d);
                if (sumCount.find(target) != sumCount.end())
                {
                    count += sumCount[target];
                }
            }
        }

        return count;
    }

    // 6. 最长连续序列
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;

        for (int num : nums)
        {
            // 只从序列的开始处开始计算
            if (numSet.find(num - 1) == numSet.end())
            {
                int currentNum = num;
                int currentLength = 1;

                while (numSet.find(currentNum + 1) != numSet.end())
                {
                    currentNum++;
                    currentLength++;
                }

                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }

    // 7. 和为K的子数组
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1; // 前缀和为0的情况

        int sum = 0;
        int count = 0;

        for (int num : nums)
        {
            sum += num;
            if (prefixSum.find(sum - k) != prefixSum.end())
            {
                count += prefixSum[sum - k];
            }
            prefixSum[sum]++;
        }

        return count;
    }

    // 8. 单词模式
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        // 分割字符串
        vector<string> words;
        string word = "";
        for (char c : s + " ")
        {
            if (c == ' ')
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word = "";
                }
            }
            else
            {
                word += c;
            }
        }

        if (pattern.length() != words.size())
        {
            return false;
        }

        for (int i = 0; i < pattern.length(); i++)
        {
            char c = pattern[i];
            string w = words[i];

            if (charToWord.find(c) != charToWord.end())
            {
                if (charToWord[c] != w)
                    return false;
            }
            else
            {
                charToWord[c] = w;
            }

            if (wordToChar.find(w) != wordToChar.end())
            {
                if (wordToChar[w] != c)
                    return false;
            }
            else
            {
                wordToChar[w] = c;
            }
        }

        return true;
    }
};

// 测试函数
void testAlgorithms()
{
    HashMapAlgorithms algo;

    cout << "=== HashMap 算法题应用 ===" << endl;

    // 测试1: 两数之和
    cout << "\n1. 两数之和" << endl;
    vector<int> nums1 = {2, 7, 11, 15};
    int target = 9;
    vector<int> result1 = algo.twoSum(nums1, target);
    cout << "数组: [2,7,11,15], 目标: 9" << endl;
    cout << "结果: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // 测试2: 字母异位词分组
    cout << "\n2. 字母异位词分组" << endl;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result2 = algo.groupAnagrams(strs);
    cout << "输入: [\"eat\",\"tea\",\"tan\",\"ate\",\"nat\",\"bat\"]" << endl;
    cout << "结果: " << endl;
    for (auto &group : result2)
    {
        cout << "[";
        for (int i = 0; i < group.size(); i++)
        {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    // 测试3: 最长无重复字符子串
    cout << "\n3. 最长无重复字符子串" << endl;
    string s = "abcabcbb";
    int result3 = algo.lengthOfLongestSubstring(s);
    cout << "输入: \"" << s << "\"" << endl;
    cout << "结果: " << result3 << endl;

    // 测试4: 最长连续序列
    cout << "\n4. 最长连续序列" << endl;
    vector<int> nums4 = {100, 4, 200, 1, 3, 2};
    int result4 = algo.longestConsecutive(nums4);
    cout << "输入: [100,4,200,1,3,2]" << endl;
    cout << "结果: " << result4 << endl;

    // 测试5: 和为K的子数组
    cout << "\n5. 和为K的子数组" << endl;
    vector<int> nums5 = {1, 1, 1};
    int k = 2;
    int result5 = algo.subarraySum(nums5, k);
    cout << "输入: [1,1,1], k=2" << endl;
    cout << "结果: " << result5 << endl;

    // 测试6: 单词模式
    cout << "\n6. 单词模式" << endl;
    string pattern = "abba";
    string words = "dog cat cat dog";
    bool result6 = algo.wordPattern(pattern, words);
    cout << "模式: \"" << pattern << "\", 单词: \"" << words << "\"" << endl;
    cout << "结果: " << (result6 ? "true" : "false") << endl;
}

int main()
{
    testAlgorithms();
    return 0;
}
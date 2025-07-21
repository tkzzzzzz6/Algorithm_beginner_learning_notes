#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 用户的原始代码
int userGoodnessScore(string s)
{
    int count[52] = {0};

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            count[c - 'a']--; // 小写字母减1
        }
        else if (c >= 'A' && c <= 'Z')
        {
            count[c - 'A']++; // 大写字母加1 (注意：这里确实应该是同一个索引！)
        }
    }

    int goodnessScore = 0;
    for (int i = 0; i < 26; i++)
    {
        int caseCount = count[i];
        if (caseCount > 0)
        {
            goodnessScore++;
        }
        else if (caseCount < 0)
        { // 修正：应该是 < 0，不是 else
            goodnessScore--;
        }
        // caseCount == 0 时不变
    }

    return goodnessScore;
}

// 修正版本的用户代码
int correctedUserCode(string s)
{
    int count[26] = {0}; // 只需要26个位置

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            count[c - 'a']--; // 小写字母减1
        }
        else if (c >= 'A' && c <= 'Z')
        {
            count[c - 'A']++; // 大写字母加1
        }
    }

    int goodnessScore = 0;
    for (int i = 0; i < 26; i++)
    {
        int diff = count[i]; // diff = 大写数量 - 小写数量
        if (diff > 0)
        {
            goodnessScore++; // 大写多
        }
        else if (diff < 0)
        {
            goodnessScore--; // 小写多
        }
        // diff == 0 时相等，不变
    }

    return goodnessScore;
}

// 标准解法（用于对比）
int standardSolution(string s)
{
    int lowercase[26] = {0};
    int uppercase[26] = {0};

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            lowercase[c - 'a']++;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            uppercase[c - 'A']++;
        }
    }

    int score = 0;
    for (int i = 0; i < 26; i++)
    {
        if (uppercase[i] > lowercase[i])
        {
            score++;
        }
        else if (uppercase[i] < lowercase[i])
        {
            score--;
        }
    }

    return score;
}

void detailedAnalysis(string s)
{
    cout << "\n=== 详细分析: \"" << s << "\" ===" << endl;

    // 模拟用户代码执行过程
    int count[26] = {0};
    cout << "执行过程:" << endl;

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            cout << "'" << c << "' (小写) -> count[" << (c - 'a') << "]--" << endl;
            count[c - 'a']--;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            cout << "'" << c << "' (大写) -> count[" << (c - 'A') << "]++" << endl;
            count[c - 'A']++;
        }
    }

    cout << "\n最终统计结果:" << endl;
    int score = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            char letter = 'a' + i;
            cout << "字母 '" << letter << "': count[" << i << "] = " << count[i];

            if (count[i] > 0)
            {
                cout << " (大写多) -> +1";
                score++;
            }
            else if (count[i] < 0)
            {
                cout << " (小写多) -> -1";
                score--;
            }
            else
            {
                cout << " (相等) -> 0";
            }
            cout << endl;
        }
    }

    cout << "最终得分: " << score << endl;

    // 验证
    int userResult = correctedUserCode(s);
    int standardResult = standardSolution(s);

    cout << "修正后用户代码结果: " << userResult << endl;
    cout << "标准解法结果: " << standardResult << endl;
    cout << "结果一致: " << (userResult == standardResult ? "✅" : "❌") << endl;
}

void testCases()
{
    cout << "=== 测试用例验证 ===" << endl;

    vector<string> tests = {"AABae", "aaaa"};
    vector<int> expected = {1, -1};

    for (int i = 0; i < tests.size(); i++)
    {
        string test = tests[i];
        int exp = expected[i];

        cout << "\n测试 " << (i + 1) << ": \"" << test << "\"" << endl;
        cout << "期望结果: " << exp << endl;

        int originalUser = userGoodnessScore(test);
        int correctedUser = correctedUserCode(test);
        int standard = standardSolution(test);

        cout << "原始用户代码: " << originalUser << endl;
        cout << "修正用户代码: " << correctedUser << endl;
        cout << "标准解法: " << standard << endl;

        cout << "用户思路正确性: " << (correctedUser == exp ? "✅ 正确" : "❌ 错误") << endl;

        detailedAnalysis(test);
    }
}

void explainUserApproach()
{
    cout << "\n"
         << string(60, '=') << endl;
    cout << "=== 用户代码思路分析 ===" << endl;

    cout << "\n用户的巧妙思路:" << endl;
    cout << "1. 使用同一个数组位置统计每个字母的大小写差异" << endl;
    cout << "2. 大写字母 +1，小写字母 -1" << endl;
    cout << "3. 最终 count[i] 的值直接表示该字母的 (大写数量 - 小写数量)" << endl;
    cout << "   - count[i] > 0: 大写多于小写 -> +1" << endl;
    cout << "   - count[i] < 0: 小写多于大写 -> -1" << endl;
    cout << "   - count[i] = 0: 大小写相等 -> +0" << endl;

    cout << "\n原代码的小问题:" << endl;
    cout << "1. 声明了 count[52] 但只用了前26个位置" << endl;
    cout << "2. 最终判断用了 'else' 而不是 'else if (caseCount < 0)'" << endl;
    cout << "   这导致 count[i] = 0 的情况被错误处理为 -1" << endl;

    cout << "\n修正方案:" << endl;
    cout << "将 'else' 改为 'else if (caseCount < 0)'" << endl;
    cout << "这样 count[i] = 0 时就不会改变 goodnessScore" << endl;
}

int main()
{
    testCases();
    explainUserApproach();
    return 0;
}
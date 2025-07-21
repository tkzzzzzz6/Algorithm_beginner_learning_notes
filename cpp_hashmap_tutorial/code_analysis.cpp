#include <iostream>
#include <string>

using namespace std;

// 用户提供的代码
int goodnessScore(string s)
{
    // 使用数组统计，索引0-25对应a-z，索引26-51对应A-Z
    int count[52] = {0};

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            count[c - 'a']--; // 小写字母  ⚠️ 这里是减法
        }
        else if (c >= 'A' && c <= 'Z')
        {
            count[c - 'A']++; // 大写字母  ⚠️ 注意：这里应该是 c - 'A' + 26
        }
    }

    int goodnessScore = 0;

    for (int i = 0; i < 26; i++)
    {
        int caseCount = count[i]; // a-z

        if (caseCount > 0)
        {
            goodnessScore++;
        }
        else
        {
            goodnessScore--;
        }
    }

    return goodnessScore;
}

// 正确的解法
int correctGoodnessScore(string s)
{
    int count[52] = {0};

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            count[c - 'a']++; // 小写字母：索引 0-25
        }
        else if (c >= 'A' && c <= 'Z')
        {
            count[c - 'A' + 26]++; // 大写字母：索引 26-51
        }
    }

    int score = 0;
    for (int i = 0; i < 26; i++)
    {
        int lowercaseCount = count[i];      // 小写
        int uppercaseCount = count[i + 26]; // 大写

        if (uppercaseCount > lowercaseCount)
        {
            score++;
        }
        else if (uppercaseCount < lowercaseCount)
        {
            score--;
        }
        // 相等时不变
    }

    return score;
}

// 测试和分析函数
void analyzeCode()
{
    cout << "=== 代码分析：用户提供的代码是否正确？ ===" << endl;

    string testCase = "AABae";
    cout << "\n测试用例: \"" << testCase << "\"" << endl;
    cout << "预期结果: 1" << endl;

    // 测试用户的代码
    int userResult = goodnessScore(testCase);
    cout << "用户代码结果: " << userResult << endl;

    // 测试正确的代码
    int correctResult = correctGoodnessScore(testCase);
    cout << "正确代码结果: " << correctResult << endl;

    cout << "\n"
         << string(60, '=') << endl;
    cout << "结论: " << (userResult == correctResult && correctResult == 1 ? "✅ 用户代码正确" : "❌ 用户代码有问题") << endl;

    // 详细分析用户代码的问题
    cout << "\n=== 用户代码问题分析 ===" << endl;

    cout << "\n问题1: 大写字母索引错误" << endl;
    cout << "用户代码: count[c - 'A']++    // 索引范围 0-25" << endl;
    cout << "正确代码: count[c - 'A' + 26]++ // 索引范围 26-51" << endl;
    cout << "影响: 大写字母会覆盖小写字母的统计" << endl;

    cout << "\n问题2: 小写字母使用减法" << endl;
    cout << "用户代码: count[c - 'a']--" << endl;
    cout << "正确代码: count[c - 'a']++" << endl;
    cout << "影响: 统计逻辑错误" << endl;

    cout << "\n问题3: 最终判断逻辑简化过度" << endl;
    cout << "用户代码: 只看 count[i] 是否大于0" << endl;
    cout << "正确代码: 比较大写频率和小写频率" << endl;
    cout << "影响: 无法正确处理频率相等的情况" << endl;

    // 展示详细计算过程
    cout << "\n=== 详细计算过程对比 ===" << endl;

    cout << "\n用户代码的计算过程 (\"AABae\"):" << endl;
    // 模拟用户代码的执行过程
    int userCount[52] = {0};
    for (char c : testCase)
    {
        if (c >= 'a' && c <= 'z')
        {
            cout << "处理 '" << c << "': count[" << (c - 'a') << "]--" << endl;
            userCount[c - 'a']--;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            cout << "处理 '" << c << "': count[" << (c - 'A') << "]++" << endl;
            userCount[c - 'A']++;
        }
    }

    cout << "\n最终数组状态:" << endl;
    for (int i = 0; i < 26; i++)
    {
        char letter = 'a' + i;
        if (userCount[i] != 0)
        {
            cout << "count[" << i << "] (" << letter << "): " << userCount[i] << endl;
        }
    }

    cout << "\n正确代码的计算过程:" << endl;
    int correctCount[52] = {0};
    for (char c : testCase)
    {
        if (c >= 'a' && c <= 'z')
        {
            cout << "处理 '" << c << "': count[" << (c - 'a') << "]++ (小写)" << endl;
            correctCount[c - 'a']++;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            cout << "处理 '" << c << "': count[" << (c - 'A' + 26) << "]++ (大写)" << endl;
            correctCount[c - 'A' + 26]++;
        }
    }

    cout << "\n字母频率统计:" << endl;
    for (int i = 0; i < 26; i++)
    {
        char letter = 'a' + i;
        int lower = correctCount[i];
        int upper = correctCount[i + 26];
        if (lower > 0 || upper > 0)
        {
            cout << "字母 '" << letter << "': 大写=" << upper << ", 小写=" << lower;
            if (upper > lower)
                cout << " -> +1";
            else if (upper < lower)
                cout << " -> -1";
            else
                cout << " -> 0";
            cout << endl;
        }
    }
}

// 更多测试用例
void moreTests()
{
    cout << "\n"
         << string(60, '=') << endl;
    cout << "=== 更多测试用例验证 ===" << endl;

    vector<string> testCases = {
        "AABae",  // 原题示例
        "AaBbCc", // 完全平衡
        "ABCDE",  // 只有大写
        "abcde",  // 只有小写
        "AaaBbb", // 混合情况
        ""        // 空字符串
    };

    for (const string &test : testCases)
    {
        cout << "\n测试: \"" << test << "\"" << endl;
        int userResult = goodnessScore(test);
        int correctResult = correctGoodnessScore(test);
        cout << "用户代码: " << userResult << ", 正确代码: " << correctResult;
        cout << (userResult == correctResult ? " ✅" : " ❌") << endl;
    }
}

int main()
{
    analyzeCode();
    moreTests();
    return 0;
}
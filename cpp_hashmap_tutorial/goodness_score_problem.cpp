#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class GoodnessScoreSolver
{
public:
    // 方法1: 使用unordered_map统计频率
    int calculateGoodnessScore(string s)
    {
        // 统计每个字符的频率
        unordered_map<char, int> frequency;

        for (char c : s)
        {
            frequency[c]++;
        }

        int goodnessScore = 0;

        // 遍历26个字母
        for (char letter = 'a'; letter <= 'z'; letter++)
        {
            char uppercase = letter - 'a' + 'A'; // 转换为大写
            char lowercase = letter;

            int uppercaseCount = frequency[uppercase]; // 如果不存在，默认为0
            int lowercaseCount = frequency[lowercase];

            cout << "字母 '" << letter << "': 大写(" << uppercase << ")="
                 << uppercaseCount << ", 小写(" << lowercase << ")="
                 << lowercaseCount;

            if (uppercaseCount > lowercaseCount)
            {
                goodnessScore++;
                cout << " -> +1" << endl;
            }
            else if (uppercaseCount < lowercaseCount)
            {
                goodnessScore--;
                cout << " -> -1" << endl;
            }
            else
            {
                cout << " -> 0" << endl;
            }
        }

        return goodnessScore;
    }

    // 方法2: 优化版本，只统计出现的字符
    int calculateGoodnessScoreOptimized(string s)
    {
        unordered_map<char, int> frequency;

        // 统计频率
        for (char c : s)
        {
            frequency[c]++;
        }

        int goodnessScore = 0;

        // 只处理在字符串中出现的字母
        unordered_map<char, bool> processed; // 记录已处理的字母

        for (auto &pair : frequency)
        {
            char c = pair.first;

            if (isalpha(c))
            {                                 // 确保是字母
                char baseLetter = tolower(c); // 转换为小写基准字母

                if (!processed[baseLetter])
                { // 如果这个字母还没处理过
                    processed[baseLetter] = true;

                    char uppercase = toupper(baseLetter);
                    char lowercase = baseLetter;

                    int uppercaseCount = frequency[uppercase];
                    int lowercaseCount = frequency[lowercase];

                    if (uppercaseCount > lowercaseCount)
                    {
                        goodnessScore++;
                    }
                    else if (uppercaseCount < lowercaseCount)
                    {
                        goodnessScore--;
                    }
                }
            }
        }

        return goodnessScore;
    }

    // 方法3: 使用数组优化（最高效）
    int calculateGoodnessScoreArray(string s)
    {
        // 使用数组统计，索引0-25对应a-z，索引26-51对应A-Z
        int count[52] = {0};

        for (char c : s)
        {
            if (c >= 'a' && c <= 'z')
            {
                count[c - 'a']++; // 小写字母
            }
            else if (c >= 'A' && c <= 'Z')
            {
                count[c - 'A' + 26]++; // 大写字母
            }
        }

        int goodnessScore = 0;

        for (int i = 0; i < 26; i++)
        {
            int lowercaseCount = count[i];      // a-z
            int uppercaseCount = count[i + 26]; // A-Z

            if (uppercaseCount > lowercaseCount)
            {
                goodnessScore++;
            }
            else if (uppercaseCount < lowercaseCount)
            {
                goodnessScore--;
            }
        }

        return goodnessScore;
    }
};

// 测试函数
void testGoodnessScore()
{
    GoodnessScoreSolver solver;

    cout << "=== Goodness Score Problem 解决方案 ===" << endl;

    // 测试用例1: 题目示例
    string test1 = "AABae";
    cout << "\n测试用例1: \"" << test1 << "\"" << endl;
    cout << "详细计算过程:" << endl;
    int result1 = solver.calculateGoodnessScore(test1);
    cout << "最终 Goodness Score: " << result1 << endl;

    // 验证其他方法
    int result1_opt = solver.calculateGoodnessScoreOptimized(test1);
    int result1_arr = solver.calculateGoodnessScoreArray(test1);
    cout << "优化方法结果: " << result1_opt << endl;
    cout << "数组方法结果: " << result1_arr << endl;

    // 测试用例2: 更复杂的例子
    cout << "\n"
         << string(50, '=') << endl;
    string test2 = "AaaBbbCccDdd";
    cout << "\n测试用例2: \"" << test2 << "\"" << endl;
    int result2 = solver.calculateGoodnessScoreArray(test2);
    cout << "Goodness Score: " << result2 << endl;

    // 分析：A(1) vs a(2) -> -1, B(1) vs b(2) -> -1, C(1) vs c(2) -> -1, D(1) vs d(2) -> -1
    // 总分: -4

    // 测试用例3: 平衡的例子
    cout << "\n"
         << string(50, '=') << endl;
    string test3 = "AaBbCc";
    cout << "\n测试用例3: \"" << test3 << "\"" << endl;
    int result3 = solver.calculateGoodnessScoreArray(test3);
    cout << "Goodness Score: " << result3 << endl;

    // 测试用例4: 只有大写
    cout << "\n"
         << string(50, '=') << endl;
    string test4 = "ABCDE";
    cout << "\n测试用例4: \"" << test4 << "\"" << endl;
    int result4 = solver.calculateGoodnessScoreArray(test4);
    cout << "Goodness Score: " << result4 << endl;

    // 测试用例5: 只有小写
    cout << "\n"
         << string(50, '=') << endl;
    string test5 = "abcde";
    cout << "\n测试用例5: \"" << test5 << "\"" << endl;
    int result5 = solver.calculateGoodnessScoreArray(test5);
    cout << "Goodness Score: " << result5 << endl;
}

// 性能测试
void performanceTest()
{
    GoodnessScoreSolver solver;

    cout << "\n=== 性能测试 ===" << endl;

    // 生成长字符串进行测试
    string longString = "";
    for (int i = 0; i < 1000; i++)
    {
        longString += "AaaBbbCccDdd";
    }

    cout << "测试字符串长度: " << longString.length() << endl;

    // 测试HashMap方法
    auto start = clock();
    int result_map = solver.calculateGoodnessScoreOptimized(longString);
    auto end = clock();
    cout << "HashMap方法耗时: " << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;
    cout << "结果: " << result_map << endl;

    // 测试数组方法
    start = clock();
    int result_array = solver.calculateGoodnessScoreArray(longString);
    end = clock();
    cout << "数组方法耗时: " << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;
    cout << "结果: " << result_array << endl;
}

int main()
{
    testGoodnessScore();
    performanceTest();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    char ch[100];    // 储存变量名
    bool value[100]; // 储存变量真值

} Val;
int number(char str[], int length) // 计算命题变元数量
{
    int i, j, num = 0;
    for (i = 0; i < length; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') // 如果当前字符的范围在A~Z之间，代表这是一个命题变元
        {
            for (j = 0; j < i; j++) // 再遍历该命题变元之前的所有字符，用来判断该命题变元是否为新变量
            {
                if (str[j] == str[i]) // 遇到相等的命题变元跳出循环
                    break;
            }
            if (i == j) // 如果i==j时，代表在i之前都没有字符与i相等，即i处命题变元为新出现的命题变元 ，num+1.
                num++;
        }
    }
    return num;
}
Val *Getval(char str[], int length, int num) // 将命题变量存储于结构体中
{
    Val *val = (Val *)malloc(sizeof(Val));
    int i, j, n = 0;
    for (i = 0; i < num; i++) // 赋变量真值初始值
    {
        val->value[i] = 0;
    }
    for (i = 0; i < length; i++) // 储存得到的命题变元名，循环和判断是否为新变元的方法与number相同
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            for (j = 0; j < i; j++)
            {
                if (str[j] == str[i])
                {
                    break;
                }
            }
            if (i == j)
            {
                val->ch[n++] = str[i];
            }
        }
    }
    return val;
}
void Binary(Val *val, int num) // 模仿二进制对变量赋值
{
    int i;
    for (i = num - 1; i >= 0; i--)
    {
        if (val->value[i] == 1)
        {
            val->value[i] = 0;
        }
        else
        {
            val->value[i] = 1;
            break;
        }
    }
}

bool Fouding(bool a) // 否定运算
{
    if (a)
        return false; // a为true则返回false
    return true;
}

bool And(bool a, bool b) // 合取运算
{
    if (!a || !b)
        return false;
    return true; // 只有a、b都为true才返回true
}

bool Or(bool a, bool b) // 析取运算
{
    if (a || b)
        return true; // a和b至少有一个为true就返回true
    return false;
}

bool lookfor(char word, Val *val) // 查询变量真值
{
    for (int i = 0;; i++)
    {
        if (val->ch[i] == word)
        {
            return val->value[i];
        }
    }
}
bool qiujie(char str[], int length, Val *val) // 求解命题公式
{
    bool jie;
    int i = 0;
    if (str[0] == '!') // 如果首位命题变元为否定形式
    {
        jie = Fouding(val->value[0]); // 进行否定运算
        i++;
    }
    else
    {
        jie = val->value[0]; // 把命题变元的值赋给解
    }
    i++;
    for (i; i < length; i++) // 进行顺序运算
    {
        if (str[i] == '~') // 如果遇到条件
        {

            if (str[i + 1] == '!') // 如果条件后项为否定形式
            {
                jie = Or(Fouding(jie), Fouding(lookfor(str[i + 2], val))); // 将解的否定与后项的否定进行析取运算
                i++;
                continue;
            }
            else
            {
                jie = Or(Fouding(jie), lookfor(str[i + 1], val)); // 条件化为前项否定并析取后项
                continue;
            }
        }
        if (str[i] == '&') // 如果遇到合取
        {
            if (str[i + 1] == '!') // 如果合取后项为否定形式
            {
                jie = And(jie, Fouding(lookfor(str[i + 2], val))); // 将解与后项的否定进行合取运算
                i++;
                continue;
            }
            else
            {
                jie = And(jie, lookfor(str[i + 1], val)); // 将解与后项进行合取运算
                continue;
            }
        }
        if (str[i] == '|') // 如果遇到析取
        {
            if (str[i + 1] == '!') // 如果析取后项为否定形式
            {
                jie = Or(jie, Fouding(lookfor(str[i + 2], val))); // 将解与后项的否定进行析取运算
                i++;
                continue;
            }
            else
            {
                jie = Or(jie, lookfor(str[i + 1], val)); // 将解与后项进行析取运算
                continue;
            }
        }
    }
    return jie;
}
void leibie(int arr[][100], int num, int l) // 判断命题公式类别
{

    int flag1 = 0, flag2 = 0;   // 定义两个标志变量
    for (int i = 0; i < l; i++) // 对每一行最后的结果进行遍历
    {
        if (arr[i][num] == 1) // 如果命题公式的值的结果存在true则flag1=1 并跳出循环
        {
            flag1 = 1;
            break;
        }
    }
    for (int i = 0; i < l; i++) // 对每一行最后的结果进行遍历
    {
        if (arr[i][num] == 0) // 如果命题公式的值的结果存在false则flag2=1 并跳出循环
        {
            flag2 = 1;
            break;
        }
    }
    printf("命题公式类别：  ");
    if (flag1 == 1 && flag2 == 0) // 如果结果的值全为true，永真
        printf("永真");
    else if (flag1 == 0 && flag2 == 1) // 如果结果的值全为false，永假
        printf("永假");
    else if (flag1 == 1 && flag2 == 1) // 如果结果的值存在true，可满足
        printf("可满足");
}
void print(int arr[][100], int num, Val *val) // 打印主析取范式与主合取范式
{
    int x = num;
    int y = pow(2, num);
    int numT = 0, numF = 0;
    for (int i = 0; i < y; i++) // 统计结果为true的数量
    {
        if (arr[i][x] == 1)
        {
            numT++;
        }
    }
    numF = y - numT; // 计结果为false的数量
    printf("主析取范式为：\n");
    int flag1 = 0, flag2 = 0;
    for (int j = 0; j < y; j++) // 行循环
    {
        if (arr[j][x] == 1) // 结果为true
        {
            flag1++;
            printf("(");
            for (int k = 0; k < x; k++) // 列循环
            {
                if (arr[j][k] == 1)
                {
                    printf("%c", val->ch[k]);
                }
                if (arr[j][k] == 0)
                {
                    printf("!%c", val->ch[k]);
                }
                if (k < x - 1)
                {
                    printf("&");
                }
            }
            printf(")");
        }
        if (flag1 < numT && arr[j][x] == 1) // 打印连接词
        {
            printf(" | ");
        }
    }
    if (numT == 0)
    {
        printf("不存在");
    }
    printf("\n主合取范式为：\n"); // 与主析取范式思路一致

    for (int j = 0; j < y; j++)
    {
        if (arr[j][x] == 0)
        {
            flag2++;
            printf("(");
            for (int k = 0; k < x; k++)
            {
                if (arr[j][k] == 1)
                {
                    printf("!%c", val->ch[k]);
                }
                if (arr[j][k] == 0)
                {
                    printf("%c", val->ch[k]);
                }
                if (k < x - 1)
                {
                    printf("|");
                }
            }
            printf(")");
        }
        if (flag2 < numF && arr[j][x] == 0)
        {
            printf(" & ");
        }
    }
    if (numF == 0)
    {
        printf("不存在");
    }
}

int main()
{
    printf("本程序支持由析取（|）、合取（&）、否定（！）、条件（~）组成的命题公式。\n请输入命题公式：");
    printf("请输入命题公式(命题变元的范围为A~Z):\n");
    int i = 0, j = 0, flag, length = 0;
    int arr[100][100]; // 存储结果的数组
    char str[50];      // 存储命题公式的数组
    do
    {
        flag = 0;
        gets(str);
        length = strlen(str);
        for (i = 0; i < length; i++) // 判断输入是否有误
        {
            if (str[i] >= 'A' && str[i] <= 'Z' || str[i] == 38 || str[i] == 124 || str[i] == 33 || str[i] == 126)
                flag++;
        }
        if (flag == length) // 相等是输入无误跳出循环
            break;
        else
            printf("输入错误，请重新输入：");
    } while (flag < length);
    int num;
    num = number(str, length);
    Val *val = Getval(str, length, num);
    printf("真值表如下：\n");
    for (i = 0; i < num; i++) // 打印真值表
    {
        printf("%c\t", val->ch[i]);
    }
    printf("%s\n", str);
    for (i = 0; i < pow(2, num); i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%d\t", val->value[j]);
            arr[i][j] = val->value[j];
        }
        arr[i][j] = qiujie(str, length, val);
        printf("%d\n", qiujie(str, length, val));

        Binary(val, num);
    }
    print(arr, num, val); // 打印主合取范式和主析取范式
    printf("\n");
    int l = pow(2, num);
    leibie(arr, num, l); // 打印命题公式类别
    return 0;
}
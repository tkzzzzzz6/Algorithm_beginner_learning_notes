#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    char ch[100];    // ���������
    bool value[100]; // ���������ֵ

} Val;
int number(char str[], int length) // ���������Ԫ����
{
    int i, j, num = 0;
    for (i = 0; i < length; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') // �����ǰ�ַ��ķ�Χ��A~Z֮�䣬��������һ�������Ԫ
        {
            for (j = 0; j < i; j++) // �ٱ����������Ԫ֮ǰ�������ַ��������жϸ������Ԫ�Ƿ�Ϊ�±���
            {
                if (str[j] == str[i]) // ������ȵ������Ԫ����ѭ��
                    break;
            }
            if (i == j) // ���i==jʱ��������i֮ǰ��û���ַ���i��ȣ���i�������ԪΪ�³��ֵ������Ԫ ��num+1.
                num++;
        }
    }
    return num;
}
Val *Getval(char str[], int length, int num) // ����������洢�ڽṹ����
{
    Val *val = (Val *)malloc(sizeof(Val));
    int i, j, n = 0;
    for (i = 0; i < num; i++) // ��������ֵ��ʼֵ
    {
        val->value[i] = 0;
    }
    for (i = 0; i < length; i++) // ����õ��������Ԫ����ѭ�����ж��Ƿ�Ϊ�±�Ԫ�ķ�����number��ͬ
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
void Binary(Val *val, int num) // ģ�¶����ƶԱ�����ֵ
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

bool Fouding(bool a) // ������
{
    if (a)
        return false; // aΪtrue�򷵻�false
    return true;
}

bool And(bool a, bool b) // ��ȡ����
{
    if (!a || !b)
        return false;
    return true; // ֻ��a��b��Ϊtrue�ŷ���true
}

bool Or(bool a, bool b) // ��ȡ����
{
    if (a || b)
        return true; // a��b������һ��Ϊtrue�ͷ���true
    return false;
}

bool lookfor(char word, Val *val) // ��ѯ������ֵ
{
    for (int i = 0;; i++)
    {
        if (val->ch[i] == word)
        {
            return val->value[i];
        }
    }
}
bool qiujie(char str[], int length, Val *val) // ������⹫ʽ
{
    bool jie;
    int i = 0;
    if (str[0] == '!') // �����λ�����ԪΪ����ʽ
    {
        jie = Fouding(val->value[0]); // ���з�����
        i++;
    }
    else
    {
        jie = val->value[0]; // �������Ԫ��ֵ������
    }
    i++;
    for (i; i < length; i++) // ����˳������
    {
        if (str[i] == '~') // �����������
        {

            if (str[i + 1] == '!') // �����������Ϊ����ʽ
            {
                jie = Or(Fouding(jie), Fouding(lookfor(str[i + 2], val))); // ����ķ������ķ񶨽�����ȡ����
                i++;
                continue;
            }
            else
            {
                jie = Or(Fouding(jie), lookfor(str[i + 1], val)); // ������Ϊǰ��񶨲���ȡ����
                continue;
            }
        }
        if (str[i] == '&') // ���������ȡ
        {
            if (str[i + 1] == '!') // �����ȡ����Ϊ����ʽ
            {
                jie = And(jie, Fouding(lookfor(str[i + 2], val))); // ���������ķ񶨽��к�ȡ����
                i++;
                continue;
            }
            else
            {
                jie = And(jie, lookfor(str[i + 1], val)); // �����������к�ȡ����
                continue;
            }
        }
        if (str[i] == '|') // ���������ȡ
        {
            if (str[i + 1] == '!') // �����ȡ����Ϊ����ʽ
            {
                jie = Or(jie, Fouding(lookfor(str[i + 2], val))); // ���������ķ񶨽�����ȡ����
                i++;
                continue;
            }
            else
            {
                jie = Or(jie, lookfor(str[i + 1], val)); // ��������������ȡ����
                continue;
            }
        }
    }
    return jie;
}
void leibie(int arr[][100], int num, int l) // �ж����⹫ʽ���
{

    int flag1 = 0, flag2 = 0;   // ����������־����
    for (int i = 0; i < l; i++) // ��ÿһ�����Ľ�����б���
    {
        if (arr[i][num] == 1) // ������⹫ʽ��ֵ�Ľ������true��flag1=1 ������ѭ��
        {
            flag1 = 1;
            break;
        }
    }
    for (int i = 0; i < l; i++) // ��ÿһ�����Ľ�����б���
    {
        if (arr[i][num] == 0) // ������⹫ʽ��ֵ�Ľ������false��flag2=1 ������ѭ��
        {
            flag2 = 1;
            break;
        }
    }
    printf("���⹫ʽ���  ");
    if (flag1 == 1 && flag2 == 0) // ��������ֵȫΪtrue������
        printf("����");
    else if (flag1 == 0 && flag2 == 1) // ��������ֵȫΪfalse������
        printf("����");
    else if (flag1 == 1 && flag2 == 1) // ��������ֵ����true��������
        printf("������");
}
void print(int arr[][100], int num, Val *val) // ��ӡ����ȡ��ʽ������ȡ��ʽ
{
    int x = num;
    int y = pow(2, num);
    int numT = 0, numF = 0;
    for (int i = 0; i < y; i++) // ͳ�ƽ��Ϊtrue������
    {
        if (arr[i][x] == 1)
        {
            numT++;
        }
    }
    numF = y - numT; // �ƽ��Ϊfalse������
    printf("����ȡ��ʽΪ��\n");
    int flag1 = 0, flag2 = 0;
    for (int j = 0; j < y; j++) // ��ѭ��
    {
        if (arr[j][x] == 1) // ���Ϊtrue
        {
            flag1++;
            printf("(");
            for (int k = 0; k < x; k++) // ��ѭ��
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
        if (flag1 < numT && arr[j][x] == 1) // ��ӡ���Ӵ�
        {
            printf(" | ");
        }
    }
    if (numT == 0)
    {
        printf("������");
    }
    printf("\n����ȡ��ʽΪ��\n"); // ������ȡ��ʽ˼·һ��

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
        printf("������");
    }
}

int main()
{
    printf("������֧������ȡ��|������ȡ��&�����񶨣�������������~����ɵ����⹫ʽ��\n���������⹫ʽ��");
    printf("���������⹫ʽ(�����Ԫ�ķ�ΧΪA~Z):\n");
    int i = 0, j = 0, flag, length = 0;
    int arr[100][100]; // �洢���������
    char str[50];      // �洢���⹫ʽ������
    do
    {
        flag = 0;
        gets(str);
        length = strlen(str);
        for (i = 0; i < length; i++) // �ж������Ƿ�����
        {
            if (str[i] >= 'A' && str[i] <= 'Z' || str[i] == 38 || str[i] == 124 || str[i] == 33 || str[i] == 126)
                flag++;
        }
        if (flag == length) // �����������������ѭ��
            break;
        else
            printf("����������������룺");
    } while (flag < length);
    int num;
    num = number(str, length);
    Val *val = Getval(str, length, num);
    printf("��ֵ�����£�\n");
    for (i = 0; i < num; i++) // ��ӡ��ֵ��
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
    print(arr, num, val); // ��ӡ����ȡ��ʽ������ȡ��ʽ
    printf("\n");
    int l = pow(2, num);
    leibie(arr, num, l); // ��ӡ���⹫ʽ���
    return 0;
}
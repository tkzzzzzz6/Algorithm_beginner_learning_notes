// 使用 OpenSSL 计算 SHA-256 哈希值
#include <iostream>
#include <openssl/sha.h> // 包含 OpenSSL 的 SHA-256 头文件
#include <iomanip>       // 用于格式化输出

using namespace std;

void calculate_sha256(const int *arr, int len, unsigned char *output)
{
    // 将整数数组转换为字节数组
    unsigned char data[len * sizeof(int)];
    for (int i = 0; i < len; ++i)
    {
        data[i * sizeof(int)] = (arr[i] >> 24) & 0xFF;
        data[i * sizeof(int) + 1] = (arr[i] >> 16) & 0xFF;
        data[i * sizeof(int) + 2] = (arr[i] >> 8) & 0xFF;
        data[i * sizeof(int) + 3] = arr[i] & 0xFF;
    }

    // 计算 SHA-256 哈希值
    SHA256(data, len * sizeof(int), output);
}

int main()
{
    int data[6] = {1, 2, 3, 4, 10, 6};
    int len = sizeof(data) / sizeof(data[0]);
    unsigned char hash[SHA256_DIGEST_LENGTH];

    calculate_sha256(data, len, hash);

    cout << "SHA-256: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        cout << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    cout << endl;

    return 0;
}
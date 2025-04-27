#include <iostream>
#include <string>

using namespace std;

class MyComputer
{
public:
    ~MyComputer();                                  // 这是析构函数声明
    MyComputer(string cpu, string gpu, int memory); // 这是构造函数声明
    string get_cpu();                               // 获取CPU信息
    string get_gpu();                               // 获取GPU信息
    int get_memory();                               // 获取内存信息

private:
    string cpu;
    string gpu;
    int memory;
};

// 成员函数定义，包括构造函数
MyComputer::MyComputer(string cpu, string gpu, int memory) : cpu(cpu), gpu(gpu), memory(memory)
{
    cout << "Computer is being created" << endl;
    cout << "CPU: " << cpu << endl;
    cout << "GPU: " << gpu << endl;
    cout << "Memory: " << memory << "GB" << endl;
}

MyComputer::~MyComputer()
{
    cout << "Computer is being destroyed" << endl;
}

string MyComputer::get_cpu()
{
    return cpu;
}

string MyComputer::get_gpu()
{
    return gpu;
}

int MyComputer::get_memory()
{
    return memory;
}

int main()
{
    MyComputer computer("Intel 13600kf", "NVIDIA RTX 4060Ti", 16);

    return 0;
}
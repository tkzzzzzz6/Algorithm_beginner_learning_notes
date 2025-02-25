#include <cstdint>
#include <limits>
#include <iostream>

using namespace std;

int main() {
    // 打印整数类型的最值
    cout << "int32_t max: " << std::numeric_limits<int32_t>::max() << endl; // 2'147'483'647
    cout << "int32_t min: " << std::numeric_limits<int32_t>::min() << endl; // -2'147'483'648

    // 打印浮点数类型的特殊值
    cout << "double min: " << std::numeric_limits<double>::min() << endl;     // 2.22507e-308
    cout << "double epsilon: " << std::numeric_limits<double>::epsilon() << endl; // 2.22045e-16

    return 0;
}
#include <iostream>
#include <vector>

int count_event(int n) {
    // 使用埃拉托斯特尼筛法优化质因数计数
    std::vector<int> factors(n + 1, 0);
    int event_count = 0;
    
    for (int i = 2; i <= n; ++i) {
        if (factors[i] == 0) {  // i是质数
            for (int j = i; j <= n; j += i) {
                factors[j]++;
            }
        }
        
        if (factors[i] > 1) {
            event_count++;
        }
    }
    
    return event_count;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << count_event(n) << std::endl;
    return 0;
}

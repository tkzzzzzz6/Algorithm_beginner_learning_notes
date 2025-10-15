#include <iostream>

int main(){
    int x;
    std::cin >> x;
     if (x == 0 || x == 1) {
        std::cout << "Today, I ate " << x << " apple." << std::endl;
    }
    if (x>1) {
        std::cout << "Today, I ate " << x << " apples." << std::endl;
    }
}



#include <iostream>
#include <string>

using namespace std;

int string2mask(const string& s) {
    int mask = 0;

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        if (s[i] == '1') {
            mask |= (1 << i);
        }
    }

    return mask;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    

	return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int string2mask(const string &s) {
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

    vector<int> patients(n);

    for (int i = 0; i < n; ++i) {
        string symptoms;
        cin >> symptoms;
        patients[i] = string2mask(symptoms);
    }

    int k;
    cin >> k;

    vector<int> medicines(k);

    for (int i = 0; i < k; ++i) {
        string symptoms;
        cin >> symptoms;
        medicines[i] = string2mask(symptoms);
    }

    int total = 1 << k;
    vector<int> cover(total, 0);
    vector<int> medicineCnt(total, 0);

    for (int subset = 1; subset < total; ++subset) {
        int lowbit = subset & -subset;
        int previous = subset ^ lowbit;
        int medicineIndex = __builtin_ctz(lowbit);

        cover[subset] = cover[previous] | medicines[medicineIndex];
        medicineCnt[subset] = medicineCnt[previous] + 1;
    }

    for (int patientMask : patients) {
        int ans = k + 1;

        for (int subset = 0; subset < total; ++subset) {
            if (medicineCnt[subset] >= ans) continue;

            if ((cover[subset] & patientMask) == patientMask) {
                ans = medicineCnt[subset];
            }
        }

        if (ans == k + 1)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}

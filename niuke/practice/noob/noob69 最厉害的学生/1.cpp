#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#define il inline
#define endl '\n'
using namespace std;

#define pb push_back
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

const ll N = 5e5 + 5, mod = 1e9 + 7, inf = 2e18;
const double eps = 1e-9;
const double PI = 3.1415926;

class Student {
   public:
    string name;
    unordered_map<string, int> scores = {
        {"chinese", 0},
        {"math", 0},
        {"english", 0},
    };
    int total_score = 0;

    Student(string _name, int math, int chinese, int english) : name(_name) {
        scores["chinese"] = chinese;
        scores["math"] = math;
        scores["english"] = english;
        total_score = chinese + math + english;
    }
};

auto cmp = [](const Student &a, const Student &b) {
    return a.total_score < b.total_score; // Max heap: highest score on top
};

priority_queue<Student, vector<Student>, decltype(cmp)> pq(cmp);

il void solve() {
    string name;
    int chinese, math, english;
    cin >> name >> chinese >> math >> english;
    Student stu(name, math, chinese, english);
    pq.push(stu);

}

int main() {
    fastio;
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    if (!pq.empty()) {
        Student top_student = pq.top();
        cout << top_student.name << " " << top_student.scores["chinese"] << " " << top_student.scores["math"] << " "
             << top_student.scores["english"] << endl;
    }
    return 0;
}

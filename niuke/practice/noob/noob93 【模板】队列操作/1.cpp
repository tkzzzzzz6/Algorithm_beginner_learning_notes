#include <iostream>
#include <queue>
using namespace std;

template <typename T> class Queue_e {

  queue<T> q;

public:
  void push(const T &x) { q.push(x); }

  void pop() {
    if (!q.empty()) {
      q.pop();
    } else {
      cout << "ERR_CANNOT_POP\n";
    }
  }

  void front() const {
    if (!q.empty()) {
      cout << q.front() << '\n';
    } else {
      cout << "ERR_CANNOT_QUERY\n";
    }
  }

  void size() const { cout << q.size() << '\n'; }

  bool empty() const { return q.empty(); }
};

int main() {
  Queue_e<int> qe;
  int n;
  cin >> n;

  while (n--) {
    int op;
    cin >> op;
    switch (op) {
    case 1: {
      int x;
      cin >> x;
      qe.push(x);
      break;
    }
    case 2:
      qe.pop();
      break;
    case 3:
      qe.front();
      break;
    case 4:
      qe.size();
      break;
    }
  }
  return 0;
}
// 64 位输出请用 printf("%lld")

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class Queue_e{

    queue<T> q;
public:

    void push(const T& x){
        q.push(x);
    }

    void pop(){
        if(!q.empty()){
            q.pop();
        }else{
          cout << "ERR_CANNOT_POP\n";
        }
    }

    void front() const {
        if(!q.empty()){
            cout << q.fornt() << '\n';
        }else{
          cout << "ERR_CANNOT_QUERY\n";
        }
    }

    void size() const {
        cout << q.size() << '\n';
    }

    bool empty() const {
        return q.empty();
    }

};

int main() {
    Queue_e<int> qe;
    int n;cin>> n;

    while(n--){
        
    }

}
// 64 位输出请用 printf("%lld")

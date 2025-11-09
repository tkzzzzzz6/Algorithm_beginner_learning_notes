<<<<<<< HEAD
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0];
        for (int i = 1; i < n; ++i) {
            ans += max(target[i] - target[i - 1], 0);
        }
        return ans;
    }
};
=======
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0];
        for (int i = 1; i < n; ++i) {
            ans += max(target[i] - target[i - 1], 0);
        }
        return ans;
    }
};
>>>>>>> 6948676579abca6ba4f3824e53edf9bbb7e1b238

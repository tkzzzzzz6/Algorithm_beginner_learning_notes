#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        // Store pairs of (businessLine priority, code)
        vector<pair<int, string>> ans;
        for(int i = 0; i < n; ++i)
        {
            if(isActive[i] && isValid(code[i], businessLine[i]))
            {
                int priority = getBusinessPriority(businessLine[i]);
                ans.push_back({priority, code[i]});
            }
        }
        // Sort by priority first, then by code lexicographically
        sort(ans.begin(), ans.end());
        
        // Extract just the codes for the result
        vector<string> result;
        for(auto &p : ans)
        {
            result.push_back(p.second);
        }
        return result;
    }
    
private:
    vector<string> vaild_business = {
        "electronics",
        "grocery",
        "pharmacy",
        "restaurant"
    };
    
    // Get priority of business line (0 = highest priority)
    int getBusinessPriority(const string &b)
    {
        auto it = find(vaild_business.begin(), vaild_business.end(), b);
        if(it == vaild_business.end()) return -1;
        return it - vaild_business.begin();
    }
    
    bool isValid(const string &c, const string &b)
    {
        if(find(vaild_business.begin(), vaild_business.end(), b) == vaild_business.end())
            return false;
        if(c == "")
            return false;
        for(auto ch : c)
        {
            bool isAlpha = (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
            bool isDigit = ch >= '0' && ch <= '9';
            bool isUnderscore = ch == '_';
            
            if(!isAlpha && !isDigit && !isUnderscore)
                return false;
        }
        return true;
    }
};

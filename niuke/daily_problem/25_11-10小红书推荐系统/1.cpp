// 哈希表加排序,输出频次从高到低,频次相同的按照字典序升序进行排序
#include<bits/stdc++.h>
using namespace std;

#define ll long long;

class Keyword{
private:
    string word;
    int count;
public:
    Keyword(string word,int count):word(word),count(count){}
    int getCount() const{
        return count;
    }
    string getWord() const{
        return word;
    }
};

bool compareKeywords(const Keyword &w1,const Keyword & w2)
{
    if(w1.getCount() != w2.getCount())
    {
        return w1.getCount() > w2.getCount();
    }
    return w1.getWord() < w2.getWord();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin,line);

    stringstream ss(line);
    string word;
    map<string, int> counts_map;
    while(ss >> word)
    {
        counts_map[word]++;
    }

    vector<Keyword> keywords;
    for(auto const &[key,val]:counts_map)
    {
        if(val>=3)
        {
            keywords.push_back(Keyword(key, val));
        }
    }
    sort(keywords.begin(),keywords.end(),compareKeywords);

    for(const auto &keyword:keywords)
    {
        cout << keyword.getWord() << '\n';
    }
    
    return 0;
}



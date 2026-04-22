#include <iostream>
#include <vector>

using namespace std;
/*
 *动态数组
 *人员管理
 */

int main()
{
    vector<int> vec1;
    vector<float> vec2(3);
    vector<string> vec3(3, "ABC");
    vector<string> vec4(vec3);
    for (int i = 0; i < 6; i++)
    {
        vec1.push_back(i);
    }
    vec2.push_back(1);
    vector<int> vec5(vec1.begin(), vec1.end());

    // vec1.clear();
    int max = vec1.max_size();
    cout << "max is " << max << endl;
    if (vec5.empty())
        cout << "vector is empty" << endl;
    else
    {
        cout << "vec5 = " << endl;
        for (int i = 0; i < vec5.size(); i++)
        {
            cout << vec5[i] << endl;
        }
    }
}
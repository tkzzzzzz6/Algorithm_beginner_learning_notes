class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param students int整型vector 
     * @param sandwiches int整型vector 
     * @return int整型
     */
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // write code here
        int i = 0,j = 0,ans = 0;
        while(i < students.size() && j < students.size()){
            if(students[i] == sandwiches[j]){
                ++i;++j;
            }else{
                ++i;
                ++ans;
            }
        }
        return ans;
    }
};

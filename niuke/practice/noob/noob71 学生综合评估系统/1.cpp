#include<bits/stdc++.h>
using namespace std;

// 定义学生结构体
struct Student{
    int id;
    int academic_score;
    int activity_score;
};

// 评估函数：判断学生是否优秀
bool isExcellent(Student student){
    // TODO: 实现优秀标准的判断逻辑
    double overall_score = student.academic_score * 70 + student.activity_score * 30;
    if(overall_score < 8000)
        return false;
    if(student.academic_score + student.activity_score <= 140.0)
        return false;
    return true; //true 代表学生优秀
}

































































































































































































//主函数用于读入数据调用函数，请勿修改
int main(){
    int n;
    cin >> n;
    Student student;
    for(int i=1;i<=n;i++){
        cin >> student.id >> student.academic_score >> student.activity_score;
        if (isExcellent(student)) cout << "Excellent\n";
        else cout << "Not excellent\n";
    }
    return 0;
}

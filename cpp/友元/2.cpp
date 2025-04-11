#include <iostream>

class Student;

class School
{
public:
    void checkStudent(const Student &s);
};

class Student
{
private:
    int score;

public:
    Student(int s) : score(s) {}

    // 声明School类的成员函数为友元
    friend void School::checkStudent(const Student &s);
};

void School::checkStudent(const Student &s)
{
    if (s.score >= 60)
    {
        std::cout << "Pass!" << std::endl;
    }
    else
    {
        std::cout << "Fail!" << std::endl;
    }
}

int main()
{
    Student s(75);
    School school;
    school.checkStudent(s); // 输出：Pass!
    return 0;
}
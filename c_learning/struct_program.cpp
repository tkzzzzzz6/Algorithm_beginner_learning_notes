
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100

// 移除 using namespace std;，因为这是C++特性，而我们使用的是C

/*
结构体数组的基本操作实现
增删改查外加排序
*/
struct stu1
{
    char name[20];
    int age;
    int score;
};

/*
菜单的制作
*/
void makemenu()
{
    time_t now;
    struct tm *local_time;
    char time_str[80];

    time(&now);
    local_time = localtime(&now);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local_time);

    printf("****************************\n");
    printf("**********学生信息管理系统**********\n");
    printf("**********当前时间：%s**********\n", time_str);
    printf("**********1.添加学生信息**********\n");
    printf("**********2.删除学生信息**********\n");
    printf("**********3.修改学生信息**********\n");
    printf("**********4.查询学生信息**********\n");
    printf("**********5.排序学生信息**********\n");
    printf("**********6.退出系统**********\n");
    printf("****************************\n");
}


// 函数声明
void insert_stu(struct stu1 stu[], int *cursize);
void delete_stu(struct stu1 stu[], int *cursize);
void modify_stu(struct stu1 stu[], int cursize);
void search_stu(struct stu1 stu[], int cursize);
void sort_stu(struct stu1 stu[], int cursize);
void print_stu(struct stu1 stu[], int cursize);

/*
执行按键操作
*/
void ketdown(struct stu1 stu[], int *cursize)
{
    int use_key = 0;
    if (scanf("%d", &use_key) != 1) {
        // 清除输入缓冲区
        while (getchar() != '\n');
        printf("输入错误，请输入一个数字\n");
        return;
    }
    
    switch (use_key)
    { 
    case 1:
        printf("添加学生信息\n");
        printf("示例：张三 18 95\n");
        printf("请按照示例格式输入学生信息（姓名 年龄 成绩）：\n");
        insert_stu(stu, cursize);
        break;
    case 2:
        printf("删除学生信息\n");
        printf("示例：张三 18 95\n");
        printf("请按照示例格式输入要删除的学生信息（姓名 年龄 成绩）：\n");
        delete_stu(stu, cursize);
        break;
    case 3:
        printf("修改学生信息\n");
        printf("示例：张三\n");
        printf("请输入要修改的学生姓名：\n");
        modify_stu(stu, *cursize);
        break;
    case 4:
        printf("查询学生信息\n");
        printf("示例：张三\n");
        printf("请输入要查询的学生姓名：\n");
        search_stu(stu, *cursize);
        break;
    case 5:
        printf("排序学生信息\n");
        sort_stu(stu, *cursize);
        break;
    case 6:
        printf("退出系统\n");
        exit(0);
    default:
        printf("输入错误，请重新输入\n");
    }
}

/*
结构体的数组的操作
*/
void print_stu(struct stu1 stu[], int cursize){
    for(int i = 0; i < cursize; i++){
        printf("学生信息：%s\t %d\t %d \n", stu[i].name, stu[i].age, stu[i].score);
    }
}

void insert_stu(struct stu1 stu[], int *cursize){
    if(*cursize >= MAXN){
        printf("学生信息已满，无法添加\n");
        return;
    }
    scanf("%s %d %d", stu[*cursize].name, &stu[*cursize].age, &stu[*cursize].score);
    (*cursize)++;
    printf("添加成功\n");
}

void delete_stu(struct stu1 stu[], int *cursize){
    if(*cursize <= 0){
        printf("学生信息为空，无法删除\n");
        return;
    }
    char name[20];
    int age, score;
    scanf("%s %d %d", name, &age, &score);

    for(int i = 0; i < *cursize; i++){
        if(strcmp(stu[i].name, name) == 0 && stu[i].age == age && stu[i].score == score){
            for(int j = i; j < *cursize - 1; j++){
                stu[j] = stu[j + 1];
            }
            (*cursize)--;
            printf("删除成功\n");
            return;
        }
    }
    printf("删除失败，未找到匹配的学生信息\n");
}

void modify_stu(struct stu1 stu[], int cursize){
    if(cursize <= 0){
        printf("学生信息为空，无法修改\n");
        return;
    }
    char name[20];
    scanf("%s", name);
    
    for(int i = 0; i < cursize; i++){
        if(strcmp(stu[i].name, name) == 0){
            printf("已找到学生信息，请输入新的学生信息\n");
            printf("示例：18 95\n");
            printf("请按照示例格式输入新的学生信息（年龄 成绩）：\n");
            scanf("%d %d", &stu[i].age, &stu[i].score);
            printf("修改成功\n");
            return;
        }
    }
    printf("修改失败，未找到匹配的学生信息\n");
}

void search_stu(struct stu1 stu[], int cursize){
    if(cursize <= 0){
        printf("学生信息为空，无法查询\n");
        return;
    }
    char name[20];
    scanf("%s", name);
    
    for(int i = 0; i < cursize; i++){
        if(strcmp(stu[i].name, name) == 0){
            printf("学生信息：%s\t %d\t %d \n", stu[i].name, stu[i].age, stu[i].score);
            return;
        }
    }
    printf("查询失败，未找到匹配的学生信息\n");
}

void sort_stu(struct stu1 stu[], int cursize){
    if(cursize <= 0){
        printf("学生信息为空，无法排序\n");
        return;
    }
    // 按照成绩从高到低排序
    for(int i = 0; i < cursize - 1; i++){
        for(int j = 0; j < cursize - 1 - i; j++){
            if(stu[j].score < stu[j+1].score){
                struct stu1 temp = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = temp;
            }
        }
    }
    printf("排序完成，按成绩从高到低排序：\n");
    print_stu(stu, cursize);
}


int main()
{
    struct stu1 stu[MAXN]; // 存储所有学生的信息
    int cursize = 0;       // 当前学生数量

    while(1){
        makemenu();
        ketdown(stu, &cursize);
        printf("按Enter键继续...\n");
        while (getchar() != '\n'); // 清除输入缓冲区
        getchar(); // 等待用户按Enter键
        system("cls");
    }
    return 0;
}

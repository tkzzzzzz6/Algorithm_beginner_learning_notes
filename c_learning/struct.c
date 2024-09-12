#include <stdio.h>

// // 1.结构体的定义
// struct Student {
//     int id;
//     char name[20];
//     int age;
// };

// //2.结构体的声明和初始化

// //可以在定义时直接声明
// struct Student stu1 = {1001, "张三", 20};

// //也可以定义后再后续声明
// struct Student stu2;
// stu2 = (struct Student){1002, "李四", 20};

// //访问结构体成员
// printf("学生1的ID: %d\n", stu1.id);

// //结构体指针
// struct Student *pStu = &stu1;
// //通过指针访问结构体中的成员
// printf("学生1的ID: %d\n", pStu->id);

// //创建结构体数组
// struct Student stuArray[3];

// //结构体嵌套
// struct Address {
//     char city[20];
//     char street[30];
//     int zipCode;
// };

// struct Student {
//     int id;
//     char name[20];
//     int age;
//     struct Address addr;
// };

// //结构体作为参数传递到函数
// void printStudent(struct Student stu) {
//     printf("学生ID: %d\n", stu.id);
//     printf("学生姓名: %s\n", stu.name);
//     printf("学生年龄: %d\n", stu.age);
//     printf("学生地址: %s\n", stu.addr.city);
// }

// //更加高效的是传递结构体的指针
// //因为上面的操作是直接复制的结构体,采用指针的话,只是复制了指针的地址,效率更高
// //并且采用指针的话,可以修改结构体中的成员
// void printStudent(struct Student *pStu) {
//     printf("学生ID: %d\n", pStu->id);
//     printf("学生姓名: %s\n", pStu->name);
//     printf("学生年龄: %d\n", pStu->age);
//     printf("学生地址: %s\n", pStu->addr.city);
// }

// //结构体的内存对齐

// typedef struct LNod*List{    
//     ElementType data[MAXSIZE];
//     int last;
// };
// struct LNode L;
// List PtrL;

// //访问下标的元素
// L.data[i]
// PtrL->data[i]

// //初始化
// List MakeEmpty(){
//     List PtrL;
//     PtrL = (List)malloc(sizeof(struct LNode));
//     PtrL->last = -1;
//     return PtrL;
// }

// //查找
// int Find(ElementType X, List PtrL){
//     int i = 0;
//     while(i <= PtrL->last && PtrL->data[i] != X)
//         i++;
//     if(i > PtrL->last) return -1;
//     else return i;
// }

// //插入
// void Insert(ElementType X, int i, List PtrL){
//     int j;

//     if(Ptrl->last == MAXSIZE - 1){
//         printf("表满")
//     }

//     if (i<1 || i > Ptrl->last +2){
//         printf("位置不合法")
//     }

//     for (j = Ptrl->last; j >= i - 1;j--){
//         Ptrl->data[j + 1] = Ptrl->data[j];
//     Ptrl->data[i - 1] = X;
//     Ptrl->last++;
//     return;
//     }
// }

// void Delete(int i, List PtrL){
//     int j;
//     if(i < 1 || i > Ptrl->last + 1){
//         printf("位置不合法") return;
//     }

//     for (j = i; j <= Ptrl->last;j++){
//         Ptrl->data[j - 1] = Ptrl->data[j];
//     }
//     Ptrl->last--;
//     return;
// }

typedef struct student{
    string name;
    int age;
    string hobby;
} stu1;

int main(){
    stu1 arrstu[4];
    arrstu[0] = {"张三", 20, "篮球"};
    arrstu[1] = {"李四", 21, "足球"};
    arrstu[2] = {"王五", 22, "乒乓球"};

    for (int i = 0; i < 3;i++){
        printf("学生的姓名:%s\n", arrstu[i].name);
        printf("学生的年龄:%d\n", arrstu[i].age);
        printf("学生的爱好:%s\n", arrstu[i].hobby);
    }
}
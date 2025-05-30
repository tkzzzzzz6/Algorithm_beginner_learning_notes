#include <iostream>
#include <string>

// 基类Entity，定义了一个虚函数GetName()
class Entity
{
public:
    // 虚函数，返回一个默认的实体名称
    // 使用virtual关键字，允许派生类重写
    virtual std::string GetName() { return "Entity"; }
};

// 派生类Player，继承自Entity
class Player : public Entity
{
private:
    // 私有成员，存储玩家名称
    std::string m_Name;

public:
    // 构造函数，使用传入的名称初始化玩家
    Player(const std::string &name) : m_Name(name) {};

    // 重写基类的GetName()虚函数
    // override关键字确保正确重写基类虚函数
    std::string GetName() override { return m_Name; };

    // 设置玩家名称的成员函数
    void SetName(std::string name) { m_Name = name; };
};

// 打印实体名称的函数
// 接受一个Entity指针作为参数，体现了多态性
void PrintName(Entity *entity)
{
    // 调用虚函数GetName()，实际执行的是对象的具体实现
    std::cout << entity->GetName() << std::endl;
};

int main()
{
    // 创建一个基类Entity对象的指针
    Entity *e = new Entity();
    // 调用PrintName()，将打印"Entity"
    PrintName(e);

    // 创建一个Player对象，名称为"tanke"
    Player *p = new Player("tanke");
    // 调用PrintName()，将打印"tanke"
    PrintName(p);

    // 修改Player对象的名称为"wangjie"
    p->SetName("wangjie");

    // 将Player指针赋值给基类指针，体现了多态性
    Entity *e1 = p;
    // 调用PrintName()，将打印"wangjie"
    PrintName(p);

    // 等待用户输入，保持窗口打开
    std::cin.get();

    return 0;
}
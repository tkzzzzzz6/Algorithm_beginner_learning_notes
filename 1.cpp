#include <iostream>
using namespace std;

// 前向声明
class NoblePhantasm;
class Servant;
class Battle;

// 声明战斗类
class Battle
{
public:
    static void startBattle(Servant &s1, Servant &s2);
};

// 声明英灵类
class Servant
{
public:
    Servant(char *name, char *class_type, int strength);

    // 非成员函数声明为友元
    friend void compareStrength(const Servant &s1, const Servant &s2);

    // 成员函数声明为友元
    friend void Battle::startBattle(Servant &s1, Servant &s2);

    void show(NoblePhantasm *np);

private:
    char *m_name;       // 英灵名称
    char *m_class_type; // 英灵职阶
    int m_strength;     // 英灵强度
};

// 声明宝具类
class NoblePhantasm
{
public:
    NoblePhantasm(char *name, char *rank, char *type);

    // 将英灵类声明为宝具类的友元类
    friend class Servant;

private:
    char *m_name; // 宝具名称
    char *m_rank; // 宝具等级
    char *m_type; // 宝具类型
};

// 实现英灵类
Servant::Servant(char *name, char *class_type, int strength)
    : m_name(name), m_class_type(class_type), m_strength(strength) {}

void Servant::show(NoblePhantasm *np)
{
    cout << "英灵：" << m_name << "，职阶：" << m_class_type << "，强度：" << m_strength << endl;
    cout << "宝具：" << np->m_name << "，等级：" << np->m_rank << "，类型：" << np->m_type << endl;
}

// 实现宝具类
NoblePhantasm::NoblePhantasm(char *name, char *rank, char *type)
{
    m_name = name;
    m_rank = rank;
    m_type = type;
}

// 非成员函数作为友元：比较两个英灵的强度
void compareStrength(const Servant &s1, const Servant &s2)
{
    if (s1.m_strength > s2.m_strength)
    {
        cout << s1.m_name << " 的强度 (" << s1.m_strength << ") 高于 " << s2.m_name << " 的强度 (" << s2.m_strength << ")" << endl;
    }
    else if (s1.m_strength < s2.m_strength)
    {
        cout << s2.m_name << " 的强度 (" << s2.m_strength << ") 高于 " << s1.m_name << " 的强度 (" << s1.m_strength << ")" << endl;
    }
    else
    {
        cout << s1.m_name << " 和 " << s2.m_name << " 的强度相同 (" << s1.m_strength << ")" << endl;
    }
}

// 成员函数作为友元：模拟战斗
void Battle::startBattle(Servant &s1, Servant &s2)
{
    cout << "战斗开始：" << s1.m_name << " vs " << s2.m_name << endl;
    if (s1.m_strength > s2.m_strength)
    {
        cout << s1.m_name << " 获胜！" << endl;
    }
    else if (s1.m_strength < s2.m_strength)
    {
        cout << s2.m_name << " 获胜！" << endl;
    }
    else
    {
        cout << "平局！" << endl;
    }
}

int main()
{
    // 创建英灵和宝具实例
    Servant saber((char *)"阿尔托莉雅", (char *)"Saber", 90);
    NoblePhantasm excalibur((char *)"誓约胜利之剑", (char *)"EX", (char *)"对军宝具");
    saber.show(&excalibur);

    Servant archer((char *)"卫宫", (char *)"Archer", 85);
    NoblePhantasm ubw((char *)"无限剑制", (char *)"E~A++", (char *)"现实宝具");
    archer.show(&ubw);

    Servant rider((char *)"美杜莎", (char *)"Rider", 88);
    NoblePhantasm bellerophon((char *)"波塞冬之子", (char *)"A++", (char *)"对城宝具");
    rider.show(&bellerophon);

    Servant lancer((char *)"迪卢木多", (char *)"Lancer", 87);
    NoblePhantasm gae_bolg((char *)"丛云Swift", (char *)"A+++", (char *)"对人宝具");
    lancer.show(&gae_bolg);

    // 使用非成员函数友元比较强度
    compareStrength(saber, archer);
    compareStrength(rider, lancer);

    // 使用成员函数友元模拟战斗
    Battle::startBattle(saber, rider);
    Battle::startBattle(archer, lancer);

    return 0;
}
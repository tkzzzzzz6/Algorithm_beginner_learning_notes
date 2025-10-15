#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

enum WarriorType
{
    DRAGON,
    NINJA,
    ICEMAN,
    LION,
    WOLF
};
enum Color
{
    RED,
    BLUE
};

// 前向声明
class Headquarters;
class City;

class Warrior
{
private:
    int id;
    WarriorType type;
    int health;
    int attack;
    Color color;
    int position; // 0 表示在红色司令部，n+1 表示在蓝色司令部，1~n 表示在城市中
    Headquarters *headquarters;
    int killCount; // 记录该武士杀死敌人的次数

public:
    Warrior(int id, WarriorType type, int health, int attack, Color color, Headquarters *headquarters)
        : id(id), type(type), health(health), attack(attack), color(color), headquarters(headquarters), killCount(0)
    {
        position = 0; // 临时初始值，会在Headquarters中设置
    }

    virtual ~Warrior() {}

    int getId() const { return id; }
    WarriorType getType() const { return type; }
    int getHealth() const { return health; }
    int getAttack() const { return attack; }
    Color getColor() const { return color; }
    int getPosition() const { return position; }
    void setPosition(int pos) { position = pos; }
    int getKillCount() const { return killCount; }

    void increaseHealth(int amount) { health += amount; }
    void decreaseHealth(int amount) { health = max(0, health - amount); }
    void increaseAttack(int amount) { attack += amount; }

    bool isAlive() const { return health > 0; }

    virtual void march()
    {
        if (color == RED)
        {
            position++;
        }
        else
        {
            position--;
        }
    }

    virtual void attack(Warrior *enemy)
    {
        enemy->beAttacked(attack);
        if (!enemy->isAlive())
        {
            killCount++;
        }
    }

    virtual void beAttacked(int damage)
    {
        health -= damage;
    }

    virtual void fightBack(Warrior *enemy)
    {
        int backDamage = attack / 2;
        enemy->beAttacked(backDamage);
    }

    // 返回武士类型的字符串
    string getTypeStr() const
    {
        switch (type)
        {
        case DRAGON:
            return "dragon";
        case NINJA:
            return "ninja";
        case ICEMAN:
            return "iceman";
        case LION:
            return "lion";
        case WOLF:
            return "wolf";
        default:
            return "unknown";
        }
    }

    // 返回武士所属的颜色字符串
    string getColorStr() const
    {
        return (color == RED) ? "red" : "blue";
    }

    // 由子类实现的特殊行为
    virtual void specialAction() {}
    virtual void afterKill(Warrior *enemy) {}
};

// Dragon特有行为
class Dragon : public Warrior
{
public:
    Dragon(int id, int health, int attack, Color color, Headquarters *headquarters)
        : Warrior(id, DRAGON, health, attack, color, headquarters) {}

    // Dragon在主动进攻后会欢呼
    void specialAction() override
    {
        printf("%03d:40 %s dragon %d yelled in city %d\n",
               getPosition() / 60, getColorStr().c_str(), getId(), getPosition());
    }
};

// Ninja特有行为
class Ninja : public Warrior
{
public:
    Ninja(int id, int health, int attack, Color color, Headquarters *headquarters)
        : Warrior(id, NINJA, health, attack, color, headquarters) {}

    // Ninja不会反击
    void fightBack(Warrior *enemy) override {}
};

// Iceman特有行为
class Iceman : public Warrior
{
private:
    int stepCount;

public:
    Iceman(int id, int health, int attack, Color color, Headquarters *headquarters)
        : Warrior(id, ICEMAN, health, attack, color, headquarters), stepCount(0) {}

    // Iceman每前进两步，生命值减少9，攻击力增加20
    void march() override
    {
        Warrior::march();
        stepCount++;
        if (stepCount % 2 == 0)
        {
            if (getHealth() <= 9)
            {
                // 生命值不会低于1
                decreaseHealth(getHealth() - 1);
            }
            else
            {
                decreaseHealth(9);
            }
            increaseAttack(20);
        }
    }
};

// Lion特有行为
class Lion : public Warrior
{
public:
    Lion(int id, int health, int attack, Color color, Headquarters *headquarters)
        : Warrior(id, LION, health, attack, color, headquarters) {}

    // Lion死亡时，生命值转移给对手
    void beAttacked(int damage) override
    {
        int before = getHealth();
        Warrior::beAttacked(damage);
        if (!isAlive())
        {
            // 转移生命值的逻辑在战斗处理中实现
        }
    }
};

// Wolf特有行为
class Wolf : public Warrior
{
public:
    Wolf(int id, int health, int attack, Color color, Headquarters *headquarters)
        : Warrior(id, WOLF, health, attack, color, headquarters) {}

    // Wolf在杀死敌人次数为偶数时，生命值和攻击力翻倍
    void afterKill(Warrior *enemy) override
    {
        if (getKillCount() % 2 == 0 && getKillCount() > 0)
        {
            increaseHealth(getHealth());
            increaseAttack(getAttack());
        }
    }
};

class Headquarters
{
private:
    Color color;
    int elements; // 生命元
    int totalWarriors;
    vector<Warrior *> warriors;
    vector<WarriorType> warriorSequence; // 制造武士的顺序
    int currentSequenceIndex;
    int cityCount; // 城市数量，用于确定蓝色司令部位置

    // 各类武士的初始属性
    vector<int> initialHealth;
    vector<int> initialAttack;

public:
    Headquarters(Color color, int initialElements, int cityCount,
                 vector<int> initHealth, vector<int> initAttack)
        : color(color), elements(initialElements), totalWarriors(0),
          currentSequenceIndex(0), cityCount(cityCount),
          initialHealth(initHealth), initialAttack(initAttack)
    {

        // 设置武士制造顺序
        if (color == RED)
        {
            warriorSequence = {ICEMAN, LION, WOLF, NINJA, DRAGON};
        }
        else
        {
            warriorSequence = {LION, DRAGON, NINJA, ICEMAN, WOLF};
        }
    }

    Color getColor() const { return color; }
    int getElements() const { return elements; }

    bool canMakeWarrior() const
    {
        WarriorType nextType = warriorSequence[currentSequenceIndex];
        return elements >= initialHealth[nextType];
    }

    // 制造下一个武士
    Warrior *produceWarrior()
    {
        if (!canMakeWarrior())
        {
            return nullptr;
        }

        WarriorType type = warriorSequence[currentSequenceIndex];
        int warriorId = ++totalWarriors;
        int health = initialHealth[type];
        int attack = initialAttack[type];

        // 减少生命元
        elements -= health;

        // 更新下一个要制造的武士类型
        currentSequenceIndex = (currentSequenceIndex + 1) % warriorSequence.size();

        Warrior *warrior = nullptr;
        switch (type)
        {
        case DRAGON:
            warrior = new Dragon(warriorId, health, attack, color, this);
            break;
        case NINJA:
            warrior = new Ninja(warriorId, health, attack, color, this);
            break;
        case ICEMAN:
            warrior = new Iceman(warriorId, health, attack, color, this);
            break;
        case LION:
            warrior = new Lion(warriorId, health, attack, color, this);
            break;
        case WOLF:
            warrior = new Wolf(warriorId, health, attack, color, this);
            break;
        }

        // 设置初始位置
        if (color == RED)
        {
            warrior->setPosition(0);
        }
        else
        {
            warrior->setPosition(cityCount + 1);
        }

        warriors.push_back(warrior);
        return warrior;
    }

    void addElements(int count)
    {
        elements += count;
    }

    void reportElements()
    {
        cout << elements << " elements in " << (color == RED ? "red" : "blue") << " headquarter" << endl;
    }

    void decreaseElements(int amount)
    {
        elements -= amount;
    }
};

class City
{
private:
    int id;
    int elements;
    Color flag; // RED, BLUE或-1表示无旗帜
    bool hasFlag;
    Color lastWinner;    // 记录上一次胜利方
    int consecutiveWins; // 记录连续胜利次数

public:
    City(int id) : id(id), elements(0), hasFlag(false), consecutiveWins(0) {}

    int getId() const { return id; }
    int getElements() const { return elements; }

    void produceElements()
    {
        elements += 10;
    }

    void takeAllElements()
    {
        elements = 0;
    }

    void battle(Warrior *red, Warrior *blue, int hour)
    {
        // 战斗逻辑将在Game类中实现
    }

    Color getFlag() const { return flag; }
    bool hasFlag() const { return hasFlag; }

    void updateFlag(Color winner, int hour)
    {
        if (lastWinner == winner)
        {
            consecutiveWins++;
            if (consecutiveWins == 2 && (!hasFlag || flag != winner))
            {
                hasFlag = true;
                flag = winner;
                // 打印旗帜升起事件
                printf("%03d:40 %s flag raised in city %d\n",
                       hour, winner == RED ? "red" : "blue", id);
            }
        }
        else
        {
            lastWinner = winner;
            consecutiveWins = 1;
        }
    }
};

class Game
{
private:
    int M, N, T; // M: 初始生命元, N: 城市数量, T: 结束时间(分钟)
    vector<int> initialHealth;
    vector<int> initialAttack;
    Headquarters *redHQ;
    Headquarters *blueHQ;
    vector<City *> cities;
    map<int, vector<Warrior *>> warriorsInCity; // 每个位置的武士列表
    int redHQEnemyCount = 0;                    // 红方司令部敌人数量
    int blueHQEnemyCount = 0;                   // 蓝方司令部敌人数量
    int currentTime;                            // 当前时间(分钟)
    bool gameOver;

public:
    Game(int M, int N, int T, vector<int> health, vector<int> attack)
        : M(M), N(N), T(T), initialHealth(health), initialAttack(attack),
          currentTime(0), gameOver(false)
    {

        // 创建总部
        redHQ = new Headquarters(RED, M, N, initialHealth, initialAttack);
        blueHQ = new Headquarters(BLUE, M, N, initialHealth, initialAttack);

        // 创建城市
        for (int i = 1; i <= N; i++)
        {
            cities.push_back(new City(i));
        }
    }

    ~Game()
    {
        delete redHQ;
        delete blueHQ;
        for (auto city : cities)
        {
            delete city;
        }
        for (auto warrior : warriorsInCity)
        {
            for (Warrior *w : warrior.second)
            {
                delete w;
            }
        }
    }

    void run()
    {
        while (currentTime <= T && !gameOver)
        {
            // 处理当前时间的事件
            int hour = currentTime / 60;
            int minute = currentTime % 60;

            switch (minute)
            {
            case 0: // 整点：武士诞生
                produceWarriors();
                break;
            case 10: // 10分：武士前进
                warriorsAdvance();
                break;
            case 20: // 20分：城市产生生命元
                citiesProduceElements();
                break;
            case 30: // 30分：武士获取生命元
                warriorsTakeElements();
                break;
            case 40: // 40分：战斗
                battles();
                break;
            case 50: // 50分：总部报告生命元数量
                reportElements();
                break;
            }

            currentTime++;
        }
    }

private:
    void produceWarriors()
    {
        int hour = currentTime / 60;

        // 红方司令部生产武士
        Warrior *redWarrior = redHQ->produceWarrior();
        if (redWarrior)
        {
            printf("%03d:00 red %s %d born\n",
                   hour, redWarrior->getTypeStr().c_str(), redWarrior->getId());
            addWarriorToCity(redWarrior, 0);
        }

        // 蓝方司令部生产武士
        Warrior *blueWarrior = blueHQ->produceWarrior();
        if (blueWarrior)
        {
            printf("%03d:00 blue %s %d born\n",
                   hour, blueWarrior->getTypeStr().c_str(), blueWarrior->getId());
            addWarriorToCity(blueWarrior, N + 1);
        }
    }

    void warriorsAdvance()
    {
        int hour = currentTime / 60;
        map<int, vector<Warrior *>> newPositions;

        // 处理所有位置的武士
        for (int pos = 0; pos <= N + 1; pos++)
        {
            if (!warriorsInCity[pos].empty())
            {
                for (Warrior *warrior : warriorsInCity[pos])
                {
                    int oldPos = warrior->getPosition();

                    // 武士前进
                    warrior->march();
                    int newPos = warrior->getPosition();

                    // 如果到达敌方司令部
                    if ((warrior->getColor() == RED && newPos == N + 1) ||
                        (warrior->getColor() == BLUE && newPos == 0))
                    {
                        printf("%03d:10 %s %s %d reached %s headquarter with %d elements and force %d\n",
                               hour, warrior->getColorStr().c_str(), warrior->getTypeStr().c_str(),
                               warrior->getId(),
                               warrior->getColor() == RED ? "blue" : "red",
                               warrior->getHealth(), warrior->getAttack());

                        // 增加敌方司令部的敌人计数
                        if (warrior->getColor() == RED)
                        {
                            blueHQEnemyCount++;
                            if (blueHQEnemyCount == 2)
                            {
                                printf("%03d:10 blue headquarter was taken\n", hour);
                                gameOver = true;
                            }
                        }
                        else
                        {
                            redHQEnemyCount++;
                            if (redHQEnemyCount == 2)
                            {
                                printf("%03d:10 red headquarter was taken\n", hour);
                                gameOver = true;
                            }
                        }
                    }
                    // 如果在城市间移动
                    else if (oldPos != newPos)
                    {
                        printf("%03d:10 %s %s %d marched to city %d with %d elements and force %d\n",
                               hour, warrior->getColorStr().c_str(), warrior->getTypeStr().c_str(),
                               warrior->getId(), newPos,
                               warrior->getHealth(), warrior->getAttack());
                    }

                    // 将武士添加到新位置列表
                    newPositions[newPos].push_back(warrior);
                }
            }
        }

        // 更新位置列表
        warriorsInCity = newPositions;
    }

    void citiesProduceElements()
    {
        for (auto city : cities)
        {
            city->produceElements();
        }
    }

    void warriorsTakeElements()
    {
        int hour = currentTime / 60;

        // 遍历所有城市
        for (int i = 1; i <= N; i++)
        {
            City *city = cities[i - 1];
            vector<Warrior *> &warriorsHere = warriorsInCity[i];

            // 如果城市只有一个武士，他获取所有生命元
            if (warriorsHere.size() == 1)
            {
                Warrior *warrior = warriorsHere[0];
                int cityElements = city->getElements();
                if (cityElements > 0)
                {
                    // 武士获取生命元并传送到总部
                    if (warrior->getColor() == RED)
                    {
                        redHQ->addElements(cityElements);
                    }
                    else
                    {
                        blueHQ->addElements(cityElements);
                    }

                    printf("%03d:30 %s %s %d earned %d elements for his headquarter\n",
                           hour, warrior->getColorStr().c_str(), warrior->getTypeStr().c_str(),
                           warrior->getId(), cityElements);

                    // 城市生命元清零
                    city->takeAllElements();
                }
            }
        }
    }

    void battles()
    {
        int hour = currentTime / 60;

        // 在每个城市进行战斗
        for (int i = 1; i <= N; i++)
        {
            City *city = cities[i - 1];
            vector<Warrior *> &warriorsHere = warriorsInCity[i];

            // 如果城市有两个武士
            if (warriorsHere.size() == 2)
            {
                Warrior *redWarrior = nullptr;
                Warrior *blueWarrior = nullptr;

                // 确定红蓝双方武士
                for (Warrior *warrior : warriorsHere)
                {
                    if (warrior->getColor() == RED)
                    {
                        redWarrior = warrior;
                    }
                    else
                    {
                        blueWarrior = warrior;
                    }
                }

                if (!redWarrior || !blueWarrior)
                    continue; // 安全检查

                // 确定谁先攻击
                bool redFirst = false;
                if (city->hasFlag())
                {
                    redFirst = (city->getFlag() == RED);
                }
                else
                {
                    redFirst = (i % 2 == 1); // 奇数城市红方先攻
                }

                Warrior *attacker = redFirst ? redWarrior : blueWarrior;
                Warrior *defender = redFirst ? blueWarrior : redWarrior;

                // 记录战前生命值
                int attackerHealthBefore = attacker->getHealth();
                int defenderHealthBefore = defender->getHealth();

                // 打印攻击信息
                printf("%03d:40 %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n",
                       hour, attacker->getColorStr().c_str(), attacker->getTypeStr().c_str(),
                       attacker->getId(), defender->getColorStr().c_str(), defender->getTypeStr().c_str(),
                       defender->getId(), i, attacker->getHealth(), attacker->getAttack());

                // 进行攻击
                attacker->attack(defender);

                // 如果防守方死亡
                if (!defender->isAlive())
                {
                    printf("%03d:40 %s %s %d was killed in city %d\n",
                           hour, defender->getColorStr().c_str(), defender->getTypeStr().c_str(),
                           defender->getId(), i);

                    // 如果是lion死亡，转移生命值给攻击方
                    if (defender->getType() == LION)
                    {
                        attacker->increaseHealth(defenderHealthBefore);
                    }

                    // wolf杀死敌人的特殊处理
                    attacker->afterKill(defender);

                    // 攻击方总部奖励8个生命元
                    if (attacker->getColor() == RED)
                    {
                        if (redHQ->getElements() >= 8)
                        {
                            redHQ->decreaseElements(8);
                            attacker->increaseHealth(8);
                        }
                    }
                    else
                    {
                        if (blueHQ->getElements() >= 8)
                        {
                            blueHQ->decreaseElements(8);
                            attacker->increaseHealth(8);
                        }
                    }

                    // 攻击方获取城市所有生命元
                    int cityElements = city->getElements();
                    if (cityElements > 0)
                    {
                        if (attacker->getColor() == RED)
                        {
                            redHQ->addElements(cityElements);
                        }
                        else
                        {
                            blueHQ->addElements(cityElements);
                        }
                        city->takeAllElements();
                    }

                    // 更新城市旗帜
                    city->updateFlag(attacker->getColor(), hour);

                    // 如果是dragon，则欢呼
                    if (attacker->getType() == DRAGON)
                    {
                        attacker->specialAction();
                    }
                }
                // 如果防守方没死，可能会反击
                else
                {
                    // 如果不是ninja，就会反击
                    if (defender->getType() != NINJA)
                    {
                        printf("%03d:40 %s %s %d fought back against %s %s %d in city %d\n",
                               hour, defender->getColorStr().c_str(), defender->getTypeStr().c_str(),
                               defender->getId(), attacker->getColorStr().c_str(), attacker->getTypeStr().c_str(),
                               attacker->getId(), i);

                        defender->fightBack(attacker);

                        // 如果攻击方被反击死亡
                        if (!attacker->isAlive())
                        {
                            printf("%03d:40 %s %s %d was killed in city %d\n",
                                   hour, attacker->getColorStr().c_str(), attacker->getTypeStr().c_str(),
                                   attacker->getId(), i);

                            // 如果是lion死亡，转移生命值
                            if (attacker->getType() == LION)
                            {
                                defender->increaseHealth(attackerHealthBefore);
                            }

                            // 更新城市旗帜
                            city->updateFlag(defender->getColor(), hour);
                        }
                        // 如果都没死，是平局
                        else
                        {
                            // 平局时城市不会改变旗帜，生命元也不会被拿走
                        }
                    }
                    // ninja不反击
                    else
                    {
                        // 如果是dragon，则欢呼
                        if (attacker->getType() == DRAGON)
                        {
                            attacker->specialAction();
                        }
                    }
                }

                // 移除死亡的武士
                vector<Warrior *> survivors;
                for (Warrior *warrior : warriorsHere)
                {
                    if (warrior->isAlive())
                    {
                        survivors.push_back(warrior);
                    }
                    else
                    {
                        // 从warriors全局列表中移除
                        auto it = find(warriorsInCity[i].begin(), warriorsInCity[i].end(), warrior);
                        if (it != warriorsInCity[i].end())
                        {
                            warriorsInCity[i].erase(it);
                        }
                        delete warrior;
                    }
                }
                warriorsInCity[i] = survivors;
            }
        }
    }

    void reportElements()
    {
        int hour = currentTime / 60;
        printf("%03d:50 ", hour);
        redHQ->reportElements();
        printf("%03d:50 ", hour);
        blueHQ->reportElements();
    }

    // 辅助函数：将武士添加到城市列表
    void addWarriorToCity(Warrior *warrior, int position)
    {
        warriorsInCity[position].push_back(warrior);
    }
};

int main()
{
    int caseCount;
    cin >> caseCount;

    for (int caseNum = 1; caseNum <= caseCount; caseNum++)
    {
        int M, N, T;
        cin >> M >> N >> T;

        vector<int> initialHealth(5);
        vector<int> initialAttack(5);

        for (int i = 0; i < 5; i++)
        {
            cin >> initialHealth[i];
        }

        for (int i = 0; i < 5; i++)
        {
            cin >> initialAttack[i];
        }

        cout << "Case:" << caseNum << endl;

        Game game(M, N, T, initialHealth, initialAttack);
        game.run();
    }

    return 0;
}

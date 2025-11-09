#include <iostream>
using namespace std;

/**
 * 根据魔法来袭的方向确定躲避的方向
 *
 * @param direction 魔法来袭的方向 ('U', 'D', 'L', 或 'R')
 * @return 躲避的方向 ('U', 'D', 'L', 或 'R')
 */
char dodgeMagic(char direction)
{
    // 如果魔法从上方或下方来袭，向左或右躲避
    if (direction == 'U' || direction == 'D')
    {
        return 'L'; // 可以选择 'L' 或 'R'
    }
    // 如果魔法从左侧或右侧来袭，向上或下躲避
    else
    {               // direction == 'L' || direction == 'R'
        return 'U'; // 可以选择 'U' 或 'D'
    }
}

int main()
{
    char magicDirection;

    // 读取输入
    cin >> magicDirection;

    // 计算并输出躲避方向
    char dodgeDirection = dodgeMagic(magicDirection);
    cout << dodgeDirection << endl;

    return 0;
}

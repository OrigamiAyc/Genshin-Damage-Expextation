/**
 * @file DamageExpection.cpp
 * @author OrigamiAyc
 * @brief 用于粗略估计原神伤害期望
 * @version 0.1
 * @date 2022-03-13
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * 默认如蒸发、钟离盾等深渊buff常驻生效以控制变量
 * 若是宗室4、教官4、讨龙、苍古、终末、点赞、赌狗等非常驻buff需要标记其覆盖率
 * 设暴击率、暴击伤害和暴击时伤害分别为 a, b, x
 * 则期望伤害为 (1+ab)/(1+b)*x
 */

#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    float CRIT_Rate, CRIT_DMG, DMG_CRIT, buffed_CRIT, buff_percentage;
    float CRIT_coefficient, avg_DMG;
    char choice;

    cout << "输入暴击率和暴击伤害" << endl;
    cin >> CRIT_Rate >> CRIT_DMG;
    cout << "是否有非全覆盖buff，如流浪乐章（Y/N）：" << endl;
    CRIT_coefficient = (1 + CRIT_Rate * CRIT_DMG) / (1 + CRIT_DMG);

    cin >> choice;
    switch (choice)
    {
    case 'Y':
        cout << "输入有buff时伤害、无buff时伤害和buff覆盖率：" << endl;
        cin >> buffed_CRIT >> DMG_CRIT >> buff_percentage;
        avg_DMG = buff_percentage * buffed_CRIT + (1 - buff_percentage) * DMG_CRIT;
        break;
    case 'N':
        cout << "输入暴击时伤害" << endl;
        cin >> avg_DMG;
        break;
    default:
        cout << "爬吧" << endl;
        exit(1);
    }
    cout<<"期望伤害为：" << CRIT_coefficient * avg_DMG << endl;
    return 0;
}

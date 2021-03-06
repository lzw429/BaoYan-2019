/*
 * 题目背景

　　小明是汉东省政法大学附属中学的一名学生，他每天都要骑自行车往返于家和学校。为了能尽可能充足地睡眠，他希望能够预计自己上学所需要的时间。他上学需要经过数段道路，相邻两段道路之间设有至多一盏红绿灯。
　　京州市的红绿灯是这样工作的：每盏红绿灯有红、黄、绿三盏灯和一个能够显示倒计时的显示牌。假设红绿灯被设定为红灯 r 秒，黄灯 y 秒，绿灯 g 秒，那么从 0 时刻起，[0,r) 秒内亮红灯，车辆不许通过；[r, r+g) 秒内亮绿灯，车辆允许通过；[r+g, r+g+y) 秒内亮黄灯，车辆不许通过，然后依次循环。倒计时的显示牌上显示的数字 l（l > 0）是指距离下一次信号灯变化的秒数。

问题描述

　　一次上学的路上，小明记录下了经过每段路的时间，和各个红绿灯在小明到达路口时的颜色和倒计时秒数。希望你帮忙计算此次小明上学所用的时间。

输入格式

　　输入的第一行包含空格分隔的三个正整数 r、y、g，表示红绿灯的设置。这三个数均不超过 106。
　　输入的第二行包含一个正整数 n（n ≤ 100），表示小明总共经过的道路段数和看到的红绿灯数目。
　　接下来的 n 行，每行包含空格分隔的两个整数 k、t。k=0 表示经过了一段道路，耗时 t 秒，此处 t 不超过 106；k=1、2、3 时，分别表示看到了一个红灯、黄灯、绿灯，且倒计时显示牌上显示的数字是 t，此处 t 分别不会超过 r、y、g。

输出格式

　　输出一个数字，表示此次小明上学所用的时间。

样例输入

30 3 30
8
0 10
1 5
0 11
2 2
0 6
0 3
3 10
0 3

样例输出

70

样例说明

　　小明先经过第一段道路，用时 10 秒，然后等待 5 秒的红灯，再经过第二段道路，用时 11 秒，然后等待 2 秒的黄灯和 30 秒的红灯，再经过第三段、第四段道路，分别用时6、3秒，然后通过绿灯，再经过最后一段道路，用时 3 秒。共计 10 + 5 + 11 + 2 + 30 + 6 + 3 + 3=70 秒。

评测用例规模与约定

　　测试点 1, 2 中不存在任何信号灯。
　　测试点 3, 4 中所有的信号灯在被观察时均为绿灯。
　　测试点 5, 6 中所有的信号灯在被观察时均为红灯。
　　测试点 7, 8 中所有的信号灯在被观察时均为黄灯。
　　测试点 9, 10 中将出现各种可能的情况。
 */

/*
 * 本题需要计算通过道路的总时间
 * 1. 在道路上的行驶时间应该直接加上
 * 2. 遇到红灯，需要等待相应的时长，然后转换到绿灯通行
 * 3. 遇到绿灯，直接通过，不影响时间
 * 4. 遇到黄灯，需要等待相应的时长，然后转换到红灯，继续等待整个红灯时长，直到转换为绿灯
 */

#include <iostream>

using namespace std;

int r, y, g; // 红灯、黄灯、绿灯的时长
int n;       // 道路的数量和看到的红绿灯的数量
int k, t;    // 事件类型和相关时间
int ans = 0;     // 通过所有路段的总时长

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    cin >> r >> y >> g;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> t;
        if (k == 0 || k == 1) { // 行驶 或 遇到红灯，等待相应的时长
            ans += t;
        } else if (k == 2) {    // 遇到黄灯，等待相应的时长，并且等待整个红灯
            ans += t;
            ans += r;
        } else if (k == 3) {    // 遇到绿灯
            continue;
        }
    }
    cout << ans;
    return 0;
}
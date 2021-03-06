/*
样例输入：
11 B A
5 @ W

样例输出：
 AAAAAAAAA
ABBBBBBBBBA
ABAAAAAAABA
ABABBBBBABA
ABABAAABABA
ABABABABABA
ABABAAABABA
ABABBBBBABA
ABAAAAAAABA
ABBBBBBBBBA
 AAAAAAAAA

 @@@
@WWW@
@W@W@
@WWW@
 @@@
*/


// 本题思路：从里层向外层逐层输出，每一层先通过中心点坐标获取左上角的坐标
// 通过边长次数的循环将四边填充，并将四个角置为空格

#include <iostream>

using namespace std;

int main() {
    char outPut[82][82] = {}; // 用于预排版的输出缓存
    char a, b;                // 中心字符和外筐字符
    int n;                    // 外筐尺寸，是奇数
    bool firstCase = true;
    while (cin >> n >> a >> b) {
        if (firstCase)  // 第一个测试样例不输出换行
            firstCase = false;
        else // 从第二个测试样例之后，先输出换行
            cout << endl;

        // 从里到外逐层输出，i 是矩形边长，j 是边界到中心点距离
        for (int i = 1, j = 1; i <= n; i += 2, j++) {
            // 获得中心点的坐标 (x, y)
            int x = n / 2 + 1;
            int y = x;
            // 移动到该层的左上角
            x -= j - 1;
            y -= j - 1;

            // 最内层作为第1层向外数，奇数层填充a，偶数层填充b
            char c = (j % 2 == 1) ? a : b;

            for (int k = 1; k <= i; k++) {
                outPut[x + k - 1][y] = c;         // 左边
                outPut[x][y + k - 1] = c;         // 上边
                outPut[x + i - 1][y + k - 1] = c; // 右边
                outPut[x + k - 1][y + i - 1] = c; // 下边
            }
        }

        // 四角置为空格
        if (n != 1) { // 注意当 n = 1 时不需要
            outPut[1][1] = ' ';
            outPut[n][1] = ' ';
            outPut[1][n] = ' ';
            outPut[n][n] = ' ';
        }

        // 输出
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << outPut[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

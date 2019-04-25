/*
10:�������ӷ�
�鿴 �ύ ͳ�� ����
��ʱ������: 1000ms �ڴ�����: 65536kB
����
������������200λ�ķǸ������ĺ͡�

����
�����У�ÿ����һ��������200λ�ķǸ������������ж����ǰ��0��
���
һ�У�����Ӻ�Ľ��������ﲻ���ж����ǰ��0������������342����ô�Ͳ������Ϊ0342��
��������
22222222222222222222
33333333333333333333
�������
55555555555555555555
��Դ
�������ʵϰ2007
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const int maxlen = 205;

class BigInteger {
public:
    int len;
    int d[maxlen]; // �����λ�洢������λ

    // ��ʼ��
    void init() {
        len = 0;
        memset(d, 0, sizeof(d));
    }
    
    // ���췽��
    BigInteger() {
        init();
    }

    BigInteger(const string &str) { // �ַ����ĵ�λ�����ֵĸ�λ
        init();
        for(int i = str.size(); i >= 0; i--) {
            this->d[len++] = str[i];
        }
    }

    BigInteger operator+(const BigInteger &bigInteger) {
        BigInteger res;
        int carry = 0;
        // �Ӵ�����λ��ʼ���
        for(int i = 0; i < max(this->len, bigInteger.len); i++) {
            int t = d[i] + bigInteger.d[i] + carry;
            res.d[res.len++] = t % 10;
            carry = t / 10;
        }
        if(carry)
            res.d[res.len++] = carry;
        return res;
    }
};

ostream &operator<<(ostream &os, const BigInteger &bigInteger) {
    for(int i = bigInteger.len - 1; i >= 0; i--) {
        os << bigInteger.d[i];
    }
    return os;
}

int main() {
    string a, b;
    cin >> a >> b;

    BigInteger bigInt1(a);
    BigInteger bigInt2(b);
    BigInteger res = a + b;
    cout << res;

    return 0;
}

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


// ����ע��㣺
// 1. �ַ����ĸ�λ�Ǵ����ĵ�λ��ע���ַ�����ѭ�������ķ�Χ
// 2. ��������ֿ�����ǰ��0����������־���0��Ҫ����һλ0

#include "stdafx.h"
#include <iostream>
#include <cstring>

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
        for(int i = str.size() - 1; i >= 0; i--) { // ע��ѭ�������ķ�Χ
            this->d[len++] = str[i] - '0';
        }
        while(len > 1 && d[len - 1] == 0) {
            len--;
        }
    }

    BigInteger operator+(const BigInteger &bigInteger) {
        BigInteger res;
        int carry = 0;
        // �Ӵ�����λ��ʼ���
        for(int i = 0; i < max(this->len, bigInteger.len); i++) { // ע��ѭ�������ķ�Χ
            int t = d[i] + bigInteger.d[i] + carry;
            res.d[res.len++] = t % 10;
            carry = t / 10;
        }
        if(carry) // �������Ľ�λ
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
    BigInteger res = bigInt1 + bigInt2;
    cout << res;

    return 0;
}

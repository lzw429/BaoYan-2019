#include <cstdio>
int main() {
  long long a, b; // ʹ�� long long ȷ���������
  int m;
  while (scanf("%d", &m) != EOF) {
    if (m == 0)
      break;
    scanf("%lld%lld", &a, &b);
    a = a + b; // ���潫 a ת��Ϊ m ����
    int ans[50],
        size =
            0; // ans ���ڱ�������ת���õ��ĸ�����λ���ֵ�ֵ�� size ��ʾ�����
    do {       // ������ø�����λ�ϵ�����ֵ
      ans[size++] = a % m;
      a /= m;
    } while (a != 0); // �� a ��Ϊ 0 ʱ�ظ�
    for (int i = size - 1; i >= 0; i--) {
      printf("%d", ans[i]);
    }             // �����ע��˳��Ϊ�Ӹ�λ����λ
    printf("\n"); // �������
  }
  return 0;
}

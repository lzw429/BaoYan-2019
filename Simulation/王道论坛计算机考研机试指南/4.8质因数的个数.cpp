#include <iostream>
#define MAXN 100010
using namespace std;

bool mark[MAXN]; // ����Ϊ true 
int prime[MAXN];
int primeSize;

void init() // ����ɸ����ɸѡ��2��100000�ڵ��������� 
{
	primeSize = 0;
	for(int i = 2; i <= 100000; i++)
	{
		if(mark[i] == true) continue;
		prime[primeSize++] = i;
		if(i >= 1000) continue;
		for(int j = i * i; j <= 100000; j += i)
		{
			mark[j] = true;
		} 
	}
}

int main() 
{
	init();
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int ansPrime[30] = {}; // ��˳�򱣴�ֽ����������
		int ansSize = 0; // �ֽ��������������
		int ansNum[30] = {}; // ����ֽ������������Ӧ����ָ��
		for(int i = 0; i < primeSize; i++) // ���β������� 
		{
			if(n % prime[i] == 0) // �����������������ֽ���
			{
				ansPrime[ansSize] = prime[i];
				while(n % prime[i] == 0)
				{
					ansNum[ansSize]++;
					n /= prime[i];
				}
				ansSize++;
				if(n == 1) // ���ֽ�Ϊ1 
					break;
			} 
		} 
		if(n != 1) // �������2��100000����������������δ�ֽ⵽1����ʣ���������n�����Ǵ���100000�������� 
		{
			ansPrime[ansSize] = n;
			ansNum[ansSize++] = 1;
		} 
		
		int ans = 0;
		for(int i = 0; i < ansSize; i++)
		{
			ans += ansNum[i];
		}
		cout << ans << endl;
	} 
	return 0;
}

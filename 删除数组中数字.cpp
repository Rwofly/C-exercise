#include<iostream>
using namespace std;
void deleteNumber(int n, int* num);
int m = 10;
int main()
{
	int num[10];
	int n;
	cout << "����һ�����֣�" << endl;
	for (int i = 0;i < m;i++)
	{
		cin >> num[i];
	}
	cout << "������Ҫɾ�������֣�";
	cin >> n;
	deleteNumber(n, num);
	cout << "ɾ��������Ϊ��" << endl;
	for (int i = 0;i < m;i++)
	{
		cout << num[i] << " ";
	}
	return 0;
}
void deleteNumber(int n, int* num)
{
	for (int i = 0;i < m;i++)
	{
		while(num[i] == n)
		{
			for (int j = i;j < m - 1;j++)
			{
				num[j] = num[j + 1];
			}
			m--;
		}
	}
	return;
}
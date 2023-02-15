#include<iostream>
using namespace std;
template<class T>
class Myarray
{
public:
	Myarray()//Ĭ�Ϲ��캯��
	{

	}
	Myarray(int capacity)//�вι��캯��
	{
		this->m_Capacity = capacity;
		this->m_Szie = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	Myarray(const Myarray& arr)//�������캯��
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Szie = arr.m_Szie;
		//this->pAddress = arr.pAddress;ǳ���������׷����ڴ��ظ��ͷ�
		this->pAddress=new T[arr.m_Capacity];//���
		//��arr�е����ݿ�������
		for (int i = 0;i < this->m_Szie;i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=��ֹǳ����������
	Myarray &operator=(const Myarray& arr)
	{
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Szie = 0;
		}
		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Szie = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0;i < this->m_Szie;i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//β�巨
	void Push_Back(const T& val)
	{
		if (this->m_Capacity == this->m_Szie)//�ж������Ƿ���ڴ�С
		{
			cout << "����������" << endl;
			return;
		}
		this->pAddress[this->m_Szie] = val;//����ĩβ��������
		this->m_Szie++;//���������С
	}
	//βɾ��
	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ�ؼ���
		if (this->m_Szie == 0)
		{
			cout << "û�����ݣ�" << endl;
			return;
		}
		this->m_Szie--;
	}
	//ͨ���±�����������е�Ԫ��
	T& operator[](int index)//�������ÿ����޸�����Ԫ��
	{
		return this->pAddress[index];
	}
	//������������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//���������С
	int getSize()
	{
		return this->m_Szie;
	}
private:
	T* pAddress;//ָ��ָ��������ٵ���ʵ����
	int m_Capacity;//��������
	int m_Szie;//�����С
};
//�Զ�����������
class Person
{
public:
	Person()
	{

	}
	Person(string name, int age)
	{
		m_age = age;
		m_name = name;
	}
	void show()
	{
		cout << "������" << m_name << " " << "���䣺" << m_age << endl;
	}
private:
	int m_age;
	string m_name;
};
int main()
{
	Myarray<int> arr1(5);
	for (int i = 0;i < 5;i++)
	{
		//����β�巨�������в�������
		arr1.Push_Back(i);
	}
	cout << "arr1�����Ϊ��" << endl;
	for (int i = 0;i < 5;i++)
	{
		cout << arr1[i] << " ";//�±귽ʽ��������
	}
	cout << endl;
	cout << "arr1������Ϊ��" << arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�СΪ��" << arr1.getSize() << endl;
	//βɾ
	arr1.Pop_Back();
	cout << "����βɾ��" << endl;
	cout << "arr1������Ϊ��" << arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�СΪ��" << arr1.getSize() << endl;
	//��������
	Myarray<int>arr2(arr1);
	cout << "arr2�����Ϊ��" << endl;
	for (int i = 0;i < arr2.getSize();i++)
	{
		cout << arr2[i] << " ";
	}
	cout <<endl<< "�Զ����������͵ĵ��ԣ�" << endl;
	Myarray<Person>arr3(10);
	Person p1("R", 18);
	Person p2("M", 19);
	Person p3("Y", 20);
	//�����ݲ���������
	arr3.Push_Back(p1);
	arr3.Push_Back(p2);
	arr3.Push_Back(p3);
	//�������
	cout << "arr3�����Ϊ��" << endl;
	for (int i = 0;i < arr3.getSize();i++)
	{
		arr3[i].show();
	}
	cout << "arr3������Ϊ��" << arr3.getCapacity() << endl;
	cout << "arr3�Ĵ�СΪ��" << arr3.getSize() << endl;
	return 0;
}
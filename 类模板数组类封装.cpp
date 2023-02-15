#include<iostream>
using namespace std;
template<class T>
class Myarray
{
public:
	Myarray()//默认构造函数
	{

	}
	Myarray(int capacity)//有参构造函数
	{
		this->m_Capacity = capacity;
		this->m_Szie = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	Myarray(const Myarray& arr)//拷贝构造函数
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Szie = arr.m_Szie;
		//this->pAddress = arr.pAddress;浅拷贝，容易发生内存重复释放
		this->pAddress=new T[arr.m_Capacity];//深拷贝
		//将arr中的数据拷贝过来
		for (int i = 0;i < this->m_Szie;i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=防止浅拷贝的问题
	Myarray &operator=(const Myarray& arr)
	{
		//先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Szie = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Szie = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0;i < this->m_Szie;i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插法
	void Push_Back(const T& val)
	{
		if (this->m_Capacity == this->m_Szie)//判断容量是否等于大小
		{
			cout << "容量已满！" << endl;
			return;
		}
		this->pAddress[this->m_Szie] = val;//数组末尾插入数据
		this->m_Szie++;//更新数组大小
	}
	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素即可
		if (this->m_Szie == 0)
		{
			cout << "没有数据！" << endl;
			return;
		}
		this->m_Szie--;
	}
	//通过下标访问数据组中的元素
	T& operator[](int index)//返回引用可以修改数组元素
	{
		return this->pAddress[index];
	}
	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//返回数组大小
	int getSize()
	{
		return this->m_Szie;
	}
private:
	T* pAddress;//指针指向堆区开辟的真实数组
	int m_Capacity;//数组容量
	int m_Szie;//数组大小
};
//自定义数据类型
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
		cout << "姓名：" << m_name << " " << "年龄：" << m_age << endl;
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
		//利用尾插法向数组中插入数据
		arr1.Push_Back(i);
	}
	cout << "arr1的输出为：" << endl;
	for (int i = 0;i < 5;i++)
	{
		cout << arr1[i] << " ";//下标方式访问数据
	}
	cout << endl;
	cout << "arr1的容量为：" << arr1.getCapacity() << endl;
	cout << "arr1的大小为：" << arr1.getSize() << endl;
	//尾删
	arr1.Pop_Back();
	cout << "进行尾删后：" << endl;
	cout << "arr1的容量为：" << arr1.getCapacity() << endl;
	cout << "arr1的大小为：" << arr1.getSize() << endl;
	//拷贝问题
	Myarray<int>arr2(arr1);
	cout << "arr2的输出为：" << endl;
	for (int i = 0;i < arr2.getSize();i++)
	{
		cout << arr2[i] << " ";
	}
	cout <<endl<< "自定义数据类型的调试：" << endl;
	Myarray<Person>arr3(10);
	Person p1("R", 18);
	Person p2("M", 19);
	Person p3("Y", 20);
	//将数据插入数组中
	arr3.Push_Back(p1);
	arr3.Push_Back(p2);
	arr3.Push_Back(p3);
	//输出数组
	cout << "arr3的输出为：" << endl;
	for (int i = 0;i < arr3.getSize();i++)
	{
		arr3[i].show();
	}
	cout << "arr3的容量为：" << arr3.getCapacity() << endl;
	cout << "arr3的大小为：" << arr3.getSize() << endl;
	return 0;
}
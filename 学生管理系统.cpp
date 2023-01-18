#include<iostream>//学生管理系统
#include<string>
using namespace std;
struct Student
{
	string name;//学生姓名
	string stnumber;//学号
	int math=0;//数学成绩
	int english=0;//英语成绩
	int cplus=0;//C++成绩
	struct Student* next=NULL;
};
void add_student(Student* St);//添加学生
void delete_student(Student* St);//删除学生
void sort_score(Student* St);//分数排名
void travel_student(Student* St);//输出全部学生
void alter_student(Student* St);//修改学生信息
void seek_student(Student* St);//查找学生
int menu1();//选项菜单
int menu2();
int main()
{
	int choose;
	Student* St=new Student;
	St->next = NULL;
	choose = menu1();
	while (choose)
	{
		switch (choose)
		{
		case 1:
			add_student(St);
			break;
		case 2:
			delete_student(St);
			break;
		case 3:
			sort_score(St);
			break;
		case 4:
			travel_student(St);
			break;
		case 5:
			alter_student(St);
			break;
		case 6:
			seek_student(St);
			break;
		case 7:
			return 0;
		}
		choose = menu1();
	}
	return 0;
}
void add_student(Student* St)
{
	Student* pVal;
	pVal = St;
	while (pVal->next != NULL)
	{
		pVal = pVal->next;
	}
	Student* pNew = new Student;
	cout << "请输入学生姓名：";
	cin >> pNew->name;
	cout << "请输入学生学号：";
	cin >> pNew->stnumber;
	cout << "请输入学生数学成绩：";
	cin >> pNew->math;
	cout << "请输入学生英语成绩：";
	cin >> pNew->english;
	cout << "请输入C++成绩：";
	cin >> pNew->cplus;
	pVal->next = pNew;
	pNew->next = NULL;
	system("cls");
	return;
}
void delete_student(Student* St)
{
	string studentnum;
	Student* p = St;
	if (p->next == NULL)
	{
		cout << "系统中没有没有学生信息！"<<endl;
		cout << "请添加学生信息！" << endl;
		return;
	}
	cout << "请输入要删除学生的学号：";
	cin >> studentnum;
	while (p!=NULL)
	{
		if (p->next->stnumber== studentnum)
		{
			Student* val = p->next;
			p->next = val->next;
			delete val;
			return;
		}
		if (p->next == NULL)
		{
			cout << "该学生不存在！" << endl;
		}
		p = p->next;
	}
	system("cls");
	return;
}
void travel_student(Student* St)
{
	int count = 0;
	Student* p = St->next;
	if (p == NULL)
	{
		cout << "系统中没有学生信息！" << endl;
		cout << "请添加学生信息！" << endl;
		return;
	}
	while (p != NULL)
	{
		count++;
		cout << "第 " << count << " 位学生：" << endl;
		cout << "学生姓名：" << p->name << endl;
		cout << "学生学号：" << p->stnumber << endl;
		cout << "数学成绩：" << p->math << endl;
		cout << "英语成绩：" << p->english << endl;
		cout << "编程成绩：" << p->cplus << endl;
		p = p->next;
	}
	return;
}
void sort_score(Student* St)
{
	int len=0;
	Student* p = NULL;
	p = St->next;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	Student* m, * n;
	int i, j;
	Student t;
	for (i = 0,m=St->next;i < len - 1;i++,m=m->next)
	{
		for (j = i + 1,n=m->next;j < len;j++,n=n->next)
		{
			if (m->cplus+m->english+m->math<n->cplus+n->english+n->math)
			{
				t.cplus = m->cplus, t.english = m->english, t.math = m->math, t.name = m->name, t.stnumber = m->stnumber;
				m->cplus = n->cplus, m->english = n->english, m->math = n->math, m->name = n->name, m->stnumber = n->stnumber;
				n->cplus = t.cplus, n->english = t.english, n->math = t.math, n->name = t.name, n->stnumber = t.stnumber;

			}
		}
	}
	cout << "排名后的顺序为：" << endl;
	travel_student(St);
	return;
}
void alter_student(Student* St)
{
	string studentnum;
	Student* p = St->next;
	if (p == NULL)
	{
		cout << "系统中没有没有学生信息！" << endl;
		cout << "请添加学生信息！" << endl;
		return;
	}
	cout << "请输入要修改信息学生的学号：";
	cin >> studentnum;
	while (p != NULL)
	{
		if (p->stnumber == studentnum)
		{
			int n;
			n = menu2();
			while (n)
			{
				switch (n)
				{
				case 1:
					cout << "输入修改后的姓名：";
					cin >> p->name;
					break;
				case 2:
					cout << "请输入修改后的学号：";
					cin >> p->stnumber;
					break;
				case 3:
					cout << "请输入修改后的数学成绩：";
					cin >> p->math;
					break;
				case 4:
					cout << "请输入修改后的英语成绩：";
					cin >> p->english;
					break;
				case 5:
					cout << "请输入修改后的编程成绩：";
					cin >> p->cplus;
					break;
				case 6:
					return;
				}
				n = menu2();
			}
			break;
		}
		if (p->next == NULL)
		{
			cout << "该学生不存在！" << endl;
		}
		p = p->next;
	}
	return;
}
int menu1()
{
	int choose;
	cout << "------------学生管理系统------------" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.删除学生" << endl;
	cout << "3.学生排名" << endl;
	cout << "4.输出全部学生" << endl;
	cout << "5.修改学生信息" << endl;
	cout << "6.通过学号查找学生" << endl;
	cout << "7.退出学生管理系统" << endl;
	cout << "-------------------------------------" << endl;
	cout << "输入你的选项（1--7）：";
	cin >> choose;
	system("cls");
	return choose;
}
int menu2()
{
	int n;
	cout << "*************信息修改*************" << endl;
	cout << "1.修改姓名" << endl;
	cout << "2.修改学号" << endl;
	cout << "3.修改数学成绩" << endl;
	cout << "4.修改英语成绩" << endl;
	cout << "5.修改编程成绩" << endl;
	cout << "6.不进行修改" << endl;
	cout << "********************************" << endl;
	cout << "请输入修改选项(1--6):";
	cin >> n;
	system("cls");
	return n;
}
void seek_student(Student* St)
{
	string studentnum;
	Student* p = St;
	if (p->next == NULL)
	{
		cout << "系统中没有没有学生信息！" << endl;
		cout << "请添加学生信息！" << endl;
		return;
	}
	cout << "请输入要查找学生的学号：";
	cin >> studentnum;
	while (p != NULL)
	{
		if (p->stnumber==studentnum)
		{
			cout << "$$$$$$$$$$$$查找结果为$$$$$$$$$$$$" << endl;
			cout << "学生姓名：" << p->name << endl;
			cout << "学生学号：" << p->stnumber << endl;
			cout << "数学成绩：" << p->math << endl;
			cout << "英语成绩：" << p->english << endl;
			cout << "编程成绩：" << p->cplus << endl;
			cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
			return;
		}
		if (p->next == NULL)
		{
			cout << "该学生不存在！" << endl;
		}
		p = p->next;
	}
	system("cls");
	return;
}
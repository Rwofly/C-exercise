#include<iostream>//ѧ������ϵͳ
#include<string>
using namespace std;
struct Student
{
	string name;//ѧ������
	string stnumber;//ѧ��
	int math=0;//��ѧ�ɼ�
	int english=0;//Ӣ��ɼ�
	int cplus=0;//C++�ɼ�
	struct Student* next=NULL;
};
void add_student(Student* St);//���ѧ��
void delete_student(Student* St);//ɾ��ѧ��
void sort_score(Student* St);//��������
void travel_student(Student* St);//���ȫ��ѧ��
void alter_student(Student* St);//�޸�ѧ����Ϣ
void seek_student(Student* St);//����ѧ��
int menu1();//ѡ��˵�
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
	cout << "������ѧ��������";
	cin >> pNew->name;
	cout << "������ѧ��ѧ�ţ�";
	cin >> pNew->stnumber;
	cout << "������ѧ����ѧ�ɼ���";
	cin >> pNew->math;
	cout << "������ѧ��Ӣ��ɼ���";
	cin >> pNew->english;
	cout << "������C++�ɼ���";
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
		cout << "ϵͳ��û��û��ѧ����Ϣ��"<<endl;
		cout << "�����ѧ����Ϣ��" << endl;
		return;
	}
	cout << "������Ҫɾ��ѧ����ѧ�ţ�";
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
			cout << "��ѧ�������ڣ�" << endl;
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
		cout << "ϵͳ��û��ѧ����Ϣ��" << endl;
		cout << "�����ѧ����Ϣ��" << endl;
		return;
	}
	while (p != NULL)
	{
		count++;
		cout << "�� " << count << " λѧ����" << endl;
		cout << "ѧ��������" << p->name << endl;
		cout << "ѧ��ѧ�ţ�" << p->stnumber << endl;
		cout << "��ѧ�ɼ���" << p->math << endl;
		cout << "Ӣ��ɼ���" << p->english << endl;
		cout << "��̳ɼ���" << p->cplus << endl;
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
	cout << "�������˳��Ϊ��" << endl;
	travel_student(St);
	return;
}
void alter_student(Student* St)
{
	string studentnum;
	Student* p = St->next;
	if (p == NULL)
	{
		cout << "ϵͳ��û��û��ѧ����Ϣ��" << endl;
		cout << "�����ѧ����Ϣ��" << endl;
		return;
	}
	cout << "������Ҫ�޸���Ϣѧ����ѧ�ţ�";
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
					cout << "�����޸ĺ��������";
					cin >> p->name;
					break;
				case 2:
					cout << "�������޸ĺ��ѧ�ţ�";
					cin >> p->stnumber;
					break;
				case 3:
					cout << "�������޸ĺ����ѧ�ɼ���";
					cin >> p->math;
					break;
				case 4:
					cout << "�������޸ĺ��Ӣ��ɼ���";
					cin >> p->english;
					break;
				case 5:
					cout << "�������޸ĺ�ı�̳ɼ���";
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
			cout << "��ѧ�������ڣ�" << endl;
		}
		p = p->next;
	}
	return;
}
int menu1()
{
	int choose;
	cout << "------------ѧ������ϵͳ------------" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.ɾ��ѧ��" << endl;
	cout << "3.ѧ������" << endl;
	cout << "4.���ȫ��ѧ��" << endl;
	cout << "5.�޸�ѧ����Ϣ" << endl;
	cout << "6.ͨ��ѧ�Ų���ѧ��" << endl;
	cout << "7.�˳�ѧ������ϵͳ" << endl;
	cout << "-------------------------------------" << endl;
	cout << "�������ѡ�1--7����";
	cin >> choose;
	system("cls");
	return choose;
}
int menu2()
{
	int n;
	cout << "*************��Ϣ�޸�*************" << endl;
	cout << "1.�޸�����" << endl;
	cout << "2.�޸�ѧ��" << endl;
	cout << "3.�޸���ѧ�ɼ�" << endl;
	cout << "4.�޸�Ӣ��ɼ�" << endl;
	cout << "5.�޸ı�̳ɼ�" << endl;
	cout << "6.�������޸�" << endl;
	cout << "********************************" << endl;
	cout << "�������޸�ѡ��(1--6):";
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
		cout << "ϵͳ��û��û��ѧ����Ϣ��" << endl;
		cout << "�����ѧ����Ϣ��" << endl;
		return;
	}
	cout << "������Ҫ����ѧ����ѧ�ţ�";
	cin >> studentnum;
	while (p != NULL)
	{
		if (p->stnumber==studentnum)
		{
			cout << "$$$$$$$$$$$$���ҽ��Ϊ$$$$$$$$$$$$" << endl;
			cout << "ѧ��������" << p->name << endl;
			cout << "ѧ��ѧ�ţ�" << p->stnumber << endl;
			cout << "��ѧ�ɼ���" << p->math << endl;
			cout << "Ӣ��ɼ���" << p->english << endl;
			cout << "��̳ɼ���" << p->cplus << endl;
			cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
			return;
		}
		if (p->next == NULL)
		{
			cout << "��ѧ�������ڣ�" << endl;
		}
		p = p->next;
	}
	system("cls");
	return;
}
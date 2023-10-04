#include <iostream>//������������� 
#include <fstream> //�ļ����� 
#include <cstring>//strcmp�������Ƚ������ַ��� 
#include<string>//atoi
#include<algorithm>
#include<stdlib.h>
#include <conio.h>//��getch();
#include <vector>//vector���� 
#define _CRT_SECURE_NO_DEPRECATE
#define SIZE 10  //���ú궨�壬����char����Ĵ�С 
using namespace std;
//�鲢����
void mergesort(int* a, int left, int right, int* temp)
{
	if (left >= right)return;
	int mid = left + (right - left) / 2;
	mergesort(a, left, mid, temp);
	mergesort(a, mid+1, right, temp);
	int begin1 = left, end1 = mid, begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i] = a[begin1];++begin1;
		}
		else
		{
			temp[i] = a[begin2]; ++begin2;
		}
		++i; 
	}
	//������������һ�����䣬����һ������ʣ�������ֱ�ӷŵ�temp����
	while (begin1 <= end1)
	{
		temp[i] = a[begin1];
		++i; ++begin1;
	}
	while (begin2 <= end2)
	{
		temp[i] = a[begin2];
		++i; ++begin2;
	}
	for (int j = left; j <= right; j++)
	{
		a[j] = temp[j];
	}
}
void mergeact(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	cout << "mergesort" << endl;
	mergesort(a, 0, n - 1, temp);
}
//��������
void quicksort(int* a, int begin, int end)
{
	if (begin >= end)return;
	int left = begin, right = end, key = begin;
	while (begin < end)
	{
		while (a[end] >= a[key] && end > begin)
		{
			--end;
		}
		while (a[begin] <= a[key] && begin < end)
		{
			++begin;
		}
		swap(a[begin], a[end]);
	}
	swap(a[end], a[key]);
	key = end;
	cout << "quicksort" << endl;
	quicksort(a, left, key - 1);
	quicksort(a, key + 1, right);
}
//ϣ������
void shellsort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
		}
	}
}
//������
void adjustdown(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && child + 1 < n)
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void heapsort(int* a, int n)
{
	//�����򣬽����
	//�ӵ�һ����Ҷ�ӽ�㿪ʼ���µ�����һֱ����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		adjustdown(a, n, i);
	}
	int end = n - 1;
	while (end)
	{
		swap(a[0], a[end]);
		adjustdown(a, end, 0);
		end--;
		cout << "heapsort" << endl;
	}
}
//��������
void insertsort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
}
class Goods//Goods�ඨ�� 
{
public:
	Goods() {}//�޲����޳�ֵ�Ĺ��캯�� ,ȱʡ���캯�� 
	char Number[SIZE];//��� 
	char Name[SIZE];//��Ʒ�� 
	int Amount;//���� 
	float Price;//�۸� 
	char Type[SIZE];//��� 
	Goods* Next;//ָ�� 

	vector<Goods> Manage; //vector����Ķ��� 
	friend ostream& operator<<(ostream& out, Goods& obj)//����<<�������� 
	{
		out << obj.Number << obj.Name << obj.Amount << obj.Type;
	}
	friend istream& operator>>(istream& in, Goods& obj)//����>>��������� 
	{
		in >> obj.Number >> obj.Name >> obj.Amount >> obj.Type;
	}
	void SetType()//������Ʒ��� 
	{
		cout << "��ѡ�����ࣺ";	cin >> Type;
	}
	void SetName()//������Ʒ�� 
	{
		cout << "��������Ʒ�����ƣ�"; cin >> Name;
	}
	void SetNumber()//������Ʒ��� 
	{
		cout << "��������Ʒ�ı�ţ�"; cin >> Number;
	}
	void SetPrice()//��������Ʒ�۸� 
	{
		cout << "��������Ʒ���ۣ�"; cin >> Price;
	}
	void ChangeAmount()
	{
		int temp=0;
		cout << "��������Ʒ�仯�Ŀ�棺";
		cin >> temp;
		Amount += temp;
	}
	void SetAmount()//������Ʒ���� 
	{
		cout << "��������Ʒ��棺"; cin >> Amount;
	}
	void SetOther() //������������ 
	{
		cout << "��������Ʒ�۸�"; cin >> Price;
		cout << "��������������"; cin >> Amount;
	}
	void ReadFile(istream& in)//��ȡ�ļ� 
	{
		in >> Name >> Type >> Number >> Price >> Amount;
	}
	void SetAll()//��Ա����  ���ܣ�������Ϣ 
	{
		SetName();
		SetType();
		SetNumber();
		SetOther();
	}
	void Show()//�����Ʒ��Ϣ 
	{
		cout << "��Ʒ��: " << Name << endl << "����:" << Type << endl << "���: " << Number << endl << "�۸� " << Price << endl << "��Ʒ���: " << Amount << endl << endl;
	}
};
Goods* Array[100];
class Manage :public Goods//������ 
{
public:
	Goods* Head, * End;//������Ʒ���ͷ����β�ڵ��ָ�� 
	int i;//��¼��Ʒ����Ŀ 
	int count = 0;
	ifstream in;//���ļ�������Ϣ 
	ofstream out;//�ر��ļ�������Ϣ 
	Manage();//���캯�� 
	~Manage();//�������� 
	void AddGoods();//�����Ʒ��Ϣ 
	void ShowMenu(int n);//��ʾ�˵�������n����switch������ɾ�Ĳ��� 
	void FindGoods();//������Ʒ 
	void SaveGoods();//������Ʒ��Ϣ 
	void ChangeGoods();//�޸���Ʒ���� 
	void DelGoods();//ɾ����Ʒ��Ϣ 
	int ListCount();//������Ʒ����
	void Sell_Buy_Goods();//���ۻ���
	void Display()//��ʾ������Ʒ��Ϣ 
	{
		i = 0;
		for (Goods* goods = Head->Next; goods != End; goods = goods->Next)//��ͷ���ѭ����β�ڵ㣬���ȫ������Ʒ��Ϣ 
		{
			goods->Show(); //���ÿһ�����ĸ�����Ϣ 
			i++;
		}
		cout << "����" << i << "����Ʒ" << "\n" << endl;
		cout << "�����������......" << endl;
		//();
	}
	Goods* FindName(char* Name)//���������� 
	{
		for (Goods* goods = Head; goods->Next != End; goods = goods->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
			if (!strcmp(goods->Next->Name, Name))return goods;
		return NULL;
	}
	Goods* FindNumber(char* Number)//����Ų��� 
	{
		for (Goods* goods = Head; goods->Next != End; goods = goods->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
			if (!strcmp(goods->Next->Number, Number))return goods;
		return NULL;
	}
	Goods* FindType(char* Type)//�����Ͳ��� 
	{
		for (Goods* goods = Head; goods->Next != End; goods = goods->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
			if (!strcmp(goods->Next->Type, Type))return goods;
		return NULL;
	}
	Goods* FindAmount()//������Ŀ����Ҫ������ 
	{
		for (Goods* goods = Head; goods->Next != End; goods = goods->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
			if (goods->Next->Amount<50)return goods;
		return NULL;
	}
	
	void CreateArray()
	{
		int input; 
		cout << "�������� ����1��������� ����2���������� ����3���������� ����4����������" << endl;
		cin >> input;
		for (Goods* goods = Head; goods->Next != NULL; goods = goods->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
		{
			Array[count] = new Goods;
			Array[count] = goods;
			count++;
		}
		int temp_number_1[100];
		int temp_number_2[100];
		int record[100];
		if (input == 4)
		{
			string s_1[100];
			string s_2[100];
			for (int k = 0; k < count; k++)
			{
				string temp;
				temp = Array[k]->Amount;
				s_1[k] = temp;
				s_2[k] = temp;
			}
			sort(s_1, s_1 + count);
			for (int i = count - 1; i > 0; i--)
			{
				for (int j = 0; j < count; j++)
				{
					if (s_1[i] == s_2[j])
					{
						record[i] = j;
						break;
					}
				}
			}
			for (int i = 1; i < count; i++)
			{
				Array[record[i]]->Show();
			}
			return;
		}
		switch (input)
		{
			case 1:
			{
				for (int k = 0; k < count; k++)
				{
					string temp;
					temp = Array[k]->Number;
					temp_number_1[k] = atoi(temp.c_str());
					temp_number_2[k] = atoi(temp.c_str());
				}
			}break;
			case 2:
			{
				for (int k = 0; k < count; k++)
				{
					string temp;
					temp = Array[k]->Type;
					temp_number_1[k] = atoi(temp.c_str());
					temp_number_2[k] = atoi(temp.c_str());
				}
			}break;
			case 3:
			{
				for (int k = 0; k < count; k++)
				{
					string temp;
					temp = Array[k]->Amount;
					temp_number_1[k] = atoi(temp.c_str());
					temp_number_2[k] = atoi(temp.c_str());
				}

			}break;
			
		}
		cout << "selection:3 quicksort:4 shellsort:5 mergesort:6 heapsort:7 ���������԰���Ӧ����" << endl;
		cin >> input;
		switch (input)
		{
			case 3: 
			{
				insertsort(temp_number_1, count);
			}break;
			case 4:
			{
				quicksort(temp_number_1, 0, count - 1);
			}break;
			case 5:
			{
				shellsort(temp_number_1, count);
			}break;
			case 6:
			{
				heapsort(temp_number_1, count);
			}break;
			case 7: 
			{
				mergeact(temp_number_1, count);
			}break;
		}
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (temp_number_1[i] == temp_number_2[j])
				{
					record[i] = j;
					break;
				}
			}
		}
		for (int i = 1; i < count; i++)
		{
			Array[record[i]]->Show();
		}
	}
};
void Manage::AddGoods()//�Ӽ���������Ʒ��Ϣ
{
	ShowMenu(1);//���ò˵����� 
	End->SetName();
	End->SetType();
	do
	{
		End->SetNumber();
	} while (FindNumber(End->Number));//����Ų�Ϊ��ʱ����ÿһ����Ϣ 
	End->SetOther();
	End->Next = new Goods;//�����¿ռ䣬�洢�µ���Ʒ��Ϣ 
	End = End->Next;
	cout << "��ӳɹ�!" << endl;
	SaveGoods();
	cout << "�����������......"<<endl;
	//();
}
Manage::Manage() 	//���캯��������ʵ�� 
{
	Head = new Goods;//����һ���µĽ�㣬��ͷָ��ָ���½�� 
	Head->Next = new Goods;
	End = Head->Next;
	in.open("C:/Users/pqs-xsz-xia/Desktop/lib.txt");//�򿪲ֿ��ļ� 
	if (!in)//�����ʧ�� 
		cout << "û�п��" << endl;
	else
	{
		while (!in.eof())//ѭ������ֿ��ļ��ڵ����ݣ�ֱ����Ϊֹ 
		{
			End->ReadFile(in);
			if (End->Name[0] == '\0')break;//������Ϊ0�ǽ�����ȡ 
			End->Next = new Goods;
			End = End->Next;
		}
		in.close();//�ر��ļ� 
		cout << " ��ȡ��Ʒ��Ϣ�ɹ�!" << endl << endl;
	}
}
void Manage::ShowMenu(int n)//�˵� ��������ͬ���ò�ͬ�Ĳ˵� 
{
	switch (n) //����n�����ò�ͬ�Ĳ˵� 
	{
	case 1:
	{
		break;
	}
	case 2:
	{
		cout << "************************************************************" << endl
			<< "*                   �� �� �� �� �� �� ϵ ͳ                *" << endl
			<< "************************************************************" << endl
			<< "*                      1���� �� �� Ʒ                      *" << endl
			<< "*                      2���� ʾ �� Ʒ                      *" << endl
			<< "*                      3���� �� �� Ʒ                      *" << endl
			<< "*                      4��ɾ �� �� Ʒ                      *" << endl
			<< "*                      5���� �� �� Ʒ                      *" << endl
			<< "*                      6���� �� �� Ʒ                      *" << endl
			<< "*                      7���� Ʒ �� �� �� �� ��             *" << endl
			<< "*                      8���� �� �� ʾ                      *" << endl
			<< "*                      0���� �� ϵ ͳ                      *" << endl
			<< "************************************************************" << endl
			<< endl << "  ��ѡ��(0-7):  ";
		break; }
	case 3:
	{
		cout << "************************************************************" << endl
			<< "*      1���޸���Ʒ��             4���޸ļ۸�               *" << endl
			<< "*      2���޸����               5���޸ı���Ʒ��           *" << endl
			<< "*      3���޸ı��               10���޸�ȫ��               *" << endl
			<< "************************************************************" << endl
			<< endl << "  ��ѡ��:  ";
		break;
	}
	case 5:
	{
		cout << "************************************************************" << endl
			<< "*                     1������Ʒ������                      *" << endl
			<< "*                     2������Ʒ��Ų���                    *" << endl
			<< "*                     3������Ʒ������                    *" << endl
			<< "*                     4����Ҫ��������Ʒ(�涨��ĿС��50)    *" << endl
			<< "************************************************************" << endl
			<< endl << "  ��ѡ��:  ";
		break;
	}
	case 6:
	{
		cout << "************************************************************" << endl
			<< "*                   ���������۵ĸ���Ʒ������                *" << endl
			<< "************************************************************" << endl
			;
		break;
	}
	}
}
Manage::~Manage() //�������� 
{
	for (Goods* temp; Head->Next != End;) //ѭ���������ͷ����е�ָ�� 
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head, End;
}
void Manage::FindGoods() //������Ʒ 
{
	char Name[SIZE], Number[10],Type[20];
	int Input;
	Goods* goods = NULL;//��ʼ��ָ�� 
	ShowMenu(5);//���ò˵� 
	cin >> Input;//���������߱�Ų�ѯ 
	switch (Input)
	{
	case 1: {cout << " ������Ҫ���ҵ���Ʒ�����ƣ�"; cin >> Name;
		if (goods = FindName(Name))
		{
			goods->Next->Show();
			cout << "�����������......" << endl;
			//();
		}
		else {
			cout << " û���ҵ������Ƶ���Ʒ��" << '\n' << endl;
			cout << "�����������......" << endl;
			//();
		}	}break;
	case 2:
	{ 	cout << " ������Ҫ���ҵ���Ʒ�ı�ţ�"; cin >> Number;
	if (goods = FindNumber(Number))
	{
		goods->Next->Show();
		cout << "�����������......" << endl;
		//();
	}
	else {
		cout << " û���ҵ��ñ�ŵ���Ʒ��" << '\n' << endl;
		cout << "�����������......" << endl;
		//();
	}
	}break;
	case 3:
	{ 	cout << " ������Ҫ���ҵ���Ʒ�����"; cin >> Type;
	if (goods = FindType(Type))
	{
		goods->Next->Show();
		cout << "�����������......" << endl;
		//();
	}
	else {
		cout << " û���ҵ��ñ�ŵ���Ʒ��" << '\n' << endl;
		cout << "�����������......" << endl;
		//();
	}
	}break;
	case 4:
	{ 	
	if (goods = FindAmount())
	{
		goods->Next->Show();
		cout << "�����������......" << endl;
		//();
	}
	else {
		cout << " û���ҵ��ñ�ŵ���Ʒ��" << '\n' << endl;
		cout << "�����������......" << endl;
		//();
	}
	}break;
	}
}
void Manage::ChangeGoods() //�޸���Ʒ��Ϣ
{
	ShowMenu(3);//���ò˵� 
	int Input;
	cin >> Input;
	switch (Input)
	{
	case 1:
	{
		char Number[SIZE];
		Goods* goods = NULL;
		cout << " ������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " ���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
			goods->Next->SetName();//��������������浽������ 
			cout << "�޸ĳɹ���" << endl;
			cout << "�����������......" << endl;
			//();
		}
		else {
			cout << "  δ�ҵ�ָ����Ʒ����ȷ�Ϻ����²���!" << endl;
			cout << "�����������......" << endl;
			//();
		}
		break;
	}
	case 2:
	{
		char Number[SIZE];
		Goods* goods = NULL;
		cout << " ������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " ���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
			goods->Next->SetType();//������������浽������ 
			cout << "�޸ĳɹ���" << endl;
			cout << "�����������......" << endl;
			//();
		}
		else {
			cout << " δ�ҵ�ָ����Ʒ����ȷ�Ϻ����²���!" << endl;
			cout << "�����������......" << endl;
			//();
		}	break; }
	case 3:
	{
		char Number[SIZE];
		Goods* goods = NULL;
		cout << " ������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " ���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
			goods->Next->SetNumber();//��������ı�Ŵ浽������ 
			cout << "�޸ĳɹ���" << endl;
			cout << "�����������......" << endl;
			//();
		}
		else {
			cout << " δ�ҵ�ָ����Ʒ����ȷ�Ϻ����²���!" << endl;
			cout << "�����������......" << endl;
			//();
		}	break; }
	case 4:
	{
		char Number[SIZE];
		Goods* goods = NULL;
		cout << " ������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " ���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
			goods->Next->SetPrice();//��������ļ۸�浽������ 
			cout << "�޸ĳɹ���" << endl;
			cout << "�����������......" << endl;
			//();
		}
		else
		{
			cout << " δ�ҵ�ָ����Ʒ����ȷ�Ϻ����²���!" << endl;
			cout << "�����������......" << endl;
			//();
		}
		break;
	}
	case 5:
	{
		char Number[SIZE];
		Goods* goods = NULL;
		cout << " ������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " ���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
			goods->Next->SetAmount();//��������������浽������ 
			cout << "�޸ĳɹ���" << endl;
			cout << "�����������......" << endl;
			//();
		}
		else {
			cout << " δ�ҵ�ָ����Ʒ����ȷ�Ϻ����²���!" << endl;
			cout << "�����������......" << endl;
			_getch();
		}	break;
	}
	}
}
void Manage::DelGoods() // ɾ����Ϣ 
{
	char Number[SIZE];
	Goods* goods = NULL, * temp = NULL;
	cout << " ������Ҫɾ������Ʒ�ı��:" << endl; cin >> Number;
	if (goods = FindNumber(Number))//���� FindNumber�����������ձ�Ų��ң��ҵ������ɾ�� 
	{
		temp = goods->Next;
		goods->Next = goods->Next->Next;
		delete temp;
		cout << " ɾ���ɹ�!" << endl;
		cout << "�����������......" << endl;
		//();
	}
	else
	{
		cout << " δ�ҵ�ָ����Ʒ����ȷ�Ϻ����²���!" << endl;
		cout << "�����������......" << endl;
		//();
	}
}
int Manage::ListCount() //ͳ�Ƶ�ǰ����ļ�¼����������һ������
{
	if (!Head)
		return 0;
	int n = 0;
	for (Goods* goods = Head->Next; goods != End; goods = goods->Next)//�����н����б���������������n��Ϊ���� 
		n++;
	return n;
}
void Manage::SaveGoods() // �������е��ļ�д���ı��ļ��� 
{
	out.open("C:/Users/pqs-xsz-xia/Desktop/lib.txt");
	for (Goods* goods = Head->Next; goods != End; goods = goods->Next)//ѭ��д�� 
		out << goods->Name << " " << goods->Type << " " << goods->Number << " " << goods->Price << " " << goods->Amount << '\n';
	out.close();
	cout << "��Ϣ����ɹ�" << endl;
}
void Manage::Sell_Buy_Goods() //�޸���Ʒ��Ϣ
{
	char Number[SIZE];
	Goods* goods = NULL, * temp = NULL;
	int input = 0;	
	cout << "����1Ϊ����Ʒ��š�����2Ϊ����Ʒ����ȥ���ۻ��� �����룺" << endl;

	cin >> input;
	switch (input)
	{
	case 1:
	{cout << " ������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " ���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
			cout << "***ԭ����Ʒ�����***" << endl;
			goods->Next->Show();
			goods->Next->ChangeAmount();//��������������浽������ 
			cout << "***������Ʒ�����***" << endl;
			goods->Next->Show();
			goods->Next->Show();
			if (goods->Next->Amount == 0)
			{
				temp = goods->Next;
				goods->Next = goods->Next->Next;
				delete temp;
				cout << "��Ϊ��Ʒ���Ϊ0 ����ɾ����Ʒ��Ϊ:" << goods->Name << "��������Ϣ" << endl;
				//();
			}
			cout << "�޸ĳɹ���" << endl;
			cout << "�����������......" << endl;
			//();
		}
		else {
			cout << " δ�ҵ�ָ����Ʒ����ȷ�Ϻ����²���!" << endl;
			cout << "�����������......" << endl;
			_getch();
		}
		break;
	}
	case 2:
	{
		if (goods = FindName(Name))
		{
			cout << " ���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
			cout << "***ԭ����Ʒ�����***" << endl;
			goods->Next->Show();
			goods->Next->ChangeAmount();//��������������浽������ 
			cout << "***������Ʒ�����***" << endl;
			goods->Next->Show();
			cout << "�޸ĳɹ���" << endl;
			cout << "�����������......" << endl;
			//();
			if (goods->Next->Amount == 0)
			{
				temp = goods->Next;
				goods->Next = goods->Next->Next;
				delete temp;
				cout << "��Ϊ��Ʒ���Ϊ0 ����ɾ����Ʒ��Ϊ:" << goods->Name << "��������Ϣ" << endl;
				//();
			}
		}
		else {
			cout << " û���ҵ������Ƶ���Ʒ��" << '\n' << endl;
			cout << "�����������......" << endl;
			//();
		}
	}
	break;
	}
	ShowMenu(6);//���ò˵� 
	
}
int main() //������
{
	Manage G;
	cout<< "\t\t\t��ӭ������Ʒ�ֿ����ϵͳ�������������" << endl << endl ;
	//();
	int Input;
	bool quit = false;
	while (!quit)
	{
		G.ShowMenu(2);
		cin >> Input;
		switch (Input)
		{
		case 0: {quit = true; break; }
		case 1: {G.AddGoods(); break; }
		case 2: {G.Display(); break; }
		case 3: {G.FindGoods(); break; }
		case 4: {G.DelGoods(); break; }
		case 5: {G.ChangeGoods(); break; }
		case 6: {G.SaveGoods(); break; }
		case 7: {G.Sell_Buy_Goods(); break; }
		case 8: {G.CreateArray();  break; }
		}
	}
	return 0;
}


#include <iostream>//基本的输入输出 
#include <fstream> //文件操作 
#include <cstring>//strcmp函数，比较两个字符串 
#include<string>//atoi
#include<algorithm>
#include<stdlib.h>
#include <conio.h>//用getch();
#include <vector>//vector数组 
#define _CRT_SECURE_NO_DEPRECATE
#define SIZE 10  //采用宏定义，定义char数组的大小 
using namespace std;
//归并排序
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
	//当遍历完其中一个区间，将另一个区间剩余的数据直接放到temp后面
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
//快速排序
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
//希尔排序
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
//堆排序
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
	//排升序，建大堆
	//从第一个非叶子结点开始向下调整，一直到根
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
//插入排序
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
class Goods//Goods类定义 
{
public:
	Goods() {}//无参数无初值的构造函数 ,缺省构造函数 
	char Number[SIZE];//编号 
	char Name[SIZE];//商品名 
	int Amount;//数量 
	float Price;//价格 
	char Type[SIZE];//类别 
	Goods* Next;//指针 

	vector<Goods> Manage; //vector数组的定义 
	friend ostream& operator<<(ostream& out, Goods& obj)//重载<<输出运算符 
	{
		out << obj.Number << obj.Name << obj.Amount << obj.Type;
	}
	friend istream& operator>>(istream& in, Goods& obj)//重载>>输入运算符 
	{
		in >> obj.Number >> obj.Name >> obj.Amount >> obj.Type;
	}
	void SetType()//设置商品类别 
	{
		cout << "请选择种类：";	cin >> Type;
	}
	void SetName()//设置商品名 
	{
		cout << "请输入商品的名称："; cin >> Name;
	}
	void SetNumber()//设置商品编号 
	{
		cout << "请输入商品的编号："; cin >> Number;
	}
	void SetPrice()//设置类商品价格 
	{
		cout << "请输入商品单价："; cin >> Price;
	}
	void ChangeAmount()
	{
		int temp=0;
		cout << "请输入商品变化的库存：";
		cin >> temp;
		Amount += temp;
	}
	void SetAmount()//设置商品数量 
	{
		cout << "请输入商品库存："; cin >> Amount;
	}
	void SetOther() //设置其他数据 
	{
		cout << "请输入商品价格："; cin >> Price;
		cout << "请输入存货数量："; cin >> Amount;
	}
	void ReadFile(istream& in)//读取文件 
	{
		in >> Name >> Type >> Number >> Price >> Amount;
	}
	void SetAll()//成员函数  功能：输入信息 
	{
		SetName();
		SetType();
		SetNumber();
		SetOther();
	}
	void Show()//输出商品信息 
	{
		cout << "商品名: " << Name << endl << "种类:" << Type << endl << "编号: " << Number << endl << "价格 " << Price << endl << "商品库存: " << Amount << endl << endl;
	}
};
Goods* Array[100];
class Manage :public Goods//管理类 
{
public:
	Goods* Head, * End;//定义商品类的头结点和尾节点的指针 
	int i;//记录商品总数目 
	int count = 0;
	ifstream in;//打开文件输入信息 
	ofstream out;//关闭文件储存信息 
	Manage();//构造函数 
	~Manage();//析构函数 
	void AddGoods();//添加商品信息 
	void ShowMenu(int n);//显示菜单，参数n用于switch进行增删改查作 
	void FindGoods();//查找商品 
	void SaveGoods();//保存商品信息 
	void ChangeGoods();//修改商品内容 
	void DelGoods();//删除商品信息 
	int ListCount();//计算商品个数
	void Sell_Buy_Goods();//销售货物
	void Display()//显示所有商品信息 
	{
		i = 0;
		for (Goods* goods = Head->Next; goods != End; goods = goods->Next)//从头结点循环到尾节点，输出全部的商品信息 
		{
			goods->Show(); //输出每一个结点的各条信息 
			i++;
		}
		cout << "共有" << i << "个商品" << "\n" << endl;
		cout << "按任意键继续......" << endl;
		//();
	}
	Goods* FindName(char* Name)//按姓名查找 
	{
		for (Goods* goods = Head; goods->Next != End; goods = goods->Next)//匹配成功则返回上一个指针，不成功就返回空
			if (!strcmp(goods->Next->Name, Name))return goods;
		return NULL;
	}
	Goods* FindNumber(char* Number)//按编号查找 
	{
		for (Goods* goods = Head; goods->Next != End; goods = goods->Next)//匹配成功则返回上一个指针，不成功就返回空
			if (!strcmp(goods->Next->Number, Number))return goods;
		return NULL;
	}
	Goods* FindType(char* Type)//按类型查找 
	{
		for (Goods* goods = Head; goods->Next != End; goods = goods->Next)//匹配成功则返回上一个指针，不成功就返回空
			if (!strcmp(goods->Next->Type, Type))return goods;
		return NULL;
	}
	Goods* FindAmount()//查找数目少需要进货的 
	{
		for (Goods* goods = Head; goods->Next != End; goods = goods->Next)//匹配成功则返回上一个指针，不成功就返回空
			if (goods->Next->Amount<50)return goods;
		return NULL;
	}
	
	void CreateArray()
	{
		int input; 
		cout << "输入数字 数字1按编号排序 数字2按类型排序 数字3按数量排序 数字4按名称排序" << endl;
		cin >> input;
		for (Goods* goods = Head; goods->Next != NULL; goods = goods->Next)//匹配成功则返回上一个指针，不成功就返回空
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
		cout << "selection:3 quicksort:4 shellsort:5 mergesort:6 heapsort:7 输入数字以按相应排序" << endl;
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
void Manage::AddGoods()//从键盘输入商品信息
{
	ShowMenu(1);//调用菜单函数 
	End->SetName();
	End->SetType();
	do
	{
		End->SetNumber();
	} while (FindNumber(End->Number));//当编号不为空时输入每一条信息 
	End->SetOther();
	End->Next = new Goods;//开辟新空间，存储新的商品信息 
	End = End->Next;
	cout << "添加成功!" << endl;
	SaveGoods();
	cout << "按任意键继续......"<<endl;
	//();
}
Manage::Manage() 	//构造函数在类外实现 
{
	Head = new Goods;//开辟一个新的结点，让头指针指向新结点 
	Head->Next = new Goods;
	End = Head->Next;
	in.open("C:/Users/pqs-xsz-xia/Desktop/lib.txt");//打开仓库文件 
	if (!in)//如果打开失败 
		cout << "没有库存" << endl;
	else
	{
		while (!in.eof())//循环读入仓库文件内的数据，直到空为止 
		{
			End->ReadFile(in);
			if (End->Name[0] == '\0')break;//当名字为0是结束读取 
			End->Next = new Goods;
			End = End->Next;
		}
		in.close();//关闭文件 
		cout << " 读取商品信息成功!" << endl << endl;
	}
}
void Manage::ShowMenu(int n)//菜单 ，参数不同调用不同的菜单 
{
	switch (n) //根据n来调用不同的菜单 
	{
	case 1:
	{
		break;
	}
	case 2:
	{
		cout << "************************************************************" << endl
			<< "*                   商 店 仓 库 管 理 系 统                *" << endl
			<< "************************************************************" << endl
			<< "*                      1、新 增 商 品                      *" << endl
			<< "*                      2、显 示 商 品                      *" << endl
			<< "*                      3、查 找 商 品                      *" << endl
			<< "*                      4、删 除 商 品                      *" << endl
			<< "*                      5、修 改 商 品                      *" << endl
			<< "*                      6、保 存 商 品                      *" << endl
			<< "*                      7、商 品 销 售 与 进 货             *" << endl
			<< "*                      8、排 序 显 示                      *" << endl
			<< "*                      0、退 出 系 统                      *" << endl
			<< "************************************************************" << endl
			<< endl << "  请选择(0-7):  ";
		break; }
	case 3:
	{
		cout << "************************************************************" << endl
			<< "*      1、修改商品名             4、修改价格               *" << endl
			<< "*      2、修改类别               5、修改编商品量           *" << endl
			<< "*      3、修改编号               10、修改全部               *" << endl
			<< "************************************************************" << endl
			<< endl << "  请选择:  ";
		break;
	}
	case 5:
	{
		cout << "************************************************************" << endl
			<< "*                     1、按商品名查找                      *" << endl
			<< "*                     2、按商品编号查找                    *" << endl
			<< "*                     3、按商品类别查找                    *" << endl
			<< "*                     4、需要进货的商品(规定数目小于50)    *" << endl
			<< "************************************************************" << endl
			<< endl << "  请选择:  ";
		break;
	}
	case 6:
	{
		cout << "************************************************************" << endl
			<< "*                   请输入销售的该物品的数量                *" << endl
			<< "************************************************************" << endl
			;
		break;
	}
	}
}
Manage::~Manage() //析构函数 
{
	for (Goods* temp; Head->Next != End;) //循环遍历，释放所有的指针 
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head, End;
}
void Manage::FindGoods() //查找商品 
{
	char Name[SIZE], Number[10],Type[20];
	int Input;
	Goods* goods = NULL;//初始化指针 
	ShowMenu(5);//调用菜单 
	cin >> Input;//按姓名或者编号查询 
	switch (Input)
	{
	case 1: {cout << " 请输入要查找的商品的名称："; cin >> Name;
		if (goods = FindName(Name))
		{
			goods->Next->Show();
			cout << "按任意键继续......" << endl;
			//();
		}
		else {
			cout << " 没有找到该名称的商品！" << '\n' << endl;
			cout << "按任意键继续......" << endl;
			//();
		}	}break;
	case 2:
	{ 	cout << " 请输入要查找的商品的编号："; cin >> Number;
	if (goods = FindNumber(Number))
	{
		goods->Next->Show();
		cout << "按任意键继续......" << endl;
		//();
	}
	else {
		cout << " 没有找到该编号的商品！" << '\n' << endl;
		cout << "按任意键继续......" << endl;
		//();
	}
	}break;
	case 3:
	{ 	cout << " 请输入要查找的商品的类别："; cin >> Type;
	if (goods = FindType(Type))
	{
		goods->Next->Show();
		cout << "按任意键继续......" << endl;
		//();
	}
	else {
		cout << " 没有找到该编号的商品！" << '\n' << endl;
		cout << "按任意键继续......" << endl;
		//();
	}
	}break;
	case 4:
	{ 	
	if (goods = FindAmount())
	{
		goods->Next->Show();
		cout << "按任意键继续......" << endl;
		//();
	}
	else {
		cout << " 没有找到该编号的商品！" << '\n' << endl;
		cout << "按任意键继续......" << endl;
		//();
	}
	}break;
	}
}
void Manage::ChangeGoods() //修改商品信息
{
	ShowMenu(3);//调用菜单 
	int Input;
	cin >> Input;
	switch (Input)
	{
	case 1:
	{
		char Number[SIZE];
		Goods* goods = NULL;
		cout << " 请输入要修改的商品的编号:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " 已找到商品的信息，请输入新的信息!" << endl;
			goods->Next->SetName();//将新输入的姓名存到磁盘中 
			cout << "修改成功！" << endl;
			cout << "按任意键继续......" << endl;
			//();
		}
		else {
			cout << "  未找到指定商品，请确认后重新查找!" << endl;
			cout << "按任意键继续......" << endl;
			//();
		}
		break;
	}
	case 2:
	{
		char Number[SIZE];
		Goods* goods = NULL;
		cout << " 请输入要修改的商品的编号:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " 已找到商品的信息，请输入新的信息!" << endl;
			goods->Next->SetType();//将新输入的类别存到磁盘中 
			cout << "修改成功！" << endl;
			cout << "按任意键继续......" << endl;
			//();
		}
		else {
			cout << " 未找到指定商品，请确认后重新查找!" << endl;
			cout << "按任意键继续......" << endl;
			//();
		}	break; }
	case 3:
	{
		char Number[SIZE];
		Goods* goods = NULL;
		cout << " 请输入要修改的商品的编号:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " 已找到商品的信息，请输入新的信息!" << endl;
			goods->Next->SetNumber();//将新输入的编号存到磁盘中 
			cout << "修改成功！" << endl;
			cout << "按任意键继续......" << endl;
			//();
		}
		else {
			cout << " 未找到指定商品，请确认后重新查找!" << endl;
			cout << "按任意键继续......" << endl;
			//();
		}	break; }
	case 4:
	{
		char Number[SIZE];
		Goods* goods = NULL;
		cout << " 请输入要修改的商品的编号:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " 已找到商品的信息，请输入新的信息!" << endl;
			goods->Next->SetPrice();//将新输入的价格存到磁盘中 
			cout << "修改成功！" << endl;
			cout << "按任意键继续......" << endl;
			//();
		}
		else
		{
			cout << " 未找到指定商品，请确认后重新查找!" << endl;
			cout << "按任意键继续......" << endl;
			//();
		}
		break;
	}
	case 5:
	{
		char Number[SIZE];
		Goods* goods = NULL;
		cout << " 请输入要修改的商品的编号:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " 已找到商品的信息，请输入新的信息!" << endl;
			goods->Next->SetAmount();//将新输入的数量存到磁盘中 
			cout << "修改成功！" << endl;
			cout << "按任意键继续......" << endl;
			//();
		}
		else {
			cout << " 未找到指定商品，请确认后重新查找!" << endl;
			cout << "按任意键继续......" << endl;
			_getch();
		}	break;
	}
	}
}
void Manage::DelGoods() // 删除信息 
{
	char Number[SIZE];
	Goods* goods = NULL, * temp = NULL;
	cout << " 请输入要删除的商品的编号:" << endl; cin >> Number;
	if (goods = FindNumber(Number))//调用 FindNumber（）函数按照编号查找，找到后进行删除 
	{
		temp = goods->Next;
		goods->Next = goods->Next->Next;
		delete temp;
		cout << " 删除成功!" << endl;
		cout << "按任意键继续......" << endl;
		//();
	}
	else
	{
		cout << " 未找到指定商品，请确认后重新查找!" << endl;
		cout << "按任意键继续......" << endl;
		//();
	}
}
int Manage::ListCount() //统计当前链表的记录总数，返回一个整数
{
	if (!Head)
		return 0;
	int n = 0;
	for (Goods* goods = Head->Next; goods != End; goods = goods->Next)//对所有结点进行遍历，遍历结束后n即为总数 
		n++;
	return n;
}
void Manage::SaveGoods() // 将磁盘中的文件写入文本文件中 
{
	out.open("C:/Users/pqs-xsz-xia/Desktop/lib.txt");
	for (Goods* goods = Head->Next; goods != End; goods = goods->Next)//循环写入 
		out << goods->Name << " " << goods->Type << " " << goods->Number << " " << goods->Price << " " << goods->Amount << '\n';
	out.close();
	cout << "信息保存成功" << endl;
}
void Manage::Sell_Buy_Goods() //修改商品信息
{
	char Number[SIZE];
	Goods* goods = NULL, * temp = NULL;
	int input = 0;	
	cout << "输入1为按商品编号、输入2为按商品名字去销售或购入 请输入：" << endl;

	cin >> input;
	switch (input)
	{
	case 1:
	{cout << " 请输入要修改的商品的编号:"; cin >> Number;
		if (goods = FindNumber(Number))
		{
			cout << " 已找到商品的信息，请输入新的信息!" << endl;
			cout << "***原来商品的情况***" << endl;
			goods->Next->Show();
			goods->Next->ChangeAmount();//将新输入的数量存到磁盘中 
			cout << "***现在商品的情况***" << endl;
			goods->Next->Show();
			goods->Next->Show();
			if (goods->Next->Amount == 0)
			{
				temp = goods->Next;
				goods->Next = goods->Next->Next;
				delete temp;
				cout << "因为商品库存为0 所以删除商品名为:" << goods->Name << "的所有信息" << endl;
				//();
			}
			cout << "修改成功！" << endl;
			cout << "按任意键继续......" << endl;
			//();
		}
		else {
			cout << " 未找到指定商品，请确认后重新查找!" << endl;
			cout << "按任意键继续......" << endl;
			_getch();
		}
		break;
	}
	case 2:
	{
		if (goods = FindName(Name))
		{
			cout << " 已找到商品的信息，请输入新的信息!" << endl;
			cout << "***原来商品的情况***" << endl;
			goods->Next->Show();
			goods->Next->ChangeAmount();//将新输入的数量存到磁盘中 
			cout << "***现在商品的情况***" << endl;
			goods->Next->Show();
			cout << "修改成功！" << endl;
			cout << "按任意键继续......" << endl;
			//();
			if (goods->Next->Amount == 0)
			{
				temp = goods->Next;
				goods->Next = goods->Next->Next;
				delete temp;
				cout << "因为商品库存为0 所以删除商品名为:" << goods->Name << "的所有信息" << endl;
				//();
			}
		}
		else {
			cout << " 没有找到该名称的商品！" << '\n' << endl;
			cout << "按任意键继续......" << endl;
			//();
		}
	}
	break;
	}
	ShowMenu(6);//调用菜单 
	
}
int main() //主函数
{
	Manage G;
	cout<< "\t\t\t欢迎进入商品仓库管理系统，按任意键继续" << endl << endl ;
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


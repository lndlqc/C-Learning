#include <iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "默认构造"<<endl;
	}
	Person(int age,int height): p_age{30}
	{

		p_age = age;
		p_height = new int(height);
		cout << "有参数构造"<<endl;
	}
	Person(const Person &p)
	{
		p_age = p.p_age;
		p_height = new int(*p.p_height);
		
		cout << "change_change";
		cout << "拷贝构造0"<<endl;
	}
	~Person()
	{
		if (p_height != NULL) {
			delete p_height;
		}
		
		cout << "默认析构"<<endl;
	}
	int p_age;
	int *p_height;
	string name;
};


void test()
{
	Person p1(10,160);
	Person p2(p1);
	cout << "p2的age为" << p2.p_age << "p2height为" << *p2.p_height << endl;
	p1.p_age = 11;
	cout << "p2的age为" << p2.p_age << "p2height为" << *p2.p_height << endl;
}
class X
{
public:
	static int count;
	X()
	{
		count++;
	}
	~X()
	{
		count--;
	}
};
int X::count = 0;
int main()
{
	test();

}
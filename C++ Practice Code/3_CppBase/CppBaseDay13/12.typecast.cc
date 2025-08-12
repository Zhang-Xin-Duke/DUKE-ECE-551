#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
	Base(long base)
	: _base(base)
	{}

	virtual void display(){
		cout << "Base::display() " << _base << endl;
	}
    
	long _base;
};

class Derived
: public Base 
{
public:
	Derived(long base,long derived)
	: Base(base)
	, _derived(derived)
	{}
    
	void display2(){
		cout << "Derived::display() " << _derived << endl;
	}
    
	long _derived;
};

void test0(){
    Base base(10);
    Derived d1(2,6);

    /* d1 = base;//error */

    //Base & operator=(const Base & rhs);
    //实参初始化形参的效果实际就是
    //const Base & rhs = d1;
    base = d1;

    //向上转换可以直接进行(派生类向基类称为向上)
    //Derived*转换为Base*的过程
    //pb实际是指向d1对象中的基类子对象
    //也只能访问基类子对象的部分
    Base * pb = &d1;
    pb->display();
    /* pb->display2();//error */

    //此处是Base*希望转换为Derived*,属于向下转换
    //直接进行向下转换会报错
    /* Derived * pd = &base;//error */


    Base & bref = d1;
    /* Derived & dref = base;//error */
}

void test1()
{
    Base base(10);
    Derived d1(2,6);

    Base * pb = &d1;

    //这是一个合理的向下转换,但是不合法
    //虽然不能自动转换，但是可以用上类型转换的方式
    /* Derived * pd = pb; */
    Derived * pd = (Derived*)pb;
    pd->display2();


    //这是一个不合理的向下转换，但仍然能够转换成功
    //后果就是pd2可以去操作非法空间
    Base * pb2 = &base;
    Derived * pd2 = (Derived*)pb2;
    pd2->display2();
}

void test2()
{
    Base base(10);
    Derived d1(2,6);

    //合理的向下转换得到的是有效的指针
    Base * pb = &d1;
    Derived * pd = dynamic_cast<Derived*>(pb);
    pd->display2();


    //不合理的向下转换得到的是空指针
    Base * pb2 = &base;
    Derived * pd2 = dynamic_cast<Derived*>(pb2);
    /* pd2->display2(); */
    if(pd2 == nullptr)
    {
        cout << "不合理的向下转换" << endl;
    }
}



int main(void){

    test2();
    return 0;
}

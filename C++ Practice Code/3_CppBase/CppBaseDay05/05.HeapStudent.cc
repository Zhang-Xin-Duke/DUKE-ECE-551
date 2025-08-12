#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Test
{};

class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	, _name(new char[strlen(name) + 1]())
	{
		strcpy(_name, name);
		cout << "Student(int,const char *)" << endl;
	}
    
    
	void * operator new(size_t sz)
	{
        cout << "operator new" << endl;
		void * ret = malloc(sz);
		return ret;
	}
    
	void operator delete(void * pointer)
	{
        cout << "operator delete" << endl;
		free(pointer);
	}
    
	void print() const
	{
		cout << "id:" << _id << endl
			<< "name:" << _name << endl;
	}

    //粗略的回收方式
    //后续讲解更安全的回收方式
    void destroy()
    {
        delete this;
    }
private:
	~Student()
	{
        cout << "~Student()" << endl;
        if(_name){
            delete [] _name;
            _name = nullptr;
        }
	}

	int _id;
	char * _name;
};

void test0(){
    //对于空类，
    //编译器自动提供默认的operator new/operator delete
    /* Test t1; */
    /* Test * pt = new Test(); */
    
    //创建堆上的对象
    //需要公有的构造函数、operator new 、operator delete
    //对析构函数没有要求
    Student * pstu = new Student(100,"Tom");
    pstu->print();
    pstu->destroy();
    /* delete pstu; */
    pstu = nullptr;

    //如果是一个对象调用成员函数
    //那么编译器会自动获取这个对象的地址值
    //作为this指针提供给成员函数作为第一个参数
    //
    //如果是一个指针调用成员函数
    //那么这个指针本身保存的就是对象的地址值
    //编译器复制这个地址值作为this指针

}

int main(void){
    test0();
    return 0;
}

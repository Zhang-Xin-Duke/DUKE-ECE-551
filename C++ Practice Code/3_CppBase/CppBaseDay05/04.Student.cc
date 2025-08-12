#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

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
    
	~Student()
	{
        cout << "~Student()" << endl;
        if(_name){
            delete [] _name;
            _name = nullptr;
        }
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
private:
	int _id;
	char * _name;
};

void test0()
{
    //申请堆空间的方式和回收堆空间的方式
    //注意保持一致
	Student * stu = new Student(100, "Jackie");
	stu->print();
    delete stu;
    /* free(stu); */
    stu = nullptr;

    int * p = new int(10);
    delete p;
    /* free(p); */
}

int main(void){
    test0();
    return 0;
}

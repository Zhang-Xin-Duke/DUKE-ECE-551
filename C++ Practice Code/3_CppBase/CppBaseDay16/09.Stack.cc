#include <iostream>
using std::cout;
using std::endl;



template <class T = int, int capacity = 10>
class Stack
{
public:
    Stack()
    : _top(-1)
    , _data(new T[capacity]())
    {}

    ~Stack()
    {
        if(_data)
        {
            delete [] _data;
            _data = nullptr;
        }
    }
    
    bool empty() const
    {
        return _top == -1;
    }

    bool full() const
    {
        return _top == capacity - 1;
    }

    void push(const T & t)
    {
        if(!full())
        {
            _data[++_top] = t;
        }else{
            cout << "Stack is full!" << endl;
        }
    }

    void pop()
    {
        if(!empty())
        {
            --_top;
        }else{
            cout << "Stack is empty!" << endl;
        }
    }

    T top();
private:
    int _top;
    T * _data;
};

template <class T,int capacity>
T Stack<T,capacity>::top()
{
    if(!empty())
    {
        return _data[_top];
    }else{
        throw "Stack is empty";
    }
}

//普通类不能与类模板重载
/* class Stack */
/* {}; */

void test0(){
    Stack<int,20> nums;
    Stack<double> nums2;
    Stack<> nums3;
    cout << nums.empty() << endl;
}

int main(void){
    test0();
    return 0;
}

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::uninitialized_copy;

template<typename T>
class Vector
{
public:
    using iterator = T *;
    iterator begin()
    {
        return _start;
    }

    iterator end()
    {
        return _finish;
    }

    Vector();
    ~Vector();

    void push_back(const T &);
    void pop_back();

    int size() const;
    int capacity() const;
private:
    void reallocate();//重新分配内存,动态扩容要用的
private:
    static std::allocator<T> _alloc;//空间的申请与对象的构建分开

    T * _start;      //指向数组中的第一个元素
    T * _finish; //指向最后一个实际元素之后的那个元素
    T * _end_of_storage;        //指向数组本身之后的位置
};

template<typename T>
std::allocator<T> Vector<T>::_alloc;//空间的申请与对象的构建分开

template<typename T>
Vector<T>::Vector()
: _start(nullptr)
, _finish(nullptr)
, _end_of_storage(nullptr)
{

}

template<typename T>
Vector<T>::~Vector()
{
    if(_start)
    {
        //3、将新的空间上的对象销毁并且将新的空间回收
        while(_start != _finish)
        {
            _alloc.destroy(--_finish);
        }
        _alloc.deallocate(_start, capacity());
    }
}

template<typename T>
void Vector<T>::push_back(const T &value)
{
    if(size() == capacity())
    {
        reallocate();//需要扩容
    }
    if(size() < capacity())
    {
        //构建对象
        _alloc.construct(_finish++, value);
    }
}

template<typename T>
void Vector<T>::pop_back()
{
    if(size() > 0)
    {
        //销毁最后一个对象
        _alloc.destroy(--_finish);
    }
}

template<typename T>
int Vector<T>::size() const
{
    return _finish - _start;
}

template<typename T>
int Vector<T>::capacity() const
{
    return _end_of_storage - _start;
}

template<typename T>
void Vector<T>::reallocate()//重新分配内存,动态扩容要用的
{
    //1、申请两倍的新空间
    int oldCapacity = capacity();
    int newCapacity = 2 * oldCapacity > 0 ? 2 * oldCapacity : 1;
    T *tmp = _alloc.allocate(newCapacity);

    if(_start)
    {
        //2、将老的空间上的元素拷贝到新空间
        uninitialized_copy(_start, _finish, tmp);
        //3、将老的空间上的对象销毁并且将老的空间回收
        while(_start != _finish)
        {
            /* _alloc.destroy(_start++);//方法1 */
            _alloc.destroy(--_finish);//方法2
        }
        _alloc.deallocate(_start, oldCapacity);
    }

    //4、三个指针与新的空间产生关系
    _start = tmp;
    _finish = tmp + oldCapacity;
    _end_of_storage = tmp + newCapacity;

}

void printCapacity(const Vector<int> &con)
{
    cout << "size() = " << con.size() << endl;
    cout << "capacity() = " << con.capacity() << endl;
}
void test()
{
    Vector<int> vec;
    printCapacity(vec);

    cout << endl;
    vec.push_back(1);
    printCapacity(vec);

    cout << endl;
    vec.push_back(2);
    printCapacity(vec);

    cout << endl;
    vec.push_back(3);
    printCapacity(vec);

    cout << endl;
    vec.push_back(4);
    printCapacity(vec);

    cout << endl;
    vec.push_back(5);
    printCapacity(vec);

    cout << endl;
    for(auto &elem : vec)
    {
        cout << elem << "  ";
    }
    cout << endl;

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}


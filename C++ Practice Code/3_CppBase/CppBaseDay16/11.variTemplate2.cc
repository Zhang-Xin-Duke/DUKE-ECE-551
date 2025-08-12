#include <iostream>
using std::cout;
using std::endl;

//递归的出口
void display()
{
    cout << endl;
}

template <class T>
void display(T t1)
{
    cout << t1 << endl;
}

/* template <class T, class ...Args> */
/* void display(T x, Args ...args) */
/* { */
/*     cout << x << " "; */
/*     display(args...);//省略号在包的右边代表解包 */
/* } */

template <class T1, class T2, class ...Args>
void display(T1 x, T2 y, Args ...args)
{
    cout << x << " " << y << " ";
    display(args...);
}
void test0(){
    //cout << 1 << " ";
    //display(3.6);
    //cout << 3.6 << " ";
    //display();
    display(1,3.6);
    display(2,7.8,'d',"hello",true);
    display(2,7.8,'d',"hello",true,10);
}

int main(void){
    test0();
    return 0;
}

#ifndef __multiply_HH__
#define __multiply_HH__

//内联函数如果写在头文件中
//需要写出完整的定义
//因为头文件需要提供完整的替换逻辑(内联展开)

//作为对比
//普通函数不要把定义写在头文件中
inline 
double multiply(double x,double y);

inline 
double multiply(double x,double y)
{
    return x * y;
}


#endif

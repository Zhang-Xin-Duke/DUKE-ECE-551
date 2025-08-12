// .h： 头文件
// 结构体的定义，以及暴露给外界使用的函数 (API) 的声明

typedef int E;

typedef struct {
    E* elements;   // 指向堆空间的数组
    int size;	// 元素的个数
    int capacity; // 数组的容量
} Vector;

// API

// 构造函数
Vector* vector_create(void);
// 析构函数
void vector_destroy(Vector* v);

// 请实现push_back方法
void push_back(Vector* v, E val);

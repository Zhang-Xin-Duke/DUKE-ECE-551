// #define N 5  // 宏定义
#define FOO(x) (1 + (x) * (x))

int main(void)
{
	printf("20 / FOO(1 + 2) = %d\n", 20 / FOO(1 + 2));  // 参数需要加括号
	return 0;
}
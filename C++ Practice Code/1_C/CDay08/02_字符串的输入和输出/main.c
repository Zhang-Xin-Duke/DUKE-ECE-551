#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 10
/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	// 1. 输出
	//    a. printf + %s
	//    b. puts(str) 等价于 printf("%s\n", str);

	// char* s = "Hello string";
	// printf("%s", s);
	// puts(s);

	// 2. 输入
	//    a. scanf + %s: 忽略前置的空白字符，读取字符填入字符数组，遇到空白字符结束。
	//       局限性：a. 不能读取空白字符
	//              b. 不能检查数组是否越界
	//       应用场景：读取单词 (以空白字符分隔)
	//char str[N];
	//scanf("%s", str);	// 注意事项：不要添加&

	//  b. gets(str)
	// 读取一行数据，填入字符数组，并将'\n'替换成'\0'
	// 缺陷：不会检查数组越界
	char line[N];
	// gets(line);

	fgets(line, N, stdin);	// 第二个参数填字符数组的长度
	return 0;
}
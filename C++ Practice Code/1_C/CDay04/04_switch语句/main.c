#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {

    // 级联式if-else
    // 缺点：可读性太差；分支太多，性能(相较switch语句)比较差
    //int grade;
    //printf("Enter a grade: ");
    //scanf("%d", &grade);

    //if (grade == 4)
    //    printf("Excellent\n");
    //else if (grade == 3)
    //    printf("Good\n");
    //else if (grade == 2)
    //    printf("Average\n");
    //else if (grade == 1)
    //    printf("Poor\n");
    //else if (grade == 0)
    //    printf("Failing\n");
    //else
    //    printf("Illegal grade\n");

    // switch语句
    // 注意事项：
    //     a. switch后面的表达式必须是整数（包含字符，枚举）
    //     b. 多个case标签，可以共用一组语句
    //     c. 警惕case穿透现象 （机制）
    int grade;
    printf("Enter a grade: ");
    scanf("%d", &grade);

    switch (grade) {
    case 4:
        printf("Excellent\n");
        /*   break through   */
    case 3:
        printf("Good\n");
        break;
    case 2:
        printf("Average\n");
        break;
    case 1:
        printf("Poor\n");
        break;
    case 0:
        printf("Failing\n");
        break;
    default:
        printf("Illegal grade\n");
        break;
    }

    //switch (grade) {
    //case 4: case 3: case 2: case 1:
    //    printf("Passing\n");
    //    break;
    //case 0:
    //    printf("Failing\n");
    //    break;
    //default:
    //    printf("Illegal grade\n");
    //    break;
    //}

    

	return 0;
}
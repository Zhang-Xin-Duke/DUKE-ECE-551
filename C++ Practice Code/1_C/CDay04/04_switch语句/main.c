#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {

    // ����ʽif-else
    // ȱ�㣺�ɶ���̫���֧̫�࣬����(���switch���)�Ƚϲ�
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

    // switch���
    // ע�����
    //     a. switch����ı��ʽ�����������������ַ���ö�٣�
    //     b. ���case��ǩ�����Թ���һ�����
    //     c. ����case��͸���� �����ƣ�
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
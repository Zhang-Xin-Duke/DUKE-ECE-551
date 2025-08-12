#include <header.h>
#include <unistd.h>
#include <crypt.h>
#include <stdio.h>

int main() {

    const char *password = "123";
    const char *salt = "$6$EcGQ/umB$"; // 使用SHA-512算法

    // crypt: 这个函数可以帮助我们把密码计算出hash值
    // 参数一: 密码原文
    // 参数二: 盐值


    char *encrypted = crypt(password, salt);



    if (encrypted == NULL) {
        perror("计算失败 \n");
        return 0;
    }

    printf("password: %s\n", encrypted);
    return 0;
}

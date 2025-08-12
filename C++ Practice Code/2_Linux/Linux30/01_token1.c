#include <header.h>
#include <l8w8jwt/encode.h>

int main(void)
{
    // 用于存储生成的JWT字符串
    char* jwt; 

    // JWT字符串的长度
    size_t jwt_length;  

    // 初始化编码参数结构体
    struct l8w8jwt_encoding_params params;
    l8w8jwt_encoding_params_init(&params); 

    // 设置JWT使用的算法，这里使用HS512
    params.alg = L8W8JWT_ALG_HS512;  

    // 设置JWT的主要荷载部分内容:
    // 主题
    params.sub = "zs";  
    // 签发者
    params.iss = "123";  
    // 接收方
    params.aud = "1";  
    // token过期/有效时间(0x7fffffff:最大值-> 2038年1月19日)
    params.exp = 0x7fffffff;  
    // token签发时间
    params.iat = 0;  

    // 设置加密密钥
    params.secret_key = (unsigned char*)"snow string token key";
    params.secret_key_length = strlen((char *)params.secret_key);

    // 输出变量
    params.out = &jwt;
    params.out_length = &jwt_length;

    // 加密
    l8w8jwt_encode(&params);

    // 输出结果
    printf("l8w8jwt create token: %s \n",  jwt);

    // 释放token 字符串的内存
    l8w8jwt_free(jwt);
    return 0;
}

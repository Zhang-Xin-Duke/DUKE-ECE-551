#include <header.h>

int main(){

    char *ip = "192.168.106.130";
    char *port = "8080";



    struct sockaddr_in sock;
    sock.sin_family = AF_INET; // ipv4, ipv6
    sock.sin_port =  htons( atoi(port));// 字符串-> int -> htons 转成16位大端表示
    sock.sin_addr.s_addr = inet_addr(ip);//  字符串的点分十进制的ip  -> 通过inet_addr变成32位的大端表示的ip地址

    bind(10,( struct sockaddr * ) &sock, sizeof(sock) );

    return 0;
}


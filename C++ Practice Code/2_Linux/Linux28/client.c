#include <header.h>
#include <header.h>

int main(int argc,char*argv[])
{
    int sofd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = inet_addr("192.168.106.130");
    sockaddr.sin_port = htons(atoi("8080"));
    connect(sofd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));

    while(1){
        printf("账号: ");
        fflush(stdout);
        char username[60] = {0};
        read(STDIN_FILENO, username, sizeof(username));
        username[strlen(username)-1] = 0;

        printf("密码: ");
        fflush(stdout);
        char password[60] = {0};
        read(STDIN_FILENO, password, sizeof(password));
        password[strlen(password)-1] = 0;

        send(sofd, username, sizeof(username), 0);
        send(sofd, password, sizeof(password), 0);

        char res[4096] = {0};
        recv(sofd, res, sizeof(res), 0);
        printf("res: %s \n", res);

    }

    close(sofd);
    return 0;
}

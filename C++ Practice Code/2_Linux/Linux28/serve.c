#include <header.h>
#include <mysql/mysql.h>

// 服务端
int main(int argc,char*argv[])
{
    // 初始化socket
    int sofd = socket(AF_INET, SOCK_STREAM, 0);
    int reuse = 1;
    setsockopt(sofd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = inet_addr("192.168.106.130");
    sockaddr.sin_port = htons(atoi("8080"));
    bind(sofd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    listen(sofd, 10);
    int net_fd = accept(sofd, NULL, NULL);

    // 初始化mysql
    MYSQL *mysql = mysql_init(NULL);
    mysql_set_character_set(mysql, "utf8mb4");
    mysql_real_connect(mysql, "localhost", "root", "123456", "cpp62", 0, NULL, 0) ;

    // 读取客户端用户密码, 查询账号信息, 返回给客户端
    while(1){

        // 接收客户端发送过来的账号密码
        char username[60] = {0};
        char password[60] = {0};

        recv(net_fd, username, sizeof(username), 0);
        int ret = recv(net_fd, password, sizeof(password), 0);
        if(ret == 0){
            break;
        }

        // 根据客户端发送的用户密码, 查询数据库获得账号信息
        char sql_buf[1024] = {0};
        sprintf(sql_buf, "select * from User where username='%s' and password = '%s' ",
                username, password);

        printf("sql: %s \n", sql_buf);


        mysql_query(mysql, sql_buf);
        MYSQL_RES *result = mysql_store_result(mysql);

        char buf[4096] = {0};
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(result))) {
            for(int i=0; i<mysql_num_fields(result); i++){
                strncat(buf, " \t ", 4 );
                strncat(buf, row[i], strlen(row[i]));
            }
            strncat(buf, " \n ", 4 );
        }
        mysql_free_result(result);

        // 把账号信息: 回给客户端
        send(net_fd, buf, sizeof(buf), 0);
    }

    mysql_close(mysql);
    close(sofd);
    return 0;
}

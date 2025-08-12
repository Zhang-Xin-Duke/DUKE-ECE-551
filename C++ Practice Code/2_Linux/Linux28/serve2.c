#include <header.h>
#include <mysql/mysql.h>

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
        sprintf(sql_buf, "select * from User where username=? and password = ? ");

        // 设置预处理的sql
        MYSQL_STMT *stmt = mysql_stmt_init(mysql);
        mysql_stmt_prepare(stmt, sql_buf, strlen(sql_buf));

        // 放入参数
        MYSQL_BIND bind[2];
        memset(bind, 0, sizeof(bind));
        bind[0].buffer_type = MYSQL_TYPE_STRING;
        bind[0].buffer = (char *)username;
        bind[0].buffer_length = strlen(username);
        bind[1].buffer_type = MYSQL_TYPE_STRING;
        bind[1].buffer = (char *)password;
        bind[1].buffer_length = strlen(password);
        mysql_stmt_bind_param(stmt, bind);

        // 调用执行
        if (mysql_stmt_execute(stmt)) {
            printf("Error: %s\n", mysql_stmt_error(stmt));
        } else {
            printf("Query executed successfully.\n");
        }

        // 绑定结果集
        MYSQL_BIND bind_result[5];
        char result_column[5][60];
        memset(bind_result, 0, sizeof(bind_result));
        memset(result_column, 0, sizeof(result_column));

        for(int k=0; k<5; k++){
            bind_result[k].buffer_type = MYSQL_TYPE_STRING;
            bind_result[k].buffer = result_column[k];
            bind_result[k].buffer_length = sizeof(result_column[k]);
        }
        mysql_stmt_bind_result(stmt, bind_result);

        // 获取查询结果
        char buf[4096] = {0};
        int fetch_num = mysql_stmt_fetch(stmt);

        if(fetch_num != 0){
            printf("没有结果 \n");
            send(net_fd, buf, strlen(buf), 0);
            mysql_stmt_close(stmt);
            break;
        }

        while (fetch_num == 0) {
            // 拼接结果
            for(int l=0; l<5; l++){
                strncat(buf, " \t ", 4 );
                strncat(buf, result_column[l], strlen(result_column[l]));
            }
            strncat(buf, " \n ", 4 );
            fetch_num = mysql_stmt_fetch(stmt);
        }

        // 把多行查询结果发送给客户端
        send(net_fd, buf, strlen(buf), 0);
        mysql_stmt_close(stmt);
    }

    mysql_close(mysql);
    close(sofd);
    return 0;
}

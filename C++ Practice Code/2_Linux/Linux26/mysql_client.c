#include <header.h>
#include <mysql/mysql.h>

// 写一个mysql的客户端, 通过调用mysql团队提供的库向mysql数据库发送sql语句获得结果
int main(){
    // 调用mysql的函数 -> 引入了头文件
    

    // 1, 初始化mysql

    MYSQL *mysql = mysql_init(NULL);
    // 和下面写法等价

    //MYSQL *mysql;
    //mysql_init(mysql);
    printf("%s\n", mysql_error(mysql));


    // 2, 建立链接, 并且发送账号密码
    mysql_real_connect(mysql, "localhost", "root", "123456", "cpp62", 0, NULL, 0);
    printf("%s\n", mysql_error(mysql));


    // insert into class  values (6, "六班");
    // 3, 上面连接已经建立, 账号密码已经验证 -> 发送sql语句给mysql服务器
    // mysql_query(mysql, "insert into class values( 6, '六班' )");

    //mysql_query(mysql, "update class set class_name='6班' where id =6");

    mysql_query(mysql, "delete from class where id =6");



    mysql_close(mysql);

    return 0;
}


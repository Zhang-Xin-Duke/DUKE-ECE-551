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

    //指明编码格式
	mysql_set_character_set(mysql, "utf8mb4");

    // 2, 建立链接, 并且发送账号密码
    mysql_real_connect(mysql, "localhost", "root", "123456", "cpp62", 0, NULL, 0);
    printf("%s\n", mysql_error(mysql));


    // insert into class  values (6, "六班");
    // 3, 上面连接已经建立, 账号密码已经验证 -> 发送sql语句给mysql服务器
    mysql_query(mysql, "select * from class");

    // 做查询操作: 需要获取查询结果

    // TODO: 只要是select查询, 必须获取结果集 并且释放

    // mysql_store_result: 帮我们获取查询的结果集
    MYSQL_RES * res =mysql_store_result(mysql);
    // MYSQL_RES * res: 就是我们查询之后获取到的结果


    // 获取查询结果有几行
    printf("行数: %ld \n", mysql_num_rows(res));

    // 获取一行数据
    MYSQL_ROW row;

    while((row = mysql_fetch_row(res))){
        //printf(" %s   %s \n", row[0], row[1]);
        unsigned int  num=mysql_num_fields(res);
        for(int k=0; k<num; k++){
            printf(" -%s- ", row[k]);
        }
        printf("\n");
    }

    // 释放结果
    mysql_free_result(res);


    mysql_close(mysql);

    return 0;
}


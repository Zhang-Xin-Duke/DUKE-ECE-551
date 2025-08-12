#include <header.h>
#include <mysql/mysql.h>

// 事务
int main(){

    MYSQL *mysql = mysql_init(NULL);
    mysql_real_connect(mysql, "localhost", "root", "123456", "cpp62", 0, NULL, 0) ;



    // 开始事务: 可以认为等价于 - begin;
    mysql_autocommit(mysql, 0);

    // 执行
    mysql_query(mysql, "insert into class  VALUES (1, '1班')");

    int ret = mysql_query(mysql, "insert into class  VALUES (NULL, '11班')");

    if(ret != 0){
        // 出现错误，回滚事务:   rollback
        printf("回滚 \n");
        mysql_rollback(mysql);
    }else{
        printf("提交 \n");
        // 提交事务: 等价于commit
        mysql_commit(mysql);
    }

    // 恢复自动提交模式
    mysql_autocommit(mysql, 1);

    mysql_close(mysql);
    return 0;

}


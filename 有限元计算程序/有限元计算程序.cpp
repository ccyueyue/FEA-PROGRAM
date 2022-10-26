#include<iostream>
#include<mysql.h>


int main() {
    MYSQL mysql;
    MYSQL_ROW row;
    MYSQL_RES* res;
    
    mysql_init(&mysql);
    //mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
    mysql_set_character_set(&mysql, "gbk");
    mysql_real_connect(&mysql, "127.0.0.1", "root", "000000", "demo", 3306, NULL, 0);

    int ret = mysql_query(&mysql, "select * from student;");
    //std::cout << ret << std::endl;

    res = mysql_store_result(&mysql);

    while (row = mysql_fetch_row(res)) {
        std::cout << row[0] << ' ';
        std::cout << row[1] << ' ';
        std::cout << row[2] << std::endl;
    }
    mysql_free_result(res);
    mysql_close(&mysql);
}










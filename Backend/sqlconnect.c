#pragma once

#include <mysql/mysql.h>
#include "check.c"
#include <stdbool.h>

typedef struct details{
  char *server;
  char *user;
  char *password;
  char *database;
}details;

MYSQL_RES* mysql_execute_query(MYSQL* conn, char *query)
{ 
   if(mysql_query(conn,query))
        printf("MYSQL QUERY Error: %s\n",mysql_error(conn));
    else
        printf("Successful\n");
   /* 
    //free(data.server);
    //free(data.user);
    //free(data.password);
    //free(data.database);
    
    //const char* query="SELECT *FROM sample_url";
    

   // mysql_free_result(res);
   */
   
    return mysql_use_result(conn);

}

MYSQL* connectsql(){

    MYSQL* conn;
   
    
    if (mysql_library_init(0, NULL, NULL)) {
    fprintf(stderr, "could not initialize MySQL client library\n");
    exit(1);
  }
    
    details data;
    data.server= (char *) malloc( sizeof(char)*20);
    data.user= malloc(sizeof(char)*20);
    data.password=  malloc(sizeof(char)*20);
    data.database=  malloc(sizeof(char)*20);
    
    data.server="localhost";
    data.user="Sikkim";
    data.password="Sikkim@report1";
    data.database="SikkimDB";
    
    conn= mysql_init(NULL);
    if(!mysql_real_connect(conn,data.server,data.user,data.password,data.database,3306,NULL,0)){
        printf("Connection Error : %s\n",mysql_error(conn));
        exit(1);
    }
    return conn;
}



void processQuery(MYSQL* conn, char *tablename, data set)
{

   MYSQL_RES * res;
   MYSQL_ROW row;
  char *query = (char *) malloc(sizeof(char)*500);
    sprintf(query, "INSERT INTO %s (URL, ResponseCode, Status, ResponseTime, ConnectionTime) values (\'%s\', %ld, \'%s\', %lf, %lf);", tablename, set.url, set.status_code, set.status, set.res_time, set.conn_time);
    printf("%s\n", query);
    
    res = mysql_execute_query(conn,query);
    
    if(res)
    printf("Result Error : %s\n",mysql_error(conn));
    mysql_free_result(res);

}


void closeConn(MYSQL *conn){
    mysql_close(conn);
}
    //bool autoReconnectMySQL = true;
    //mysql_options( conn, MYSQL_OPT_RECONNECT, &autoReconnectMySQL );
    
   

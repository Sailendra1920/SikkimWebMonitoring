/* This program defines what type of user defined data-types are used
   This program isn't implied dedicatedly on programs.
*/

#pragma once


//defined in check.c
typedef struct data{
  char url[100];
  long status_code;
  double conn_time;
  double res_time;
  char status[50];
}data;

//defined in sqlconnect.c
typedef struct details{
  char *server;
  char *user;
  char *password;
  char *database;
}details;

//defined in app.c
typedef enum cat{

  MAIN = 0,
  HRDD = 1,
  WATER = 2,
  SNT = 3, 
  SPSC = 4,
  TOURISM = 5,
  POWER = 6
}cat;

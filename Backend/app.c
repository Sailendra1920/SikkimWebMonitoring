#include "check.c"
#include "sqlconnect.c"
typedef enum cat{

  MAIN = 0,
  HRDD = 1,
  WATER = 2,
  SNT = 3, 
  SPSC = 4,
  TOURISM = 5,
  POWER = 6
}cat;
  
char *urlname[7]={"https://sikkim.gov.in/","https://sikkimhrdd.org","ephed.sikkim.gov.in","https://www.sntd.in","https://spsc.sikkim.gov.in","https://www.sikkimtourism.gov.in/Public/index","https://power.sikkim.gov.in"};
 char *tablename[7]={"SikkimGovIN","SikkimHRDD","EPHEDSikkim","SikkimSNT","SikkimSPSC","SikkimTourism","SikkimPower"};
  
int main(){
  data set[7];
  
  MYSQL *conn;
  conn = connectsql();
  
  
  for(int i = 0; i<7; i++){
      set[i] = getStatusCode(urlname[i]);
  }
  
  for(int i=0; i<7; i++)
  {
      processQuery(conn, tablename[i],set[i]);
  }
  closeConn(conn);
  
  return 0;
}

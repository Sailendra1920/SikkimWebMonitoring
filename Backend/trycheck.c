

#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>
#include<string.h>
//#include<stderr.h>

typedef struct data{

  char url[100];
  long status_code;
  double conn_time;
  double res_time;
}data;


size_t getCode(char *buffer, size_t itemsize, size_t totalitems, void *userdata ){

  size_t bytes = itemsize*totalitems;
  //printf("in Getcode\n");
  //printf("Chunks: %zu bytes\n", bytes);
  return bytes;
}

data getStatusCode( char *url){

  //initialisation of curl
  CURL *curl = curl_easy_init();
  //URL is fed to and made ready to be performed
  curl_easy_setopt(curl, CURLOPT_URL, url );
  //curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
  char buff[6] = "Status";
  //Very easy function operational function with no HTML output
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getCode);
  curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
  //curl_easy_setopt(curl, CURLOPT_HEADERDATA, &buff);
  //Checker to check the function working status
  printf("in GetstatusCode\n");

  //perform the operation on url
  CURLcode result = curl_easy_perform(curl);
 // printf("hello WORLD");
  if(result != CURLE_OK){
    fprintf(stderr,"download problem: %s\n",curl_easy_strerror(result));
  }

  //Getting the data set to fetch the data
  data set;
  strcpy(set.url,url);
  printf("%s \n", set.url);
  set.status_code = 0;//accepts Long
  set.conn_time = 0.0;//accepts double
  set.res_time = 0.0;//accepts double
  
  //Fetching the info from the HTTP
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &set.status_code);
  curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &set.res_time);
  curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &set.conn_time);
  curl_easy_getinfo(curl, CURLINFO_HTTP_CONNECTCODE, &set.code);
  
  //To check the Code
  if(set.status_code >=200 && set.status_code<=299){
	printf("status: UP %ld\n", set.status_code);
  }
  else{
    if( set.code>=200 && set.code<=299)
	printf("status: UP %ld\n", set.status_code);
    else
        printf("status: DOWN %ld \n", set.status_code);
}

  curl_easy_cleanup(curl);

  return set;
}


char *urlname[8]={"https://sikkim.gov.in","https://sikkimhrdd.org","ephed.sikkim.gov.in","https://www.sntd.in","https://spsc.sikkim.gov.in","https://www.sikkimtourism.gov.in/Public/index","https://power.sikkim.gov.in", "http://www.fadsfsadfasdf.com/"};
  
  
int main(){
  data set[8];
  
  for(int i = 0; i<8; i++){
      set[i] = getStatusCode(urlname[i]);
  }
  
  return 0;
}

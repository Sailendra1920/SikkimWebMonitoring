#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>
#include<string.h>

typedef struct data{

  char url[100];
  long status_code;
  double conn_time;
  double res_time;
  char status[50];
}data;


size_t getCode(char *buffer, size_t itemsize, size_t totalitems, void *userdata ){

  size_t bytes = itemsize*totalitems;
  //printf("in Getcode\n");
  //printf("Chunks: %zu bytes\n", bytes);
  return bytes;
}

data getStatusCode( char *url){

  //Initializing the data set to fetch the data
  data set;
  strcpy(set.url,url);
  printf("%s \n", set.url);
  set.status_code = 0;//accepts Long
  set.conn_time = 0.0;//accepts double
  set.res_time = 0.0;//accepts double
  
  //Initializing of curl
  CURL *curl = curl_easy_init();
  
  //URL is fed to and made ready to be performed
  curl_easy_setopt(curl, CURLOPT_URL, url );
  
  char buff[6] = "Status";
  
  //Very easy function operational function with no HTML output
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getCode);
  curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
  
  //Checker to check the function working status
  printf("in GetstatusCode\n");

  //perform the operation on url
  CURLcode result = curl_easy_perform(curl);

  if(result != CURLE_OK){
    fprintf(stderr,"download problem: %s\n",curl_easy_strerror(result));
      printf("status: FAILED REQ %ld \n", set.status_code);
      strcpy( set.status, "FAILURE - failure in server, server error");
  }


  //Fetching the info from the HTTP
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &set.status_code);
  curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &set.res_time);
  curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &set.conn_time);

  //To check the Code
  if(set.status_code >=200 && set.status_code<=299){
	printf("status: UP %ld\n", set.status_code);
        strcpy(set.status, "UP - rec,ack,acc");
  }
  else if( set.status_code>=300 && set.status_code<=399){
	printf("status: UP&REDIRECTED %ld\n", set.status_code);
        strcpy(set.status, "REDIRECT - redirect url");
    }
  else if( set.status_code>=400 && set.status_code<=499){
        printf("status: ERROR/DOWN %ld \n", set.status_code);
        strcpy(set.status, "DOWN - not found, client error"); 
  }
  else if( set.status_code>=500 && set.status_code<=599){
      printf("status: FAILED REQ %ld \n", set.status_code);
      strcpy(set.status, "FAILURE - failure in server, server error"); 
  }


  curl_easy_cleanup(curl);

  return set;
}


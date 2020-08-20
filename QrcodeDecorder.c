#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

char *strdup(const char *);
char upwards(int x , int y, int qrcode[21][21]);
int getnum(int x,int y,int z);
char cclockwise(int x , int y, int qrcode[21][21]);
char downwards(int x , int y, int qrcode[21][21]);
char clockwise(int x , int y, int qrcode[21][21]);

const char *scanner(int qrcode[21][21]) {
  
 char* msg = calloc(1, 17);
 int len = upwards (18,20,qrcode);
 int x = 14;
 int y = 20;
  for (int i = 1 ; i <=len; i++){
    if(i == 1 || i == 6 || i == 7 || (i >= 12 && i <=16 )){
      msg[i-1] = upwards(x,y,qrcode);
      x-= 4;  
    }else if( i == 3 || i == 4 || i == 9 || i == 10 || i == 17) {
        msg[i-1] = downwards(x,y,qrcode);
        x+= 4; 
    } else if( i == 2 || i == 8 || x == 16 ){
        msg[i-1] = cclockwise(x,y, qrcode);
        x++;
        y-= 2;
     } else if( i == 5 || i == 11  ){
        msg[i-1] = clockwise(x,y, qrcode);
        x--;
        y-= 2;
     }
  
  }

  return msg; 

}
 
  char upwards(int x , int y, int qrcode[21][21]){
    int num = 0;
    int power = 7;
    for (int i = 0; i< 4; i++){
      num += getnum(x-i,y,qrcode [x-i][y]) * pow(2, power) ;
      num += getnum(x-i, y-1, (int)qrcode [x-i][y-1]) * pow(2, power-1);
      power-=2;
    }
    return (char) num ;
  }
 


char cclockwise(int x , int y, int qrcode[21][21]){
    int num = 0;
    int power = 7;


  
    for (int i = 0; i< 2; i++){

      num += getnum(x-i,y,qrcode [x-i][y]) * pow(2, power) ;
      num += getnum(x-i, y-1, (int)qrcode [x-i][y-1]) * pow(2, power-1);
      power-=2;
    }
  
    for (int i = 0; i<2; i++){
      num += getnum(x-1+i,y-2 ,qrcode [x-1+i][y-2]) * pow(2, power) ;
      num += getnum(x-1+i, y-3, (int)qrcode [x-1+i][y-3]) * pow(2, power-1);

      power-=2;
    }
    return (char) num ;
  }
 
  char downwards(int x , int y, int qrcode[21][21]){
    int num = 0;
    int power = 7;
    for (int i = 0; i< 4; i++){
      num += getnum(x+i,y ,qrcode [x+i][y]) * pow(2, power) ;
      num += getnum(x+i, y-1, (int)qrcode [x+i][y-1]) * pow(2, power-1);
      power-=2;
    }
    return (char) num ;
  }

char clockwise(int x , int y, int qrcode[21][21]){
  int num = 0;
    int power = 7;
    for (int i = 0; i< 2; i++){
      num += getnum(x+i,y ,qrcode [x+i][y]) * pow(2, power) ;
      num += getnum(x+i, y-1, (int)qrcode [x+i][y-1]) * pow(2, power-1);
      power-=2;
    }
    for (int i = 0; i< 2; i++){
      num += getnum(x+1-i,y-2,qrcode [x+1-i][y-2]) * pow(2, power) ;
      num += getnum(x+1-i, y-3, (int)qrcode [x+1-i][y-3]) * pow(2, power-1);
      power-=2;
    }
    return (char) num ;
  }
 

int getnum(int x,int y, int z){
    if ((x+y)%2 != 0){
      return z;
    }else{
      if (z == 1){
        return 0;
      }else{
        return 1;
      }
    }
  }
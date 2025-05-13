#include<stdio.h>
#include<stdlib.h>
int main(){
 FILE *SOURCE;
 FILE *DESTINATION;
 char C;
  SOURCE = fopen("C:\\Users\\asus\\Desktop\\TP_Fichier\\SOURCE.txt","r")   ;
  DESTINATION = fopen("C:\\Users\\asus\\Desktop\\TP_Fichier\\DESTINATION.txt","w") ;
  while( ( C = fgetc(SOURCE) ) != -1 ){
    fputc(C,DESTINATION) ;
  }
  fclose(SOURCE) ;
  fclose(DESTINATION) ;
return 0;
}
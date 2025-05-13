#include<stdio.h>
#include<stdlib.h>
int main(){
 FILE *fichier;
 char ligne[200];
  fichier = fopen("C:\\Users\\asus\\Desktop\\TP_Fichier\\exer1","r") ;   
  if( !fichier ){
    printf("erreur d'ouverture de fichier") ;
  }
  else{
    while( fgets(ligne,sizeof(ligne),fichier)){
        printf("%s",ligne) ;
    }
  }
return 0 ;    
}
#include<stdio.h>
#include<stdlib.h>
int main(){
 int AGE;
 char NOM[100];
 FILE *fichier;
  do{
    printf("saisir votre age :") ;
    scanf("%d",&AGE) ;
  }while( AGE < 0 ) ;
  printf("saisir le nom : ") ;  
  scanf(" %s",NOM) ;
  fichier = fopen("C:\\Users\\asus\\Desktop\\TP_Fichier\\exer1","w") ;
  if( fichier == NULL ){
    printf("erreur d'ouverture pour le fichier") ;
  }
  else{
    fprintf(fichier,"NOM : %s\n",NOM) ;
    fprintf(fichier,"AGE : %d\n",AGE) ;
    fclose(fichier) ;
  }
return 0 ;    
}
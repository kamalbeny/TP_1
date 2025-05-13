#include<stdio.h>
#include<stdlib.h>
int main(){
 int I, NBR_MOTS = 0, NBR_LIGNES = 0, NBR_LETTRES = 0;
 char HEDRA[100], CB, CH;
 FILE *FICHIERBRAIN, *FICHIERHELP;
  FICHIERBRAIN = fopen("C:\\Users\\asus\\Desktop\\TP_Fichier\\BRAIN.txt","r") ;
  FICHIERHELP = fopen("C:\\Users\\asus\\Desktop\\TP_Fichier\\BRAIN.txt","r") ;
  CH = fgetc(FICHIERHELP) ;
  while( ( CB = getc(FICHIERBRAIN) ) != -1 ){
    CH = fgetc(FICHIERHELP) ;
     if( CB == '\n' ){
        NBR_LIGNES++ ;
     }
     else{
        if( ( CB >= 'A' && CB <= 'Z' ) ||( CB >= 'a' && CB <= 'z' ) || ( CB >= '1' && CB <= '9' )){
           if( ( CB >= 'A' && CB <= 'Z' ) ||( CB >= 'a' && CB <= 'z' ) ){
            NBR_LETTRES++ ;
           }
            if( CH == 32 || CH == '\n'){
             NBR_MOTS++ ;
            }
        }
     }
  }
  fclose(FICHIERBRAIN) ;
  fclose(FICHIERHELP) ;
  FICHIERHELP = fopen("C:\\Users\\asus\\Desktop\\TP_Fichier\\NBR.txt","w") ;
  fprintf(FICHIERHELP,"Le nombre de ligne : %d\nLe nombre de lettres : %d\nLe nombre de mots :%d\n",NBR_LIGNES,NBR_LETTRES,NBR_MOTS) ;
  fclose(FICHIERHELP) ;
return 0 ;    
}
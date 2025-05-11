#include<stdio.h>
#include<stdlib.h>
typedef struct Noeud{
  int valeur ;
  struct Noeud *suivant ;  
}Noeud ;
Noeud* ajout(){
 Noeud *BRAIN;
  BRAIN = (Noeud*)malloc( sizeof(Noeud) ) ;
  if( !BRAIN ){
    printf("allocation echouée\n") ;
    return NULL ;
  }   
  BRAIN->suivant = NULL ;
 return BRAIN ; 
}
void Enfiler( Noeud **top , int value ){
 Noeud *BRAIN, *SEMIBRAIN;
  SEMIBRAIN = ajout() ;
  if( SEMIBRAIN ){
    SEMIBRAIN->valeur = value ;
    if( !( *top ) ){
        *top =  SEMIBRAIN ;
    }
    else{
        BRAIN = *top ;
        while( BRAIN->suivant ){
          BRAIN = BRAIN->suivant ;
        }
        BRAIN->suivant = SEMIBRAIN ;
    }
  }
}
void Defiler( Noeud **top ){
 Noeud *BRAIN ;
  if( !( *top ) ){
    printf("la liste est vide\n") ;
  }
  else{
    BRAIN = *top ;
    *top = (*top)->suivant ;
    free(BRAIN) ;
  }   
}
void afficher( Noeud *top ){
 Noeud *BRAIN;
 int I;
  for( BRAIN = top , I = 1 ; BRAIN ; BRAIN = BRAIN->suivant , I++ ){
     printf("l'element %d dans la file est : %d \n",I,BRAIN->valeur) ;
  }   
  if( I == 1 ){
    printf("la liste est vide\n") ;
  }
}
void viderFile( Noeud **top ){
 Noeud *BRAIN;   
  while( *top ){
   BRAIN = *top ;
   *top = (*top)->suivant ;
   free(BRAIN) ;
  }    
}
int main( ){
 Noeud *top = NULL;
 int I, val;
  Enfiler(&top,10) ;
  Enfiler(&top,20) ;
  Enfiler(&top,30) ; 
  afficher(top) ;
  Defiler(&top) ;
  afficher(top) ;
  for( I = 1 ; I <= 2 ; I++ ){
    printf("saisir la valeur numero %d que vous voulez inserer : ",I) ;
    scanf("%d",&val) ;
    Enfiler(&top,val) ;
  }
  afficher(top) ;
  viderFile(&top) ;
  afficher(top) ;
 return 0 ;   
}
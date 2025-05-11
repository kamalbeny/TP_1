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
    printf("allocation echouée") ;
    return NULL ;
  }
  BRAIN->suivant = NULL ;
 return BRAIN ;    
}
void push( Noeud **top , int valeur ){
 Noeud *BRAIN;
  BRAIN = ajout() ;
  if( BRAIN ){
    BRAIN->suivant = *top ;
    *top = BRAIN ;
    BRAIN->valeur = valeur ;
  }   
}
void pop( Noeud **top ){
 Noeud *BRAIN;
  if( *top ){
    BRAIN = *top ;
    *top = (*top)->suivant ;
    free(BRAIN) ;
  }   
}
void peek( Noeud *top ){
  if( top ){
    printf("l'element au sommet est : %d\n",top->valeur) ;
  }   
  else{
    printf("la liste est vide \n") ;
  }
}
void afficher( Noeud *top ){
 Noeud *BRAIN;
 int I;
  for( BRAIN = top , I = 1 ; BRAIN != NULL ; BRAIN = BRAIN->suivant , I++ ){
    printf("l'element %d dans la pile est : %d\n",I,BRAIN->valeur) ;
  }
}
int taille( Noeud *top ){
 Noeud *BRAIN;
 int I;
  for( BRAIN = top , I = 0 ; BRAIN  ; BRAIN = BRAIN->suivant ){
     I++ ;
  }
 return I ;
}
int main(){
 Noeud *top = NULL;   
 int I;
  push(&top,10) ;
  push(&top,20) ;
  push(&top,30) ;
  afficher(top) ;
  peek(top) ;
  printf("la taille de la pile est : %d\n",taille(top)) ;
  for( I = 1 ; I <= 2 ; I++ ){
    pop(&top) ;
  }
  afficher(top) ;
}
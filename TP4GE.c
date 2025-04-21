#include<stdio.h>
#include<stdlib.h>
typedef struct Etudiant{
  int id;
  char nom[50];
  float moyenne;
  struct Etudiant *suivant;
  struct Etudiant *precedent;
}Etudiant;
Etudiant* creer_etudiant(){
 Etudiant *BRAIN;
  BRAIN = (Etudiant*)malloc( sizeof(Etudiant) ) ;
  if( BRAIN ){
    printf("saisir le nom complet : ") ;
    scanf(" %s",BRAIN->nom) ;
    do{
        printf("saisir l'id : ") ;
        scanf("%d",&BRAIN->id) ;
    }while( BRAIN->id < 0 ) ;
    do{
        printf("saisir la moyenne : ") ;
        scanf("%f",&BRAIN->moyenne) ;
    }while( BRAIN->moyenne < 0 ) ;
    BRAIN->suivant = BRAIN->precedent = NULL ;
  }
 return BRAIN ; 
}
int longeur( Etudiant *tete ){
 int TAILLE = 0 ;
 Etudiant *BRAIN ;
  BRAIN = tete ;
  while( BRAIN ){
    TAILLE++ ;
    BRAIN = BRAIN->suivant ;
  }
 return TAILLE ; 
}
Etudiant* ajouter_position( Etudiant *tete , Etudiant *nouveau , int position ){
 Etudiant *BRAIN;
 int TAILLE, CMP = 1;
  TAILLE = longeur(tete) ;
  if( position < 1 || position > TAILLE + 1 ){
    printf("position invalide") ;
  }   
  else{
    BRAIN = tete ;
    while( BRAIN && CMP < position - 1 ){
      BRAIN = BRAIN->suivant ;
      CMP++ ;
    }
    if( position == 1 ){
        nouveau->suivant = BRAIN ;
        nouveau->precedent = NULL ;
        if( BRAIN ){
        BRAIN->precedent = nouveau ;
        }
        tete = nouveau ;
    }
    else{
        nouveau->suivant = BRAIN->suivant ;
        nouveau->precedent = BRAIN ;
        if( BRAIN->suivant ){
            BRAIN->suivant->precedent = nouveau ;
        }
        BRAIN->suivant = nouveau ;
    }
  }
 return tete ; 
}
Etudiant* supprimer_position( Etudiant *tete , int position ){
 int LENGHT = longeur(tete) ;
 Etudiant *BRAIN;
  if( position < 1 || position > LENGHT ){
    printf("position invalide ") ;
  }   
  else{
    LENGHT = 1 ;
    BRAIN = tete ;
    while( BRAIN && LENGHT < position ){
        BRAIN = BRAIN->suivant ;
    }
    if( BRAIN->precedent ){
        BRAIN->precedent->suivant = BRAIN->suivant ;
    }
    else{
        tete = tete->suivant ;
    }
    if( BRAIN->suivant ){
        BRAIN->suivant->precedent = BRAIN->precedent ;
    }
    free(BRAIN) ;
  }
 return tete ; 
}
void afficher_liste( Etudiant *tete ){
 Etudiant *BRAIN;
  BRAIN = tete ;
  while( BRAIN ){
    printf("\nnom complet : %s",BRAIN->nom) ;
    printf("\nla moyenne : %.2f",BRAIN->moyenne) ;
    printf("\nid : %d",BRAIN->id) ;
    BRAIN = BRAIN->suivant ;
  }   
}
Etudiant* derniere_cellule( Etudiant *tete ){
 Etudiant *BRAIN;
  BRAIN = tete ;
  while( BRAIN->suivant ){
    BRAIN = BRAIN->suivant ;
  }
 return BRAIN ; 
}
void afficher_inverse( Etudiant *dernier ){
   while( dernier ){
    printf("\nnom complet : %s",dernier->nom) ;
    printf("\nla moyenne : %.2f",dernier->moyenne) ;
    printf("\nid : %d",dernier->id) ;
    dernier = dernier->precedent ;
   }  
}
int chercher_etudiant( Etudiant *tete , int id ){
 Etudiant *BRAIN;
  BRAIN = tete ;
  while( BRAIN && BRAIN->id != id ){
    BRAIN = BRAIN->suivant ;
  }    
  if( BRAIN ){
    return 1 ;
  }
  else{
    return 0 ;
  }
}
void Tri_croissant( Etudiant *tete ){
 Etudiant *BRAIN, *SEMIBRAIN, *LINK;
 char nom[50];
 int id;
 float moy;
  if( tete ){
    BRAIN = tete ;
    while( BRAIN->suivant ){
      LINK = BRAIN ;
      SEMIBRAIN = BRAIN->suivant ;
      while( SEMIBRAIN ){
        if( LINK->moyenne > SEMIBRAIN->moyenne ){
          LINK = SEMIBRAIN ;
        }
        SEMIBRAIN = SEMIBRAIN->suivant ;
      }
      if( LINK != BRAIN ){
        strcpy(BRAIN->nom,nom) ;
        strcpy(LINK->nom,BRAIN->nom) ;
        strcpy(nom,LINK->nom) ;
        id = BRAIN->id ;
        BRAIN->id = LINK->id ;
        LINK->id = id ;
      }
      BRAIN = BRAIN->suivant ;
    }
  }
}
void modifier_moyenne( Etudiant *tete , int position , float nouvelle_moyenne ){
 Etudiant *BRAIN;
 int LENGHT, POS;
  LENGHT = longeur(tete) ;
  if( position < 1 || position > LENGHT){
    printf("position invalide") ;
  } 
  else{
    BRAIN = tete ;
    POS = 1 ;
    while( BRAIN && POS < position ){
      BRAIN = BRAIN->suivant ;
      POS++ ;
    }
    BRAIN->moyenne = nouvelle_moyenne ;
  }
}
int main(){
 Etudiant *tete = NULL, *dernier, *element;
 int TAILLE, POSITION, LENGHT, I, Id;
  do{
     printf("saisir la taille : ") ;
     scanf("%d",&LENGHT) ;
  }while( LENGHT <= 0 ) ;
  for( I = 1 ; I <= LENGHT ; I++ ){
    element = creer_etudiant() ;
    printf("saisir une position : ") ;
    scanf("%d",&POSITION) ;
    tete = ajouter_position(tete,element,POSITION) ;
  }
  afficher_liste(tete) ;
  dernier = derniere_cellule(tete) ;
  afficher_inverse(dernier) ;
  printf("saisir un id : ") ;
  scanf("%d",&Id) ;
  I = chercher_etudiant(tete,Id) ;
  printf("saisir une position : ") ;
  scanf("%d",&POSITION) ;
  tete = supprimer_position(tete,POSITION) ;
  afficher_liste(tete) ;
  Tri_croissant(tete) ;
  afficher_liste(tete) ;
 return 0 ; 
}
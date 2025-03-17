#include<stdio.h> 
#include<stdlib.h>
typedef struct Noeud{
  int valeur;
  struct Noeud *suivant;
}Noeud;
Noeud* cree( int valeur ){
 Noeud *BRAIN;
  BRAIN = (Noeud*)malloc( sizeof(Noeud) ) ;
  if( !BRAIN ){
    printf("allocation echouée") ;
  }
  else{
    BRAIN->valeur = valeur ;
    BRAIN->suivant = NULL ;
  }
 return BRAIN ; 
}
void affiche( Noeud *debut ){
 Noeud *BRAIN;
  if( !debut ){
    printf("la liste est vide") ;
  } 
  else{
    BRAIN = debut ;
    while( BRAIN ){
      printf("%d",BRAIN->valeur) ;
      if( BRAIN->suivant ){
        printf("->") ;
      }
      BRAIN = BRAIN->suivant ;
    }
  }
}
Noeud* ajouterD( Noeud *debut , int valeur ){
 Noeud *BRAIN;
  BRAIN = cree(valeur) ;
  if( !BRAIN ){
    exit(EXIT_FAILURE) ;
  }        
  else{
    BRAIN->suivant = debut ;
    debut = BRAIN ;
  }
  return debut ;
}
Noeud* ajouterF( Noeud *debut , int valeur ){
 Noeud *BRAIN, *SEMIBRAIN;
  BRAIN = cree(valeur) ;
  if( !BRAIN ){
    exit(EXIT_FAILURE) ;
  } 
  else{
    if( !debut ){
      debut = BRAIN ;
    }
    else{
      SEMIBRAIN = debut ;
      while( SEMIBRAIN->suivant ){
        SEMIBRAIN = SEMIBRAIN->suivant ;
      }
      SEMIBRAIN->suivant = BRAIN ;
    }
  }
 return debut ; 
}
int TAILLE( Noeud *debut ){
 Noeud *BRAIN;
 int I;
  BRAIN = debut ;
  for( BRAIN = debut , I = 0 ; BRAIN != NULL ; BRAIN = BRAIN->suivant ){
    I++ ;
  }
 return I ; 
}
Noeud* insertion( Noeud *debut , int pos , int valeur ){
 Noeud *BRAIN, *SEMIBRAIN;
 int LENGHT , I = 1;
  LENGHT = TAILLE(debut) ; 
  if( pos < 1 || pos > LENGHT + 1 ){
    printf("position invalide") ;
  }
  else{
    if( !debut || pos == 1 ){
      debut = ajouterD(debut,valeur) ;
    }
    else{
      SEMIBRAIN = debut ;
      while( I < pos - 1 ){
        I++ ;
        SEMIBRAIN = SEMIBRAIN->suivant ;
      }
      if( SEMIBRAIN->suivant ){
        BRAIN = cree(valeur) ;
        if( !BRAIN ){
          exit(EXIT_FAILURE) ;
        }
        else{
          BRAIN->suivant = SEMIBRAIN->suivant ;
          SEMIBRAIN->suivant = BRAIN ;
        }
      }
      else{
        debut = ajouterF(debut,valeur) ;
      }
    }
  }
  return debut ;
}
void rechercher( Noeud *debut , int valeur ){
 Noeud *BRAIN;
  if( !debut ){
    printf("la liste est vide") ;
  } 
  else{
    BRAIN = debut ;
    while( BRAIN && BRAIN->valeur != valeur ){
      BRAIN = BRAIN->suivant ;                               
    } 
    if( BRAIN ){
      printf("la valeur existe dans le tableau ") ;
    }
    else{
      printf("la valeur n'existe pas dans le tableau") ;
    }
  }
}
Noeud* suppressionD( Noeud *debut ){
 Noeud *BRAIN;
  if( !debut ){
    printf("rien a supprimmer") ;
  } 
  else{
    BRAIN = debut ;
    debut = debut->suivant ;
    free(BRAIN) ;
  }
 return debut ; 
}
Noeud* suppressionF( Noeud *debut ){
 Noeud *BRAIN, *SEMIBRAIN;
 if( !debut ){
   printf("la liste est vide") ;
 } 
 else{
  if( !(debut->suivant) ){
    free(debut) ;
    debut = NULL ; 
  }
  else{
   SEMIBRAIN = debut ;
   while( SEMIBRAIN->suivant->suivant ){
    SEMIBRAIN = SEMIBRAIN->suivant ;
   }
   free(SEMIBRAIN->suivant) ;
   SEMIBRAIN->suivant = NULL ;
  }
 }
 return debut ; 
}
Noeud *suppressionP( Noeud *debut , int pos ){
 Noeud *BRAIN, *SEMIBRAIN;
 int LENGHT, I; 
  LENGHT = TAILLE(debut) ;
  if( pos < 1 || pos > LENGHT ){
    printf("position invalide") ;
  }
  else{
    if( pos == 1 ){
      debut = suppressionD(debut) ;
    }
    else{
      BRAIN = debut ;
      I = 1 ;
      while( I < pos - 1 ){
        BRAIN = BRAIN->suivant ;
      }
      SEMIBRAIN = BRAIN->suivant ;
      BRAIN->suivant = BRAIN->suivant->suivant ;
      free(SEMIBRAIN) ;
    }
  }
 return debut ; 
}
void modifierD( Noeud *debut , int valeur ){
 debut->valeur = valeur ;
}
void modifierF( Noeud *debut , int valeur ){
 Noeud *BRAIN;
  if( !debut ){
    printf("la liste est vide") ;
  }
  else{
    BRAIN = debut ;
    while( BRAIN->suivant ){
      BRAIN = BRAIN->suivant ;
    }
    BRAIN->valeur = valeur ;
  }
}
void modifierP( Noeud *debut , int pos , int valeur ){
 Noeud *BRAIN;
 int LENGHT, I = 1 ;
  LENGHT = TAILLE(debut) ;
  if( pos < 1 || pos > LENGHT ){
    printf("position invalide") ;
  }
  else{
    BRAIN = debut ;
    while( I < pos ){
      BRAIN = BRAIN->suivant ;
      I++ ;
    }
    BRAIN->valeur = valeur ;
  }  
}
int main(){
 int pos, valeur, nbr_element, I;
 Noeud *HEAD = NULL; 
  do{
    printf("saisir le nombre des Noeuds") ;
    scanf("%d",&nbr_element) ;
  }while( nbr_element <= 0 ) ;
  for( I = 1 ; I <= nbr_element ; I++ ){
    printf("saisir une valeur : ") ;
    scanf("%d",&valeur) ;
    HEAD = ajouterD(HEAD,valeur) ;
  }
  affiche(HEAD) ;
  printf("\n") ;
  printf("saisir une valeur") ;
  scanf("%d",&valeur) ;
  HEAD = ajouterF(HEAD,valeur) ;
  printf("\n") ;
  affiche(HEAD) ;
  printf("saisir une position") ;
  scanf("%d",&pos) ;
  printf("saisir une valeur") ;
  scanf("%d",&valeur) ;
  HEAD = insertion(HEAD,pos,valeur) ;
  affiche(HEAD) ;
  printf("saisir une valeur : ") ;
  scanf("%d",&valeur) ;
  rechercher(HEAD,valeur) ;
  HEAD = suppressionD(HEAD) ;
  printf("\n") ;
  affiche(HEAD) ;
  HEAD = suppressionF(HEAD) ;
  affiche(HEAD) ;
  printf("saisir une position") ;
  scanf("%d",&pos) ;
  HEAD = suppresionP(HEAD,pos) ;
  printf("\n") ;
  affiche(HEAD) ;
  printf("saisir une valeur : ") ;
  scanf("%d",&valeur) ;
  modifierD(HEAD,valeur) ;
  printf("saisir une valeur : ") ;
  scanf("%d",&valeur) ;
  modifierF(HEAD,valeur) ;
  printf("saisir une valeur : ") ;
  scanf("%d",&valeur) ;
  printf("saisr une position : ") ;
  scanf("%d",&pos) ;
  modifierP(HEAD,pos,valeur) ;
  printf("\n") ;
  affiche(HEAD) ;
 return 0;
}
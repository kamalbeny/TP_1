#include<stdio.h>
#include<stdlib.h>
typedef struct Noeud{
  int valeur;
  struct Noeud *suivant;
  struct Noeud *precedent;  
} Noeud;
Noeud* cree( int valeur ){
 Noeud *BRAIN;
  BRAIN = ( Noeud* )malloc( sizeof(Noeud) ) ;
  if( !BRAIN ){
    printf("la liste est vide") ;
  }   
  else{
    BRAIN->valeur = valeur ;
    BRAIN->suivant = BRAIN->precedent = NULL ;
  }
 return BRAIN ; 
}
void affiche( Noeud *debut ){
 Noeud *BRAIN;
  if( debut ){
    BRAIN = debut ;
    while( BRAIN->suivant ){
        printf("%d-> ",BRAIN->valeur) ;
        BRAIN = BRAIN->suivant ;
    }
    printf("%d",BRAIN->valeur) ;
  }
}
void afficheInverse( Noeud *debut ){
 Noeud *BRAIN;
  if( debut ){
    BRAIN = debut ;
    while( BRAIN->suivant ){
        BRAIN = BRAIN->suivant ;
    }
    while( BRAIN->precedent ){
       printf("%d-> ",BRAIN->valeur) ;
       BRAIN = BRAIN->precedent ; 
    }
    printf("%d",BRAIN->valeur) ;
  }
} 
Noeud* ajouterD( Noeud *debut , int valeur ){
 Noeud *BRAIN;
  BRAIN = cree(valeur) ;
  if( BRAIN ){
    if( debut ){
      debut->precedent = BRAIN ;  
    }
    BRAIN->suivant = debut ;
    BRAIN->precedent = NULL ;
    BRAIN->valeur = valeur ;
  }   
 return BRAIN ; 
}
Noeud* ajouterF( Noeud *debut , int valeur ){
 Noeud *BRAIN;
 if( !debut ){
    debut = ajouterD(debut,valeur) ;
 }
 else{
    BRAIN = debut ;
    while( BRAIN->suivant ){
      BRAIN = BRAIN->suivant ;  
    }
    BRAIN->suivant = creer(valeur) ;
    if( BRAIN->suivant ){
        BRAIN->suivant->precedent = BRAIN ; 
    }
 }
 return debut ; 
}
int taille( Noeud *debut ){
 int TAILLE = 0;
 Noeud *BRAIN; 
  BRAIN = debut ;
  while( BRAIN ){
    BRAIN = BRAIN->suivant ;
    TAILLE++ ;
  }  
 return TAILLE ;
}
Noeud* insertion( Noeud *debut, int pos , int valeur ){
 Noeud *BRAIN, *SEMIBRAIN;
 int LENGHT, CMP = 1;
  LENGHT = taille(debut) ;
  if( pos < 1 || pos > LENGHT + 1 ){
    printf("position invalide") ;
  }   
  else{
    SEMIBRAIN = cree(valeur) ;
    BRAIN = debut ;
    while( BRAIN && CMP < pos - 1 ){
        BRAIN = BRAIN->suivant ;
        CMP++ ;
    }
    if( pos == 1 ){
        debut = ajouterD(debut,valeur) ;
    }
    else{
        if( pos == LENGHT + 1 ){
            debut = ajouterF(debut,valeur) ;
        }
        else{
            SEMIBRAIN = cree(valeur) ;
            SEMIBRAIN->suivant = BRAIN->suivant ;
            SEMIBRAIN->precedent = BRAIN ;
            if( BRAIN->suivant ){
                BRAIN->suivant->precedent = SEMIBRAIN ;
            }
            BRAIN->suivant = SEMIBRAIN ;
        }
    }
  }
  return debut ;
}
Noeud* rechercher( Noeud *debut , int valeur ){
 Noeud *BRAIN;
  if( debut ){
    BRAIN = debut ;
    while( BRAIN && BRAIN->valeur != valeur ){
        BRAIN = BRAIN->suivant ;
    }
    if( BRAIN ){
     return BRAIN ;
    }
    return NULL ;
  }   
}
Noeud* suppressionD( Noeud *debut ){
 Noeud *BRAIN;
  BRAIN = debut ;
  debut = debut->suivant ;
  free(BRAIN) ;
  if( debut ){
    debut->precedent = NULL ;
  }   
 return debut ;
}
Noeud* suppressionF( Noeud *debut ){
 Noeud *BRAIN;
  if( !debut ){
    printf("la liste est vide") ;
  }
  else{
    if( !(debut->suivant) ){
        free(debut) ;
        debut = NULL ;
    }
    else{
        BRAIN == debut ;
        while( BRAIN->suivant->suivant ){
            BRAIN = BRAIN->suivant ;
        }
        free( BRAIN->suivant ) ;
        BRAIN->suivant = NULL ;
    }
  }
 return debut ; 
}
Noeud* suppressionP( Noeud *debut , int pos ){
 Noeud *BRAIN;
 int CMP = 1, LENGHT;
  LENGHT = taille(debut) ;
  if( pos < 1 || pos > LENGHT ){
    printf("position invalide") ;
  }
  else{
    BRAIN = debut ;
    while( BRAIN && CMP != pos ){
      BRAIN = BRAIN->suivant ;
      CMP++ ;   
    } 
    if( BRAIN->precedent ){
        BRAIN->precedent->suivant = BRAIN->suivant ;    
    }
    else{
        debut = BRAIN->suivant ;
    }
    if( BRAIN->suivant ){
        BRAIN->suivant->precedent = BRAIN->precedent ;
    }
    free(BRAIN) ;
  }
 return debut; 
}
void modifierD( Noeud *debut , int valeur ){
 if( debut ){
    debut->valeur = valeur ;
 }      
}
void modifierF( Noeud *debut , int valeur ){
  if( debut ){
    while( debut->suivant ){
        debut = debut->suivant ;
    }
    debut->valeur = valeur ;
  }   
}
void modifierP( Noeud *debut , int pos , int valeur ){
 int LENGHT = taille(debut), CMP = 0;
  if( pos < 1 || pos > LENGHT ){
    printf("position invalide") ;
  }
  else{
    while( debut && CMP != pos ){
        debut = debut->suivant ;
    }
    debut->valeur = valeur ;
  }   
}
void tri( Noeud *debut ){
 Noeud *BRAIN, *SEMIBRAIN, *LINK;
 int val;
  if( debut ){
    BRAIN = debut ;
    while( BRAIN->suivant ){
      SEMIBRAIN = BRAIN->suivant ;
      LINK = BRAIN ;
      while( SEMIBRAIN ){
        if( LINK->valeur > SEMIBRAIN->valeur ){
            LINK = SEMIBRAIN ;
        }
        SEMIBRAIN = SEMIBRAIN->suivant ;
      }
      if( LINK != BRAIN ){
        val = LINK->valeur ;
        LINK->valeur = BRAIN->valeur ;
        BRAIN->valeur = val ;
      }
    }
  }   
}
int main(){
 Noeud *HEAD = NULL, *RECH;
 int taille, I, val;
  do{
    printf("saisir la taille de la liste : ") ;
    scanf("%d",&taille) ;
  }while( taille <= 0 ) ;
 for( I = 1  ; I <= taille ; I++ ){
   printf("saisir une valuer : ") ;
   scanf("%d",&val) ;
   HEAD = ajouterD(HEAD,val) ;
 }
 affiche(HEAD) ;
 printf("\n") ;
 printf("saisir une valeur : ") ;
 scanf("%d",&val) ;
 HEAD = ajouterF(HEAD,val) ;
 affiche(HEAD) ;
 printf("\n") ;
 printf("saiisr une valeur : ") ;
 scanf("%d",&val) ;
 printf("saisir une position : ") ;
 scanf("%d",&I) ;
 HEAD = insertion(HEAD,I,val) ;
 affiche(HEAD) ;
 printf("saisir une valeur : ") ;
 scanf("%d",&val) ;
 RECH = rechercher(HEAD,val) ;
 printf("\nvoila le noeud : %d",RECH->valeur) ;
 HEAD = suppressionD(HEAD) ;
 printf("\n") ;
 affiche(HEAD) ;
 HEAD = suppressionF(HEAD) ;
 printf("\n") ;
 affiche(HEAD) ;
 printf("saisir une position : ") ;
 scanf("%d",&I) ;
 HEAD = suppressionP(HEAD,I) ;
 affiche(HEAD) ;
 printf("saisir une valeur : ") ;
 scanf("%d",&val) ;
 modifierD(HEAD,val) ;
 affiche(HEAD) ;
 printf("saisir une valeur : ") ;
 scanf("%d",&val) ;
 modifierF(HEAD,val) ;
 affiche(HEAD) ;
 printf("saisir une position : ") ;
 scanf("%d",&I) ;
 printf("saisir une valeur : ") ;
 scanf("%d",&val) ;
 modifierP(HEAD,I,val) ;
 affiche(HEAD) ;
 tri(HEAD) ;
 affiche(HEAD) ;
 RECH = HEAD ;
 while(RECH){
  HEAD = HEAD->suivant ;
  free(RECH) ;
  RECH = HEAD ;  
 }
return 0 ;
}
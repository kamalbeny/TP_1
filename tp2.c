#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct{
  char jour[3];
  char mois[3];
  char annee[5];
}Date;
typedef struct{
  char *Nom_produit;
  char Reference[100];
  float Montant;
  Date DateAchat;
}Produit;
typedef struct Liste{
  Produit cellule;
  struct Liste *psuiv;  
}Liste;
Liste* creer_liste_produits(){
 Liste *L;
  return NULL ;
}
int est_vide( Liste *L ){
 if( L ){
    return 1 ;
 }
    return 0 ;
}
Liste* creer_produits(){
 Liste *CP;
 int N, I;
 bool DEL;
  CP = (Liste*)malloc( sizeof(Liste) ) ;
  if( CP ){
    CP->psuiv = NULL ;
   do{
    printf("saisir le nombre de caracteres : ") ;
    scanf("%d",&N) ;
   }while( N <= 0 ) ;
   CP->cellule.Nom_produit = (char*)malloc( (N+1) * sizeof(char) ) ;
   if( CP->cellule.Nom_produit ){
    printf("saisir le nom de produit : ") ;
    scanf(" %s",CP->cellule.Nom_produit) ;
    CP->cellule.Nom_produit[N] = '\0' ;
    do{
      printf("saisir le nombre de caracteres dans la reference : ") ;
      scanf("%d",&N) ;
    }while( N <= 0 || N >= 100 ) ;
    printf("saisir la refenrece caracteres par caracteres") ;
    for( I = 0 ; I < N ; I++ ){
     printf("saisir le caracteres numero : %d") ;
     scanf(" %c",&CP->cellule.Reference[I]) ;
    }
    CP->cellule.Reference[I] = '\0' ;
    do{
      printf("saisir le montant : ") ;
      scanf("%f",&CP->cellule.Montant) ;
    }while( CP->cellule.Montant < 0 ) ;
    printf("saisir l'année de l'achat : ") ;
    scanf(" %s",CP->cellule.DateAchat.annee) ;
    CP->cellule.DateAchat.annee[4] = '\0' ; 
    do{
      printf("saisir le mois : ") ;
      scanf(" %s",CP->cellule.DateAchat.mois) ;
      CP->cellule.DateAchat.mois[2] = '\0' ;   
    }while( strcmp(CP->cellule.DateAchat.mois,"1") == -1 || strcmp(CP->cellule.DateAchat.mois,"12") == 1 ) ;
    I = atoi(CP->cellule.DateAchat.mois) ;
    switch( I ){
      case 1 : do{
                 printf("saisir le jour : ") ;
                 scanf(" %s",CP->cellule.DateAchat.jour) ;
                 CP->cellule.DateAchat.jour[2] = '\0' ;   
               }while( strcmp(CP->cellule.DateAchat.jour,"1") == -1 || strcmp(CP->cellule.DateAchat.jour,"31") == 1 ) ;
               break ;
      case 2 : I = atoi( CP->cellule.DateAchat.annee ) ;
               if( ( I % 4 == 0 && I % 100 != 0 ) || ( I % 4 == 0 && I % 100 == 0 && I % 400 == 0 ) ){
                DEL = true ;
               }
               else{
                DEL = false ;
               }
                if( DEL ){
                  do{
                    printf("saisir le nombre de jour : ") ;
                    scanf(" %s",CP->cellule.DateAchat.jour) ;
                    CP->cellule.DateAchat.jour[2] ='\0' ;
                  }while( strcmp(CP->cellule.DateAchat.jour,"1") < 0 || strcmp(CP->cellule.DateAchat.jour,"29") > 0) ;
                }
                else{
                  do{
                    printf("saisir le nombre de jour : ") ;
                    scanf(" %s",CP->cellule.DateAchat.jour) ;
                    CP->cellule.DateAchat.jour[2] ='\0' ;
                  }while( strcmp(CP->cellule.DateAchat.jour,"1") < 0 || strcmp(CP->cellule.DateAchat.jour,"28") > 0) ;                  
                }
               break ;
      case 3 :  do{
                   printf("saisir le jour : ") ;
                   scanf(" %s",CP->cellule.DateAchat.jour) ;
                   CP->cellule.DateAchat.jour[2] = '\0' ;   
                }while( strcmp(CP->cellule.DateAchat.jour,"1") == -1 || strcmp(CP->cellule.DateAchat.jour,"31") == 1 ) ;
                break ;
      case 4 :  do{
                  printf("saisir le jour : ") ;
                  scanf(" %s",CP->cellule.DateAchat.jour) ;
                  CP->cellule.DateAchat.jour[2] = '\0' ;   
               }while( strcmp(CP->cellule.DateAchat.jour,"1") == -1 || strcmp(CP->cellule.DateAchat.jour,"30") == 1 ) ;
               break ;
      case 5 :  do{
                  printf("saisir le jour : ") ;
                  scanf(" %s",CP->cellule.DateAchat.jour) ;
                CP->cellule.DateAchat.jour[2] = '\0' ;   
                }while( strcmp(CP->cellule.DateAchat.jour,"1") == -1 || strcmp(CP->cellule.DateAchat.jour,"31") == 1 ) ;
                break ;
      case 6 :  do{
                  printf("saisir le jour : ") ;
                  scanf(" %s",CP->cellule.DateAchat.jour) ;
                  CP->cellule.DateAchat.jour[2] = '\0' ;   
               }while( strcmp(CP->cellule.DateAchat.jour,"1") == -1 || strcmp(CP->cellule.DateAchat.jour,"30") == 1 ) ;
               break ;
      case 7 :  do{
                  printf("saisir le jour : ") ;
                  scanf(" %s",CP->cellule.DateAchat.jour) ;
                  CP->cellule.DateAchat.jour[2] = '\0' ;   
                }while( strcmp(CP->cellule.DateAchat.jour,"1") == -1 || strcmp(CP->cellule.DateAchat.jour,"31") == 1 ) ;
             break ; 
      case 8 :  do{
                  printf("saisir le jour : ") ;
                  scanf(" %s",CP->cellule.DateAchat.jour) ;
                  CP->cellule.DateAchat.jour[2] = '\0' ;   
                }while( strcmp(CP->cellule.DateAchat.jour,"1") == -1 || strcmp(CP->cellule.DateAchat.jour,"31") == 1 ) ;
                break ;
      case 9 :  do{
                  printf("saisir le jour : ") ;
                  scanf(" %s",CP->cellule.DateAchat.jour) ;
                  CP->cellule.DateAchat.jour[2] = '\0' ;   
               }while( strcmp(CP->cellule.DateAchat.jour,"1") == -1 || strcmp(CP->cellule.DateAchat.jour,"30") == 1 ) ;
               break ;                                                                                            
      case 10 :  do{
                  printf("saisir le jour : ") ;
                  scanf(" %s",CP->cellule.DateAchat.jour) ;
                  CP->cellule.DateAchat.jour[2] = '\0' ;   
                }while( strcmp(CP->cellule.DateAchat.jour,"1") == -1 || strcmp(CP->cellule.DateAchat.jour,"31") == 1 ) ;
                break ;
      case 11 :  do{
                  printf("saisir le jour : ") ;
                  scanf(" %s",CP->cellule.DateAchat.jour) ;
                  CP->cellule.DateAchat.jour[2] = '\0' ;   
                }while( strcmp(CP->cellule.DateAchat.jour,"1") == -1 || strcmp(CP->cellule.DateAchat.jour,"30") == 1 ) ;
                break ;                                                                            
      case 12 :  do{
                  printf("saisir le jour : ") ;
                  scanf(" %s",CP->cellule.DateAchat.jour) ;
                  CP->cellule.DateAchat.jour[2] = '\0' ;   
                }while( strcmp(CP->cellule.DateAchat.jour,"1") == -1 || strcmp(CP->cellule.DateAchat.jour,"31") == 1 ) ;
                break ;                                         
    }    
   }
  }
 return CP;
}
void afficher_prodruit( Liste* produit ){
  printf("\nle nom du produit : %s",produit->cellule.Nom_produit) ;
  printf("\nla reference du produit : %s",produit->cellule.Reference) ;
  printf("\nle montant d'achat : %/.2f",produit->cellule.Montant) ;
  printf("\nla date d'achat : %s/%s/%s",produit->cellule.DateAchat.jour,produit->cellule.DateAchat.mois,produit->cellule.DateAchat.annee) ;
}
Liste* ajouter_debut( Liste* tete ){
 Liste* BRAIN;
  BRAIN = creer_produits() ;
  if( !tete ){
    printf("la liste est vide") ;
    tete = BRAIN ;
  }
  else{
   if( BRAIN ){
    BRAIN->psuiv = tete ;
   }
   tete = BRAIN ;
  }
 return tete ; 
}
Liste* ajouter_fin( Liste* tete ){
 Liste *BRAIN, *SEMIBRAIN;
  BRAIN = creer_produits() ;
  if( !tete ){
    tete = ajouter_debut( tete ) ;
  } 
  else{
    SEMIBRAIN = tete ;
    while( SEMIBRAIN->psuiv ){
      SEMIBRAIN = SEMIBRAIN->psuiv ;
    }
    SEMIBRAIN->psuiv = BRAIN ;
  }
 return tete ; 
}
void afficher_produits( Liste *tete ){
 Liste *BRAIN;
  BRAIN = tete ;
  if( !tete ){
    printf("la liste est vide ") ;
  }
  else{
    while( BRAIN ){
     afficher_prodruit( BRAIN ) ;
     BRAIN = BRAIN->psuiv ; 
    }
  }
}
int longeur( Liste* tete ){
 int LENGHT = 0;
 Liste* BRAIN;
  while( BRAIN ){
    BRAIN = BRAIN->psuiv ;
    LENGHT++ ;
  } 
 return LENGHT ; 
}
void filtrer_date( Liste* tete , Date dt ){
 Liste *BRAIN = tete;
  while( BRAIN ){
    if( strcmp(BRAIN->cellule.DateAchat.annee,dt.annee) == 0 && strcmp(BRAIN->cellule.DateAchat.mois,dt.mois) == 0 && strcmp(BRAIN->cellule.DateAchat.jour,dt.jour) == 0){
      afficher_prodruit(BRAIN) ;
    }
    BRAIN = BRAIN->psuiv ;
  }
}
Liste* supprimer_debut( Liste* tete ){
 Liste *BRAIN;
  BRAIN = tete ;
  tete = tete->psuiv ;
  free(BRAIN) ;
 return tete ; 
}
Liste* supprimer_fin( Liste* tete ){
 Liste *BRAIN;
 if( !tete ){
  printf("la liste est vide ") ;
 } 
 else{
  if( !(tete->psuiv) ){
    free(tete) ;
    tete = NULL ;
  }
  else{
    BRAIN = tete ;
    while( BRAIN->psuiv->psuiv ){
      BRAIN = BRAIN->psuiv ;
    }
    free( BRAIN->psuiv ) ;
    BRAIN->psuiv = NULL ;
  }
 }
 return tete ;
}
Liste* rembourser( Liste* liste , char* refer ){
 Liste *BRAIN, *PREVBRAIN;
 if( liste ){
  BRAIN = liste ;
  while( BRAIN ){
    if( strcmp(BRAIN->cellule.Reference,refer) == 0 ){
      if( BRAIN == liste ){
        liste = supprimer_debut(liste) ;
        BRAIN = liste ;
      }
      else{
        if( !(BRAIN->psuiv) ){
          liste = supprimer_fin(liste) ;
          break ;
        }
        else{
          BRAIN = BRAIN->psuiv ;
          free(PREVBRAIN->psuiv) ;
          PREVBRAIN->psuiv = BRAIN ;
        }
      }
    }
    PREVBRAIN = BRAIN ;
    BRAIN = BRAIN->psuiv ;
  }
 } 
 return liste ;
}
int main(){
 Liste *HEAD, *BRAIN, *SEMIBRAIN;
 int TAILLE , I;
 char *REF;
 Date dt;
  HEAD = creer_liste_produits() ;
  I = est_vide(HEAD) ;
  do{
    printf("saisir la taillede la liste") ;
    scanf("%d",&TAILLE) ;
  }while( TAILLE <= 0 ) ;
  for( I = 1 ; I <= TAILLE ; I++ ){
    HEAD = ajouter_debut(HEAD) ;
  } 
  afficher_produits(HEAD) ;
  HEAD = ajouter_fin(HEAD) ;
  afficher_produits(HEAD) ;
  I = longeur(HEAD) ;
  printf("saisir le jour : ") ;
  scanf(" %s",dt.jour) ;
  dt.jour[2] = '\0' ;
  printf("saisir le mois : ") ;
  scanf(" %s",dt.mois) ;
  dt.mois[2] = '\0' ;
  printf("saisir l'année : ") ;
  scanf(" %s",dt.annee) ;
  dt.mois[4] = '\0' ;
  filtrer_date(HEAD,dt) ;
  HEAD = supprimer_debut(HEAD) ;
  afficher_produits(HEAD) ;
  HEAD = supprimer_fin(HEAD) ;
  afficher_produits(HEAD) ;
  do{
    printf("saisir le nombre de caractereres dans la referrence : ") ;
    scanf("%d",I) ;
  }while( I <= 0 ) ;
  REF = (char*)malloc( (I+1) * sizeof(char) ) ;
  if( REF ){
    printf("saisir la reference : ") ;
    fgets(REF,I+1,stdin) ;
  }
  HEAD = rembourser(HEAD,REF) ;
  afficher_produits(HEAD) ;
  free(REF) ;
  BRAIN = HEAD ;
  while( BRAIN ){
    SEMIBRAIN = BRAIN ;
    free( SEMIBRAIN->cellule.Nom_produit ) ;
    BRAIN = BRAIN->psuiv ;
    free(SEMIBRAIN) ;
  }   
  HEAD = NULL ;           
 return 0 ;
}
#include<stdio.h>
#include<string.h>
#include<strings.h>
#include"livre.h"
#include"client.h"
#include"emprunt.h"
#include"menu.h"
#include"save.h"



int main () {

    int a, b, c ;

    int d ;


    Livre livres[MAX_LIVRES];

    Client clients[MAX_CLIENT] ;

    Emprunt emprunts[MAX_EMPRUNT] ;


    for(a = 0 ; a<MAX_LIVRES ; a++) {
        livres[a].id = 0 ; 
    }

    for(b = 0 ; b<MAX_CLIENT ; b++) {
        clients[b].id = 0 ;
    }

    for(c = 0 ; c<MAX_EMPRUNT ; c++) {
        emprunts[c].id_emprunt = 0 ;
    }








    int e = chargelivres(livres) ;

    int f = chargeclients(clients) ;

    int g = chargeemprunts(emprunts) ;





    do {



        printf("================================================================== \n");
        printf("                   BIBLIOTHÈQUE DE MAX-STEVEN \n");
        printf("================================================================== \n \n \n");

        printf(" 1. Gestion des livres \n");
        printf(" 2. Gestion des clients \n");
        printf(" 3. Gestion des emprunts \n");
        printf(" 4. Quitter \n\n\n");

        printf("Tapez le numéro de l'action que vous souhaitez effectuer \n");
        scanf("%d",&d);
        viderbuffer() ;


        switch (d)
        {
        case 1:
            menulivres(livres) ;
            break;

        case 2:
            menuclients(clients) ;
            break ;

        case 3:
            menuemprunts(emprunts, livres, clients) ;
            break ;

        case 4:
            printf("Aurevoir\n");
            savelivres(livres, compteLivres(livres)) ;
            saveclients(clients, compteclients(clients)) ;
            saveemprunts(emprunts, compteemprunt(emprunts)) ;
            break ;
        
        default:
            printf("Saisie invalide \n\n\n\n");
            break;
        }



    } while(d != 4) ;







    return 0 ;








}
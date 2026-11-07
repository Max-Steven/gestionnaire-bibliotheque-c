#include<stdio.h>
#include<string.h>
#include<strings.h>
#include"livre.h"
#include"client.h"
#include"emprunt.h"
#include"menu.h"




void menulivres(Livre livres[]) {

    int a, b, c, d ;

    do {

        printf(" 1. Afficher tout les livres \n");
        printf(" 2. Compter les livres \n");
        printf(" 3. Ajouter un livre \n");
        printf(" 4. Modifier un livre \n");
        printf(" 5. Rechercher un livre \n");
        printf(" 6. Supprimer un livre \n");
        printf(" 7. Quitter \n");

        printf(" Tapez le numéro de l'action que vous souhaitez effectuer \n");
        scanf("%d",&a);
        viderbuffer() ;

        switch (a) {
        
            case 1:
                afficherallLivres(livres) ;
                break;

            case 2:
                do {
                    printf(" 1. Nombre total de livres \n");
                    printf(" 2. Nombre d'exemplaires d'un livre \n");
                    printf(" 3. Nombre d'exemplaires disponibles d'un livre \n");
                    printf(" 4. Quitter \n");

                    printf("Tapez le numéro de l'action que vous souhaitez effectuer \n");
                    scanf("%d",&b);
                    viderbuffer() ;

                    switch (b) {
                    
                        case 1:
                            affnbreLivres(livres) ;
                            break;

                        case 2:
                            affichnbretotalLivres(livres) ;
                            break;

                        case 3:
                            affichnbredispoLivres(livres) ;
                            break;

                        case 4:
                            printf("Aurevoir \n\n\n");
                            break;
                        
                        default:
                            printf("Saisie invalide \n");
                            break;

                    }


                } while (b != 4) ;

                break ;




            case 3:
                ajouterLivres(livres) ;
                break;

            case 4:
                modifierLivres(livres) ;
                break ;

            case 6:
                do {
                    printf(" 1. Supprimer un livre \n");
                    printf(" 2. Supprimer tous les livres \n");
                    printf(" 3. Quitter \n");

                    printf("Tapez le numéro de l'action à afficher \n");
                    scanf("%d",&c);
                    viderbuffer() ;

                    switch (c) {
                    
                        case 1:
                            suppLivres(livres) ;
                            break;
                        
                        case 2:
                            suppallLivres(livres) ;
                            break;

                        case 3:
                            printf("Aurevoir \n\n\n");
                            break;

                        default:
                            printf("Saisie invalide \n");
                            break;

                    }


                } while (c != 3) ;

                break ;




            case 7:
                printf("Aurevoir \n\n\n");
                break;


            case 5:
                do {
                    printf(" 1. Rechercher par identifiant \n");
                    printf(" 2. Rechercher par titre \n");
                    printf(" 3. Quitter \n");

                    printf("Tapez le numéro de l'action à afficher \n");
                    scanf("%d",&d);
                    viderbuffer() ;

                    switch(d) {

                        case 1:
                            afficherLivresid(livres) ;
                            break;

                        case 2:
                            afficherLivrestitre(livres) ;
                            break;

                        case 3:
                            printf("Aurevoir \n\n\n");
                            break;

                        default:
                            printf("Saisie invalide \n");
                            break;

                    }

                } while(d != 3) ;

                break;


            default :
                printf("Saisie invalide \n\n\n");
                break ;



        }




    } while (a != 7) ;








}










void menuclients(Client clients[]) {

    int a, b ;

    do {
        printf(" 1. Afficher tous les clients \n");
        printf(" 2. Compter les clients \n");
        printf(" 3. Ajouter un client \n");
        printf(" 4. Modifier un client \n");
        printf(" 5. Rechercher un client \n");
        printf(" 6. Supprimer un client \n");
        printf(" 7. Quitter \n");

        printf(" Tapez le numéro de l'action à effectuer \n");
        scanf("%d",&a);
        viderbuffer() ;

        switch (a) {
        

            case 1:
                afficherallclients(clients) ;
                break;

            case 2:
                affnbreclients(clients) ;
                break ;

            case 3:
                ajouterclients(clients) ;
                break ;

            case 4:
                modifierclients(clients) ;
                break;

            case 5:
                afficherclients(clients) ;
                break ;

            case 7:
                printf("Aurevoir \n");
                break ;

            case 6:
                do {
                    printf(" 1. Supprimer un client \n");
                    printf(" 2. Supprimer tous les clients \n");
                    printf(" 3. Quitter \n");

                    printf(" Tapez le numéro de l'action à effectuer \n");
                    scanf("%d",&b);
                    viderbuffer() ;

                    switch (b) {
                    
                    case 1:
                        suppclients(clients) ;
                        break;

                    case 2:
                        suppallclients(clients) ;
                        break;

                    case 3:
                        printf("Aurevoir \n");
                        break;
                    
                    default:
                        printf("Saisie invalide \n");
                        break;
                    }


                } while (b != 3) ;

                break;
                


            default:
                printf("Saisie invalide \n");
                break;



        }



    } while (a != 7) ;


}










void menuemprunts(Emprunt emprunts[], Livre livres[], Client clients[]) {

    int a, b ;

    do {
        
        printf(" 1. Afficher tous les emprunts \n");
        printf(" 2. Compter les emprunts \n");
        printf(" 3. Ajouter un emprunt \n");
        printf(" 4. Rechercher un emprunt \n");
        printf(" 5. Supprimer un emprunt \n");
        printf(" 6. Quitter \n");

        printf(" Tapez le numéro de l'action à effectuer \n");
        scanf("%d",&a);
        viderbuffer() ;

        switch (a) {

            case 1:
                afficherlesemprunt(emprunts) ;
                break;

            case 2:
                affichnbreemprunt(emprunts) ;
                break ;

            case 3:
                ajouteremprunt(emprunts, livres, clients) ;
                break ;

            case 5:
                supprimeremprunt(emprunts, livres) ;
                break ;

            case 6:
                printf("Aurevoir \n");
                break ;

            case 4:
                do {
                    printf(" 1. Rechercher un livre emprunté \n");
                    printf(" 2. Rechercher un client emprunteur \n");
                    printf(" 3. Quitter \n");

                    printf(" Tapez le numéro de l'action à effectuer \n");
                    scanf("%d",&b);
                    viderbuffer() ;

                    switch (b) {
                    
                        case 1:
                            searchlivreemprunt(emprunts, clients) ;
                            break;

                        case 2:
                            searchclientemprunt(emprunts, livres) ;
                            break ;

                        case 3:
                            printf("Aurevoir \n");
                            break ;
                        
                        default:
                            printf("Saisie invalide \n");
                            break;


                    }


                } while (b != 3) ;


            default:
                printf("Saisie invalide \n");
                break;


        }



    } while(a != 6) ;



}




































































































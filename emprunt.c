#include<stdio.h>
#include<string.h>
#include<strings.h>
#include"livre.h"
#include"client.h"
#include"emprunt.h"





int compteemprunt(Emprunt emprunts[]) {
    int a, b=0 ;
    for(a=0 ; a<MAX_EMPRUNT ; a++) {
        if(emprunts[a].id_emprunt != 0) {
            b++ ;
        }

        else {
            break ;
        }

    }

    return b ;




}





void afficherlesemprunt(Emprunt emprunts[]) {
    int a ;
    int b = compteemprunt(emprunts) ;

    if(b == 0) {
        printf("Il n'y a aucun emprunt à afficher \n\n\n");
    }

    else {
        for(a=0 ; a<b ; a++) {
            printf("Identifiant de l'emprunt : %d \n", emprunts[a].id_emprunt);
            printf("Identifiant du livre emprunté : %d \n" , emprunts[a].id_livre);
            printf("Identifient de l'emprunteur : %d \n" , emprunts[a].id_client);
            
        }

    }

}





void afficheremprunt(Emprunt emprunts[]) {
    int a, b ;
    int c = compteemprunt(emprunts) ;
    int d = 0 ;

    printf("Veuillez entrer l'identifiant de l'emprunt que vous souhaitez afficher");
    scanf("%d",&a);
    viderbuffer() ;
    
    if(a == 0) {
        printf("Cet emprunt n'a pas été enregistré \n");
    }

    else {
        for(b=0 ; b<c ; b++) {
            if(emprunts[b].id_emprunt == a) {
                printf("Identifiant de l'emprunt : %d \n", emprunts[b].id_emprunt);
                printf("Identifiant du livre emprunté : %d \n" , emprunts[b].id_livre);
                printf("Identifient de l'emprunteur : %d \n" , emprunts[b].id_client);
                d++ ;
                break ;
            }
        }

        if(d == 0) {
            printf("Cet emprunt n'a pas été enregistré \n");
        }
    }


}





void supprimeremprunt(Emprunt emprunts[] , Livre livres[]) {
    int a, b, d, f ;
    int e = 0 ;
    int c = compteemprunt(emprunts) ;

    printf("Veuillez entrer l'identifiant de l'emprunt que vous souhaitez supprimer \n");
    scanf("%d",&a);
    viderbuffer() ;

    if(a == 0) {
        printf("Cet emprunt n'a pas été enregistré \n ");
    }

    else {

        for(b = 0 ; b<c ; b++) {

            if(emprunts[b].id_emprunt == a) {

                emprunts[b].id_emprunt = 0 ;

                f = karl(livres , emprunts[b].id_livre) ;

                strcpy(livres[f].statut , "Disponible") ;

                for(d = b+1 ; d<c ; d++ ) {
                    emprunts[d-1] = emprunts[d] ;
                }

                emprunts[MAX_EMPRUNT].id_emprunt = 0 ;

                printf("La suppression a bien été effectuée \n");
                e ++ ;

                break ;

            }

        }

        if( e == 0 ) {
            printf("Cet emprunt n'a pas été enregistré \n");

        }

    }

}





int karl(Livre livres[] , int k) {
    int a ;
    for(a=0 ; a<compteLivres(livres) ; a++) {
        if(livres[a].id == k) {
            break ;
        }

    }

    return a ;


}





int kool(Client clients[] , int k) {
    int a ;
    for(a=0 ; a<compteclients(clients) ; a++) {
        if(clients[a].id == k) {
            break ;
        }

    }

    return a ;

}





void affichnbreemprunt (Emprunt emprunts[]) {
    int a ;
    a = compteemprunt(emprunts) ;

    printf("%d emprunts ont été effectués", a);

}





void ajouteremprunt(Emprunt emprunts[] , Livre livres[] , Client clients[]) {
    int a, c ;
    int b = compteemprunt(emprunts) ;

    searchLivresid(livres) ;
    searchidclients(clients) ;

    a = searchLivresid(livres) ;
    c = searchidclients(clients) ;

    if(strcasecmp(livres[a].statut , "Disponible") == 0) {
        emprunts[b].id_livre = livres[a].id ;
        strcpy(livres[a].statut , "Emprunté" ) ;
        emprunts[b].id_client = clients[c].id ;
        emprunts[b].id_emprunt =  (a * livres[a].id) + (c * clients[c].id) ;
        printf("Identifiant de l'emprunt : %d \n" , emprunts[b].id_emprunt);
    }

    else {
        printf("Ce livre a déjà été emprunté");
    }


}





void searchlivreemprunt(Emprunt emprunts[] , Client clients[]) {
    int a, b ;
    int f ;
    int d = 0 ;
    int c = compteemprunt(emprunts) ;
    printf("Veuillez entrer l'identifiant du livre");
    scanf("%d", &a);
    viderbuffer() ;

    for(b=0 ; b<c ; b++) {

        if( (emprunts[b].id_livre == a) && (a != 0))  {
            printf("Ce livre a été emprunté par le client dont l'identifiant est : %d \n", emprunts[b].id_client);
            f = kool(clients , emprunts[b].id_client) ;
            printf("Identifiant de l'emprunt : %d", emprunts[b].id_emprunt);
            printf("Nom et prénoms du client : %s %s" , clients[f].nom , clients[f].prenom);
            printf("Numéro de téléphone du client : %d " , clients[f].tel);
            d++ ;
            break ;

        } 
    }


    if(d == 0) {
        printf("Ce livre n'a pas été emprunté");

    }

}





void searchclientemprunt(Emprunt emprunts[] , Livre livres[]) {
    int a, b, f ;
    int d = 0 ;
    int c = compteemprunt(emprunts) ;
    printf("Veuillez entrer l'identifiant du client");
    scanf("%d", &a);
    viderbuffer() ;

    for(b=0 ; b<c ; b++) {
        if(emprunts[b].id_client == a && a != 0) {
            printf("Ce client a emprunté le livre ayant pour identifiant : %d " , emprunts[b].id_livre);
            f = karl(livres , emprunts[b].id_livre) ;
            printf("Identifiant de l'emprunt : %d" , emprunts[b].id_emprunt);
            printf("Titre du livre : %s" , livres[f].titre);
            d++ ;
            break ;

        }

    }


    if(d == 0) {
        printf("Ce client n'a emprunté aucun livre");
    }

}





























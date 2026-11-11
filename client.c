#include<stdio.h>
#include<string.h>
#include<strings.h>
#include"livre.h"
#include"client.h"



int compteclients(Client clients[]) {
    int a, b=0 ;
    for(a=0 ; a<MAX_CLIENT ; a++) {
        if(clients[a].id != 0) {
            b++ ;
        }
    }

    return b ;

}





void affnbreclients(Client clients[]) {
    int a;
    a=compteclients(clients) ;
    printf("Le nombre de clients inscrits à cette bibliothèque est %d \n", a);
}





int searchclientsid(Client clients[] , int k) {
    int a = compteclients(clients) ;
    int b ;
    int c = 0 ;

    if (k != 0) {
        for(b=0 ; b<MAX_CLIENT ; b++) {
            if(clients[b].id == k) {
                c = 1 ;
                break ;
            }
        }
    }

    return c ;

}





void afficherallclients(Client clients[]) {
    int a ;
    int b=0 ;
    for(a=0 ; a<MAX_CLIENT ; a++) {
        if(clients[a].id != 0) {
            printf("Identifiant : %d \nNom : %s \nPrénoms : %s \nNuméro de téléphone : %d \n", clients[a].id , clients[a].nom , clients[a].prenom , clients[a].tel);
            printf("\n\n");
            b++ ;
        }

        else {
            break ;
        }

    }

    if(b == 0) {
        printf("Il n'y a aucun client enregistré \n\n\n");
    }

}





void suppallclients(Client clients[]) {
    char a[100] ;
    int b ;
    printf("Souhaitez vous vraiment supprimer tous les clients enregistrés dans cette bibliothèque ? \n");
    printf("Répondez par \"Oui\" ou par \"Non\" \n");
    fgets(a, sizeof(a) , stdin) ;
    a[strcspn(a,"\n")] = '\0' ;
    if(strcasecmp(a , "Oui") == 0) {
        for(b=0 ; b<MAX_CLIENT ; b++) {
            clients[b].id = 0 ;
        }
        printf("La suppression a bien été effectuée \n");
    }

    else {
        printf("Aucune suppression n'a été effectuée \n");
    }

}





int searchidclients(Client clients[]) {
    int a, b, c ;

    printf("Veuillez entrer l'identifiant du client");
    scanf("%d",&a);
    viderbuffer() ;
    c = searchclientsid(clients , a) ;
    if(c == 0) {
        do {
            printf("Ce client n'existe pas. \nVeuillez entrer l'identifiant du client ");
            scanf("%d",&a);
            viderbuffer() ;
        } while (c == 0) ;
    }


    for(b=0 ; b<MAX_CLIENT ; b++) {
        if(clients[b].id == a) {
            break ;
        }
    }


    return b ;

}





void suppclients(Client clients[]) {
    int a , b ;
    a = searchidclients(clients) ;
    clients[a].id = 0 ;

    for(b=a+1 ; b<MAX_CLIENT ; b++) {
        clients[b-1] = clients[b] ;
    }

    clients[MAX_CLIENT - 1].id = 0 ;

    printf("La suppression a bien été effectuée \n");
}





void ajouterclients(Client clients[]) {
    int a, d ;
    char b[100] ;
    char c[100] ;

    int p = compteclients(clients) ;

    if(p >= MAX_CLIENT) {
        printf("Nous ne pouvons pas ajouter un autre client en raison d'un espace insufisant \n");
    }

    else {
        printf("Veuillez écrire chaque information du client que vous souhaitez ajouter. \nValidez chaque information en appuyant sur la touche \"Entrer\" du clavier\n");

        printf("Identifiant : ");
        scanf("%d",&a);
        viderbuffer() ;
        if(searchclientsid(clients , a) == 1 || a == 0) {
            do {
                printf("Cet identifiant existe déjà ou ne peut pas être utilisé. \nIdentifiant : ");
                scanf("%d",&a);
                viderbuffer() ;
            } while (searchclientsid(clients , a) == 1 || a == 0) ;

        }

        printf("Nom :");
        fgets(b , sizeof(b) , stdin) ;
        b[strcspn(b,"\n")] = '\0' ;

        printf("Prénom :");
        fgets(c , sizeof(c) , stdin) ;
        c[strcspn(c,"\n")] = '\0' ;

        printf("Numéro de téléphone : ");
        scanf("%d",&d);
        viderbuffer() ;



        clients[p].id = a ;
        strcpy(clients[p].nom , b) ;
        strcpy(clients[p].prenom , c) ;
        clients[p].tel = d ;

    }

}





void modifierclients(Client clients[]) {
    int a, b, c, f ;
    char d[100] ;
    char e[100] ;

    a = searchidclients(clients) ;

    printf("Quel caractéristique souhaitez-vous modifier ? \n");
    printf("Tapez 1 si vous souhaitez modifier l'identifiant ; \nTapez 2 si vous souhaitez modifier le nom \n");
    printf("Tapez 3 si vous souhaitez modifier les prénoms ; \nTapez 4 si vous souhaitez modifier le numéro de téléphone\n");
    scanf("%d",&b);
    viderbuffer() ;

    if(b<=0 || b>=4) {
        do {
            printf("Tapez un chiffre compris entre 1 et 4");
            scanf("%d",&b);
            viderbuffer() ;
        } while (b<=0 || b>=4) ;
    }


    if(b == 1) {
        printf("Veuillez entrer l'identifiant par lequel vous souhaitez le remplacer \n ");
        scanf("%d",&c);
        viderbuffer() ;
        if(searchclientsid(clients , c) == 1 || c == 0) {
            do {
                printf("Impossible d'ajouter cet identifiant. \nVeuillez entrer l'identifiant par lequel vous souhaitez le remplacer");
                scanf("%d",&c);
                viderbuffer() ;
            } while(searchclientsid(clients , c) == 1 || c == 0) ;
        }

        clients[a].id = c ;
        printf("Le changement a bien été effectué \n");

    }

    if(b == 2) {
        printf("Veuillez entrer le nom par lequel vous souhaitez le remplacer \n");
        fgets(d , sizeof(d) , stdin) ;
        d[strcspn(d,"\n")] = '\0' ;
        strcpy(clients[a].nom , d) ;
        printf("Le changement a bien été effectué \n");
    }

    if(b == 3) {
        printf("Veuillez entrer les prénoms par lesquels vous souhaitez remplacer \n");
        fgets(e, sizeof(e) , stdin) ;
        e[strcspn(e,"\n")] = '\0' ;
        strcpy(clients[a].prenom , e) ;
        printf("Le changement a bien été effectué \n");
    }


    if(b == 4) {
        printf("Veuillez entrer le numéro de téléphone par lequel vous souhaitez le remplacer \n");
        scanf("%d",&f);
        viderbuffer() ;
        clients[a].tel = f ;
    }
}





void afficherlesclients(Client clients[] ,  int k) {
    int a ;

    if(k<=0) {
        printf("Aucun client à afficher \n");
    }


    else {
        for(a=0 ; a<k ; a++) {
            printf("Identifiant : %d \nNom : %s \n", clients[a].id , clients[a].nom);
            printf("Prénoms : %s \nNuméro de téléphone : %d \n\n\n" , clients[a].prenom , clients[a].tel);
        }
    }
}





void afficherclients(Client clients[]) {
    int a, b, d ;
    int e = 0 ;
    char c[100] ;

    printf("Tapez 1 pour une recherche par identifiant ; 2 pour une recherche par nom \n");
    scanf("%d",&a);
    viderbuffer() ;
    if(a <= 0 || a>= 3) {
        do {
            printf("Tapez un chiffre entre 1 et 2");
            scanf("%d",&a) ;
            viderbuffer() ;
        } while (a <= 0 || a>= 3) ;
    }


    if(a == 1) {
        b = searchidclients(clients) ;

        printf("Informations du client : \n");
        printf("Identifiant : %d \nNom : %s \n", clients[b].id , clients[b].nom);
        printf("Prénoms : %s \nNuméro de téléphone : %d \n\n\n" , clients[b].prenom , clients[b].tel);

    }


    if(a == 2) {
        printf("Veuillez entrer le nom du client que vous recherchez (Utilisez l'orthographe exacte) \n ");
        fgets(c, sizeof(c) , stdin) ;
        c[strcspn(c,"\n")] = '\0' ;

        for(d=0 ; d<compteclients(clients) ; d++) {
            if(strcasecmp(clients[d].nom , c) == 0 && clients[d].id != 0) {
                printf("Informations du client : \n");
                printf("Identifiant : %d \nNom : %s \n", clients[d].id , clients[d].nom);
                printf("Prénoms : %s \nNuméro de téléphone : %d \n\n\n" , clients[d].prenom , clients[d].tel);
                e++ ;
            } 
        }

        if(e==0) {
            printf("Ce client n'est pas enregistré \n");
        }

    }

}
















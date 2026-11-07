#include<stdio.h>
#include<string.h>
#include<strings.h>
#include"livre.h"


void afficherlesLivres(Livre livres[], int nombre) {
    if (nombre <= 0) {
        printf("Aucun livre à afficher \n" );
    }

    else if (nombre == 1) {
        printf("Informations du premier livre : \n");
        printf("Identifiant : %d \nTitre : %s \nAuteur : %s \n", livres[0].id, livres[0].titre, livres[0].auteur);
        printf("Code ISBN : %s \nAnnée de parution : %d \nStatut : %s \n", livres[0].ISBN, livres[0].annee, livres[0].statut);
        
    }
    
    else {
        printf("Informations des  %d premiers livres :\n", nombre);
        for(int i=0; i<nombre-1; i++) {
            printf("Identifiant : %d \nTitre : %s \nAuteur : %s \n", livres[i].id, livres[i].titre, livres[i].auteur);
            printf("Code ISBN : %s \nAnnée de parution : %d \nStatut : %s \n", livres[i].ISBN, livres[i].annee, livres[i].statut);
            printf("\n\n\n");   
        }

        printf("Identifiant : %d \nTitre : %s \nAuteur : %s \n", livres[nombre-1].id, livres[nombre-1].titre, livres[nombre-1].auteur);
        printf("Code ISBN : %s \nAnnée de parution : %d \nStatut : %s \n", livres[nombre-1].ISBN, livres[nombre-1].annee, livres[nombre-1].statut); 
    }

}





void viderbuffer(void) {
    int c ;
    while((c=getchar()) != '\n' && c != EOF) ;
}





int compteLivres(Livre livres[]) {
    int i, j=0 ;
    for(i=0; i<MAX_LIVRES; i++) {
        if (livres[i].id != 0) {
            j++ ;        
        }   
    }

    return j ;
}





int searchid(Livre livres[] , int k) {
    int a = compteLivres(livres) ;
    int b ;
    int c = 0 ;

    if(k != 0) {
        for(b=0 ; b<a ; b++) {
            if(livres[b].id == k) {
                c = 1 ;
                break ;
            }
        } 
    }
    
    return c ;   /*touche pas à ça mec*/
}





void ajouterLivres(Livre livres[]) {

    int a, e ;
    char b[100] ;
    char c[100] ;
    char d[16];
    char f[14] ;
    int p = compteLivres(livres) ;

    if (p >= MAX_LIVRES) {
        printf("Nous ne pouvons pas ajouter un autre livre en raison d'un espace insuffisant. \n");
    }

    else {
        printf("Veuillez écrire chaque information du livre que vous souhaitez ajouter. \nValidez chaque information en appuyant sur la touche \"Entrer\" du clavier.\n" );

        printf("\nIdentifiant : ") ;
        scanf("%d",&a);
        viderbuffer() ;
        if(searchid(livres , a) == 1 || a == 0) {
            do {
                printf("Cet identifiant existe déjà ou ne peut pas être utilisé.\nIdentifiant : ");
                scanf("%d", &a);
                viderbuffer() ;
            } while ( searchid(livres, a) == 1 || a == 0 ) ;
        }
        
        printf("Titre : ");
        fgets(b,sizeof(b) ,stdin);
        b[strcspn(b,"\n")] = '\0' ;

        printf("Auteur : ");
        fgets(c,sizeof(c) ,stdin);
        c[strcspn(c,"\n")] = '\0' ;

        printf("Code ISBN (Sans tiret et sans espace) : ");
        fgets(d,sizeof(d) ,stdin);
        d[strcspn(d,"\n")] = '\0' ;

        printf("Année de parution : ");
        scanf("%d",&e);
        viderbuffer() ;

        printf("Statut (\"Emprunté\" ou \"Disponible\". Respectez la graphie des mots) : ");
        fgets(f,sizeof(f) ,stdin) ;
        f[strcspn(f,"\n")] = '\0' ;
        if ((strcmp(f,"Emprunté")!=0 && strcmp(f,"Disponible")!=0)) {
            do {
                printf("Ce format n'est pas reconnu. \nStatut (\"Emprunté\" ou \"Disponible\". Respectez la graphie des mots) : ");
                fgets(f,sizeof(f) ,stdin) ;
                f[strcspn(f,"\n")] = '\0' ;
            } while (strcmp(f,"Emprunté")!=0 && strcmp(f,"Disponible")!=0);
        }

        livres[p].id = a;
        strcpy(livres[p].titre,b);
        strcpy(livres[p].auteur, c);
        strcpy(livres[p].ISBN , d) ;
        livres[p].annee = e;
        strcpy(livres[p].statut, f);

    } 


}





int searchLivresid(Livre livres[]) {
    int a, b ;

    printf("Veuillez entrer l'identifiant du livre \n");
    scanf("%d",&a);
    viderbuffer() ;
    if(searchid(livres,a) == 0 ) {
        do {
            printf("Ce livre n'existe pas. \nVeuillez entrer l'identifiant du livre ");
            scanf("%d",&a);
            viderbuffer() ;
        } while (searchid(livres,a) == 0) ;
    }

    for (b=0 ; b<compteLivres(livres); b++) {
        if(livres[b].id == a) {
            break ;
        }
    }

    return b ;

}





void modifierLivres(Livre livres[]) {
    int a, b, c, g ;
    char d[100] ;
    char e[100] ;
    char f[16] ;
    char h[14] ;

    a = searchLivresid(livres) ;
    printf("Quel caractéristique souhaitez-vous modifier ? \n");
    printf("Tapez 1 si vous souhaitez modifier l'identifiant ; \nTapez 2 si vous souhaitez modifier le titre ; \nTapez 3 si vous souhaitez modifier le nom de l'auteur ; \nTapez 4 si vous souhaitez modifier le code ISBN ; \n");
    printf("Tapez 5 si vous souhaitez modifier l'année de parution ; \nTapez 6 si vous souhaitez modifier le statut \n");
    scanf("%d",&b);
    viderbuffer() ;

    if(b<=0 || b>=7) {
        do {
            printf("Tapez un chiffre compris entre 1 et 7 \n");
            scanf("%d",&b);
            viderbuffer() ;
        } while (b<=0 || b>=7) ;
    }

    if (b==1) {
        printf("Veuillez écrire l'identifiant par lequel vous souhaitez le remplacer");
        scanf("%d",&c);
        viderbuffer() ; 

        if(searchid(livres , c) == 1 || c == 0) {
            do {
                printf("Impossible d'ajouter cet identifiant \nVeuillez écrire l'identifiant par lequel vous souhaitez le remplacer ");
                scanf("%d",&c);
                viderbuffer() ;
            } while(searchid(livres , c) == 1 || c == 0) ;
        }

        livres[a].id = c ;
        printf("\nLe changement a bien été effectué \n");
    }

    if(b==2) {
        printf("Veuillez écrire le titre par lequel vous souhaitez le remplacer");
        fgets(d,sizeof(d) ,stdin) ;
        d[strcspn(d,"\n")] = '\0' ;
        strcpy(livres[a].titre , d) ;
        printf("\nLe changement a bien été effectué \n");
    }

    if(b==3) {
        printf("Veuillez écrire le nom de l'auteur par lequel vous souhaitez le remplacer");
        fgets(e,sizeof(e) ,stdin) ;
        e[strcspn(e,"\n")] = '\0' ;
        strcpy(livres[a].auteur , e) ;
        printf("\nLe changement a bien été effectué \n");
    }

    if(b==4) {
        printf("Veuillez écrire le code ISBN par lequel vous souhaitez le remplacer");
        fgets(f,sizeof(f) ,stdin) ;
        f[strcspn(f,"\n")] = '\0' ;
        strcpy(livres[a].ISBN , f) ;
        printf("\nLe changement a bien été effectué \n");
    }

    if(b==5) {
        printf("Veuillez écrire l'année de parution par laquelle vous souhaitez la remplacer");
        scanf("%d",&g);
        viderbuffer() ;
        livres[a].annee = g ;
        printf("\nLe changement a bien été effectué \n");
    }

    if(b==6) {
        printf("Veuillez entrer le nouveau statut du livre. Écrivez \"Emprunté\" ou \"Disponible\". Respectez la graphie des mots ");
        fgets(h,sizeof(h) ,stdin) ;
        h[strcspn(h,"\n")] = '\0' ;
        if(strcmp(h,"Emprunté")!=0 && strcmp(h,"Disponible")!=0) {
            do {
                printf("La modification ne peut pas être faite. \nVeuillez entrer le nouveau statut du livre. Écrivez \"Emprunté\" ou \"Disponible\". Respectez la graphie des mots ");
                fgets(h,sizeof(h) ,stdin) ;
                h[strcspn(h,"\n")] = '\0' ;
            } while (strcmp(h,"Emprunté")!=0 && strcmp(h,"Disponible")!=0);
        }
        strcpy(livres[a].statut , h) ;
        printf("\nLe changement a bien été effectué \n");
    }

}





void afficherLivresid(Livre livres[]) {
    int a ;
    a = searchLivresid(livres) ;

    printf("Informations du livre : \n");
    printf("Identifiant : %d \nTitre : %s \nAuteur : %s \n", livres[a].id, livres[a].titre, livres[a].auteur);
    printf("Code ISBN : %s \nAnnée de parution : %d \nStatut : %s \n", livres[a].ISBN, livres[a].annee, livres[a].statut);
}





void affnbreLivres(Livre livres[]) {
    int a = compteLivres(livres) ;
    printf("Il y a %d livres dans la bibliothèque \n", a);
}





void afficherLivrestitre(Livre livres[]) {
    int a, c=1 ;
    char b[100] ;
    printf("Veuillez entrer le titre du livre que vous recherchez (Utilisez l'orthographe exacte)");
    fgets(b,sizeof(b) ,stdin) ;
    b[strcspn(b,"\n")] = '\0' ;

    for(a=0 ; a<compteLivres(livres) ; a++) {
        if(strcasecmp(livres[a].titre , b) == 0  && livres[a].id != 0) {
            printf("Livre %d trouvé \n", c);
            printf("Identifiant : %d \nTitre : %s \nAuteur : %s \n", livres[a].id, livres[a].titre, livres[a].auteur);
            printf("Code ISBN : %s \nAnnée de parution : %d \nStatut : %s \n", livres[a].ISBN, livres[a].annee, livres[a].statut);
            printf("__________________________________________________________________________ \n");
            c++ ;
        }
    }

    if(c==1) {
        printf("Ce livre n'existe pas dans la bibliothèque \n");
    }

}





void affichnbretotalLivres(Livre livres[]) {
    int a, c=0 ;
    char b[100] ;
    printf("Veuillez entrer le titre du livre (Utilisez l'orthographe exacte)");
    fgets(b,sizeof(b) ,stdin) ;
    b[strcspn(b,"\n")] = '\0' ;
    for(a=0 ; a<compteLivres(livres) ; a++) {
        if(strcasecmp(livres[a].titre , b) == 0  &&  livres[a].id != 0) {
            c++ ;
        }
    }

    printf("Il y a exactement %d exemplaires de ce livre \n", c);
}





void affichnbredispoLivres(Livre livres[]) {
    int a, c=0 ;
    char b[100] ;
    printf("Veuillez entrer le titre du livre (Utilisez l'orthographe exacte)");
    fgets(b,sizeof(b) ,stdin) ;
    b[strcspn(b,"\n")] = '\0' ;
    for(a=0 ; a<compteLivres(livres) ; a++) {
        if(strcasecmp(livres[a].titre , b) == 0 && livres[a].id != 0) {
            if(strcasecmp(livres[a].statut , "Disponible") == 0) {
                c++ ;
            }
        }
    }

    printf("Il y a exactement %d exemplaires disponibles de ce livre \n", c);
}





void suppLivres(Livre livres[]) {
    int a, b ;
    a = searchLivresid(livres) ;
    livres[a].id = 0 ;
    for(b=a+1 ; b<MAX_LIVRES ; b++) {
        livres[b-1] = livres[b] ;
    }
    livres[MAX_LIVRES].id = 0 ;

    printf("\nLa suppression a bien été effectuée \n");

}





void suppallLivres(Livre livres[]) {
    int b ;
    char a[100] ;
    printf("Souhaitez vous vraiment supprimer tous les livres de la bibliothèque ? \nRépondez par \"Oui\" ou par \"Non\" ");
    fgets(a, sizeof(a), stdin) ;
    a[strcspn(a,"\n")] = '\0' ;
    if(strcasecmp(a , "Oui") == 0) {
        for(b=0; b<MAX_LIVRES ; b++) {
            livres[b].id = 0 ;
        }
        printf("La suppression a bien été effectuée \n");
    }

    else {
        printf("Aucune suppression n'a été effectuée \n");
    }
}





void afficherallLivres(Livre livres[]) {
    int a ;
    int b = 0 ;
    for(a=0 ; a<MAX_LIVRES ; a++) {
        if(livres[a].id != 0) {
            printf("Identifiant : %d \nTitre : %s \nAuteur : %s \n", livres[a].id, livres[a].titre, livres[a].auteur);
            printf("Code ISBN : %s \nAnnée de parution : %d \nStatut : %s \n", livres[a].ISBN, livres[a].annee, livres[a].statut);
            printf("\n\n\n"); 
            b++ ;
        }
        else {
            break ;
        }
    
    }

    if(b == 0) {
        printf("Il n'y a aucun livre dans la bibliothèque \n\n\n");
    }



}




























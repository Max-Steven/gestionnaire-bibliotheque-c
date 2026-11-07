#ifndef LIVRE_H
#define LIVRE_H

#define MAX_LIVRES 100

typedef struct {
    int id;
    char titre[100];
    char auteur[100];
    char ISBN[16] ;
    int annee;
    char statut[14];
} Livre;




void afficherallLivres(Livre livres[]) ; /*done*/ /*afficher les (nbres) premiers livres de la bibliothèque (pour le client) */

void suppLivres(Livre livres[]); /*supprimer un livre (pour le client) */

void suppallLivres(Livre livres[]) ; /*supprimer la bibliothèque (pour le client) */

void ajouterLivres(Livre livres[]); /*ajouter un livre (pour le client) */

void modifierLivres(Livre livres []); /*modifier les informations d'un livre (pour le client) */

void afficherLivresid(Livre livres[]); /*afficher un livre à partir de son id (pour le client) */

void afficherLivrestitre(Livre livres[]); /*afficher tt les exemplaires d'un livre à partir de son titre (pour le client) */

void affnbreLivres(Livre livres []); /*afficher le nbre de livres dans la bibliothèque (pour le client) */

void affichnbretotalLivres(Livre livres[]); /*afficher le nombre total d'exemplaires d'un livre (pour le client) */

void affichnbredispoLivres(Livre livres[]); /*afficher le nombre d'exemplaires disponibles pour un livre (pour le client) */

int compteLivres(Livre livres[]); /*compter le nombre de livres dans le tableau*/

int searchid(Livre livres[], int k); /* (touche pas à ça mec)    savoir si un identifiant tapé par le client existe dans le tableau*/

int searchLivresid(Livre livres[]) ; /*donner la position d'un livre dans le tableau à partir de son id*/

void viderbuffer(void) ; /*vider le buffer. utiliser après chaque scanf */

void afficherlesLivres(Livre livres[], int nombre); /*afficher tt les (nombre) premiers livres */  







































#endif




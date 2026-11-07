#ifndef EMPRUNT_H
#define EMPRUNT_H

#include"livre.h"
#include"client.h"

#define MAX_EMPRUNT 100

typedef struct {
    int id_emprunt ;
    int id_livre ;
    int id_client ;

} Emprunt ;



void afficherlesemprunt(Emprunt emprunts[]) ; /*afficher tt les emprunts*/

void ajouteremprunt(Emprunt emprunts[] , Livre livres[] , Client clients[]) ; /*ajouter un emprunt*/

void supprimeremprunt(Emprunt emprunts[] , Livre livres[]) ; /*supprimer un emprunt*/

int compteemprunt(Emprunt emprunts[]) ; /*compter le nombre d'emprunts*/

void affichnbreemprunt(Emprunt emprunts[]) ; /*afficher le nombre d'emprunts*/

void searchlivreemprunt(Emprunt emprunts[] , Client clients[]) ; /*savoir si un livre a été emprunté et donne id, nom et prénom de l'emprunteur*/

void searchclientemprunt(Emprunt emprunts[] , Livre livres[]) ; /*savoir si un client a emprunté un livre et donne id et titre du livre*/

void afficheremprunt(Emprunt emprunts[]) ; /*afficher un emprunt à partir de son id*/

int karl(Livre livres[] , int k) ; /*donner la position d'un livre dans le tableau à partir de son id*/

















#endif
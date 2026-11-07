#ifndef CLIENT_H
#define CLIENT_H

#define MAX_CLIENT 100

typedef struct {
    int id;
    char nom[100] ;
    char prenom[100] ;
    int tel;
} Client;

void afficherallclients(Client clients[]) ; /*afficher tt les clients (pour le client) */

void suppallclients(Client clients[]) ; /*supprimer tt les clients (pour le client) */

void suppclients(Client clients[]) ; /*supprimer un client*/

void ajouterclients(Client clients[]) ; /*ajouter un client (pour le client) */

void afficherclients(Client clients[]) ; /*afficher un client à partir de son identifiant ou de son nom (pour le client) */

void affnbreclients(Client clients[]) ; /*afficher le nombre de clients (pour le client) */

void modifierclients(Client client[]) ; /*modifier les informations d'un client*/

int compteclients(Client clients[]) ; /*compter le nombre de clients dans la bibliothèque*/

int searchclientsid(Client clients[] , int k) ; /*savoir si un identifiant tapé par le client existe dans le tableau*/

int searchidclients(Client clients[]) ; /*donner la position d'un client dans le tableau à partir de son identifiant*/

void afficherlesclients(Client clients[] , int k) ; /*afficher les (nbre) premiers clients de la bibliothèque */










































#endif
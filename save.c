#include<stdio.h>
#include<string.h>
#include<strings.h>
#include"livre.h"
#include"client.h"
#include"emprunt.h"
#include "save.h"



void savelivres(Livre livres[], int a) {

    FILE *fichier = fopen("livres.dat", "wb");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fwrite(&a, sizeof(int), 1, fichier);

    fwrite(livres, sizeof(Livre), a, fichier);

    fclose(fichier);
}





int chargelivres(Livre livres[]) {

    FILE *fichier = fopen("livres.dat", "rb");

    int nombre = 0;

    if (fichier == NULL) {
        return 0;
    }

    if (fread(&nombre, sizeof(int), 1, fichier) != 1) {
        fclose(fichier);
        return 0;
    }

    if (nombre < 0 || nombre > MAX_LIVRES) {
        fclose(fichier);
        return 0;
    }

    if (fread(livres, sizeof(Livre), nombre, fichier) != (size_t)nombre) {
        fclose(fichier);
        return 0;
    }

    fclose(fichier);

    return nombre;
}





void saveclients(Client clients[], int a) {

    FILE *fichier = fopen("clients.dat", "wb");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fwrite(&a, sizeof(int), 1, fichier);

    fwrite(clients, sizeof(Client), a, fichier);

    fclose(fichier);
}





int chargeclients(Client clients[]) {

    FILE *fichier = fopen("clients.dat", "rb");

    int nombre = 0;

    if (fichier == NULL) {
        return 0;
    }

    if (fread(&nombre, sizeof(int), 1, fichier) != 1) {
        fclose(fichier);
        return 0;
    }

    if (nombre < 0 || nombre > MAX_CLIENT) {
        fclose(fichier);
        return 0;
    }

    if (fread(clients, sizeof(Client), nombre, fichier) != (size_t)nombre) {
        fclose(fichier);
        return 0;
    }

    fclose(fichier);

    return nombre;
}





void saveemprunts(Emprunt emprunts[], int a) {

    FILE *fichier = fopen("emprunts.dat", "wb");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fwrite(&a, sizeof(int), 1, fichier);

    fwrite(emprunts, sizeof(Emprunt), a, fichier);

    fclose(fichier);
}





int chargeemprunts(Emprunt emprunts[]) {

    FILE *fichier = fopen("emprunts.dat", "rb");

    int nombre = 0;

    if (fichier == NULL) {
        return 0;
    }

    if (fread(&nombre, sizeof(int), 1, fichier) != 1) {
        fclose(fichier);
        return 0;
    }

    if (nombre < 0 || nombre > MAX_EMPRUNT) {
        fclose(fichier);
        return 0;
    }

    if (fread(emprunts, sizeof(Emprunt), nombre, fichier) != (size_t)nombre) {
        fclose(fichier);
        return 0;
    }

    fclose(fichier);

    return nombre;
}
































































































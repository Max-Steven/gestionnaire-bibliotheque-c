#ifndef SAVE_H
#define SAVE_H

#include"livre.h"
#include"client.h"
#include"emprunt.h"


void savelivres(Livre livres[] , int a) ;

int chargelivres(Livre livres[]) ;

void saveclients(Client clients[] , int a) ;

int chargeclients(Client clients[]) ;

void saveemprunts(Emprunt emprunts[] , int a) ;

int chargeemprunts(Emprunt emprunts[]) ;




#endif
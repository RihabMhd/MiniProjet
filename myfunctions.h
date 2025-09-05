#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

typedef struct {
    int id;
    char titre[50];
    char auteur[50];
    int prix;
    int quantite;
} livre;

void AjoutLivre(int id, char* titre, char* auteur, int prix, int quantite);
void AfficherLivre();
void SupprimerLivre(int id);
void ModifierLivre(int id,int Newquantite);
void RechercherLivre(int id);
void NombreLivre();

#endif

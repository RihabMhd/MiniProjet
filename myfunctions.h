#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

typedef struct {
    char  isbn[20];
    char titre[50];
    char auteur[50];
    int prix;
    int quantite;
} livre;

void AjoutLivre(char isbn[], char titre[], char auteur[], int prix, int quantite);
void AfficherLivre();
void SupprimerLivre(char isbn[]);
void ModifierLivre(char isbn[], int newQuantite);
void NombreLivre();
void TrierLivresParISBN();
void RechercherLivreBinaireISBN(char isbn[]);
void TrierLivresParTitre(int ordre);
void TrierLivresParQuantite(int ordre);



#endif

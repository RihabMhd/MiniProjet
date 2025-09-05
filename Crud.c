#include <stdio.h>
#include <string.h>
#include "myfunctions.h"

#define max 100

static livre livres[max]; 
static int count = 0;  

void AfficherLivre() {
   if(count == 0) {
       printf("aucun livre trouve\n");
       return;
   }
   for(int i = 0; i < count; i++){
        printf("id: %d | titre: %s | auteur: %s | prix: %d | quantite: %d\n",
               livres[i].id, livres[i].titre, livres[i].auteur, livres[i].prix, livres[i].quantite);
   }
}

void AjoutLivre(int id, char* titre, char* auteur, int prix, int quantite) {
    if(count < max){
        livres[count].id = id;
        strcpy(livres[count].titre, titre);
        strcpy(livres[count].auteur, auteur);
        livres[count].prix = prix;
        livres[count].quantite = quantite;
        count++;
        printf("livre ajoute avec succes\n");
    } else {
        printf("erreur: base pleine\n");
    }
}

void SupprimerLivre(int id) {
    for (int i = 0; i < count; i++) {
        if (livres[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                livres[j] = livres[j + 1]; 
            }
            count--;
            printf("livre supprime\n");
            return;
        }
    }
    printf("livre avec id %d non trouve\n", id);
}

void ModifierLivre(int id, int Newquantite) {
    for(int i = 0; i < count; i++){
        if(livres[i].id == id){
            livres[i].quantite = Newquantite;
            printf("quantite mise a jour\n");
            return;
        }
    }
    printf("erreur lors de la mise a jour\n");
}

void RechercherLivre(int id) {
    for(int i = 0; i < count; i++){
        if(livres[i].id == id){
            printf("id: %d | titre: %s | auteur: %s | prix: %d | quantite: %d\n",
                   livres[i].id, livres[i].titre, livres[i].auteur, livres[i].prix, livres[i].quantite);
            return;
        }
    }
    printf("livre avec id %d non trouve\n", id);
}

void NombreLivre() {
    printf("nombre de livres: %d\n", count);
}

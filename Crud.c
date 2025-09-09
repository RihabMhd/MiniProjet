#include <stdio.h>
#include <string.h>
#include "myfunctions.h"
#include <string.h>
#define max 100

static livre livres[max]; 
static int count = 0;  

void AfficherLivre() {
    if (count == 0) {
        printf("Aucun livre dans la base.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("isbn: %s | titre: %s | auteur: %s | prix: %d | quantite: %d\n",
               livres[i].isbn, livres[i].titre, livres[i].auteur,
               livres[i].prix, livres[i].quantite);
    }
}

void AjoutLivre(char isbn[], char titre[], char auteur[], int prix, int quantite) {
    if (count < max) {
        strcpy(livres[count].isbn, isbn); // strcpy used to Copy a string 
        strcpy(livres[count].titre, titre);
        strcpy(livres[count].auteur, auteur);
        livres[count].prix = prix;
        livres[count].quantite = quantite;
        count++;
        printf("Livre ajouté avec succès.\n");
    } else {
        printf("Erreur : base pleine.\n");
    }
}

void SupprimerLivre(char isbn[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(livres[i].isbn, isbn) == 0) { // strcmp used to compare two strings and it returns 0 if the strings are equal
            for (int j = i; j < count - 1; j++) {
                livres[j] = livres[j + 1];
            }
            count--;
            printf("Livre supprimé avec succès.\n");
            return;
        }
    }
    printf("Livre avec isbn %s introuvable.\n", isbn);
}

void ModifierLivre(char isbn[], int newQuantite) {
    for (int i = 0; i < count; i++) {
        if (strcmp(livres[i].isbn, isbn) == 0) {
            livres[i].quantite = newQuantite;
            printf("Quantité mise à jour avec succès.\n");
            return;
        }
    }
    printf("Erreur : livre non trouvé.\n");
}

// void RechercherLivre(int id) {
//     for (int i = 0; i < count; i++) {
//         if (livres[i].id == id) {
//             printf("id: %d | titre: %s | auteur: %s | prix: %d | quantite: %d\n",
//                    livres[i].isbn, livres[i].titre, livres[i].auteur,
//                    livres[i].prix, livres[i].quantite);
//             return;
//         }
//     }
//     printf("Livre avec id %d introuvable.\n", isbn);
// }


/*
        0	    a and b are exactly the same
        >0	    a is bigger (comes after) b alphabetically
        <0	    a is smaller (comes before) b alphabetically
*/

void TrierLivresParISBN() {
    for (int i = 0; i < count - 1; i++) {   //after each round, the biggest ISBN “bubbles” to the end
        for (int j = 0; j < count - i - 1; j++) {   //check two books next to each other, we don’t need to check the last one(i)
            if (strcmp(livres[j].isbn, livres[j + 1].isbn) > 0) { // Swap if needed (If the first book’s ISBN is bigger)
                livre temp = livres[j];
                livres[j] = livres[j + 1];
                livres[j + 1] = temp;
            }
        }
    }
}

void RechercherLivreBinaireISBN(char isbn[]) {
    int debut = 0;
    int fin = count - 1;

    while (debut <= fin) {
        int milieu = (debut + fin) / 2;
        int cmp = strcmp(livres[milieu].isbn, isbn);

        if (cmp == 0) {
            printf("Livre trouvé : ISBN=%s | titre=%s | auteur=%s | prix=%d | quantite=%d\n",
                   livres[milieu].isbn, livres[milieu].titre,
                   livres[milieu].auteur, livres[milieu].prix,
                   livres[milieu].quantite);
            return;
        }
        else if (cmp < 0) {
            debut = milieu + 1;
        }
        else {
            fin = milieu - 1;
        }
    }

    printf("Livre avec ISBN %s introuvable.\n", isbn);
}



// void TrierLivresParTitre(int ordre) {
//     for (int i = 0; i < count - 1; i++) {//put the last one automatically last
//         for (int j = 0; j < count - i - 1; j++) {    //this is checking each pair of books next to each other(because the last i books are already sorted)
//             int cmp = strcmp(livres[j].titre, livres[j + 1].titre);
//             if ((ordre == 1 && cmp > 0) || (ordre == 0 && cmp < 0)) {//swapp if the order is incorrect
//                 livre temp = livres[j];
//                 livres[j] = livres[j + 1];
//                 livres[j + 1] = temp;
//             }
//         }
//     }
// }


// void TrierLivresParQuantite(int ordre) { 
//     for (int i = 0; i < count - 1; i++) {
//         for (int j = 0; j < count - i - 1; j++) {
//             if ((ordre == 1 && livres[j].quantite > livres[j + 1].quantite) ||
//                 (ordre == 0 && livres[j].quantite < livres[j + 1].quantite)) {
//                 livre temp = livres[j];
//                 livres[j] = livres[j + 1];
//                 livres[j + 1] = temp;
//             }
//         }
//     }
// }

void TrierLivresParQuantiteOrTitre(int ordre,char type[]){
    if(strcmp(type, "Quantite") == 0){
        for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if ((ordre == 1 && livres[j].quantite > livres[j + 1].quantite) ||
                (ordre == 0 && livres[j].quantite < livres[j + 1].quantite)) {
                livre temp = livres[j];
                livres[j] = livres[j + 1];
                livres[j + 1] = temp;
            }
        }
    }
    }else{
        for (int i = 0; i < count - 1; i++) {//put the last one automatically last
        for (int j = 0; j < count - i - 1; j++) {    //this is checking each pair of books next to each other(because the last i books are already sorted)
            int cmp = strcmp(livres[j].titre, livres[j + 1].titre);
            if ((ordre == 1 && cmp > 0) || (ordre == 0 && cmp < 0)) {//swapp if the order is incorrect
                livre temp = livres[j];
                livres[j] = livres[j + 1];
                livres[j + 1] = temp;
            }
        }
    }
    }
}

void NombreLivre() {
    printf("Nombre total de livres : %d\n", count);
}
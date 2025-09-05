#include <stdio.h>
#include "myfunctions.h"  

int main() {
    int id, prix, quantite;
    char titre[50], auteur[50];
    int choix;
    do {
        printf("Gestion Livres - Developed by Rihab Mahdi\n\n");
        printf("\n         MENU:         \n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher les livres\n");
        printf("3. Supprimer un livre\n");
        printf("4. Modifier un livre\n");
        printf("5. Rechercher un livre\n");
        printf("6. Nombre de livres\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("entrez l id du livre : ");
                scanf("%d", &id);
                printf("entrez le titre du livre : ");
                scanf("%s", titre);
                printf("entrez l auteur du livre : ");
                scanf("%s", auteur);
                printf("entrez le prix du livre : ");
                scanf("%d", &prix);
                printf("entrez la quantite du livre : ");
                scanf("%d", &quantite);
                AjoutLivre(id, titre, auteur, prix, quantite);
                break;

            case 2:
                AfficherLivre();
                break;

            case 3:
                printf("entrez l id du livre a supprimer : ");
                scanf("%d", &id);
                SupprimerLivre(id);
                break;

            case 4:
                printf("entrez l id du livre a modifier : ");
                scanf("%d", &id);
                printf("entrez la nouvelle quantite : ");
                scanf("%d", &quantite);
                ModifierLivre(id, quantite);
                break;

            case 5:
                printf("entrez l id du livre a rechercher : ");
                scanf("%d", &id);
                RechercherLivre(id);
                break;

            case 6:
                NombreLivre();
                break;

            case 0:
                printf("au revoir\n");
                break;

            default:
                printf("choix incorrect\n");
        }
    } while (choix != 0);
    return 0;
}

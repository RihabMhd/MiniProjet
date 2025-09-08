#include <stdio.h>
#include "myfunctions.h"


int main() {
    char isbn[20];
    int prix, quantite;
    char titre[50], auteur[50];
    int choix;
    do {
        printf("\n         MENU:         \n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher les livres\n");
        printf("3. Supprimer un livre\n");
        printf("4. Modifier un livre\n");
        printf("5. Rechercher un livre\n");
        printf("6. Nombre de livres\n");
        printf("8. Trier les livres par titre\n");
        printf("9. Trier les livres par quantité\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("entrez l isbn du livre : ");
                scanf("%s", &isbn);
                printf("entrez le titre du livre : ");
                scanf("%s", titre);
                printf("entrez l auteur du livre : ");
                scanf("%s", auteur);
                printf("entrez le prix du livre : ");
                scanf("%d", &prix);
                printf("entrez la quantite du livre : ");
                scanf("%d", &quantite);
                AjoutLivre(isbn, titre, auteur, prix, quantite);
                break;

            case 2:
                AfficherLivre();
                break;

            case 3:
                printf("entrez l isbn du livre a supprimer : ");
                scanf("%s", &isbn);
                SupprimerLivre(isbn);
                break;

            case 4:
                printf("entrez l isbn du livre a modifier : ");
                scanf("%s", &isbn);
                printf("entrez la nouvelle quantite : ");
                scanf("%d", &quantite);
                ModifierLivre(isbn, quantite);
                break;

            case 5:
                printf("tri des livres par ISBN avant recherche\n");
                TrierLivresParISBN();
                printf("entrez l'ISBN du livre à rechercher : ");
                scanf("%s", isbn);
                RechercherLivreBinaireISBN(isbn);
                break;
                break;

            case 6:
                NombreLivre();
                break;                
            case 8:
                printf("1. ordre croissant\n2. ordre décroissant\nvotre choix : ");
                scanf("%d", &choix);
                TrierLivresParTitre(choix == 1 ? 1 : 0);
                AfficherLivre();
                break;

            case 9:
                printf("1. ordre croissant\n2. ordre décroissant\nvotre choix : ");
                scanf("%d", &choix);
                TrierLivresParQuantite(choix == 1 ? 1 : 0);
                AfficherLivre();
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

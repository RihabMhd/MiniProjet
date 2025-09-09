#include <stdio.h>
#include "myfunctions.h"
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"




int main() {
    char isbn[20];
    int prix, quantite;
    char titre[50], auteur[50];
    char type[20];
    int choix;
    do {
        printf(ANSI_COLOR_RED "\n         MENU:         \n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "1. Ajouter un livre\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "2. Afficher les livres\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "3. Supprimer un livre\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "4. Modifier un livre\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "5. Rechercher un livre\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "6. Nombre de livres\n" ANSI_COLOR_RESET);
        // printf("8. Trier les livres par titre\n");
        // printf("9. Trier les livres par quantité\n");
        printf(ANSI_COLOR_BLUE "10. Trier les livres par quantité or titre\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "0. Quitter\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN "Entrez votre choix : " ANSI_COLOR_RESET);
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("entrez l isbn du livre : ");
                scanf("%s",isbn);
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
                scanf("%s", isbn);
                SupprimerLivre(isbn);
                break;

            case 4:
                printf("entrez l isbn du livre a modifier : ");
                scanf("%s", isbn);
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

            case 6:
                NombreLivre();
                break;                
            // case 8:
            //     printf("1. ordre croissant\n2. ordre décroissant\nvotre choix : ");
            //     scanf("%d", &choix);
            //     TrierLivresParTitre(choix == 1 ? 1 : 0);
            //     AfficherLivre();
            //     break;

            // case 9:
            //     printf("1. ordre croissant\n2. ordre décroissant\nvotre choix : ");
            //     scanf("%d", &choix);
            //     TrierLivresParQuantite(choix == 1 ? 1 : 0);
            //     AfficherLivre();
            //     break;
            case 10: {
                    int choixType;
                    printf("1. Trier Par Quantite\n");
                    printf("2. Trier Par Livre\n");
                    printf("Votre Type : ");
                    scanf("%d", &choixType);
                    if (choixType == 1) {
                        strcpy(type, "Quantite");
                    } else if (choixType == 2) {
                        strcpy(type, "Titre");
                    } else {
                        printf("Type invalide.\n");
                        break;
                    }
                    printf("1. Ordre croissant\n");
                    printf("2. Ordre décroissant\n");
                    printf("Votre choix : ");
                    scanf("%d", &choix);
                    TrierLivresParQuantiteOrTitre(choix == 1 ? 1 : 0, type);
                    AfficherLivre();

                    break;
                }


                break;
            case 0:
                printf(ANSI_COLOR_YELLOW "au revoir\n" ANSI_COLOR_RESET);
                break;

            default:
                printf("choix incorrect\n");
        }
    } while (choix != 0);
    return 0;
}

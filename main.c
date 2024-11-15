#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

int main() {
    int choice, q = 0, f = 0, f2 = 0, nbt = 0,n,choice2, choice3,i, numt = 1, numst = 1,ch,is,k;
    Tache x,z;
    Stache y;
    Tqueue Q,projet,Qi;
    InitQueue(&Q);
    struct STstack stak,P;

    InitQueue(&projet);
    while (q == 0) {
        //menu
        printf("\nSysteme de Gestion de Projet\n");
        printf("1. Ajouter une tache\n");
        printf("2. Supprimer une tache\n");
        printf("3. Marquer une tache comme terminee\n");
        printf("4. Afficher les taches\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix :");
        if (scanf("%d", &choice) != 1) {
            printf("Entree invalide. Veuillez entrer un nombre.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();
        switch (choice) {
            case 1: //ajout
                printf("\n\t\t\t-Ajout d'une tache-\n");
                f = 1;
                printf("\n1. Ajouter une tache.\n");
                printf("2. Ajouter une sous-tache.\n");
                printf("Entrez votre choix : ");

                if (scanf("%d", &choice2) != 1) {
                    printf("Entree invalide. Veuillez entrer un nombre.\n");
                    while (getchar() != '\n');
                    continue;
                }
                getchar();
                switch (choice2) {
                    case 1:         //ajout d une tache
                        f2 = 1;
                        x.eta = 0;
                        x.num = numt;
                        x.nbst = 0;
                        initS(&x.s);
                        numt++;
                        printf("Veuillez introduire la description de la tache.\n(remplacez les espaces par des points pour le bon deroulement de la procedure).\n\ndescription: ");
                        scanf("%s", &x.des);
                        AddQ(&projet, x);
                        break;
                    case 2:         //ajout d une sous tache
                        if (f2 == 0) {
                            printf("\nErreur, vous devez ajouter une tache pour effectuer cette action.\n");}
                         else {
                            printf("\nAjout d'une sous tache:\n");
                            printf("Introduisez le numero de la tache pour laquelle vous voulez ajouter une sous tache:");
                            if (scanf("%d", &choice3) != 1) {
                                printf("Entree invalide. Veuillez entrer un nombre.\n");
                                while (getchar() != '\n');
                                continue;
                            }

                            if (choice3 > numt) {
                                printf("\nErreur, tache inexistante !\n");
                            } else {

                                printf("Introduire la description de la sous tache:");
                                scanf("%s", &y.des);
                                y.eta = 0;
                                InitQueue(&Qi);
                                Q = projet;
                                while (choice3 != (Q.Head->Data.num)) {
                                    SuppQ(&Q, &x);
                                    AddQ(&Qi, x);

                                }       //tache concernée trouvée

                                if (Q.Head->Data.nbst == 0) {
                                    initS(&(Q.Head->Data.s));
                                    add(&(Q.Head->Data.s), y);
                                    Q.Head->Data.nbst= Q.Head->Data.nbst+1;
                                } else {
                                    add(&Q.Head->Data.s, y);
                                    Q.Head->Data.nbst= Q.Head->Data.nbst+1;
                                }

                                Q.Head->Data.s.data.num = Q.Head->Data.nbst;

                                while(isQEmpty(Q)==0){
                                    SuppQ(&Q,&x);
                                    AddQ(&Qi,x);
                                }
                                projet=Qi;
                            }
                            break;
                            default:
                                printf("Choix invalide.\n");
                        }
                }
                        break;
                    case 2:     printf("\n\t\t\t-Supression d'une tache-\n");
                        switch (f) {
                            case 0:
                                printf("\nErreur, vous devez ajouter une tache pour effectuer cette action.\n");
                                break;
                            default:
                                printf(" \n1. Supprimer une tache.\n");
                                printf("2. Supprimer une sous tache.\n");
                                printf("Entrez votre choix:");

                                if (scanf("%d", &ch) != 1) {
                                    printf("Entree invalide. Veuillez entrer un nombre.\n");
                                    while (getchar() != '\n')
                                        continue;
                                }
                                getchar();
                                switch (ch) {
                                    case 1:
                                        printf("Entrez le numero de la tache a supprimer.\n");
                                        if (scanf("%d", &n) != 1) {
                                            printf("Entree invalide. Veuillez entrer un nombre.\n");
                                            while (getchar() != '\n');
                                            continue;
                                        }

                                        if (n > numt)
                                            printf("\nErreur, tache inexistante !\n");
                                        else {
                                            i=1;
                                            InitQueue(&Qi);
                                            Q = projet;
                                            while (n != (Q.Head->Data.num)) {
                                                SuppQ(&Q, &x);
                                                AddQ(&Qi, x);
                                                i++;
                                            }      //tache trouvée
                                            SuppQ(&Q, &x);
                                            while(isQEmpty(Q)==0){
                                                SuppQ(&Q,&x);
                                                x.num=i;
                                                i++;
                                                AddQ(&Qi,x);
                                            }
                                            projet=Qi;
                                        }
                                        break;
                                        case 2:
                                        printf("Supression d une sous tache\n");
                                        printf("\nEntrez le numero de la tache concernee:\n");
                                        if (scanf("%d", &n) != 1) {
                                            printf("Entree invalide. Veuillez entrer un nombre.\n");
                                            while (getchar() != '\n');
                                            continue;
                                        }
                                        if(n>numt){
                                            printf("\nErreur, tache inexistante !\n");}
                                        else {
                                            InitQueue(&Qi);
                                            Q = projet;
                                            while (n != (Q.Head->Data.num)) {
                                                SuppQ(&Q, &x);
                                                AddQ(&Qi, x);
                                            }  // tache trouvée
                                            stak = Q.Head->Data.s;
                                            printf("\nEntrez le numero de la sous tache a supprimer:\n");
                                            if (scanf("%d", &n) != 1) {
                                                printf("Entree invalide. Veuillez entrer un nombre.\n");
                                                while (getchar() != '\n');
                                                continue;
                                            }
                                            if (n > Top(&stak).num){
                                                printf("\nErreur, sous-tache inexistante !\n");
                                            }
                                            else {
                                                is = 1;
                                                while(isSEmpty(&stak)==0){
                                                    sup(&stak,&y);
                                                    if(y.num!=n) {
                                                        add(&P,y);
                                                    }
                                                }
                                                while(isSEmpty(&P)==0){
                                                    sup(&P,&y);
                                                    y.num=is;
                                                    is++;
                                                    add(&P,y);
                                                }
                                            }
                                            Q.Head->Data.nbst = Q.Head->Data.nbst - 1;
                                            Q.Head->Data.s=stak;
                                            while(isQEmpty(Q)==0){
                                                SuppQ(&Q,&x);
                                                x.num=i;
                                                i++;
                                                AddQ(&Qi,x);
                                            }
                                            projet=Qi;
                                        }
                                        break;
                                    default:
                                        printf("\nChoix invalide. Veuillez entrer a nouveau.\n");
                                        break;


                                }
                        }
                        break;
                    case 3: printf("\n\t\t\t-Marquer comme terminé-\n");
                        switch (f) {
                            case 0:
                                printf("\nErreur, vous devez ajouter une tache pour effectuer cette action.\n");
                                break;
                            default:
                                printf("\n1. Marquer une tache comme terminee.\n");
                                printf("2. Marquer une sous-tache comme terminee.\n");
                                if (scanf("%d", &ch) != 1) {
                                    printf("Entree invalide. Veuillez entrer un nombre.\n");
                                    while (getchar() != '\n');
                                    continue;
                                }
                                switch (ch) {
                                    case 1:
                                        printf("\nEntrez le numero de la tache:");

                                        if (scanf("%d", &n) != 1) {
                                            printf("Entree invalide. Veuillez entrer un nombre.\n");
                                            while (getchar() != '\n');
                                            continue;
                                        }
                                        if(n>numt){
                                            printf("\nErreur, tache inexistante !\n");}
                                        else{

                                            InitQueue(&Qi);
                                            Q = projet;
                                            while (n!=(Q.Head->Data.num)) {

                                                SuppQ(&Q, &x);
                                                AddQ(&Qi, x);
                                            }     //tache trouvee

                                            if(isSEmpty(&(Q.Head->Data.s))==0) {

                                                if (Tdep(&Q.Head->Data.s)==1){

                                                    printf("\nImpossible d'effectuer cette action, quelques sous-taches de cette tache ne sont pas encore terminees !\n");}
                                                else{
                                                    Q.Head->Data.eta = 1;
                                                    printf("\nFait.\n");}
                                            }
                                            else{
                                                printf("8");
                                                Q.Head->Data.eta = 1;
                                                printf("\nFait.\n");
                                            }

                                            while(isQEmpty(Q)==0){
                                                SuppQ(&Q,&x);
                                                AddQ(&Qi,x);
                                            }
                                            projet=Qi;
                                        }
                                    break;
                                    case 2:
                                        printf("\nIntroduire la tache concernee:");
                                        if (scanf("%d", &n) != 1) {
                                            printf("Entree invalide. Veuillez entrer un nombre.\n");
                                            while (getchar() != '\n');
                                            continue;
                                        }
                                        if(n>numt) {
                                                printf("\nErreur, tache inexistante!\n");}
                                        else{
                                                printf("\nIntroduire le numero de la sous tache");
                                                if (scanf("%d", &n) != 1) {
                                                    printf("Entree invalide. Veuillez entrer un nombre.\n");
                                                    while (getchar() != '\n');
                                                    continue;
                                                }
                                                Term(&Q.Head->Data.s, n);}

                                    break;
                                    default:
                                        printf("\nChoix invalide.\n");
                                }
                        }
                        break;
                    case 4:
                        printf("\n\t\t\t-Affichage-\n");
                        switch (f) {
                            case 0:
                                printf("\nErreur, vous devez ajouter une tache pour effectuer cette action.\n");
                                break;
                            default:
                                printf("\n1. Afficher les taches\n");
                                printf("2. Afficher les sous taches d une tache\n");
                                printf("\nVeuillez choisir:");
                                if (scanf("%d", &n) != 1) {
                                    printf("Entree invalide. Veuillez entrer un nombre.\n");
                                    while (getchar() != '\n');
                                    continue;
                                }
                                switch (n) {
                                    case 1:
                                        printf("\nAffichage des taches\n");
                                        DispgenT(&projet);
                                        break;
                                    case 2:
                                        printf("\nSelectionnez la tache concernee\n");
                                        if (scanf("%d", &n) != 1) {
                                            printf("Entree invalide. Veuillez entrer un nombre.\n");
                                            while (getchar() != '\n');
                                            continue;}
                                        
                                        InitQueue(&Qi);
                                        Q = projet;
                                        while (n != (Q.Head->Data.num)) {
                                            SuppQ(&Q, &x);
                                            AddQ(&Qi, x);

                                        }       //tache concernée trouvée
                                            dispSG(&Q.Head->Data.s);
                                        while(isQEmpty(Q)==0){
                                            SuppQ(&Q,&x);
                                            AddQ(&Qi,x);
                                        }
                                        projet=Qi;
                                    break;
                                    default:
                                        printf("\nChoix invalide.\n");
                                }

                        }
                        break;
                    case 5:
                        printf("\n\t\t\t-Programme termine-\n");
                        q = 1;
                        break;
                    default:
                        printf("\nChoix invalide. Veuillez entrer a nouveau.\n");
                }
        }
    }
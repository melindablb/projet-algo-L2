//
// Created by HP on 22/01/2024.
//
#ifndef PROJETTPL2_BIB_H
#define PROJETTPL2_BIB_H
#include <stdio.h>
#include <stdlib.h>

//deb bib des stacks
typedef struct{
    int num;
    char des[100];
    int eta;
}Stache;
typedef struct STstack* PS;
typedef struct STstack {
    Stache data;
    PS next;
}STstacknode;

void add(PS *ST, Stache x) {
    PS v;
    v = malloc(sizeof(STstacknode));
    v->data = x;
    v->next = *ST;
    *ST = v;
}
void sup(PS *ST, Stache *x) {
    PS v;
    *x = (*ST)->data;
    v = *ST;
    *ST = (*ST)->next;
    free(v);
}
void initS(PS *ST) {
    *ST = NULL;
}
int isSEmpty(PS P){
    if (P==NULL) return 1;
    else return 0;
}

void dispSG(PS *S){
    Stache x; struct STstack P;
    initS((PS *) &P);
    while(isSEmpty(*S)==0){
        sup(S, &x);
        if(x.eta==0) {
            printf("Sous-tache numero %d: %s.\t Etat: non terminee.\n", x.num, x.des);}
            else{
            printf("Sous-tache numero %d: %s.\t Etat: terminee.\n", x.num, x.des);}
        add((PS *) &P, x);
    }
    while(isSEmpty(&P)==0){
        sup((PS *) &P, &x);
        add(S,x);
    }
}


Stache Top(PS S) {
    return S->data;
}
void Term(PS *S,int n){
    Stache x;
    if(n> Top(*S).num)
        printf("Erreur, cette sous tache n'existe pas");
    else{
        sup(S,&x);
        if(x.num==n){
            x.eta=1;
            add(S,x);
        }
        else{
            Term(S,n);
            add(S,x);
        }
    }
}
int Tdep(PS *S){
   int b; Stache x;
   if(isSEmpty(*S)==0){
       if(Top(*S).eta==0){
           return 1;
       }
       else{
           sup(S,&x);
           b= Tdep(S);
           add(S,x);
       }

   }
   else{
       return 0;}
    return b;
}



//fin bib des stacks
//deb bib des queues
typedef struct {
    char des[100];
    int num;
    int eta;
    struct STstack s;
    int nbst;
} Tache;

typedef struct Element* PQ;
typedef struct Element { Tache Data; PQ Next;} Telt;
typedef struct {PQ Head,Tail;} Tqueue;

int isQEmpty(Tqueue Q)
{if (Q.Head==NULL) return 1;
    else return 0;
}
void AddQ(Tqueue* Q, Tache x) {
    PQ T;
    T=malloc(sizeof(Telt));
    T->Data=x;
    T->Next=NULL;
    if ((*Q).Head==NULL) (*Q).Head=T; //la Queue est vide
    else (*Q).Tail->Next=T;
    (*Q).Tail=T;
}
void SuppQ(Tqueue *Q, Tache *x)
{PQ V;
    V=(*Q).Head;
    *x=V->Data; //ou  *x=(*Q).Head->Data;

    if ((*Q).Head==(*Q).Tail) {(*Q).Head=NULL; (*Q).Tail=NULL;}
    else (*Q).Head=((*Q).Head)->Next; // ou  (*Q).Head=V->Next;
    free(V);
}
void InitQueue(Tqueue *Q)
{(*Q).Head=NULL; (*Q).Tail=NULL;}
void DispgenT(Tqueue *Q) {
    Tache x; Tqueue P;
    InitQueue(&P);
    //(*P).Head=NULL; (*P).Tail=NULL;
    while (isQEmpty(*Q)==0) {
        SuppQ(Q,&x);
        if (x.eta == 0) {
            printf("Tache numero %d: %s.\t Etat: non terminee. Nombre de sous-taches: %d\n",x.num,x.des,x.nbst);
        } else{printf("Tache numero %d: %s.\t Etat: terminee. Nombre de sous-taches: %d \n",x.num,x.des,x.nbst);}
        AddQ(&P,x);}
    *Q=P;
}
//fin bib des queues

#endif

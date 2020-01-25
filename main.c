#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//structure pour les monstre
struct Monstre
{
    int pv;
    int att;
    int attsort;
};

struct Joueur
{
    int pv;
    int att;
    int PM;
    int attsort;
};


typedef struct Monstre monstre;
typedef struct Joueur joueur;

//aléa
int genRandoms(int lower, int upper, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        int num = (rand() %
                   (upper - lower + 1)) +
                  lower;
        return num;
    }
}

//genère un monstre aléatoire
monstre geneCombat(monstre table[5], int lower, int upper, int count) { return table[genRandoms(lower, upper, count)]; }

//vide la console
void clrscr()
{
    system("@cls||clear");
}

int tourJoueur(int PM)



int main(void){

    int game;
    int choix;

    //variable des monstre
    monstre demon_inferieur = {50, 4, 6};
    monstre demon_superieur = {100, 10, 16};
    monstre roi_des_slime = {500, 2, 8000};
    monstre goblin = {15, 5, 5};
    monstre dragon = {5000, 50, 90};

    monstre tableMonstre[5] = {demon_inferieur, demon_superieur, roi_des_slime, goblin, dragon};

    monstre combat[3];

    //PlayerStats
    joueur player = {50,5,20,15};

    //génère les monstre
    for (int i = 0; i < 3; i++)
    {
        combat[i] = geneCombat(tableMonstre, 0, 4, 1);
        printf("PV:%d ATT:%d ATTS:%d\n", combat[i].pv, combat[i].att, combat[i].attsort);
    }

    while(game){

        choix = tourJoueur(player.PM);

    }

}
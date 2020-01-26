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

//Maryam

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

int tourJoueur(int PM){
    int choix;
    printf("1:ATT 2:DEF 3:SORT 4:GERISON :");
    scanf("%d\n",&choix);

    if (choix == 3 && PM<10)
    {
        return 0;
    }
    else
    {
        return choix;
    }
}



int main(void){

    int game;
    int choix;
    int Cible;
    game = 1;

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

    //génère les monstres
    for (int i = 0; i < 3; i++)
    {
        combat[i] = geneCombat(tableMonstre, 0, 4, 1);
        //printf("PV:%d ATT:%d ATTS:%d\n", combat[i].pv, combat[i].att, combat[i].attsort);
    }

    while(game){

        //Demande du joueur
        player.PM++;
        choix = tourJoueur(player.PM);

        if (choix == 0)
        {
            choix = tourJoueur(player.PM);
        }
        

        if (choix == 1){
            printf("Choisissez votre cible: ");
            scanf("%d\n",&Cible);
            if (Cible>2)
            {
                Cible = 2;
            }
            
            combat[Cible].pv -= player.att;
            printf("Vous attaquez le monstre!\nle monstre n°%d a maintenant %dPV !\n",Cible,combat[Cible].pv);

        }
		printf("Votre allié OV3R a attaqué un monstre");
		printf("Votre allié OV3R vous soigne");
		printf("Votre allié W.D a attaqué un monstre");
		printf("Votre allié W.D vous soigne");
		printf("Votre allié RIVER a attaqué un monstre");
		printf("Votre allié RIVER vous soigne");
    }
		
}

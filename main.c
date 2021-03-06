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
    int defOn;
    int poison;
    poison = 0;

    //variable des monstre
    monstre demon_inferieur = {50, 4, 6};
    monstre demon_superieur = {100, 10, 16};
    monstre roi_des_slime = {500, 2, 8000};
    monstre goblin = {15, 5, 5};
    monstre dragon = {5000, 50, 90};

    monstre tableMonstre[5] = {demon_inferieur, demon_superieur, roi_des_slime, goblin, dragon};

    monstre combat[3];

    //PlayerStats
    joueur player = {50000,5,20,15};

    //génère les monstres
    for (int i = 0; i < 3; i++)
    {
        combat[i] = geneCombat(tableMonstre, 0, 4, 1);
        //printf("PV:%d ATT:%d ATTS:%d\n", combat[i].pv, combat[i].att, combat[i].attsort);
    }

    while(game){

        //Demande du joueur
        player.PM++;
        defOn = 0;
        choix = 0;
        choix = tourJoueur(player.PM);

        if (poison >0)
        {
            player.pv-=poison;
            printf("vous soufrez du poison il vous reste %dPv\n",player.pv);
        }
        

        if (choix == 0)
        {
            choix = tourJoueur(player.PM);
        }
        if (choix == 1){

            clrscr();
            printf("Choisez votre cible(de 0 à 2): ");
            scanf("%d\n",&Cible);
            if (Cible>2)
            {
                Cible = 2;
            }
            
            combat[Cible].pv -= player.att;
            printf("Vous attaquez le monstre!\nle monstre n°%d a maintenant %dPV !\n",Cible,combat[Cible].pv);

        }

        if (choix == 2)
        {
            clrscr();
            printf("Vous vous defendez !\n");
            defOn++;

        }
        if (choix == 3)
        {
            printf("Choisez votre cible(de 0 à 2): ");
            scanf("%d\n", &Cible);
            if (Cible > 2)
            {
                Cible = 2;
            }
            clrscr();
            player.PM-=10;
            combat[Cible].pv -= player.attsort;
            printf("Vous lancez une puissance boule de feu !\nle monstre n°%d a maintenant %dPV !\n Il vous reste %dPM\n", Cible, combat[Cible].pv,player.PM);
        }
        if (choix == 4)
        {
            clrscr();
            printf("Vous n'êtes plus empoisoné !\n");
            poison = 0;
        }
        

        //Tour du monstre
        for (int i = 0; i < 3; i++)
        {
            choix = genRandoms(1,3,1);
            if (choix == 1)
            {
                player.pv-=combat[i].att;
                printf("Le monstre n°%d vous attaque ! vous avez %dPV\n",i,player.pv);
            }
            if (choix == 2)
            {
                player.pv-=combat[i].attsort;
                printf("Le monstre n°%d vous lance un puissant sort ! vous avez %dPV\n", i, player.pv);
            }
            if (choix == 3)
            {
                poison++;
                printf("Le monstre n°%d vous empoisone !\n", i);
            }
            
            //tour des Allié
            choix = genRandoms(1,2,1);
            if (choix == 1)
            {
                printf("Votre allié OV3R a attaqué un monstre\n");
                Cible = genRandoms(0, 2, 1);
                combat[Cible].pv -= 4;
            }
            if (choix == 2)
            {
                printf("Votre allié OV3R vous soigne\n");
                player.pv+=15;
            }

            choix = genRandoms(1, 2, 1);
            if (choix == 1)
            {
                printf("Votre allié W.D a attaqué un monstre\n");
                Cible = genRandoms(0,2,1);
                combat[Cible].pv-=4;
            }
            if (choix == 2)
            {
                printf("Votre allié W.D vous soigne\n");
                player.pv += 15;
            }

            choix = genRandoms(1, 2, 1);
            if (choix == 1)
            {
                printf("Votre allié RIVER a attaqué un monstre\n");
                Cible = genRandoms(0, 2, 1);
                combat[Cible].pv -= 4;
            }
            if (choix == 2)
            {
                printf("Votre allié RIVER vous soigne\n");
                player.pv += 15;
            }
        }      
    }	
}

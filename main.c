#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 16
#define QUESTIONS_PER_GAME 6


char *questions[MAX_QUESTIONS] = {
    "Quelle est la capitale de la France ?",
    "Quelle planete est surnommee la planete rouge ?",
    "Combien de cotes possede un hexagone ?",
    "Combien font 5 * 6 ?",
    "Quel langage de programmation utilise le quiz game ?",
    "Combien y a-t-il de jours dans une semaine ?",
    "Quel est le plus grand ocean du monde ?",
    "Quel animal est surnomme le roi de la jungle ?",
    "Quel est le contraire de chaud ?",
    "Combien y a-t-il de mois dans une annee ?",
    "Quelle planete est la plus proche du Soleil ?",
    "Quelle couleur obtient-on en melangeant du rouge et du bleu ?",
    "Combien de pattes possede une araignee ?",
    "A quelle temperature l'eau gele-t-elle en degres Celsius ?",
    "Sur quel continent se trouve l'Egypte ?",
    "Combien font 10 au carre ?"
};


char *reponses[MAX_QUESTIONS][4] = {
    {"Paris", "Londres", "Madrid", "Rome"},
    {"Venus", "Mars", "Jupiter", "Mercure"},
    {"5", "6", "7", "8"},
    {"25", "30", "35", "40"},
    {"Python", "Java", "C", "HTML"},
    {"5", "6", "7", "8"},
    {"Atlantique", "Indien", "Arctique", "Pacifique"},
    {"Lion", "Tigre", "Elephant", "Loup"},
    {"Froid", "Sec", "Humide", "Doux"},
    {"10", "11", "12", "13"},
    {"Mars", "Venus", "Mercure", "Terre"},
    {"Vert", "Orange", "Violet", "Rose"},
    {"6", "8", "10", "12"},
    {"0", "10", "32", "100"},
    {"Asie", "Afrique", "Europe", "Amerique"},
    {"20", "50", "100", "1000"}
};


char bonnes_reponses[MAX_QUESTIONS] = {
    'a', 'b', 'b', 'b',
    'c', 'c', 'd', 'a',
    'a', 'c', 'c', 'c',
    'b', 'a', 'b', 'c'
};


int main()
{
    int score = 0;
    char reponse;
    char commande[20];
    int valide;
    int questions_choisies[QUESTIONS_PER_GAME];
    int nombre;
    int deja_choisie;
    int i;

    srand(time(NULL));

    printf("============================\n");
    printf("         QUIZ GAME\n");
    printf("============================\n");

    for (i = 0; i < QUESTIONS_PER_GAME; i++)
    {
        do
        {
            nombre = rand() % MAX_QUESTIONS;
            deja_choisie = 0;

            for (int j = 0; j < i; j++)
            {
                if (questions_choisies[j] == nombre)
                {
                    deja_choisie = 1;
                }
            }

        } while (deja_choisie == 1);

        questions_choisies[i] = nombre;
    }

    for (i = 0; i < QUESTIONS_PER_GAME; i++)
    {
        nombre = questions_choisies[i];

        printf("\nQuestion %d : %s\n", i + 1, questions[nombre]);

        printf("a) %s\n", reponses[nombre][0]);
        printf("b) %s\n", reponses[nombre][1]);
        printf("c) %s\n", reponses[nombre][2]);
        printf("d) %s\n", reponses[nombre][3]);

        do
        {
            printf("\nVotre reponse : ");
            scanf(" %c", &reponse);

            reponse = tolower(reponse);

            if (reponse == 'a' || reponse == 'b' || reponse == 'c' || reponse == 'd')
            {
                valide = 1;
            }
            else
            {
                valide = 0;
                printf("Reponse invalide. Choisissez a, b, c ou d.\n");
            }

        } while (valide == 0);

        if (reponse == bonnes_reponses[nombre])
        {
            printf("Bonne reponse !\n");
            score++;
        }
        else
        {
            printf("Mauvaise reponse !\n");
        }
    }

    printf("\n============================\n");
    printf("Felicitations !\n");
    printf("Vous avez obtenu %d/%d bonnes reponses !\n", score, QUESTIONS_PER_GAME);
    printf("============================\n");

    do
    {
        printf("\nTapez Exit pour fermer le programme : ");
        scanf("%19s", commande);

        for (int i = 0; commande[i] != '\0'; i++)
        {
            commande[i] = tolower(commande[i]);
        }

    } while (strcmp(commande, "exit") != 0);

    return 0;
}
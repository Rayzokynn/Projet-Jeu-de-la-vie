#include <iostream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "console.h"
#include "graphique.h"
#include "cell.h"
#include "grille.h"
#include "extension.h"

int main() {

    std::string filename;
    int choix = 0;

    // -----------------------------------------------MODE UTILISATEUR OU TESTEUR-----------------------------------------------
    std::cout << "Bienvenue dans le Jeu de la Vie !" << std::endl;
    std::cout << "1. Mode Utilisateur" << std::endl;
    std::cout << "2. Mode Testeur (test unitaire)" << std::endl;
    std::cout << "Votre choix : ";

    // -----------------------------------------------Validité des réponses-----------------------------------------
    while (!(std::cin >> choix) || (choix != 1 && choix != 2)) {
        std::cin.clear();                                                        // Nettoie std::cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');      // Ignore les caractères restants
        std::cerr << "Entrée invalide. Veuillez entrer 1 ou 2 : ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');         // Nettoyage du tampon

    // -------------------------------------------------Mode Testeur------------------------------------------------
    if (choix == 2) {
        Grille grille;
        std::string destinationDir;
        int generations;

        std::cout << "Veuillez entrer le chemin du fichier source : ";
        std::getline(std::cin, filename);

        std::cout << "Veuillez entrer le nom du dossier de destination : ";
        std::getline(std::cin, destinationDir);

        std::cout << "Combien de générations souhaitez-vous calculer ? : ";
        std::cin >> generations;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // Nettoyage du tampon

        grille.TestUnitaire(filename, destinationDir, generations);
        return 0;
    }

    // ------------------------------------------------Mode Utilisateur-----------------------------------------------
    choix = 0;
    std::cout << "Choisissez un mode :" << std::endl;
    std::cout << "1. Mode Console" << std::endl;
    std::cout << "2. Mode Graphique" << std::endl;
    std::cout << "Votre choix : ";

    // -----------------------------------------------Validité des réponses-----------------------------------------
    while (!(std::cin >> choix) || (choix != 1 && choix != 2 && choix != 3)) {
        std::cin.clear();                                                       // nettoie std::cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // Ignore les caractères restants
        std::cerr << "Entrée invalide. Veuillez entrer 1 ou 2 : ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');         // Nettoyage du tampon

    Grille grille;
    std::cout << "Veuillez entrer le chemin du fichier source : ";
    std::getline(std::cin, filename);
    grille.initializeGrille(filename);

    if (choix == 1) {
        // -----------------------------------------------Mode Console-----------------------------------------------
        std::string destinationDir;
        int generations;

        std::cout << "Veuillez entrer le nom du dossier de destination : ";
        std::getline(std::cin, destinationDir);

        std::cout << "Combien de générations souhaitez-vous générer ? : ";
        std::cin >> generations;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // Nettoyage du tampon

        grille.modeConsole(filename, destinationDir, generations);
    }
    else if (choix == 2) {
        // -----------------------------------------------Mode Graphique-----------------------------------------------
        int delay;

        std::cout << "Entrez le délai entre chaque génération (en millisecondes) : ";
        while (!(std::cin >> delay) || delay <= 0) {
            std::cin.clear();                                                   // Nettoie std::cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer les entrées incorrectes
            std::cerr << "Entrée invalide. Le délai doit être un entier positif. Essayez à nouveau : ";
        }

        grille.modeGraphique(filename, delay);
    }
    /*else if (choix == 3) {
        // -----------------------------------------------Mode Console+extensionCinthia-----------------------------------------------
        std::string destinationDir;
        int generations;
        Celluleobs celluleobs;

        std::cout << "Veuillez entrer le nom du dossier de destination : ";
        std::getline(std::cin, destinationDir);

        std::cout << "Combien de générations souhaitez-vous générer ? : ";
        std::cin >> generations;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // Nettoyage du tampon

        std::filesystem::create_directory(destinationDir);
        initializeGrille(filename);
        celluleobs.createobstacle();
        celluleobs.generateGeneration(generations, destinationDir);
}

    return 0;*/
}




/*Explication du fonctionnement :
Compilation avec la commande : g++ grille.cpp console.cpp graphique.cpp cell.cpp main.cpp -o GameofLife -lsfml-graphics -lsfml-window -lsfml-system
Execution du .exe : ./GameofLife


Une fois le programme lancé cette interface s'affichera :

    Bienvenue dans le Jeu de la Vie !
    1. Mode Utilisateur
    2. Mode Testeur (tests unitaires)
    Votre choix :

en fonction du choix 1 ou 2, vous serez dirigé vers 
dans le premier cas:

    Bienvenue dans le Jeu de la Vie !
    1. Mode Utilisateur
    2. Mode Testeur (tests unitaires)
    Votre choix : 1
    Choisissez un mode :
    1. Mode Console
    2. Mode Graphique
    Votre choix :

dans le second cas :

    Bienvenue dans le Jeu de la Vie !
    1. Mode Utilisateur
    2. Mode Testeur (tests unitaires)
    Votre choix : 2
    Veuillez entrer le chemin du fichier source :

Pour le MODE TESTEUR:
A la première question que voici vous mettre le chemin affiché ici:

    Veuillez entrer le chemin du fichier source : /mnt/c/Users/alexi/Desktop/CESI/A2/BLOC_2_Programmation_Orientée_Objet/Jeu_De_La_Vie/01_test_unitaire.txt

A la deuxième vous nommerez votre dossier de cette manière :

    Veuillez entrer le nom du dossier de destination : Test_unitaire_out

Puis vous définirez le nombre de génération à calculer à 4 (la génération initiale (0) jusqu'à la 3ieme):

    Combien de générations souhaitez-vous calculer ? : 4

Il s'affichera ensuite ceci si tout se passe bien :

    Dimensions lues du fichier : 5x10
    Generation 0 sauvegardée dans : Test_unitaire_out/generation_0.txt
    Generation 1 sauvegardée dans : Test_unitaire_out/generation_1.txt
    Generation 2 sauvegardée dans : Test_unitaire_out/generation_2.txt
    Generation 3 sauvegardée dans : Test_unitaire_out/generation_3.txt

Et vous pourrez vérifier qu'à la génération 3 le fichier ressemble à ça :
    0 0 0 0 0 0 0 0 0 0 
    0 0 0 0 0 0 0 0 0 0 
    0 0 1 1 1 0 0 0 0 0 
    0 0 0 0 0 0 0 0 0 0 
    0 0 0 0 0 0 0 0 0 0 



Pour le MODE UTILISATEUR:

en fonction du choix 1 ou 2, vous serez dirigé vers 
dans le PREMIER CAS MODE CONSOLE:

    Bienvenue dans le Jeu de la Vie !
    1. Mode Utilisateur
    2. Mode Testeur (tests unitaires)
    Votre choix : 1
    Choisissez un mode :
    1. Mode Console
    2. Mode Graphique
    Votre choix : 1
    Veuillez entrer le chemin du fichier source : 

Vous entrerez le chemin du fichier comme ci dessous: 

    Veuillez entrer le chemin du fichier source : /mnt/c/Users/alexi/Desktop/CESI/A2/BLOC_2_Programmation_Orientée_Objet/Jeu_De_La_Vie/01_fichier_test.txt

Puis le nom de votre dossier:

    Veuillez entrer le nom du dossier de destination : fichier_test_out

Et enfin le nombre de génération à calculer :

    Combien de générations souhaitez-vous générer ? : 4

Vous verrez apparaitre ceci :

    Dimensions lues du fichier : 50x100
    Generation 0 sauvegardée dans : fichier_test_out/generation_0.txt
    Generation 1 sauvegardée dans : fichier_test_out/generation_1.txt
    Generation 2 sauvegardée dans : fichier_test_out/generation_2.txt
    Generation 3 sauvegardée dans : fichier_test_out/generation_3.txt

et votre dossier "fichier_test_out" appraître dans vos fichiers, vous pourrez ensuite visualiser les différentes générations


dans le SECOND CAS MODE GRAPHIQUE:

    Bienvenue dans le Jeu de la Vie !
    1. Mode Utilisateur
    2. Mode Testeur (tests unitaires)
    Votre choix : 1
    Choisissez un mode :
    1. Mode Console
    2. Mode Graphique
    Votre choix : 2
    Veuillez entrer le chemin du fichier source : 

Vous entrerez le chemin du fichier comme ci dessous: 

    Veuillez entrer le chemin du fichier source : /mnt/c/Users/alexi/Desktop/CESI/A2/BLOC_2_Programmation_Orientée_Objet/Jeu_De_La_Vie/01_fichier_test.txt

Vous verrez apparaitre ceci, qui sont les paramètres que vous aurez mis dans le fichier pour la grille: 

    Dimensions lues du fichier : 50x100

Puis vous donnerez le delay entre chaque génération en millisecondes (je vous conseille (500ms) pour que le passage entre génération ne soit ni trop rapide ni trop lent):

    Entrez le délai entre chaque génération (en millisecondes) : 500

Vous verrez apparaitre ceci :

    MESA: error: ZINK: failed to choose pdev         ici les erreurs affichées n'empechent en rien le bon fonctionnement du programme, elles vous seront expliquées dans le livrable
    glx: failed to create drisw screen
    Dimensions de la fenêtre : 1000x500                ici les dimensions sont multipliées par la taille des cellules(cellSize) ici paramètrées à 10.
    Setting vertical sync not supported

et une fenetre apparaitra vous émulant le jeu de la vie à partir de votre fichier. Pour arrêter 
*/
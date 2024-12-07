Fonctionnement :

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
A la première question que voici vous mettre le chemin de votre fichier; exemple:

    Veuillez entrer le chemin du fichier source : /mnt/c/Users/alexi/Desktop/CESI/A2/BLOC_2_Programmation_Orientée_Objet/Jeu_De_La_Vie/01_test_unitaire.txt

A la deuxième vous nommerez votre dossier de cette manière, exemple :

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
    Veuillez entrer le chemin du fichier source: 

Vous entrerez le chemin du fichier comme dans l'exemple ci-dessous: 

    Veuillez entrer le chemin du fichier source : /mnt/c/Users/alexi/Desktop/CESI/A2/BLOC_2_Programmation_Orientée_Objet/Jeu_De_La_Vie/01_fichier_test.txt

Puis le nom de votre dossier; exemple:

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

Vous entrerez le chemin du fichier comme dans l'exemple ci-dessous: 

    Veuillez entrer le chemin du fichier source : /mnt/c/Users/alexi/Desktop/CESI/A2/BLOC_2_Programmation_Orientée_Objet/Jeu_De_La_Vie/01_fichier_test.txt

Vous verrez apparaitre ceci, qui sont les paramètres que vous aurez mis dans le fichier pour la grille: 

    Dimensions lues du fichier : 50x100

Puis vous donnerez le delay entre chaque génération en millisecondes (je vous conseille (500ms) pour que le passage entre génération ne soit ni trop rapide ni trop lent):

    Entrez le délai entre chaque génération (en millisecondes) : 500

Vous verrez apparaitre ceci :

    MESA: error: ZINK: failed to choose pdev         ici les erreurs affichées n'empechent en rien le bon fonctionnement du programme, elles vous seront expliquées dans le livrable
    glx: failed to create drisw screen
    Dimensions de la fenêtre : 1000x500                ici les dimensions sont multipliées par la taille des cellules(cellSize) ici paramêtrées à 10.
    Setting vertical sync not supported

et une fenetre apparaitra vous émulant le jeu de la vie à partir de votre fichier. 
Pour arrêter vous aurez juste à fermer la fenêtre.


Dans le Mode Graphique vous aurez la possibilité d'intéragir de différentes manières.
Vous pouvez mettre pause la simulation en appuyant simplement sur:

    -"BARRE ESPACE"

Si vous voulez intéragir plus directement sur la simulation vous pourrez, en plaçant votre souris sur la simulation à l'endroit que vous souhaitez, générer différentes formes basiques.

En appuyant sur:

    -la touche "C" vous pourrez ajouter à l'endroit que vous voudrez une cellule vivante unique.
    -la touche "S" vous pourrez ajouter à l'endroit que vous voudrez une structure stable (carré 2x2).
    -la touche "B" vous pourrez ajouter à l'endroit que vous voudrez un blinker en deux générations.
    -la touche "G" vous pourrez ajouter à l'endroit que vous voudrez un glider.

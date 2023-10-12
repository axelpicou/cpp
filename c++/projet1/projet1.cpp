// projet1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>

class Perso {
public:
    int vie;
    int attaque;
    int agilite;
    std::string nom;

public:

    Perso(std::string nom_, int vie_, int attaque_, int agilite_);
    void prendredmg(int dmg) {
        vie -= dmg;
        if (vie <= 0) {
            vie = 0;
        }
    }
    void attaquer(Perso& cible) {
        cible.prendredmg(attaque);

    }
    bool vivant() {
        return vie > 0;
    }

};


int main(int argc, char const* argv[])
{
    Perso perso1("pablo", 100, 10, 10);
    Perso perso2("miguel", 100, 15, 20);


    std::cout << "choisisez la dificulté" << std::endl;
    std::cout << "entre 1 pour facile | 2 pour normal | 3 pour dificile | 4 pour impossible" << std::endl;
    int dificulte;
    int mod;
    std::cin >> dificulte;
    if (dificulte == 1) {
        std::cout << "facile" << std::endl;
        mod = 0,5;
        Perso perso2("miguel", 100 * mod, 15 * mod, 20 * mod);
    }
    else if (dificulte == 2) {
        std::cout << "normal" << std::endl;
        mod = 1;
        Perso perso2("juan", 100 * mod, 15 * mod, 20 * mod);
    }
    else if (dificulte == 3) {
        std::cout << "dificile" << std::endl;
        mod = 1,5;
        Perso perso2("benito", 100 * mod, 15 * mod, 20 * mod);
    }
    else if (dificulte == 4) {
        std::cout << "impossible" << std::endl;
        mod = 3;
        Perso perso2("juanito", 100 * mod, 15 * mod, 20 * mod);
    }

    std::cout << "votre adversaire est " << perso2.nom << std::endl;
    std::cout << "votre perso est " << perso1.nom << std::endl;
    return 0;
}







// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

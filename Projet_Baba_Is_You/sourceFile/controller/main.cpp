#include <iostream>

#include "../../headerFile/model/position.h"
#include "../../headerFile/model/direction.h"
#include "../../headerFile/model/board.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


using namespace std;
using namespace dev4;


int main() {

    int level = 0;
    std::stringstream chemin;
    chemin << "../sourceFile/level/level_" << level << ".txt";
    std::string fichierString = chemin.str();

    std::ifstream fichier(fichierString);

    int i = 0;
    if (fichier.is_open()) {
        std::cout << "le fichier est ou ouvert" << std::endl;
        std::string ligneFichier;
        while (std::getline(fichier, ligneFichier)) {
            cout << ligneFichier << endl;
            std::string element;
            std::vector<std::string> elementLigne;
            istringstream decompose(ligneFichier);
            while (decompose >> element) {
                elementLigne.push_back(element);
            }
            if (i == 0) {
                cout << " " << elementLigne.size() << endl;
                i++;
            } else {
                if (elementLigne.size() == 3) {
                    cout << " " << elementLigne.size() << endl;


                } else {
                    cout << " " << elementLigne.size() << endl;
                }
                i++;
            }
        }
        cout << "nombre de ligne: " << i << endl;
        fichier.close();
    }
//    else{
//        std::cerr<<"Erreur d'ouverture du fichier";
//    }
////    std::string nombres = "12 34 56 78";
////    std::istringstream iss(nombres);
////
////    int nombre1, nombre2, nombre3, nombre4;
////    iss >> nombre1 >> nombre2 >> nombre3 >> nombre4;
////
////    std::cout << "Nombre 1 : " << nombre1 << std::endl;
////    std::cout << "Nombre 2 : " << nombre2 << std::endl;
////    std::cout << "Nombre 3 : " << nombre3 << std::endl;
////    std::cout << "Nombre 4 : " << nombre4 << std::endl;
    return 0;
}

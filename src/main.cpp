#include <SFML/Graphics.hpp>
#include <vector>
#include "case.hpp"

#define WINDOW_COTE 1000
#define CASE_LIGNE 10
#define CASE_COLONNE 10

using namespace std;
using std::copy;

int main()
{
    srand(time(0));
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({WINDOW_COTE, WINDOW_COTE}), "Grille Jeu de la vie");
    vector<vector<Case>> tableau;

    for (int i=0; i<WINDOW_COTE/CASE_LIGNE; i++){
        vector<Case> ligne = vector<Case> {};
        tableau.push_back(ligne);
        for (int j=0; j<WINDOW_COTE/CASE_COLONNE; j++){
            Case current_case = Case((float) i*CASE_LIGNE, (float) j*CASE_COLONNE);
            tableau[i].push_back(current_case);
        }
    }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        vector<vector<Case>> next_tableau = tableau;
        
        for (int i=0; i<WINDOW_COTE/CASE_LIGNE; i++){
            for (int j=0; j<WINDOW_COTE/CASE_COLONNE; j++){
                tableau[i][j].PrintCase(window);
                next_tableau[i][j].UpdateState(tableau);
            }
        }

        tableau = next_tableau;
        
        window.display();
    }
}
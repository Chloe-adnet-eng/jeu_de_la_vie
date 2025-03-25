#include <SFML/Graphics.hpp>
#include <vector>
#include "case.hpp"
#include <iostream>

#define WINDOW_COTE 400
#define NOMBRE_CASE_COTE 400

using namespace std;
using std::copy;

int main()
{
    srand(time(0));
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({WINDOW_COTE, WINDOW_COTE}), "Grille Jeu de la vie");
    // Pré-allocation de la mémoire
    vector<Case> initial_board(NOMBRE_CASE_COTE * NOMBRE_CASE_COTE);
    int rectangle_length = WINDOW_COTE/NOMBRE_CASE_COTE;

    for (int i = 0; i < NOMBRE_CASE_COTE; i++) {
        for (int j = 0; j < NOMBRE_CASE_COTE; j++) {
            initial_board[i * NOMBRE_CASE_COTE + j] = Case(i * rectangle_length, j * rectangle_length);
        }
    }

    sf::Clock clock;
    float frame_rate = 0.1f;
   
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        if (clock.getElapsedTime().asSeconds() >= frame_rate) {
            vector<Case> next_board = initial_board;

            for (int i = 0; i < NOMBRE_CASE_COTE; i++) {
                for (int j = 0; j < NOMBRE_CASE_COTE; j++) {
                    int idx = i * NOMBRE_CASE_COTE + j;
                    initial_board[idx].PrintCase(window);  // Dessiner la case
                    next_board[idx].UpdateState(initial_board);  // Mettre à jour l'état de la case
                }
            }

            initial_board = next_board;  // Mise à jour de l'état pour la prochaine itération

            clock.restart();  // Réinitialiser le chrono

            window.display();  // Affichage
        }

    }
}
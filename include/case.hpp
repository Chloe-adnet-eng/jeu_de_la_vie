#include <SFML/Graphics.hpp>
#include <vector>
#define COTE 10

using namespace std;

enum State {
    Alive,
    Dead
};

class Case {
    public:
        sf::Vector2f position;
        State state;

        Case(float x, float y){
            
            sf::Vector2 position = sf::Vector2(x, y);
            
            int random_value = rand()%2;
            State state = random_value == 0 ? State::Alive : State::Dead;

            this->position = position;
            this->state = state;
            
        }

        void PrintCase(sf::RenderWindow& window){
            sf::RectangleShape rectangle;

            rectangle.setPosition(this->position);
            rectangle.setSize(sf::Vector2f(COTE, COTE));
            sf::Color color = sf::Color::Black;

            if (this->state == State::Alive){
                color = sf::Color::White;
            }
            rectangle.setFillColor(color);
            window.draw(rectangle);
        }

        void UpdateState(vector<vector<Case>> tableau){
            int alive_neighbours = 0;
            sf::Vector2 current_position = this->position;
            int x_index = position.x/10;
            int y_index = position.y/10;

            for (int i=-1; i<=1; i++){
                for (int j=-1; j<=1; j++){
                    if (i != j) {
                        if (
                            (x_index+i >= 0) &&
                            (y_index+j >= 0) &&
                            (x_index+i < tableau.size()) &&
                            (y_index+j < tableau[0].size()) &&
                            (tableau[x_index+i][y_index+j].state == State::Alive)
                        ){
                            alive_neighbours++;
                        }
                    }
                }
            }
            if (this->state == State::Alive && (alive_neighbours == 2 || alive_neighbours == 3)){
                this->state = State::Alive;
            }
            else if (this->state == State::Dead && (alive_neighbours == 3)){
                this->state = State::Alive;
            }
            else {
                this->state = State::Dead;
            }

        }
        
};


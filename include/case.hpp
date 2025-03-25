#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#define CASE_LENGTH 1
#define NOMBRE_CASE_COTE 400


using namespace std;

enum State {
    Alive,
    Dead
};

class Case {
    public:
        sf::Vector2f position;
        State state;
        sf::RectangleShape rectangle;

        Case() : position(0, 0), state(State::Dead) {

            rectangle.setSize(sf::Vector2f(CASE_LENGTH, CASE_LENGTH));
            rectangle.setPosition(position);
        }

        Case(float x, float y){
            this->position = sf::Vector2f(x, y);

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, 1);  
            this->state = dis(gen) == 0 ? State::Alive : State::Dead;

            this->rectangle.setSize(sf::Vector2f(CASE_LENGTH, CASE_LENGTH));
            this->rectangle.setPosition(position);
        }

        void PrintCase(sf::RenderWindow& window){
            sf::Color color = sf::Color::Red;

            if (this->state == State::Alive){
                color = sf::Color::White;
            }
            this->rectangle.setFillColor(color);
            window.draw(this->rectangle);
        }

        void UpdateState(const vector<Case> &board){
            int alive_neighbours = 0;
            
            int x_index = this->position.x/CASE_LENGTH;
            int y_index = this->position.y/CASE_LENGTH;

            for (int i=-1; i<=1; i++){
                for (int j=-1; j<=1; j++){

                    if (i == 0 && j == 0) continue;

                    int neighbour_x = x_index + i;
                    int neighbour_y = y_index + j;

                        if ( 
                            neighbour_x >= 0 && neighbour_x < NOMBRE_CASE_COTE &&
                            neighbour_y >= 0 && neighbour_y < NOMBRE_CASE_COTE 
                        ){
                            if (board[neighbour_x + neighbour_y*NOMBRE_CASE_COTE].state == State::Alive){
                                alive_neighbours++;
                            }
                        }

                    }
                }
            if (
                this->state == State::Alive 
                && (alive_neighbours == 2 || alive_neighbours == 3)
            ){
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


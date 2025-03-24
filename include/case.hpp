#include <SFML/Graphics.hpp>
#define COTE 10

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
        
};


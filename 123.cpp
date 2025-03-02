#include<iostream>
#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(500, 500), ".");
    sf::CircleShape shape(15);
    shape.setFillColor(sf::Color(133, 77, 179, 120));;

    sf::Clock* clock = new sf::Clock;
    float time;
    float speed = 5000;

    while (window.isOpen()){
        time = clock->restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                shape.move(-1.0f * time * speed, 0.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                shape.move(1.0f * time * speed, 0.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                shape.move(0.0f, -1.0f * time * speed);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                shape.move(0.0f, 1.0f * time * speed);
            }
        }
        window.clear(sf::Color(157, 210, 227, 181));
        window.draw(shape);
        window.display();
    }
}
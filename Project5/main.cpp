#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <utility>
#include <algorithm>
#include <chrono>
#include <thread>


int main()
{
    const int range_from = 0;
    const int range_to = 400;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range_from, range_to);

    sf::RenderWindow window(sf::VideoMode(1000, 500), "Sorting Algorithm");
    sf::Event event;

    std::vector<sf::RectangleShape> vec;
    double size = 1000.0 / 100;

    bool swapped = false;


    for (int i = 0; i < 100; i++) {
        sf::RectangleShape rec(sf::Vector2f(size, distr(generator)));
        vec.push_back(rec);
    }

    
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        for (int i = 0; i < 100; i++) {
            // the height of the rectangle is the number generated
            vec[i].setPosition(i * size, 500 - vec[i].getSize().y);
            window.draw(vec[i]);
        }
          // Call bubbleSort function
        for (int i = 0; i < vec.size() - 1; i++) {
            for (int j = 0; j < vec.size() - 1 - i; j++) {
                if (vec[j].getSize().y > vec[j + 1].getSize().y) {
                    std::swap(vec[j], vec[j + 1]);
                    swapped = true;
                }
                std::this_thread::sleep_for(std::chrono::nanoseconds(500));
                if (swapped) { 
                    window.clear();
                    for (int i = 0; i < 100; i++) {
                        // the height of the rectangle is the number generated
                        vec[i].setPosition(i * size, 500 - vec[i].getSize().y);
                        window.draw(vec[i]);
                    }
                    window.display();
                }
                swapped = false;
            }

        }
        window.display();
        
    }

    return EXIT_SUCCESS;
}

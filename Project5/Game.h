#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {

public:
	Game();
	~Game();
	void render();
	void events();
	void update();
	void run();
	void updatedt();

private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock clock;
	float dt;

	void init();

};

#endif
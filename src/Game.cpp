
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	in_menu = true;

	// init background
	if (!background_texture.loadFromFile("Data/WhackaMole Worksheet/background.png"))
	{
		std::cout << "background texture did not load \n";
	}
	background.setTexture(background_texture);

	// init bird
	if (!bird_texture.loadFromFile("Data/WhackaMole Worksheet/bird.png"))
	{
		std::cout << "bird texture did not load \n";
	}
	bird.setTexture(bird_texture);
	bird.setPosition(100, 100);
	bird.setScale(0.5, 0.5);

	// init text
	if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "font did not load \n";
	}
	title_text.setString("Whack-a-mole");
	title_text.setFont(font);
	title_text.setCharacterSize(100);
	title_text.setFillColor(sf::Color(255, 255, 255, 128));
	title_text.setPosition(
		window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
		window.getSize().y / 2 - title_text.getGlobalBounds().height / 2);

	menu_text.setString("Welcome to Whack a Mole, please select an option:");
	menu_text.setFont(font);
	menu_text.setCharacterSize(20);
	menu_text.setFillColor(sf::Color(255, 255, 0, 255));
	menu_text.setPosition(
		window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2,
		window.getSize().y / 6 - menu_text.getGlobalBounds().height / 2);

	play_text.setString("Play");
	play_text.setFont(font);
	play_text.setCharacterSize(20);
	play_text.setFillColor(sf::Color(255, 255, 0, 255));
	play_text.setPosition(
		window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2,
		window.getSize().y / 4 - play_text.getGlobalBounds().height / 2);

	quit_text.setString("Quit");
	quit_text.setFont(font);
	quit_text.setCharacterSize(20);
	quit_text.setFillColor(sf::Color(255, 255, 0, 255));
	quit_text.setPosition(
		window.getSize().x / 2 + (menu_text.getGlobalBounds().width / 2) - (quit_text.getGlobalBounds().width),
		window.getSize().y / 4 - quit_text.getGlobalBounds().height / 2);



  return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
	if (in_menu)
	{
		window.draw(menu_text);
		window.draw(play_text);
		window.draw(quit_text);
	}
	else
	{
		window.draw(background);
		window.draw(title_text);
		window.draw(bird);
	}

	
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{

}



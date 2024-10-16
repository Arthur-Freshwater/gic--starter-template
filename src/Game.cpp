
#include "Game.h"
#include <iostream>
#include <random>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
  sf::Clock clock;
  sf::Time time = clock.restart();
  float dt = time.asSeconds();
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

	score_text.setString("0");
	score_text.setFont(font);
	score_text.setCharacterSize(50);
	score_text.setFillColor(sf::Color(255, 0, 0, 255));
	score_text.setPosition(
		window.getSize().x - score_text.getGlobalBounds().width * 6,
		window.getSize().y / 6 - score_text.getGlobalBounds().height / 2);



  return true;
}

void Game::update(float dt)
{
	if (in_menu)
	{

	}
	else
	{
		if ((bird.getPosition().x > (window.getSize().x - bird.getGlobalBounds().width)) ||
			(bird.getPosition().x < 0))
		{
			reverse = !reverse;
		}

		if (!reverse)
		{
			bird.move(-1.0f * speed * dt, 0);
			bird.setTextureRect(sf::IntRect(
				bird.getLocalBounds().width,
				0,
				-bird.getLocalBounds().width,
				bird.getLocalBounds().height));
		}
		else
		{
			bird.move(1.0f * speed * dt, 0);
			bird.setTextureRect(sf::IntRect(
				0, 0, bird.getLocalBounds().width, bird.getLocalBounds().height));

		}
	}
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
		window.draw(score_text);
		window.draw(bird);
	}
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  click.x = sf::Mouse::getPosition(window).x;
  click.y = sf::Mouse::getPosition(window).y;

  //check if in bounds of bird Sprite
  if (collisionCheck(click, bird))
  {
	  score++;
	  score_text.setString(std::to_string(score));
	  
	  spawn(bird);

  }


}

void Game::keyPressed(sf::Event event)
{
	if (
		(event.key.code == sf::Keyboard::Left) ||
		(event.key.code == sf::Keyboard::Right))
	{
		play_option = !play_option;
		if (!play_option)
		{
			play_text.setString("> Play <");
			quit_text.setString("Quit");
		}
		else
		{
			play_text.setString("Play");
			quit_text.setString("> Quit <");
		}
	}
	else if (event.key.code == sf::Keyboard::Enter)
	{
		if (!play_option)
		{
			in_menu = false;
		}
		else
		{
			window.close();
		}
	}
}

bool Game::collisionCheck(sf::Vector2i, sf::Sprite)
{
	if ((click.x > bird.getPosition().x && (click.x < bird.getPosition().x + bird.getGlobalBounds().width)) && 
		(click.y > bird.getPosition().y && (click.y < bird.getPosition().y + bird.getGlobalBounds().height)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::spawn(sf::Sprite)
{
	int rand_x = rand() % window.getSize().x;
	int rand_y = rand() % window.getSize().y;

	if (rand_x > window.getSize().x - bird.getGlobalBounds().width)
	{
		rand_x = window.getSize().x - bird.getGlobalBounds().width;
	}
	else if (rand_y > window.getSize().y - bird.getGlobalBounds().height)
	{
		rand_y = rand_y > window.getSize().y - bird.getGlobalBounds().height;
	}
	bird.setPosition(rand_x,rand_y);

}



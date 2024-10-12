
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  bool collisionCheck(sf::Vector2i, sf::Sprite);
  void spawn(sf::Sprite);

 private:
  sf::RenderWindow& window;
  sf::Sprite ball;
  sf::Texture ball_texture;

  sf::Sprite background;
  sf::Texture background_texture;

  sf::Sprite bird;
  sf::Texture bird_texture;

  sf::Text title_text;
  sf::Font font;

  sf::Text menu_text;
  sf::Text play_text;
  sf::Text quit_text;
  
  bool in_menu;
  bool play_option;

  int speed = 300;
  bool reverse;

  sf::Vector2i click;

  sf::Text score_text;
  int score = 0;

};

#endif // PLATFORMER_GAME_H

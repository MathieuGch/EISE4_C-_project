#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

/*
La classe photo permet de créer un objet possédant un sprite qui sera ensuite
facilement affichage via la méthode photo de la classe Fenêtre.
*/

class Photo {
 public:
  // Constructor
  Photo(string n, int x, int y, int w, int h, int px, int py);
  Photo();
  // Destructor
  ~Photo();
  // Function members
  void resize(int x, int y);

  sf::Sprite getSprite(void){
    return this->Sphoto;
  }
  string getNom(void){
    return this->nom;
  }
 private:
  //attributes
  string nom;
  int posX;
  int posY;
  int width;
  int height;
  sf::Texture SFigur;
  sf::Sprite Sphoto;
};

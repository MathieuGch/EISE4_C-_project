#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

/* La classe bouton permet de créer un bouton qui pourra ensuite être
afficher via la classe Fenêtre
Elle possède une méthode "isSelected" afin de savoir si on a appuyé sur le Bouton
et qui entre autre augmente le contour du bouton dès que l'on passe la souris
dessus*/


class Bouton{
public:
  Bouton(int x, int y, int w, int h, string t, sf::Color cBouton, sf::Color cText);
  ~Bouton(){}
  void Afficher();
  bool isSelected(int mouseX, int mouseY);

  int getPosX(){
    return this->posX;
  }
  int getPosY(){
    return this->posY;
  }
  int getWidth(){
    return this->width;
  }
  int getHeight(){
    return this->height;
  }
  int getThickness(void){
    return this->thickness;
  }
  string getText(void){
    return this->text;
  }
  sf::Color getColorBouton(void){
    return this->colorBouton;
  }
  sf::Color getColorText(void){
    return this->colorText;
  }
private:
  int posX;
  int posY;
  int width;
  int height;
  int thickness;
  string text;
  sf::Color colorBouton;
  sf::Color colorText;

};

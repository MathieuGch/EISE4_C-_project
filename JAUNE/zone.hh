#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

/*
La classe zone permet de créer une zone sur l'écran ou, grâce à sa méthode
"isSelected()", on pourra afficher un texte dès que la souris se trouve dans
cette zone. La méthode retoure en plus vraie si on a cliqué dans cette zone. 
*/

class Zone{
public:
  Zone(int x, int y, int w, int h, string n);
  ~Zone();
  bool isSelected(int mouseX, int mouseY);
  string getText(void){
    return this->text;
  }
  void setText(string t){
    this->text = t;
  }
  int getposX(){
    return this->posX;
  }
  int getposY(){
    return this->posY;
  }
  int getWidth(){
    return this->width;
  }
  int getHeight(){
    return this->height;
  }

private:
  string text;
  string nom;
  int posX;
  int posY;
  int width;
  int height;


};

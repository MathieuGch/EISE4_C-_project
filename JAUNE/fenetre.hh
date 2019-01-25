#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "photo.hh"
#include "bouton.hh"
using namespace std;

/*
La classe fenêtre permet de réaliser tout l'affichage de l'application
On peut créer du texte, des zones, des boutons ou des photos (via leur classe
respective). Elle renvoie également des informations sur l'état de la fenêtre via
la méthode isOpen
*/

class Fenetre{
public:
   Fenetre(int w, int h, string header);
   ~Fenetre(){delete window;};
   void majAffichage();
   bool isOpen(){return window->isOpen();}
   void close(){window->close();}
   bool pollEvent(sf::Event& event){return window->pollEvent(event);}
   int getPosMouseX(){ return sf::Mouse::getPosition(*window).x;}
   int getPosMouseY(){ return sf::Mouse::getPosition(*window).y;}
   void text(int x, int y, string text, sf::Color color = sf::Color(255,240,0,255));
   void bouton(Bouton b);
   void box(int x, int y, int w, int h, sf::Color color = sf::Color::Yellow);
   void photo(Photo *p);

private:
    int width;
    int height;
    sf::RenderWindow *window;
};

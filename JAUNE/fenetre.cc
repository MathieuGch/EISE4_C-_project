#include "fenetre.hh"


Fenetre::Fenetre(int w, int h, string header){
  width = w;
  height = h;
  window = new sf::RenderWindow(sf::VideoMode(w, h), header);
}
void Fenetre::majAffichage(){
    window->display();
    window->clear(sf::Color(245,245,245,255));

}

void Fenetre::text(int x, int y, string t, sf::Color color){
  sf::Font font;
  if (!font.loadFromFile("arial.ttf"))
  {
      // error...
  }
  sf::Text text;
  text.setFont(font);
  text.setPosition(x,y);
  text.setString(t);
  text.setCharacterSize(20);
  text.setFillColor(sf::Color(color));
  window->draw(text);
}

void Fenetre::bouton(Bouton b){
  sf::RectangleShape rectangle(sf::Vector2f(b.getWidth(), b.getHeight()));
  rectangle.setFillColor(b.getColorBouton());
  rectangle.setPosition(b.getPosX(), b.getPosY());
  rectangle.setOutlineColor(sf::Color::Black);
  rectangle.setOutlineThickness(b.getThickness());
  window->draw(rectangle);
  text(b.getPosX() + 10, b.getPosY() + 10, b.getText(), b.getColorText());
}

void Fenetre::box(int x, int y, int w, int h, sf::Color color){
  sf::RectangleShape rectangle(sf::Vector2f(w, h));
  rectangle.setPosition(x, y);
  rectangle.setFillColor(sf::Color(245,245,245,255));
  rectangle.setOutlineColor(sf::Color(color));
  rectangle.setOutlineThickness(3);
  window->draw(rectangle);
}
void Fenetre::photo(Photo *p){
  window->draw(p->getSprite());
}

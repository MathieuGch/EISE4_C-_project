#include "bouton.hh"


Bouton::Bouton(int x, int y, int w, int h, string t, sf::Color cBouton, sf::Color cText){
  posX = x;
  posY = y;
  width = w;
  height = h;
  thickness = 1;
  text = t;
  colorBouton = cBouton;
  colorText = cText;
}



bool Bouton::isSelected(int mouseX, int mouseY){
  if(mouseX > posX && mouseX < (posX + width) && mouseY > posY && mouseY < (posY + height)){
    thickness = 3;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      return true;
    }else
      return false;
  }else{
    thickness = 1;
    return false;
  }
}

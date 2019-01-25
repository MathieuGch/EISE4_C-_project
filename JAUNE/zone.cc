#include "zone.hh"




Zone::Zone(int x, int y, int w, int h, string n){
  posX = x;
  posY = y;
  width = w;
  height = h;
  nom = n;
  text = "";
}

Zone::~Zone(){
}

bool Zone::isSelected(int mouseX, int mouseY){
  if(mouseX > posX && mouseX < (posX + width) && mouseY > posY && mouseY < (posY + height)){
    // On change le texte ce qui permet de l'afficher à l'écran
    text = nom;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      return true;
    }else
      return false;
  }else{
    //On affiche rien (aka "")
    text = "";
    return false;
  }
}

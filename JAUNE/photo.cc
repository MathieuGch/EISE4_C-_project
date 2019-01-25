#include "photo.hh"

//Constructors

Photo::Photo(){}

Photo::Photo(string n, int x, int y, int w, int h, int px, int py){
    nom = n;
    posX = px;
    posY = py;
    width = w;
    height = h;
    if (!SFigur.loadFromFile(nom,sf::IntRect(x, y, width, height))){
      std::cout << "Image can't load!\n";
    }
    sf::Sprite PImage(SFigur);
    PImage.setPosition (posX, posY);
    PImage.setScale (1, 1);
    Sphoto = PImage;
}
// Destructor
Photo::~Photo(){
}
// Function members

void Photo::resize(int x, int y){
  Sphoto.setPosition(x, y);
}

/*
std::string Pays::toString() const{
	std::string res = "(" + this->nom + " = " + val_to_string(this->val) + ")";
   return res;
}


Pays& Pays::operator = (bool b){
	(b == true)?(this->val = T):(this->val = F);
	return *this;
}

*/

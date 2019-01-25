#include "joueur.hh"


Joueur::Joueur(string n){
  nom = n;
  vie = 5;
  score = 0;
}


// Retourne vrai si le joueur à battu l'ia
bool Joueur::operator > (Joueur ia){
  if(this->vie > 0){
    if(this->score > ia.getScore()){
      return true;
    }
  }
  return false;
}

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

/*
La classe Joueur créé un joueur avec possédant un nom, un score et un nombre de
vie prédifinie (ici 5).
La méthode perVie fait automatiquement perdre une vie au joueur et retourne
vraie si le joueur n'a plus de vie.
*/

class Joueur{
public:
  Joueur(string n);
  ~Joueur(){}
  string getNom(void){
    return this->nom;
  }
  string getTextScore(void){
    sprintf(nbScore,"Score : %d",score);
    return this->nbScore;
  }

  int getVie(void){
    return this->vie;
  }
  bool perdVie(void){
    this->vie -= 1;
    if (this->vie == 0) return true;
    else return false;
  }
  int getScore(void){
    return this->score;
  }
  void addScore(int s){
    this->score += s;
  }
  bool operator > (Joueur ia);

protected:
  string nom;
  int vie;
  int score;
  char nbScore[20];

};

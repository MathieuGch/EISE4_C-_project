#include <iostream>
#include "jeu.hh"
#include "fenetre.hh"
#include "bouton.hh"


int main(void){
  srand (time(NULL));
  string nom;
  int score;
  bool jouer = true;
  char displayScore[100];
  cout << "Enter your name : ";
  cin >> nom;
  Joueur joueur(nom);
  Fenetre welcome(200,150,"WELCOME");
  Bouton play(70,100,60,47,"Play", sf::Color::Yellow, sf::Color::Black);
  while(welcome.isOpen()){
    welcome.majAffichage();
    sf::Event event;
    while (welcome.pollEvent(event)){
      if (event.type == sf::Event::Closed){
        welcome.close();
        exit(0);
      }else{
        int mouseX = welcome.getPosMouseX();
        int mouseY = welcome.getPosMouseY();
        if(play.isSelected(mouseX, mouseY)) welcome.close();
      }
    }
    welcome.text(30,40,"Welcome " + joueur.getNom());
    welcome.bouton(play);
  }
  while(jouer){
    jouer = false;
    Jeu jeu(joueur);
    score = jeu.jouer();
    Fenetre wellplayed(300,150,"WELL PLAYED");
    Bouton playAgain(90,100,120,47,"Play again", sf::Color::Yellow, sf::Color::Black);
    while(wellplayed.isOpen()){
      wellplayed.majAffichage();
      sf::Event event;
      while (wellplayed.pollEvent(event)){
        if (event.type == sf::Event::Closed){
          welcome.close();
          exit(0);
        }else{
          int mouseX = wellplayed.getPosMouseX();
          int mouseY = wellplayed.getPosMouseY();
          if(playAgain.isSelected(mouseX, mouseY)){
            jouer = true;
            wellplayed.close();
          }
        }
      }
      wellplayed.text(50,25,"Well played " + joueur.getNom());
      if(score > 1000){
        wellplayed.text(50,50,"you beat the AI ");
        sprintf(displayScore,"Your score : %d",score - 1000);
        wellplayed.text(50, 75, displayScore);
      }else{
        sprintf(displayScore,"Your score : %d",score);
        wellplayed.text(50, 50, displayScore);
      }
      wellplayed.bouton(playAgain);
    }

  }
  return 0;
}

#ifndef CHESSLIB
#define CHESSLIB

#include "chessman.h"

class Bishop: virtual public Figure
{
 public:
  Bishop(char* p):Figure(p){};
  Bishop(){};
  char isa() {return 'B';};
  int attack(char*);
};

class Rook: virtual public Figure
{
 public:
  Rook(char* p): Figure(p){};
Rook(){};
  char isa(){return 'R';};
  int attack(char*);
};

class Queen: public Bishop,public Rook
{
 public:
  Queen(char* p):Figure(p){};
  Queen(){};
  char isa(){return 'Q';};
  int attack(char*);
};
#endif

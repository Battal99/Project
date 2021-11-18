#include"chesslib.h"

int Rook::attack(char* p)
{
 if(deskout(p)>0)
  return(0);
 int x=p[0]-pos[0];
 int y=p[1]-pos[1];
 if(x<0)x=-x;
 if(y<0)y=-y;
 //if((x+y)<2)
 if((p[0]==pos[0])||(p[1]==pos[1]))
  return(1);
 return(0);
}

int Bishop::attack(char* p)
{
 if(deskout(p)>0)
  return(0);
 int x=p[0]-pos[0];
 int y=p[1]-pos[1];
 if(x<0) x=-x;
 if(y<0) y=-y;
 if (x!=y)
  return(0);
 return(1);
}

int Queen::attack(char* s)
{
 if(Rook::attack(s)>0)
  return(1);
 if(Bishop::attack(s)>0)
  return(2);
 return(0);
}


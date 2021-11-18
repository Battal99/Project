#include "chessman.h"
using std::cout;

Figure::Figure(char* p)
{
pos[0]=p[0]; pos[1]=p[1];
}

Figure::operator char*()
{
 return pos;
}

int Figure::deskout(char* p)
{ 
 return((p[0]>'h')||(p[0]<'a')||(p[1]<'1')||(p[1]>'8'));
}

Figure& Figure::operator=(char* p)
{
 pos[0]=p[0]; pos[1]=p[1];
 return(*this);
}

int Figure::operator==(char* p)
{
 return((pos[0]==p[0])&&(pos[1]==p[1]));
}

int Figure::operator!=(char* p)
{
 return((pos[0]!=p[0])||(pos[1]!=p[1]));
}

std::ostream& operator<<(std::ostream& out, Figure& f)
{
 return out<<f.isa()<<f.pos[0]<<f.pos[1];
}

std::istream& operator>>(std::istream& in, Figure& f)
{
 char s[2];
 in.unsetf(std::ios::skipws);
 in>>s[0]>>s[1];
 in.ignore(64,'\n');
 if((f.attack(s)==0)||(f==s))
  in.clear(std::ios::failbit | in.rdstate());
 f=s;
 return in;
}

int Figure::danger()
{ 
 int i,j;
 char s[2];
 char* mark=".+x";
 char m;
 cout<<"  a b c d e f g h\n";
 for(i=8;i>0;i--)
 {
   cout<<i<<' ';
   s[1]='0'+i;
   for(j=0;j<8;j++)
   {
     s[0]='a'+j;
     m=(*this!=s)?mark[attack(s)]:isa();
     cout<<m<<" ";
   }
  cout<<i<<"\n";
 }
 cout<<"  a b c d e f g h\n";
 return(0);
}

int Figure::city(char* p)
{
 int dx,dy;
 if((dx=pos[0]-p[0])<0)
  dx=-dx;
 if((dy=pos[1]-p[1])<0)
  dy=-dy;
 return(dx+dy);
}

/*;Figure& Figure::dodge(Figure* f)
{
 char s[2];
 char p[2];
 char q[2];
 short d;
 short dm=16;
 short i,j;
 p[0]=p[1]=q[0]=q[1]=0;
 for(i=8;i>0;i--)
 {
  s[1]='0'+i;
  for(j=0;j<8;j++)
   {
     s[0]='a'+i;
     if(*this==s)
      continue;
     if(!attack(s))
      continue;
     q[0]=s[0];
     q[1]=s[1];
     if(f->attack(s))
      continue;
     if((d=f->city(s))>dm)
      continue;
     dm=d; p[0]=s[0];p[1]=s[1];
   }
 }
*this=p[0]?p:q;
return(*this);
}*/







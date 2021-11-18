 #include<iostream>
#include"chesslib.h"
using namespace std;
int main(int argc,char* argv[])
{
 if(argc<2)
  argv[1]=(char*)"nil";
 if(Figure::deskout(argv[1]))
 {
  cout<<"Correct"<<argv[1];
  cout<<"to"<<(argv[1]=(char*)"a1")<<"Default\n";
  cout<<"Usage example: chess+ e5\n";
 }
 Queen f(argv[1]);
 do
 {
  f.danger();
  cout<<f<<'-'<<f.isa();
 } while(cin>>f);
 return(0);
}

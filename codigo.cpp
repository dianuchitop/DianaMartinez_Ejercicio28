#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(void){

  int Nx = 101;
  int Nt = 200;

  double Dx = 0.02;
  double Dt = 0.9;
  double KAPPA = 200;
  double SPH = 900;
  double RHO = 2700;

  double K = KAPPA/(SPH*RHO)*Dt/(Dx*Dx);

  int m = 1;
  //int NT = Nt/300;
  int NT = 200;

  double T[Nx][2];
  double Tpl[Nx][NT];

  for(int i=0;i<Nx;i++){
    T[i][0]=200.0;
    T[i][1]=200.0;
    for(int j=0;j<NT;j++){
      Tpl[i][j]=200.0;
    }
  }

  for(int i=1;i<Nx-1;i++){
    if(i*Dx < 1.2 && i*Dx > 0.8){
      T[i][0]=500.0;
    }
  }

  for(int t=1;t<Nt;t++){
    for(int ix=1; ix<Nx-1;ix++){
      T[ix][1] = T[ix][0] + K*(T[ix+1][0]+T[ix-1][0]-2*T[ix][0]);
    }
    if(t%1 == 0 || t == 1){
      for(int i=1;i<Nx;i++){
        Tpl[i][m]=T[i][1];
      }
      cout << m << endl;
      m = m + 1;
    }
    for(int ix=1;ix<Nx-1;ix++){
      T[ix][0]=T[ix][1];
    }
  }

  ofstream MiData("Data.dat");
  for(int ix = 0; ix < Nx; ix++){
    for(int t = 0; t < m; t++){
      //MiData << ix*Dx << "\t" << t << "\t" << Tpl[ix][t] << endl;
      MiData << Tpl[ix][t] << endl;
    }
  }

  return 0;
}



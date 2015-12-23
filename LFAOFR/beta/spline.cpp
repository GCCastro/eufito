#include "TSpline.h"
#include "TGraph.h"
#include <fstream>
#include <string>

using namespace std;

void spline()
{
  int N=28;
  ifstream P;
  P.open("P.txt");
  ofstream G;
  G.open("G.txt");

  double *x = new double[N];
  for(int i=0; i<N; i++)
  {
    string value;
    getline(P,value);
    x[i]=atof(value.c_str());
  }

  TGraph *gr = new TGraph("Fermi.txt","%lg" "%lg");
  TSpline3 *spl = new TSpline3("splinelinda",gr);

  gr->Draw();

  for(int i=0; i<N; i++)
  {
    double result = spl->Eval(x[i]);
    printf("G(%f) = %f\n",x[i],result);
    G << result << "\n";
  }

  P.close();
  G.close();
}

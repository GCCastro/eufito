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
  double *res = new double[N];
  for(int i=0; i<N; i++)
  {
    string value;
    getline(P,value);
    x[i]=atof(value.c_str());
  }

  TGraph *gr = new TGraph("Fermi.txt","%lg" "%lg");
  gr->SetMarkerStyle(3);
  gr->SetMarkerSize(1.5);
  TSpline3 *spl = new TSpline3("splinelinda",gr);


  for(int i=0; i<N; i++)
  {
    double result = spl->Eval(x[i]);
    res[i] = result;
    printf("G(%f) = %f\n",x[i],result);
    G << result << "\n";
  }

  TGraph *gr1 = new TGraph(N,x,res);
  gr1->SetMarkerStyle(5);
  gr1->Draw();
  TMultiGraph *mg = new TMultiGraph("mg","Spline cubico;P;G(Z,W)");
  mg->Add(gr);
  mg->Add(gr1);
  mg->Draw("ALP");

  P.close();
  G.close();
}

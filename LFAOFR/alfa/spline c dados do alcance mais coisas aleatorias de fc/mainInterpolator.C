#include "cFCgraphics.h"
#include "DataInterpolator.h"
#include "Vec.h"
#include "EqSolver.h"
#include "TLatex.h" //Legenda no Grafico das sobreposiçoes

using namespace std;
int main () {
  cFCgraphics gr;
  TPad *pad1=  gr.CreatePad("Pad1");
 

  //pontos
  int N=18;
  double*x=new double [18];
  double *y=new double [18];

  x[0]=0.05;
  x[1]=0.08;
  x[2]=0.128;
  x[3]=0.201;
  x[4]=0.4;
  x[5]=0.5;
  x[6]=0.64;
  x[7]=0.8;
  x[8]=1;
  x[9]=1.6;
  x[10]=2;
  x[11]=2.401;
  x[12]=2.8;
  x[13]=3.2;
  x[14]=4;
  x[15]=5;
  x[16]=6.4;
  x[17]=8;

  y[0]=0.12489;
  y[1]=0.17231;
  y[2]=0.23515;
  y[3]=0.31578;
  y[4]=0.49483;
  y[5]=0.56825;
  y[6]=0.6603;
  y[7]=0.75693;
  y[8]=0.87077;
  y[9]=1.20413;
  y[10]=1.44165;
  y[11]=1.70338;
  y[12]=1.99874;
  y[13]=2.3311;
  y[14]=3.11008;
  y[15]=4.27968;
  y[16]=6.25158;
  y[17]=8.94046;

 

  DataInterpolator A(N,x,y);

  double *k= A.CubicSplineCurvatures();
  //b
  TGraph *g=A.Draw();
  g->SetMarkerColor(kBlack);
  g->SetMarkerStyle(8);
  gr.AddObject(g,"Pad1","ap");
  //  TLatex *latex = new TLatex(g->GetX()[5], g->GetY()[3],"CubicSpline");
  // g->GetListOfFunctions()->Add(latex);
  // latex->SetTextSize(0.06);
  //latex->SetTextColor(kRed);

 TF1* r=A.CubicSpline(k);

  r->SetLineColor(kRed);
  r->SetLineWidth(2);
  gr.AddObject(r,"Pad1","same");

 

  gr.DumpPad("Pad1");
  gr.AddObject(pad1);
  

  //a (aqui para se ver ao mesmo tempo que os graficos)
 cout << "************************************************" << endl;
  cout << "Valor da Interpolaçao por Cubic Spline no ponto de Energia 5.305 MeV: "<<  r->Eval(5.305)<< " mg/cm2" << endl;

  cout << "R**-1 " << r->GetX(0.642) << endl; 

  gr.Draw();
  gr.Print("alcance.pdf");
  delete[] k;
  return 0;
}

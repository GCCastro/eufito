#include <iostream>
#include <string>
#include "TROOT.h"
#include "TH1F.h"
#include "TF1.h"
#include "cFCgraphics.h"
#include "DataInterpolator.h"
#include "Vec.h"
#include "EqSolver.h"
#include "TGraph.h"

#include "TSpline.h"
#include "TVirtualPad.h"
#include "TSystem.h"
#include "Riostream.h"
#include "TClass.h"
#include "TMath.h"

using namespace std;

int main()
{
  cFCgraphics gr;
  TPad* pad = gr.CreatePad("Pad"); 
  int N=18;
  double x[18];
  double y[18];

  x[0]=0.05;
  x[1]=0.08;
  x[2]=0.128;
  x[3]=0.201;
  x[4]=0.4;
  x[5]=0.5;
  x[6]=0.64;
  x[7]=0.8;
  x[8]=1.;
  x[9]=1.6;
  x[10]=2.0;
  x[11]=2.401;
  x[12]=2.8;
  x[13]=3.2;
  x[14]=4.;
  x[15]=5.;
  x[16]=6.4;
  x[17]=8.0;

  y[0]=0.55686;
  y[1]=0.6756;
  y[2]=0.8086;
  y[3]=0.95054;
  y[4]=1.29439;
  y[5]=1.43087;
  y[6]=1.59182;
  y[7]=1.71951;
  y[8]=1.80172;
  y[9]=1.75752;
  y[10]=1.62341;
  y[11]=1.44267;
  y[12]=1.27835;
  y[13]=1.14066;
  y[14]=0.93871;
  y[15]=0.78444;
  y[16]=0.64891;
  y[17]=0.55054;

  DataInterpolator A((int)18,x,y);

  double* k=new double[N];
  k=A.CubicSplineCurvatures();  
  /*
  //alinea a)
  double ce,pe;
  ce=A.CSEvaluate(k,57.3);
  pe=A.PEvaluate(57.3);
  cout << "Valor da interpolaçao por Cubic Spline em E=57.3 MeV: " << ce << " (mbarn)"<< endl;
  cout << "\nValor da interpolaçao por polinomio em E=57.3 MeV: " << pe << " (mbarn)\n"<< endl;
  */
  //alinea b)
  TGraph* g =A.Draw();
  g->SetMarkerStyle(7);
  //gr.AddObject(g);
  gr.AddObject(g,"Pad","ap");
  /*
  TF1* f2=A.Polynomial();
  f2->SetLineColor(kRed+2);
  f2->SetLineWidth(2);
  //gr.AddObject(f2);  
  gr.AddObject(f2,"Pad","same");
  */
  TF1* function = A.CubicSpline(k);
  function->SetLineColor(kCyan+3);
  function->SetLineWidth(2);
  //gr.AddObject(function);
  gr.AddObject(function,"Pad","same");
  
  g->SetTitle("dE/dx em funcao da energia");
  gr.DumpPad("Pad");
  gr.AddObject(pad);

  /*
  //alinea c)
  TGraph* g2= A.InterpolDif(k);
  g2->SetMarkerStyle(6);
  gr.AddObject(g2);

  //alinea d)
  TGraph* g3 =A.CubicDerivDif(k);
  g3->SetMarkerStyle(6);
  gr.AddObject(g3);

  //alinea e)
  TGraph* g4 =A.DerivNDif(k);
  g4->SetMarkerStyle(6);
  gr.AddObject(g4);
  */

  TSpline3 * CuSpl = new TSpline3("Cubic Spline", x, y, N);
  //CuSpl->Draw("SAMECP");

  gr.AddObject(CuSpl);

  gr.Draw();
  gr.Print("Graphs.pdf");


  delete [] k;

  return 0;
}

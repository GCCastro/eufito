#include "TROOT.h"
#include "TApplication.h"
#include "TFrame.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TMultiGraph.h"
#include "TCanvas.h"

#include <iostream>

using namespace std;

int main(int argc,char **argv)
{
  //faz aparecer o canvas
  TApplication theApp("App", &argc, argv);
  //theApp.InitializeGraphics();

  TCanvas *c1 = new TCanvas("c1","Nome",200,10,700,500);
  c1->SetFillColor(0);
  //c1->SetGrid();
  c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(12);


  double *x = new double[6];
  x[0]=42.538081515;
  x[1]=86.8813349815;
  x[2]=132.7894519984;
  x[3]=176.2294069193;
  x[4]=221.2611202636;
  x[5]=262.4911413267;


  double *y = new double[6];
  y[0]=0.2;
  y[1]=0.4;
  y[2]=0.6;
  y[3]=0.8;
  y[4]=1;
  y[5]=1.2;

  double *ey = new double[6];
  ey[0]=0;
  ey[1]=0;
  ey[2]=0;
  ey[3]=0;
  ey[4]=0;
  ey[5]=0;

  double *ex = new double[6];
  ex[0]=0.0134019989;
  ex[1]=0.0128314812;
  ex[2]=0.0132069372;
  ex[3]=0.0128354235;
  ex[4]=0.01311796866;
  ex[5]=0.0143358451;


  TGraphErrors *gr1 = new TGraphErrors(6,x,y,ex,ey);
  TGraphErrors *gr2 = new TGraphErrors(6,x,y,ex,ey);
  TGraphErrors *gr3 = new TGraphErrors(6,x,y,ex,ey);

  TF1 *f1 = new TF1("f1","[0]+[1]*x");
  f1->SetParameters(0.001,0.004);
  TF1 *f2 = new TF1("f2","[2]+[3]*x");
  f2->SetParameters(0.001,0.004);
  TF1 *f3 = new TF1("f3","[4]+[5]*x");
  f3->SetParameters(0.001,0.004);

  gr1->Fit("f1","MF","",0.,300.);
  gr2->Fit("f2","MF","",50.,300.);
  gr3->Fit("f3","MF","",0.,250.);

  gr1->SetLineWidth(0.1);
  gr2->SetLineWidth(0.1);
  gr3->SetLineWidth(0.1);

  f1->SetLineWidth(0.1);
  f2->SetLineWidth(0.1);
  f3->SetLineWidth(0.1);


  TMultiGraph *mg = new TMultiGraph();
  cout << gr1->GetX()[0] << " BATATA" << endl;

  mg->Add(gr1);
  mg->Add(gr2);
  mg->Add(gr3);

  mg->Draw("AP");

  theApp.Run();
  //theApp.Terminate();

  return 0;
}

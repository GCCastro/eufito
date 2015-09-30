#include "TROOT.h"
#include "TFrame.h" //gClient
#include "TCanvas.h"
#include "TPad.h"
#include "TSystem.h"
#include <TList.h>
#include "TApplication.h"
#include "TVirtualX.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include <cmath>
#include <iostream>
#include "TPaveStats.h"
#include "TStyle.h"
#include "TLegend.h"
#include <unistd.h>

#include <fstream>

using namespace std;

int main(int argc, char **argv) {
  
  cout << "Hail Eris! All hail Discordia!" << endl;

  if (argc != 3)
    {
      cout << "Faltam argumentos. Ler manual." << endl;
      return 0;
    }

  const char* paramf = argv[1];
  const char* dadosf = argv[2];

  string titulo, faju;
  ifstream det(paramf);
  if(det.is_open())
    {
      getline(det,titulo);
      getline(det,faju);

    }
  else cout << "Erro. Nao foi possivel abrir o ficheiro" << endl;

  bool eufito = true;
  //bool eufito = false;


  //faz aparecer o canvas
  TApplication theApp("App", &argc, argv);
 
  //box com resultados do fit
  gStyle->SetOptFit();
  //settings do canvas  
  TCanvas *c1 = new TCanvas("c1","Nome",200,10,700,500);
  c1->SetFillColor(0);
  c1->SetGrid();
  c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(12);

  //Definir multiplos graficos num canvas
  TMultiGraph *mg = new TMultiGraph("mg","mg");
  mg->SetTitle(titulo.c_str());
  //
 
  //grafico 1
  TGraphErrors *gr1 = new TGraphErrors(dadosf,"%lg %lg %lg %lg");
  gr1->SetName("gr1");
  gr1->SetTitle("graph 1");
  gr1->SetMarkerStyle(20);
  gr1->SetMarkerColor(kRed);

  //por L e comentar o fit e o stat do fit correspondete -> pa desenhar linha a unir pontos
  //gr1->SetDrawOption("AP");
  //Com opçao L define a cor da linha que une os pontos, e a cor das barras de erro
  gr1->SetLineColor(1);
  gr1->SetLineWidth(1);
  gr1->SetFillStyle(0);

  //funcao a fittar
  TF1 *f1 = new TF1("f1",faju.c_str());
  //  f1->SetParLimits(0,7,9);
  f1->SetLineColor(kBlue);
  if (eufito)
    {
      gr1->Fit("f1","EMF");
    }
  //   gPad->SetLogx();
  mg->Add(gr1);
  //TGraphErrors *gr2 = new TGraphErrors("dados2.txt","%lg %lg %lg %lg"); 
  //mg->Add(gr2);


  //Draws, prints e updates no canvas
  mg->Draw("AP");
  c1->Update();

  //legenda
  // posiçao legenda (x,y) -> primeiro argumento x, ultimo argumento y
  // TLegend *leg = new TLegend(1,0.8,0.7,0.9);
  //argumentos add entry 
  //  L: draw line associated with TAttLine if obj inherits from TAttLine
  // P: draw polymarker associated with TAttMarker if obj inherits from TAttMarker
  // F: draw a box with fill associated wit TAttFill if obj inherits TAttFill
  //  E: draw vertical error bar 

  
  // leg->AddEntry("gr1","X=0.06m (T3)","lep");
  // leg->Draw();



  //box com resultados do fit
  if (eufito)
    {

//box com resultados do fit
   TPaveStats *stats1 = (TPaveStats*)gr1->GetListOfFunctions()->FindObject("stats");
   //  TPaveStats *stats2 = (TPaveStats*)gr2->GetListOfFunctions()->FindObject("stats");
  stats1->SetTextColor(kBlue); 
  //   stats2->SetTextColor(kRed); 
   stats1->SetX1NDC(0.7); stats1->SetX2NDC(0.9); stats1->SetY1NDC(0.1); stats1->SetY2NDC(0.3);
   //  stats2->SetX1NDC(0.3); stats2->SetX2NDC(0.5); stats2->SetY1NDC(0.8);
 
    }

  c1->Modified();
 
  c1->Print("plot.pdf");
  getchar();
  return 0;
}

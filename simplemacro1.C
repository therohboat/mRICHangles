#include "TTree.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void simplemacro1()
{
  TFile *myfile = new TFile("Agel_output.root");
  TTreeReader myreader ("Sensor",  myfile);
  TH2D *hist = new TH2D("SensorXY","4 GeV #pi",1200,-60,60,1200,-60,60);
  TTreeReaderValue<Double_t> x(myreader,"x");
  TTreeReaderValue<Double_t> y(myreader,"y");
  while(myreader.Next())
    {
      hist->Fill(*x,*y);
    }
  TCanvas *swagtastic = new TCanvas("4Gev /pi","4GeV mRICH",700,700,700,700);
  //Sensor->Draw("x:y");
  hist->Draw();  
}

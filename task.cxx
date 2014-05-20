#include <TFile.h>
#include <TTree.h>
#include <TBrowser.h>
#include <TRandom.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TH2.h>
#include <TLorentzVector.h>
#include <TMath.h>

void LearningTrees(Char_t* name = "Pi0_mc_out_250.root")
	{
		TFile *file = new TFile(name);
		TTree *tree=(TTree*)file->Get("h1");
		
		Float_t En_bm;
		
		tree->SetBranchAddress("En_bm",	&En_bm);
		
		TH1F *En_bm_Gev = new TH1F("En_bm_GeV", "Energy of Incoming Photon Beam (GeV)", 100, 0.244, 0.256);
		TH1F *En_bm_MeV = new TH1F("En_bm_MeV", "Energy of Incoming Photon Beam (MeV)", 100, 244, 256);
		
		En_bm_GeV->GetYaxis()->SetTitle("# of Counts");
		En_bm_MeV->GetYaxis()->SetTitle("# of Counts");
		
		Int_t nentries = (Int_t)tree->GetEntries();
		for (Int_t i=0;i<nentries; i++)
			{
				tree->GetEntry(i);
				
				En_bm_GeV->Fill(En_bm);
				En_bm_MeV->Fill(En_bm*1000);
				
			}
			
		canvasEnergyBeam = new TCanvas("En_bm", "En_bm as function of GeV and MeV");
		canvasEnergyBeam->Divide(1,2);
			
		canvasEnergyBeam->cd(1); En_bm_GeV->Draw();
		canvasEnergyBeam->cd(2); En_bm_MeV->Draw();
		
		Float_t Px_l0114, Py_l0114, Pz_l0114, Pt_l0114, En_l0114;
		Float_t Px_l0201, Py_l0201, Pz_l0201, Pt_l0201, En_l0201;
		Float_t Px_l0301, Py_l0301, Pz_l0301, Pt_l0301, En_l0301;
		Float_t Px_bm, Py_bm, Pz_bm, Pt_bm;
			
		tree->SetBranchAddress("Px_l0114", &Px_l0114);
		tree->SetBranchAddress("Py_l0114", &Py_l0114);
		tree->SetBranchAddress("Pz_l0114", &Pz_l0114);
		tree->SetBranchAddress("Pt_l0114", &Pt_l0114);
		tree->SetBranchAddress("En_l0114", &En_l0114);
		
		tree->SetBranchAddress("Px_l0201", &Px_l0201);
		tree->SetBranchAddress("Py_l0201", &Py_l0201);
		tree->SetBranchAddress("Pz_l0201", &Pz_l0201);
		tree->SetBranchAddress("Pt_l0201", &Pt_l0201);
		tree->SetBranchAddress("En_l0201", &En_l0201);
		
		tree->SetBranchAddress("Px_l0301", &Px_l0301);
		tree->SetBranchAddress("Py_l0301", &Py_l0301);
		tree->SetBranchAddress("Pz_l0301", &Pz_l0301);
		tree->SetBranchAddress("Pt_l0301", &Pt_l0301);
		tree->SetBranchAddress("En_l0301", &En_l0301);
		
		tree->SetBranchAddress("Px_bm", &Px_bm);
		tree->SetBranchAddress("Py_bm", &Py_bm);
		tree->SetBranchAddress("Pz_bm", &Pz_bm);
		tree->SetBranchAddress("Pt_bm", &Pt_bm);
				
		TLorentzVector vProton;
		TLorentzVector vPhotonl0201;
		TLorentzVector vPhotonl0301;
		TLorentzVector vPion;
		TLorentzVector vBeam;	
		TLorentzVector vMissingMass;
		TLorentzVector vTagger(0,0,0,0.938);	
		
		Float_t Px1n, Py1n, Pz1n;
		Float_t Px2n, Py2n, Pz2n;
		Float_t Px3n, Py3n, Pz3n;
		
		Float_t PxBm, PyBm, PzBm;
		
		Double_t theta1, phi1;
		Double_t theta2, phi2;
		Double_t theta3, phi3;
		Double_t InMass;
		Double_t MissMass;
		
		TH1F *Theta2 = new TH1F("Theta2", "Photon l0201 - Theta", 100, 0, 180);
		TH1F *Phi2 = new TH1F("Phi2", "Photon l0201 - Phi", 100, -180, 180);
		TH1F *Theta3 = new TH1F("Theta3", "Photon l0301 - Theta", 100, 0, 180);
		TH1F *Phi3 = new TH1F("Phi3", "Photon l0301 - Phi", 100, -180, 180);
		TH1F *Mass_GeV = new TH1F("Mass_GeV", "Invarient Mass (GeV/c^2)", 100, 0, 0.25);
		TH1F *Mass_MeV = new TH1F("Mass_MeV", "Invarient Mass (MeV/c^2)", 100, 0, 250);
		TH1F *MissMass_GeV = new TH1F("MissMass_GeV", "Missing Mass (GeV/c^2)", 100, 0.900, 1.000);
		TH1F *MissMass_MeV = new TH1F("MissMass_MeV", "Missing Mass (MeV/c^2)", 100, 900, 1000);
		
		for (Int_t i=0;i<nentries; i++)
			{
				tree->GetEntry(i);
				
				Px1n=Px_l0114*Pt_l0114;
				Py1n=Py_l0114*Pt_l0114;
				Pz1n=Pz_l0114*Pt_l0114;
				
				Px2n=Px_l0201*Pt_l0201;
				Py2n=Py_l0201*Pt_l0201;
				Pz2n=Pz_l0201*Pt_l0201;
				
				Px3n=Px_l0301*Pt_l0301;
				Py3n=Py_l0301*Pt_l0301;
				Pz3n=Pz_l0301*Pt_l0301;
				
				PxBm=Px_bm*Pt_bm;
				PyBm=Py_bm*Pt_bm;
				PzBm=Pz_bm*Pt_bm;
				
				vProton.SetPxPyPzE(Px1n,Py1n,Pz1n,En_l0114);
				vPhotonl0201.SetPxPyPzE(Px2n,Py2n,Pz2n,En_l0201);
				vPhotonl0301.SetPxPyPzE(Px3n,Py3n,Pz3n,En_l0301);
				vBeam.SetPxPyPzE(PxBm,PyBm,PzBm,En_bm);
				
				Double_t theta2 = vPhotonl0201.Theta();
				Double_t phi2 = vPhotonl0201.Phi();
				Double_t theta3 = vPhotonl0301.Theta();
				Double_t phi3 = vPhotonl0301.Phi();
				
				Theta2->Fill(theta2*(180/3.14));
				Phi2->Fill(phi2*(180/3.14));
				Theta3->Fill(theta3*(180/3.14));
				Phi3->Fill(phi3*(180/3.14));
				
				vPion = vPhotonl0201+vPhotonl0301; 
				InMass = vPion.M();
				Mass_GeV->Fill(InMass);
				Mass_MeV->Fill(InMass*1000);
				
				vMissingMass = vBeam+vTagger-vPion;				
				MissMass = vMissingMass.M();
				MissMass_GeV->Fill(MissMass);
				MissMass_MeV->Fill(MissMass*1000);
				
			}
			
			Theta2->GetXaxis()->SetTitle("Angle (rads)");
			Theta2->GetYaxis()->SetTitle("# of Counts");
			Phi2->GetXaxis()->SetTitle("Angle (rads)");
			Phi2->GetYaxis()->SetTitle("# of Counts");
			Theta3->GetXaxis()->SetTitle("Angle (rads)");
			Theta3->GetYaxis()->SetTitle("# of Counts");
			Phi3->GetXaxis()->SetTitle("Angle (rads)");
			Phi3->GetYaxis()->SetTitle("# of Counts");
			
			canvas2a = new TCanvas("Photon l0201 Angles", "Photon l0201 Angles");
			canvas2a->Divide(1,2);
			
			canvas2b = new TCanvas("Photon l0301 Angles", "Photon l0301 Angles");
			canvas2b->Divide(1,2);
			
			canvas2a->cd(1); Theta2->Draw();
			canvas2a->cd(2); Phi2->Draw();
			canvas2b->cd(1); Theta3->Draw();
			canvas2b->cd(2); Phi3->Draw();
			
			Mass_GeV->GetXaxis()->SetTitle("Invarient Mass (GeV/c^2)");
			Mass_GeV->GetYaxis()->SetTitle("# of counts");
			Mass_MeV->GetXaxis()->SetTitle("Invarient Mass (MeV/c^2)");
			Mass_MeV->GetYaxis()->SetTitle("# of counts");

			canvas3 = new TCanvas("Invarient Mass", "Invarient Mass");
			canvas3->Divide(1,2);
			
			canvas3->cd(1); Mass_GeV-> Draw();
			canvas3->cd(2); Mass_MeV-> Draw();
			
			MissMass_GeV->GetXaxis()->SetTitle("Missing Mass (GeV/c^2)");
			MissMass_GeV->GetYaxis()->SetTitle("# of counts");
			MissMass_MeV->GetXaxis()->SetTitle("Missing Mass (MeV/c^2)");
			MissMass_MeV->GetYaxis()->SetTitle("# of counts");
		
			canvas4 = new TCanvas("Missing Mass", "Missing Mass");
			canvas4->Divide(1,2);
			
			canvas4->cd(1); MissMass_GeV-> Draw();
			canvas4->cd(2); MissMass_MeV-> Draw();
		
		}
		
	

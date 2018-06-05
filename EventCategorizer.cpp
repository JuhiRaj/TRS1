/**
 *  @copyright Copyright 2017 The J-PET Framework Authors. All rights reserved.
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may find a copy of the License in the LICENCE file.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *  @file EventCategorizer.cpp
 */

#include <iostream>
#include <JPetWriter/JPetWriter.h>
#include "EventCategorizer.h"

using namespace std;

EventCategorizer::EventCategorizer(const char* name): JPetUserTask(name) {}

bool EventCategorizer::init()
{

  INFO("Event categorization started.");
  INFO("Looking at two hit Events on Layer 1&2 only - creating only control histograms");

  fOutputEvents = new JPetTimeWindow("JPetEvent");

  if (fSaveControlHistos) {



		getStatistics().createHistogram( new TH1F("Hits", "Hits Distribution",
							10, 0.5, 10.5) );
		getStatistics().getHisto1D("Hits")->GetXaxis()->SetTitle("Hist Distribution");
		getStatistics().getHisto1D("Hits")->GetYaxis()->SetTitle("Counts");


		getStatistics().createHistogram( new TH1F("TOT", "TOT",
                                                        200, 0.0, 200.0) );
                getStatistics().getHisto1D("TOT")->GetXaxis()->SetTitle("TOT [ns]");
                getStatistics().getHisto1D("TOT")->GetYaxis()->SetTitle("Counts");


	
		getStatistics().createHistogram( new TH1F("TOT_first", "TOT for first Hit",
							200, 0.0, 200.0) );
		getStatistics().getHisto1D("TOT_first")->GetXaxis()->SetTitle("TOT [ns]");
		getStatistics().getHisto1D("TOT_first")->GetYaxis()->SetTitle("Counts");

		
		getStatistics().createHistogram( new TH1F("TOT_second", "TOT for second Hit",
							200, 0.0, 200.0) );
		getStatistics().getHisto1D("TOT_second")->GetXaxis()->SetTitle("TOT [ns]");
		getStatistics().getHisto1D("TOT_second")->GetYaxis()->SetTitle("Counts");
	
		
		
		getStatistics().createHistogram( new TH1F("TOT_third", "TOT for third Hit",
							200, 0.0, 200.0) );
		getStatistics().getHisto1D("TOT_third")->GetXaxis()->SetTitle("TOT [ns]");
		getStatistics().getHisto1D("TOT_third")->GetYaxis()->SetTitle("Counts");
		
		
			
		getStatistics().createHistogram( new TH1F("TOT_fourth", "TOT for fourth Hit",
							200, 0.0, 200.0) );
		getStatistics().getHisto1D("TOT_fourth")->GetXaxis()->SetTitle("TOT [ns]");
		getStatistics().getHisto1D("TOT_fourth")->GetYaxis()->SetTitle("Counts");


		getStatistics().createHistogram( new TH1F("TOT_fifth", "TOT for fifth Hit",
                                                        200, 0.0, 200.0) );
                getStatistics().getHisto1D("TOT_fifth")->GetXaxis()->SetTitle("TOT [ns]");
                getStatistics().getHisto1D("TOT_fifth")->GetYaxis()->SetTitle("Counts");





		getStatistics().createHistogram( new TH2F("ScinID_vs_TOT", "ScinID_vs_TOT",
							1100, -5.5, 105.5,
							192, 0.5, 192.5 ));
		getStatistics().getHisto2D("ScinID_vs_TOT")->GetXaxis()->SetTitle("TOT [ns]");
		getStatistics().getHisto2D("ScinID_vs_TOT")->GetYaxis()->SetTitle("Scintillator ID");
	
		getStatistics().createHistogram( new TH2F("DeltaT_vs_ScinID_big", "Time difference B-A vs scintillator ID, big range",
							192, 0.5, 192.5,
							2000, -10, 10 ) );
		getStatistics().getHisto2D("DeltaT_vs_ScinID_big")->GetXaxis()->SetTitle("Scintillator ID");
		getStatistics().getHisto2D("DeltaT_vs_ScinID_big")->GetYaxis()->SetTitle("Time difference BA [ns]");
	
			
		getStatistics().createHistogram( new TH1F("ScinID", "Scintillator ID Distribution",
							192, 0.5, 192.5) );
		getStatistics().getHisto1D("ScinID")->GetXaxis()->SetTitle("Scintillator ID");
		getStatistics().getHisto1D("ScinID")->GetYaxis()->SetTitle("Counts");
		

		getStatistics().createHistogram( new TH1F("TimeDiff", "Time Difference Distribution",
							750, -10, 10) );
		getStatistics().getHisto1D("TimeDiff")->GetXaxis()->SetTitle("Time Difference BA [ns]");
		getStatistics().getHisto1D("TimeDiff")->GetYaxis()->SetTitle("Counts");

		

		getStatistics().createHistogram( new TH1F("timeScat51", "timeScat51" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("timeScat51")->GetXaxis()->SetTitle("timeScat51 [ns]");
                getStatistics().getHisto1D("timeScat51")->GetYaxis()->SetTitle("Counts");


		getStatistics().createHistogram( new TH1F("timeScat41", "timeScat41" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("timeScat41")->GetXaxis()->SetTitle("timeScat41 [ns]");
                getStatistics().getHisto1D("timeScat41")->GetYaxis()->SetTitle("Counts");


 		getStatistics().createHistogram( new TH1F("timeScat31", "timeScat31" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("timeScat31")->GetXaxis()->SetTitle("timeScat31 [ns]");
                getStatistics().getHisto1D("timeScat31")->GetYaxis()->SetTitle("Counts");


 		getStatistics().createHistogram( new TH1F("timeScat21", "timeScat21" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("timeScat21")->GetXaxis()->SetTitle("timeScat21 [ns]");
                getStatistics().getHisto1D("timeScat21")->GetYaxis()->SetTitle("Counts");


                getStatistics().createHistogram( new TH1F("scattimeDiff51", "scattimeDiff51" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("scattimeDiff51")->GetXaxis()->SetTitle("scattimeDiff51 [ns]");
                getStatistics().getHisto1D("scattimeDiff51")->GetYaxis()->SetTitle("Counts");


		getStatistics().createHistogram( new TH1F("scattimeDiff41", "scattimeDiff41" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("scattimeDiff41")->GetXaxis()->SetTitle("scattimeDiff41 [ns]");
                getStatistics().getHisto1D("scattimeDiff41")->GetYaxis()->SetTitle("Counts");


		getStatistics().createHistogram( new TH1F("scattimeDiff31", "scattimeDiff31" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("scattimeDiff31")->GetXaxis()->SetTitle("scattimeDiff31 [ns]");
                getStatistics().getHisto1D("scattimeDiff31")->GetYaxis()->SetTitle("Counts");


		getStatistics().createHistogram( new TH1F("scattimeDiff21", "scattimeDiff21" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("scattimeDiff21")->GetXaxis()->SetTitle("scattimeDiff21 [ns]");
                getStatistics().getHisto1D("scattimeDiff21")->GetYaxis()->SetTitle("Counts");


		getStatistics().createHistogram( new TH1F("scatDist51", "scatDist51" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("scatDist51")->GetXaxis()->SetTitle("scatDist51 [ns]");
                getStatistics().getHisto1D("scatDist51")->GetYaxis()->SetTitle("Counts");


 		getStatistics().createHistogram( new TH1F("scatDist41", "scatDist41" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("scatDist41")->GetXaxis()->SetTitle("scatDist41 [ns]");
                getStatistics().getHisto1D("scatDist41")->GetYaxis()->SetTitle("Counts");


		getStatistics().createHistogram( new TH1F("scatDist31", "scatDist31" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("scatDist31")->GetXaxis()->SetTitle("scatDist31 [ns]");
                getStatistics().getHisto1D("scatDist31")->GetYaxis()->SetTitle("Counts");


 		getStatistics().createHistogram( new TH1F("scatDist21", "scatDist21" , 800, -400.5, 400.5 ));
                getStatistics().getHisto1D("scatDist21")->GetXaxis()->SetTitle("scatDist21 [ns]");
                getStatistics().getHisto1D("scatDist21")->GetYaxis()->SetTitle("Counts");



		getStatistics().createHistogram(new TH2F("Scatter_of_5_and_4_from_1","Scatter_of_5_and_4_from_1",140, -7.5, 7.5,140, -7.5, 7.5));
                getStatistics().getHisto2D("Scatter_of_5_and_4_from_1")->GetXaxis()->SetTitle("Scatter Time 5-1 [ns]");
                getStatistics().getHisto2D("Scatter_of_5_and_4_from_1")->GetYaxis()->SetTitle("Scatter Time 4-1 [ns]");


		getStatistics().createHistogram(new TH2F("Scatter_of_3_and_2_from_1","Scatter_of_3_and_2_from_1",140, -7.5, 7.5,140, -7.5, 7.5));
                getStatistics().getHisto2D("Scatter_of_3_and_2_from_1")->GetXaxis()->SetTitle("Scatter Time 3-1 [ns]");
                getStatistics().getHisto2D("Scatter_of_3_and_2_from_1")->GetYaxis()->SetTitle("Scatter Time 2-1 [ns]");



		getStatistics().createHistogram(new TH2F("TimeScat51_vs_ScinID_Diff51","TimeScat51_vs_ScinID_Diff51",800, -400.5, 400.5,384, -192.5, 192.5));
                getStatistics().getHisto2D("TimeScat51_vs_ScinID_Diff51")->GetXaxis()->SetTitle("Scatter Time 5-1 [ns]");
                getStatistics().getHisto2D("TimeScat51_vs_ScinID_Diff51")->GetYaxis()->SetTitle("Scintillator ID Difference  5-1");


		getStatistics().createHistogram(new TH2F("TimeScat41_vs_ScinID_Diff41","TimeScat41_vs_ScinID_Diff41",800, -400.5, 400.5,384, -192.5, 192.5));
                getStatistics().getHisto2D("TimeScat41_vs_ScinID_Diff41")->GetXaxis()->SetTitle("Scatter Time 4-1 [ns]");
                getStatistics().getHisto2D("TimeScat51_vs_ScinID_Diff51")->GetYaxis()->SetTitle("Scintillator ID Difference  4-1");


		getStatistics().createHistogram(new TH2F("TimeScat31_vs_ScinID_Diff31","TimeScat31_vs_ScinID_Diff31",800, -400.5, 400.5,384, -192.5, 192.5));
                getStatistics().getHisto2D("TimeScat31_vs_ScinID_Diff31")->GetXaxis()->SetTitle("Scatter Time 3-1 [ns]");
                getStatistics().getHisto2D("TimeScat31_vs_ScinID_Diff31")->GetYaxis()->SetTitle("Scintillator ID Difference  3-1");


		getStatistics().createHistogram(new TH2F("TimeScat21_vs_ScinID_Diff21","TimeScat21_vs_ScinID_Diff21",800, -400.5, 400.5,384, -192.5, 192.5));
                getStatistics().getHisto2D("TimeScat21_vs_ScinID_Diff21")->GetXaxis()->SetTitle("Scatter Time 2-1 [ns]");
                getStatistics().getHisto2D("TimeScat21_vs_ScinID_Diff21")->GetYaxis()->SetTitle("Scintillator ID Difference  2-1");




    
                getStatistics().createHistogram(new TH2F("TimeScat21_vs_ScinID_2","TimeScat21_vs_ScinID_2",800, -400.5, 400.5,192, -0.5, 192.5));
                getStatistics().getHisto2D("TimeScat21_vs_ScinID_2")->GetXaxis()->SetTitle("Scatter Time 2-1 [ns]");
                getStatistics().getHisto2D("TimeScat21_vs_ScinID_2")->GetYaxis()->SetTitle("Scintillator ID   2");


		getStatistics().createHistogram(new TH2F("TimeScat21_vs_ScinID_1","TimeScat21_vs_ScinID_1",800, -400.5, 400.5,192, -0.5, 192.5));
                getStatistics().getHisto2D("TimeScat21_vs_ScinID_1")->GetXaxis()->SetTitle("Scatter Time 2-1 [ns]");
                getStatistics().getHisto2D("TimeScat21_vs_ScinID_1")->GetYaxis()->SetTitle("Scintillator ID  1");


		getStatistics().createHistogram(new TH2F("TimeScat31_vs_ScinID_3","TimeScat31_vs_ScinID_3",800, -400.5, 400.5,192, -0.5, 192.5));
                getStatistics().getHisto2D("TimeScat31_vs_ScinID_3")->GetXaxis()->SetTitle("Scatter Time 3-1 [ns]");
                getStatistics().getHisto2D("TimeScat31_vs_ScinID_3")->GetYaxis()->SetTitle("Scintillator ID  3");


		getStatistics().createHistogram(new TH2F("TimeScat31_vs_ScinID_1","TimeScat31_vs_ScinID_1",800, -400.5, 400.5,192, -0.5, 192.5));
                getStatistics().getHisto2D("TimeScat31_vs_ScinID_1")->GetXaxis()->SetTitle("Scatter Time 3-1 [ns]");
                getStatistics().getHisto2D("TimeScat31_vs_ScinID_1")->GetYaxis()->SetTitle("Scintillator ID  1");



		getStatistics().createHistogram(new TH2F("TimeScat41_vs_ScinID_4","TimeScat41_vs_ScinID_4",800, -400.5, 400.5,192, -0.5, 192.5));
                getStatistics().getHisto2D("TimeScat41_vs_ScinID_4")->GetXaxis()->SetTitle("Scatter Time 4-1 [ns]");
                getStatistics().getHisto2D("TimeScat41_vs_ScinID_4")->GetYaxis()->SetTitle("Scintillator ID  4");



                getStatistics().createHistogram(new TH2F("TimeScat41_vs_ScinID_1","TimeScat41_vs_ScinID_1",800, -400.5, 400.5,192, -0.5, 192.5));
                getStatistics().getHisto2D("TimeScat41_vs_ScinID_1")->GetXaxis()->SetTitle("Scatter Time 4-1 [ns]");
                getStatistics().getHisto2D("TimeScat41_vs_ScinID_1")->GetYaxis()->SetTitle("Scintillator ID  1");


		getStatistics().createHistogram(new TH2F("TimeScat51_vs_ScinID_5","TimeScat51_vs_ScinID_5",800, -400.5, 400.5,192, -0.5, 192.5));
                getStatistics().getHisto2D("TimeScat51_vs_ScinID_5")->GetXaxis()->SetTitle("Scatter Time 5-1 [ns]");
                getStatistics().getHisto2D("TimeScat51_vs_ScinID_5")->GetYaxis()->SetTitle("Scintillator ID  5");



		getStatistics().createHistogram(new TH2F("TimeScat51_vs_ScinID_1","TimeScat51_vs_ScinID_1",400, -200.5, 200.5,192, -0.5, 192.5));
                getStatistics().getHisto2D("TimeScat51_vs_ScinID_1")->GetXaxis()->SetTitle("Scatter Time 5-1 [ns]");
                getStatistics().getHisto2D("TimeScat51_vs_ScinID_1")->GetYaxis()->SetTitle("Scintillator ID  1");


		getStatistics().createHistogram(new TH2F("DeltaID15_vs_Theta","DeltaID15_vs_Theta",384, -192.5, 192.5, 360, -0.5, 360.5));
                getStatistics().getHisto2D("DeltaID15_vs_Theta")->GetXaxis()->SetTitle("DeltaID15");
                getStatistics().getHisto2D("DeltaID15_vs_Theta")->GetYaxis()->SetTitle("Theta");


		getStatistics().createHistogram(new TH2F("DeltaID14_vs_Theta","DeltaID14_vs_Theta",384, -192.5, 192.5, 360, -0.5, 360.5));
                getStatistics().getHisto2D("DeltaID14_vs_Theta")->GetXaxis()->SetTitle("DeltaID14");
                getStatistics().getHisto2D("DeltaID14_vs_Theta")->GetYaxis()->SetTitle("Theta");


		getStatistics().createHistogram(new TH2F("DeltaID13_vs_Theta","DeltaID13_vs_Theta",384, -192.5, 192.5, 360, -0.5, 360.5));
                getStatistics().getHisto2D("DeltaID13_vs_Theta")->GetXaxis()->SetTitle("DeltaID13");
                getStatistics().getHisto2D("DeltaID13_vs_Theta")->GetYaxis()->SetTitle("Theta");


		getStatistics().createHistogram(new TH2F("DeltaID12_vs_Theta","DeltaID12_vs_Theta",384, -192.5, 192.5, 360, -0.5, 360.5));
                getStatistics().getHisto2D("DeltaID12_vs_Theta")->GetXaxis()->SetTitle("DeltaID12");
                getStatistics().getHisto2D("DeltaID12_vs_Theta")->GetYaxis()->SetTitle("Theta");



		 //TOT for less than 30 ns Time Diff (1 & 5)




                getStatistics().createHistogram(new TH2F("TOT_ID_30_first","TOT_ID_30_first",200, -0.5, 200.5, 192, -0.5, 192.5));
                getStatistics().getHisto2D("TOT_ID_30_first")->GetXaxis()->SetTitle("TOT_first [ns]");
                getStatistics().getHisto2D("TOT_ID_30_first")->GetYaxis()->SetTitle("ID");


                getStatistics().createHistogram(new TH1F("TOT_30_first","TOT_30_first",200, -0.5, 200.5));
                getStatistics().getHisto1D("TOT_30_first")->GetXaxis()->SetTitle("TOT_first [ns]");
                getStatistics().getHisto1D("TOT_30_first")->GetYaxis()->SetTitle("Counts");




                getStatistics().createHistogram(new TH2F("TOT_ID_30_fifth","TOT_ID_30_fifth",200, -0.5, 200.5, 192, -0.5, 192.5));
                getStatistics().getHisto2D("TOT_ID_30_fifth")->GetXaxis()->SetTitle("TOT_fifth [ns]");
                getStatistics().getHisto2D("TOT_ID_30_fifth")->GetYaxis()->SetTitle("ID");


                getStatistics().createHistogram(new TH1F("TOT_30_fifth","TOT_30_fifth",200, -0.5, 200.5));
                getStatistics().getHisto1D("TOT_30_fifth")->GetXaxis()->SetTitle("TOT_fifth [ns]");
                getStatistics().getHisto1D("TOT_30_fifth")->GetYaxis()->SetTitle("Counts");




		//TOT for 30 to 40 ns Time Diff (1 & 5)




		getStatistics().createHistogram(new TH2F("TOT_ID_30_to_40_first","TOT_ID_30_to_40_first",200, -0.5, 200.5, 192, -0.5, 192.5));
                getStatistics().getHisto2D("TOT_ID_30_to_40_first")->GetXaxis()->SetTitle("TOT_first [ns]");
                getStatistics().getHisto2D("TOT_ID_30_to_40_first")->GetYaxis()->SetTitle("ID");


		getStatistics().createHistogram(new TH1F("TOT_30_to_40_first","TOT_30_to_40_first",200, -0.5, 200.5));
                getStatistics().getHisto1D("TOT_30_to_40_first")->GetXaxis()->SetTitle("TOT_first [ns]");
                getStatistics().getHisto1D("TOT_30_to_40_first")->GetYaxis()->SetTitle("Counts");




                getStatistics().createHistogram(new TH2F("TOT_ID_30_to_40_fifth","TOT_ID_30_to_40_fifth",200, -0.5, 200.5, 192, -0.5, 192.5));
                getStatistics().getHisto2D("TOT_ID_30_to_40_fifth")->GetXaxis()->SetTitle("TOT_fifth [ns]");
                getStatistics().getHisto2D("TOT_ID_30_to_40_fifth")->GetYaxis()->SetTitle("ID");


                getStatistics().createHistogram(new TH1F("TOT_30_to_40_fifth","TOT_30_to_40_fifth",200, -0.5, 200.5));
                getStatistics().getHisto1D("TOT_30_to_40_fifth")->GetXaxis()->SetTitle("TOT_fifth [ns]");
                getStatistics().getHisto1D("TOT_30_to_40_fifth")->GetYaxis()->SetTitle("Counts");







		 //TOT for 40 to 120 ns Time Diff (1 & 5)




                getStatistics().createHistogram(new TH2F("TOT_ID_40_to_120_first","TOT_ID_40_to_120_first",200, -0.5, 200.5, 192, -0.5, 192.5));
                getStatistics().getHisto2D("TOT_ID_40_to_120_first")->GetXaxis()->SetTitle("TOT_first [ns]");
                getStatistics().getHisto2D("TOT_ID_40_to_120_first")->GetYaxis()->SetTitle("ID");


                getStatistics().createHistogram(new TH1F("TOT_40_to_120_first","TOT_40_to_120_first",200, -0.5, 200.5));
                getStatistics().getHisto1D("TOT_40_to_120_first")->GetXaxis()->SetTitle("TOT_first [ns]");
                getStatistics().getHisto1D("TOT_40_to_120_first")->GetYaxis()->SetTitle("Counts");




                getStatistics().createHistogram(new TH2F("TOT_ID_40_to_120_fifth","TOT_ID_40_to_120_fifth",200, -0.5, 200.5, 192, -0.5, 192.5));
                getStatistics().getHisto2D("TOT_ID_40_to_120_fifth")->GetXaxis()->SetTitle("TOT_fifth [ns]");
                getStatistics().getHisto2D("TOT_ID_40_to_120_fifth")->GetYaxis()->SetTitle("ID");


                getStatistics().createHistogram(new TH1F("TOT_40_to_120_fifth","TOT_40_to_120_fifth",200, -0.5, 200.5));
                getStatistics().getHisto1D("TOT_40_to_120_fifth")->GetXaxis()->SetTitle("TOT_fifth [ns]");
                getStatistics().getHisto1D("TOT_40_to_120_fifth")->GetYaxis()->SetTitle("Counts");









		//TOT for 120 to 150 ns Time Diff (1 & 5)




                getStatistics().createHistogram(new TH2F("TOT_ID_120_to_150_first","TOT_ID_120_to_150_first",200, -0.5, 200.5, 192, -0.5, 192.5));
                getStatistics().getHisto2D("TOT_ID_120_to_150_first")->GetXaxis()->SetTitle("TOT_first [ns]");
                getStatistics().getHisto2D("TOT_ID_120_to_150_first")->GetYaxis()->SetTitle("ID");


                getStatistics().createHistogram(new TH1F("TOT_120_to_150_first","TOT_120_to_150_first",200, -0.5, 200.5));
                getStatistics().getHisto1D("TOT_120_to_150_first")->GetXaxis()->SetTitle("TOT_first [ns]");
                getStatistics().getHisto1D("TOT_120_to_150_first")->GetYaxis()->SetTitle("Counts");




                getStatistics().createHistogram(new TH2F("TOT_ID_120_to_150_fifth","TOT_ID_120_to_150_fifth",200, -0.5, 200.5, 192, -0.5, 192.5));
                getStatistics().getHisto2D("TOT_ID_120_to_150_fifth")->GetXaxis()->SetTitle("TOT_fifth [ns]");
                getStatistics().getHisto2D("TOT_ID_120_to_150_fifth")->GetYaxis()->SetTitle("ID");


                getStatistics().createHistogram(new TH1F("TOT_120_to_150_fifth","TOT_120_to_150_fifth",200, -0.5, 200.5));
                getStatistics().getHisto1D("TOT_120_to_150_fifth")->GetXaxis()->SetTitle("TOT_fifth [ns]");
                getStatistics().getHisto1D("TOT_120_to_150_fifth")->GetYaxis()->SetTitle("Counts");












		getStatistics().createHistogram(new TH2F("DeltaID15_vs_TOT1","DeltaID15_vs_TOT1",192, -0.5, 192.5, 200, -0.5, 200.5));
                getStatistics().getHisto2D("DeltaID15_vs_TOT1")->GetXaxis()->SetTitle("DeltaID15");
                getStatistics().getHisto2D("DeltaID15_vs_TOT1")->GetYaxis()->SetTitle("TOT1");


		getStatistics().createHistogram(new TH2F("DeltaID14_vs_TOT1","DeltaID14_vs_TOT1",192, -0.5, 192.5, 200, -0.5, 200.5));
                getStatistics().getHisto2D("DeltaID14_vs_TOT1")->GetXaxis()->SetTitle("DeltaID14");
                getStatistics().getHisto2D("DeltaID14_vs_TOT1")->GetYaxis()->SetTitle("TOT1");


		getStatistics().createHistogram(new TH2F("DeltaID13_vs_TOT1","DeltaID13_vs_TOT1",192, -0.5, 192.5, 200, -0.5, 200.5));
                getStatistics().getHisto2D("DeltaID13_vs_TOT1")->GetXaxis()->SetTitle("DeltaID13");
                getStatistics().getHisto2D("DeltaID13_vs_TOT1")->GetYaxis()->SetTitle("TOT1");


		getStatistics().createHistogram(new TH2F("DeltaID12_vs_TOT1","DeltaID12_vs_TOT1",192, -0.5, 192.5, 200, -0.5, 200.5));
                getStatistics().getHisto2D("DeltaID12_vs_TOT1")->GetXaxis()->SetTitle("DeltaID12");
                getStatistics().getHisto2D("DeltaID12_vs_TOT1")->GetYaxis()->SetTitle("TOT1");



		getStatistics().createHistogram(new TH2F("DeltaID15_vs_TOT1+TOT5","DeltaID15_vs_TOT1+TOT5",192, -0.5, 192.5, 200, -0.5, 200.5));
                getStatistics().getHisto2D("DeltaID15_vs_TOT1+TOT5")->GetXaxis()->SetTitle("DeltaID15");
                getStatistics().getHisto2D("DeltaID15_vs_TOT1+TOT5")->GetYaxis()->SetTitle("TOT1+TOT5");


                getStatistics().createHistogram(new TH2F("DeltaID14_vs_TOT1+TOT5","DeltaID14_vs_TOT1+TOT5",192, -0.5, 192.5, 200, -0.5, 200.5));
                getStatistics().getHisto2D("DeltaID14_vs_TOT1+TOT5")->GetXaxis()->SetTitle("DeltaID14");
                getStatistics().getHisto2D("DeltaID14_vs_TOT1+TOT5")->GetYaxis()->SetTitle("TOT1+TOT5");


                getStatistics().createHistogram(new TH2F("DeltaID13_vs_TOT1+TOT5","DeltaID13_vs_TOT1+TOT5",192, -0.5, 192.5, 200, -0.5, 200.5));
                getStatistics().getHisto2D("DeltaID13_vs_TOT1+TOT5")->GetXaxis()->SetTitle("DeltaID13");
                getStatistics().getHisto2D("DeltaID13_vs_TOT1+TOT5")->GetYaxis()->SetTitle("TOT1+TOT5");


                getStatistics().createHistogram(new TH2F("DeltaID12_vs_TOT1+TOT5","DeltaID12_vs_TOT1+TOT5",192, -0.5, 192.5, 200, -0.5, 200.5));
                getStatistics().getHisto2D("DeltaID12_vs_TOT1+TOT5")->GetXaxis()->SetTitle("DeltaID12");
                getStatistics().getHisto2D("DeltaID12_vs_TOT1+TOT5")->GetYaxis()->SetTitle("TOT1+TOT5");



               //TOT_A_1 for PMT_A_1  && TOT_B_1 for PMT_B_1 


                getStatistics().createHistogram(new TH2F("TOT_A_1_PMT_A_1_first","TOT_A_1_PMT_A_1_first",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_A_1_PMT_A_1_first")->GetXaxis()->SetTitle("TOT_A_1");
                getStatistics().getHisto2D("TOT_A_1_PMT_A_1_first")->GetYaxis()->SetTitle("PMT_A_1");



                getStatistics().createHistogram(new TH2F("TOT_B_1_PMT_B_1_first","TOT_B_1_PMT_B_1_first",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_B_1_PMT_B_1_first")->GetXaxis()->SetTitle("TOT_B_1");
                getStatistics().getHisto2D("TOT_B_1_PMT_B_1_first")->GetYaxis()->SetTitle("PMT_B_1");





		getStatistics().createHistogram(new TH2F("TOT_A_1_PMT_A_1_fifth","TOT_A_1_PMT_A_1_fifth",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_A_1_PMT_A_1_fifth")->GetXaxis()->SetTitle("TOT_A_1");
                getStatistics().getHisto2D("TOT_A_1_PMT_A_1_fifth")->GetYaxis()->SetTitle("PMT_A_1");



                getStatistics().createHistogram(new TH2F("TOT_B_1_PMT_B_1_fifth","TOT_B_1_PMT_B_1_fifth",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_B_1_PMT_B_1_fifth")->GetXaxis()->SetTitle("TOT_B_1");
                getStatistics().getHisto2D("TOT_B_1_PMT_B_1_fifth")->GetYaxis()->SetTitle("PMT_B_1");


               //TOT_A_2 for PMT_A_2  && TOT_B_2 for PMT_B_2 

	

		getStatistics().createHistogram(new TH2F("TOT_A_2_PMT_A_2_first","TOT_A_2_PMT_A_2_first",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_A_2_PMT_A_2_first")->GetXaxis()->SetTitle("TOT_A_2");
                getStatistics().getHisto2D("TOT_A_2_PMT_A_2_first")->GetYaxis()->SetTitle("PMT_A_2");



                getStatistics().createHistogram(new TH2F("TOT_B_2_PMT_B_2_first","TOT_B_2_PMT_B_2_first",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_B_2_PMT_B_2_first")->GetXaxis()->SetTitle("TOT_B_2");
                getStatistics().getHisto2D("TOT_B_2_PMT_B_2_first")->GetYaxis()->SetTitle("PMT_B_2");





                getStatistics().createHistogram(new TH2F("TOT_A_2_PMT_A_2_fifth","TOT_A_2_PMT_A_2_fifth",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_A_2_PMT_A_2_fifth")->GetXaxis()->SetTitle("TOT_A_2");
                getStatistics().getHisto2D("TOT_A_2_PMT_A_2_fifth")->GetYaxis()->SetTitle("PMT_A_2");



                getStatistics().createHistogram(new TH2F("TOT_B_2_PMT_B_2_fifth","TOT_B_2_PMT_B_2_fifth",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_B_2_PMT_B_2_fifth")->GetXaxis()->SetTitle("TOT_B_2");
                getStatistics().getHisto2D("TOT_B_2_PMT_B_2_fifth")->GetYaxis()->SetTitle("PMT_B_2");








	       //TOT_A_3 for PMT_A_3  && TOT_B_3 for PMT_B_3 



                getStatistics().createHistogram(new TH2F("TOT_A_3_PMT_A_3_first","TOT_A_3_PMT_A_3_first",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_A_3_PMT_A_3_first")->GetXaxis()->SetTitle("TOT_A_3");
                getStatistics().getHisto2D("TOT_A_3_PMT_A_3_first")->GetYaxis()->SetTitle("PMT_A_3");



                getStatistics().createHistogram(new TH2F("TOT_B_3_PMT_B_3_first","TOT_B_3_PMT_B_3_first",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_B_3_PMT_B_3_first")->GetXaxis()->SetTitle("TOT_B_3");
                getStatistics().getHisto2D("TOT_B_3_PMT_B_3_first")->GetYaxis()->SetTitle("PMT_B_3");





                getStatistics().createHistogram(new TH2F("TOT_A_3_PMT_A_3_fifth","TOT_A_3_PMT_A_3_fifth",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_A_3_PMT_A_3_fifth")->GetXaxis()->SetTitle("TOT_A_3");
                getStatistics().getHisto2D("TOT_A_3_PMT_A_3_fifth")->GetYaxis()->SetTitle("PMT_A_3");



                getStatistics().createHistogram(new TH2F("TOT_B_3_PMT_B_3_fifth","TOT_B_3_PMT_B_3_fifth",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_B_3_PMT_B_3_fifth")->GetXaxis()->SetTitle("TOT_B_3");
                getStatistics().getHisto2D("TOT_B_3_PMT_B_3_fifth")->GetYaxis()->SetTitle("PMT_B_3");





		//TOT_A_4 for PMT_A_4  && TOT_B_4 for PMT_B_4 



                getStatistics().createHistogram(new TH2F("TOT_A_4_PMT_A_4_first","TOT_A_4_PMT_A_4_first",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_A_4_PMT_A_4_first")->GetXaxis()->SetTitle("TOT_A_4");
                getStatistics().getHisto2D("TOT_A_4_PMT_A_4_first")->GetYaxis()->SetTitle("PMT_A_4");



                getStatistics().createHistogram(new TH2F("TOT_B_4_PMT_B_4_first","TOT_B_4_PMT_B_4_first",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_B_4_PMT_B_4_first")->GetXaxis()->SetTitle("TOT_B_4");
                getStatistics().getHisto2D("TOT_B_4_PMT_B_4_first")->GetYaxis()->SetTitle("PMT_B_4");





                getStatistics().createHistogram(new TH2F("TOT_A_4_PMT_A_4_fifth","TOT_A_4_PMT_A_4_fifth",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_A_4_PMT_A_4_fifth")->GetXaxis()->SetTitle("TOT_A_4");
                getStatistics().getHisto2D("TOT_A_4_PMT_A_4_fifth")->GetYaxis()->SetTitle("PMT_A_4");



                getStatistics().createHistogram(new TH2F("TOT_B_4_PMT_B_4_fifth","TOT_B_4_PMT_B_4_fifth",200, -0.5, 200.5, 384, 0.5, 384.5));
                getStatistics().getHisto2D("TOT_B_4_PMT_B_4_fifth")->GetXaxis()->SetTitle("TOT_B_4");
                getStatistics().getHisto2D("TOT_B_4_PMT_B_4_fifth")->GetYaxis()->SetTitle("PMT_B_4");




		getStatistics().createHistogram(new TH2F("Y_vs_X_first","Y_vs_X_first",300, -150.5, 150.5, 300, -150.5, 150.5));
                getStatistics().getHisto2D("Y_vs_X_first")->GetXaxis()->SetTitle("Y_first");
                getStatistics().getHisto2D("Y_vs_X_first")->GetYaxis()->SetTitle("X_first");



                getStatistics().createHistogram(new TH2F("Y_vs_X_fifth","Y_vs_X_fifth",300, -150.5, 150.5, 300, -150.5, 150.5));
                getStatistics().getHisto2D("Y_vs_X_fifth")->GetXaxis()->SetTitle("Y_fifth");
                getStatistics().getHisto2D("Y_vs_X_fifth")->GetYaxis()->SetTitle("X_fifth");





  }


		
  return true;
}



double CalcTOT( JPetHit& Hit)
{
	

	double TOT = 0.;
	double TOT_A = 0.; 		
	double TOT_B = 0.;

	auto lead_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
	auto trail_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);
	auto lead_times_B =  Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
        auto trail_times_B = Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);


	for(auto & thr_time_pair : lead_times_A){
		int thr = thr_time_pair.first;
	  if(trail_times_A.count(thr) > 0 ){
	   TOT_A = TOT_A + trail_times_A[thr] - lead_times_A[thr];
	  }
	}
	
	for(auto & thr_time_pair : lead_times_B){
          int thr = thr_time_pair.first;
	  if( trail_times_B.count(thr) > 0 ){

	    TOT_B = TOT_B + trail_times_B[thr] - lead_times_B[thr];
          }
      	}
	 TOT = (TOT_A + TOT_B)/1000.;

	return TOT;

}


double CalcTOF(JPetHit Hit){

	double Dist = sqrt( pow(Hit.getPosX(),2) + pow(Hit.getPosY(),2) + pow(Hit.getPosZ(),2) );

	double CalTime = Dist/29.979246;    //Velocity of Light in cm/s, returns time in ns

	double HitTime = Hit.getTime()/1000.0 ;

	double TOF =  (HitTime - CalTime);

return TOF;
}




double CalcTOT_A_1(JPetHit& Hit)
{


        double TOT_A_1 = 0.;

        auto lead_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
        auto trail_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);



         TOT_A_1 = trail_times_A[1] - lead_times_A[1];
         TOT_A_1 = TOT_A_1/1000.;
         return TOT_A_1;

}





double CalcTOT_B_1(JPetHit& Hit)
{


        double TOT_B_1 = 0.;

        auto lead_times_B = Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
        auto trail_times_B = Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);



         TOT_B_1 = trail_times_B[1] - lead_times_B[1];
         TOT_B_1 = TOT_B_1/1000.;
         return TOT_B_1;

}







double CalcTOT_A_2(JPetHit& Hit)
{


        double TOT_A_2 = 0.;

        auto lead_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
        auto trail_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);



         TOT_A_2 = trail_times_A[2] - lead_times_A[2];
         TOT_A_2 = TOT_A_2/1000.;
         return TOT_A_2;

}





double CalcTOT_B_2(JPetHit& Hit)
{


        double TOT_B_2 = 0.;

        auto lead_times_B = Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
        auto trail_times_B = Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);



         TOT_B_2 = trail_times_B[2] - lead_times_B[2];
         TOT_B_2 = TOT_B_2/1000.;
         return TOT_B_2;

}









double CalcTOT_A_3(JPetHit& Hit)
{


        double TOT_A_3 = 0.;

        auto lead_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
        auto trail_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);



         TOT_A_3 = trail_times_A[3] - lead_times_A[3];
         TOT_A_3 = TOT_A_3/1000.;
         return TOT_A_3;

}





double CalcTOT_B_3(JPetHit& Hit)
{


        double TOT_B_3 = 0.;

        auto lead_times_B = Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
        auto trail_times_B = Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);



         TOT_B_3 = trail_times_B[3] - lead_times_B[3];
         TOT_B_3 = TOT_B_3/1000.;
         return TOT_B_3;

}












double CalcTOT_A_4(JPetHit& Hit)
{


        double TOT_A_4 = 0.;

        auto lead_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
        auto trail_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);

    
    
         TOT_A_4 = trail_times_A[4] - lead_times_A[4];
         TOT_A_4 = TOT_A_4/1000.;
         return TOT_A_4;

}





double CalcTOT_B_4(JPetHit& Hit)
{


        double TOT_B_4 = 0.;

        auto lead_times_B = Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
        auto trail_times_B = Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);



         TOT_B_4 = trail_times_B[4] - lead_times_B[4];
         TOT_B_4 = TOT_B_4/1000.;
         return TOT_B_4;

}















bool EventCategorizer::exec()
{

  if (auto timeWindow = dynamic_cast<const JPetTimeWindow* const>(fEvent)) {
    uint n = timeWindow->getNumberOfEvents();
    for (uint i = 0; i < n; ++i) {

      const auto& event = dynamic_cast<const JPetEvent&>(timeWindow->operator[](i));




	  std::ofstream file("trial.txt",std::ios::app);

	




   double restmass = 2*(0.5109989461);
	double pi = 3.14159 ;
	if(event.getHits().size() == 5) {

	getStatistics().getHisto1D("Hits")->Fill(event.getHits().size());

			JPetHit firstHit =event.getHits().at(0);
			JPetHit secondHit =event.getHits().at(1);
			JPetHit thirdHit = event.getHits().at(2);
			JPetHit fourthHit = event.getHits().at(3);
			JPetHit fifthHit = event.getHits().at(4);

	if(fabs(firstHit.getPosZ())<= 23.0 && fabs(secondHit.getPosZ())<= 23.0 && fabs(thirdHit.getPosZ())<= 23.0 && fabs(fourthHit.getPosZ())<= 23.0 && fabs(fifthHit.getPosZ())<= 23.0)  
	{




	 auto scinID_first = firstHit.getScintillator().getID(); 
	 auto scinID_second = secondHit.getScintillator().getID(); 
	 auto scinID_third = thirdHit.getScintillator().getID();   
	 auto scinID_fourth = fourthHit.getScintillator().getID();   
	 auto scinID_fifth = fifthHit.getScintillator().getID();





	

  		file<<scinID_first<<"	"<<scinID_second<<"	"<<scinID_third<<"	"<<scinID_fourth<<"	"<<scinID_fifth<<endl;






//TOT first Hit//

	double fTOT = CalcTOT( firstHit );
	getStatistics().getHisto1D("TOT_first")->Fill(fTOT);
        getStatistics().getHisto1D("TOT")->Fill(fTOT);

	      		//Control Spectras for first Hit
              auto timeDifference_first = firstHit.getTimeDiff()/1000.0;
	      getStatistics().getHisto2D("ScinID_vs_TOT")->Fill(fTOT,scinID_first);
              getStatistics().getHisto2D("DeltaT_vs_ScinID_big")->Fill(scinID_first, timeDifference_first);
	      getStatistics().getHisto1D("ScinID")->Fill(scinID_first);
	      getStatistics().getHisto1D("TimeDiff")->Fill(timeDifference_first);
			

//TOT second Hit//

	double sTOT = CalcTOT( secondHit );	
	getStatistics().getHisto1D("TOT_second")->Fill(sTOT);
        getStatistics().getHisto1D("TOT")->Fill(sTOT);

	      		//Control Spectras for second Hit
              auto timeDifference_second = secondHit.getTimeDiff()/1000.0;      
              getStatistics().getHisto2D("ScinID_vs_TOT")->Fill(sTOT,scinID_second);
              getStatistics().getHisto2D("DeltaT_vs_ScinID_big")->Fill(scinID_second, timeDifference_second);
	      getStatistics().getHisto1D("ScinID")->Fill(scinID_second);
	      getStatistics().getHisto1D("TimeDiff")->Fill(timeDifference_second);
							


						
//TOT third Hit//

	double tTOT = CalcTOT( thirdHit );
	getStatistics().getHisto1D("TOT_third")->Fill(tTOT);
        getStatistics().getHisto1D("TOT")->Fill(tTOT);

	      		//Control Spectras for third Hit
              auto timeDifference_third = thirdHit.getTimeDiff()/1000.0;
              getStatistics().getHisto2D("ScinID_vs_TOT")->Fill(tTOT,scinID_third);
              getStatistics().getHisto2D("DeltaT_vs_ScinID_big")->Fill(scinID_third, timeDifference_third);
	      getStatistics().getHisto1D("ScinID")->Fill(scinID_third);
	      getStatistics().getHisto1D("TimeDiff")->Fill(timeDifference_third);
			


//TOT fourth Hit//

	double foTOT = CalcTOT( fourthHit );
	getStatistics().getHisto1D("TOT_fourth")->Fill(foTOT);
	getStatistics().getHisto1D("TOT")->Fill(foTOT);

	      		//Control Spectras for fourth Hit
              auto timeDifference_fourth = fourthHit.getTimeDiff()/1000.0;
              getStatistics().getHisto2D("ScinID_vs_TOT")->Fill(foTOT,scinID_fourth);
              getStatistics().getHisto2D("DeltaT_vs_ScinID_big")->Fill(scinID_fourth, timeDifference_fourth);
	      getStatistics().getHisto1D("ScinID")->Fill(scinID_fourth);
	      getStatistics().getHisto1D("TimeDiff")->Fill(timeDifference_fourth);



//TOT fifth Hit//

        double fiTOT = CalcTOT( fifthHit );
        getStatistics().getHisto1D("TOT_fifth")->Fill(fiTOT);
        getStatistics().getHisto1D("TOT")->Fill(fiTOT);

                      //Control Spectras for fourth Hit
              auto timeDifference_fifth = fifthHit.getTimeDiff()/1000.0;
              getStatistics().getHisto2D("ScinID_vs_TOT")->Fill(fiTOT,scinID_fifth);
              getStatistics().getHisto2D("DeltaT_vs_ScinID_big")->Fill(scinID_fifth, timeDifference_fifth);
              getStatistics().getHisto1D("ScinID")->Fill(scinID_fifth);
              getStatistics().getHisto1D("TimeDiff")->Fill(timeDifference_fifth);



//Scatter Test//

	double firstHitTime = firstHit.getTime()/1000.0;
        double secondHitTime = secondHit.getTime()/1000.0;
        double thirdHitTime = thirdHit.getTime()/1000.0;
        double fourthHitTime = fourthHit.getTime()/1000.0;
	double fifthHitTime = fifthHit.getTime()/1000.0;


	double scattimeDiff51 = (fifthHitTime - firstHitTime);
        float scatDist51 = sqrt(pow(fifthHit.getPosX() - firstHit.getPosX(),2)  // Pos in cm
                        +pow(fifthHit.getPosY() - firstHit.getPosY(),2)
                        +pow(fifthHit.getPosZ() - firstHit.getPosZ(),2));
        scatDist51 = scatDist51/29.979246;
        double timeScat51 = (scattimeDiff51 - scatDist51);
	

	getStatistics().getHisto1D("scattimeDiff51")->Fill(scattimeDiff51);
	getStatistics().getHisto1D("scatDist51")->Fill(scatDist51);
        getStatistics().getHisto1D("timeScat51")->Fill(timeScat51);
	
	auto ScinID_Diff5_1 = fabs(scinID_fifth - scinID_first);
	getStatistics().getHisto2D("TimeScat51_vs_ScinID_Diff51")->Fill(timeScat51, ScinID_Diff5_1);
        getStatistics().getHisto2D("TimeScat51_vs_ScinID_1")->Fill(timeScat51, scinID_first);
        getStatistics().getHisto2D("TimeScat51_vs_ScinID_5")->Fill(timeScat51, scinID_fifth);



 	double scattimeDiff41 = (fourthHitTime - firstHitTime);
        float scatDist41 = sqrt(pow(fourthHit.getPosX() - firstHit.getPosX(),2)  // Pos in cm
                        +pow(fourthHit.getPosY() - firstHit.getPosY(),2)
                        +pow(fourthHit.getPosZ() - firstHit.getPosZ(),2));
        scatDist41 = scatDist41/29.979246;
        double timeScat41 = (scattimeDiff41 - scatDist41);
        

	getStatistics().getHisto1D("scattimeDiff41")->Fill(scattimeDiff41);
	getStatistics().getHisto1D("scatDist41")->Fill(scatDist41);
	getStatistics().getHisto1D("timeScat41")->Fill(timeScat41);



	auto ScinID_Diff4_1 = fabs(scinID_fourth - scinID_first);
        getStatistics().getHisto2D("TimeScat41_vs_ScinID_Diff41")->Fill(timeScat41, ScinID_Diff4_1);
        getStatistics().getHisto2D("TimeScat41_vs_ScinID_1")->Fill(timeScat41, scinID_first);
        getStatistics().getHisto2D("TimeScat41_vs_ScinID_4")->Fill(timeScat41, scinID_fourth);




	double scattimeDiff31 = (thirdHitTime - firstHitTime);
        float scatDist31 = sqrt(pow(thirdHit.getPosX() - firstHit.getPosX(),2)  // Pos in cm
                        +pow(thirdHit.getPosY() - firstHit.getPosY(),2)
                        +pow(thirdHit.getPosZ() - firstHit.getPosZ(),2));
        scatDist31 = scatDist31/29.979246;
        double timeScat31 = (scattimeDiff31 - scatDist31);
      

	getStatistics().getHisto1D("scattimeDiff31")->Fill(scattimeDiff31);
        getStatistics().getHisto1D("scatDist31")->Fill(scatDist31);
        getStatistics().getHisto1D("timeScat31")->Fill(timeScat31);


	auto ScinID_Diff3_1 = fabs(scinID_third - scinID_first);
        getStatistics().getHisto2D("TimeScat31_vs_ScinID_Diff31")->Fill(timeScat31, ScinID_Diff3_1);
        getStatistics().getHisto2D("TimeScat31_vs_ScinID_1")->Fill(timeScat31, scinID_first);
        getStatistics().getHisto2D("TimeScat31_vs_ScinID_3")->Fill(timeScat31, scinID_third);



	double scattimeDiff21 = (secondHitTime - firstHitTime);
        float scatDist21 = sqrt(pow(secondHit.getPosX() - firstHit.getPosX(),2)  // Pos in cm
                        +pow(secondHit.getPosY() - firstHit.getPosY(),2)
                        +pow(secondHit.getPosZ() - firstHit.getPosZ(),2));
        scatDist21 = scatDist21/29.979246;
        double timeScat21 = (scattimeDiff21 - scatDist21);


        getStatistics().getHisto1D("scattimeDiff21")->Fill(scattimeDiff21);
        getStatistics().getHisto1D("scatDist21")->Fill(scatDist21);
        getStatistics().getHisto1D("timeScat21")->Fill(timeScat21);


	auto ScinID_Diff2_1 = fabs(scinID_second - scinID_first);
        getStatistics().getHisto2D("TimeScat21_vs_ScinID_Diff21")->Fill(timeScat21, ScinID_Diff2_1);
 	getStatistics().getHisto2D("TimeScat21_vs_ScinID_1")->Fill(timeScat21, scinID_first);
 	getStatistics().getHisto2D("TimeScat21_vs_ScinID_2")->Fill(timeScat21, scinID_second);

        getStatistics().getHisto2D("Scatter_of_5_and_4_from_1")->Fill(timeScat51,timeScat41);
	getStatistics().getHisto2D("Scatter_of_3_and_2_from_1")->Fill(timeScat31,timeScat21);



	TVector3 RefVec(85.0, 0.0, 0.0);
        TVector3 Vec51(fifthHit.getPosX() - firstHit.getPosX(), fifthHit.getPosY() - firstHit.getPosY(), fifthHit.getPosZ() - firstHit.getPosZ());
        TVector3 Vec41(fourthHit.getPosX() - firstHit.getPosX(), fourthHit.getPosY() - firstHit.getPosY(), fourthHit.getPosZ() - firstHit.getPosZ());
        TVector3 Vec31(thirdHit.getPosX() - firstHit.getPosX(), thirdHit.getPosY() - firstHit.getPosY(), thirdHit.getPosZ() - firstHit.getPosZ());
        TVector3 Vec21(secondHit.getPosX() - firstHit.getPosX(), secondHit.getPosY() - firstHit.getPosY(), secondHit.getPosZ() - firstHit.getPosZ());

        double Angle51 = Vec51.Angle(RefVec) *180.0 /pi ;
        double Angle41 = Vec41.Angle(RefVec) *180.0 /pi ;
        double Angle31 = Vec31.Angle(RefVec) *180.0 /pi ;
        double Angle21 = Vec21.Angle(RefVec) *180.0 /pi ;


	getStatistics().getHisto2D("DeltaID15_vs_Theta")->Fill(ScinID_Diff5_1, Angle51);
        getStatistics().getHisto2D("DeltaID14_vs_Theta")->Fill(ScinID_Diff4_1, Angle41);
        getStatistics().getHisto2D("DeltaID13_vs_Theta")->Fill(ScinID_Diff3_1, Angle31);
        getStatistics().getHisto2D("DeltaID12_vs_Theta")->Fill(ScinID_Diff2_1, Angle21);


	getStatistics().getHisto2D("DeltaID15_vs_TOT1")->Fill(ScinID_Diff5_1, fTOT);
        getStatistics().getHisto2D("DeltaID14_vs_TOT1")->Fill(ScinID_Diff4_1, fTOT);
        getStatistics().getHisto2D("DeltaID13_vs_TOT1")->Fill(ScinID_Diff3_1, fTOT);
        getStatistics().getHisto2D("DeltaID12_vs_TOT1")->Fill(ScinID_Diff2_1, fTOT);



	getStatistics().getHisto2D("DeltaID15_vs_TOT1+TOT5")->Fill(ScinID_Diff5_1, (fTOT+fiTOT));
        getStatistics().getHisto2D("DeltaID14_vs_TOT1+TOT5")->Fill(ScinID_Diff4_1, (fTOT+fiTOT));
        getStatistics().getHisto2D("DeltaID13_vs_TOT1+TOT5")->Fill(ScinID_Diff3_1, (fTOT+fiTOT));
        getStatistics().getHisto2D("DeltaID12_vs_TOT1+TOT5")->Fill(ScinID_Diff2_1, (fTOT+fiTOT));




	if(timeScat51 < 30.0)

	{

	

	getStatistics().getHisto2D("TOT_ID_30_first")->Fill(fTOT, scinID_first);
        getStatistics().getHisto2D("TOT_ID_30_fifth")->Fill(fiTOT,scinID_fifth);

        getStatistics().getHisto1D("TOT_30_first")->Fill(fTOT);
        getStatistics().getHisto1D("TOT_30_fifth")->Fill(fiTOT);




										}

	else if(timeScat51 <= 40.0 && timeScat51 >= 30.0)

	{

        getStatistics().getHisto2D("TOT_ID_30_to_40_first")->Fill(fTOT, scinID_first);
        getStatistics().getHisto2D("TOT_ID_30_to_40_fifth")->Fill(fiTOT,scinID_fifth);
	
	getStatistics().getHisto1D("TOT_30_to_40_first")->Fill(fTOT);
        getStatistics().getHisto1D("TOT_30_to_40_fifth")->Fill(fiTOT);

  



                   auto PMT_A_1_first = firstHit.getSignalA().getPM().getID();
                   auto PMT_A_1_fifth = fifthHit.getSignalA().getPM().getID();

                   auto PMT_B_1_first = firstHit.getSignalB().getPM().getID();
                   auto PMT_B_1_fifth = fifthHit.getSignalB().getPM().getID();

                   double TOT_A_1_first = CalcTOT_A_1(firstHit);
                   double TOT_A_1_fifth = CalcTOT_A_1(fifthHit);
                   double TOT_B_1_first = CalcTOT_B_1(firstHit);
                   double TOT_B_1_fifth = CalcTOT_B_1(fifthHit);

           getStatistics().getHisto2D("TOT_A_1_PMT_A_1_first")->Fill(TOT_A_1_first,PMT_A_1_first);
           getStatistics().getHisto2D("TOT_A_1_PMT_A_1_fifth")->Fill(TOT_A_1_fifth,PMT_A_1_fifth);
           getStatistics().getHisto2D("TOT_B_1_PMT_B_1_first")->Fill(TOT_B_1_first,PMT_B_1_first);
           getStatistics().getHisto2D("TOT_B_1_PMT_B_1_fifth")->Fill(TOT_B_1_fifth,PMT_B_1_fifth);



                   auto PMT_A_2_first = firstHit.getSignalA().getPM().getID();
                   auto PMT_A_2_fifth = fifthHit.getSignalA().getPM().getID();

                   auto PMT_B_2_first = firstHit.getSignalB().getPM().getID();
                   auto PMT_B_2_fifth = fifthHit.getSignalB().getPM().getID();

                   double TOT_A_2_first = CalcTOT_A_2(firstHit);
                   double TOT_A_2_fifth = CalcTOT_A_2(fifthHit);
                   double TOT_B_2_first = CalcTOT_B_2(firstHit);
                   double TOT_B_2_fifth = CalcTOT_B_2(fifthHit);

           getStatistics().getHisto2D("TOT_A_2_PMT_A_2_first")->Fill(TOT_A_2_first,PMT_A_2_first);
           getStatistics().getHisto2D("TOT_A_2_PMT_A_2_fifth")->Fill(TOT_A_2_fifth,PMT_A_2_fifth);
           getStatistics().getHisto2D("TOT_B_2_PMT_B_2_first")->Fill(TOT_B_2_first,PMT_B_2_first);
           getStatistics().getHisto2D("TOT_B_2_PMT_B_2_fifth")->Fill(TOT_B_2_fifth,PMT_B_2_fifth);






		   auto PMT_A_3_first = firstHit.getSignalA().getPM().getID();
                   auto PMT_A_3_fifth = fifthHit.getSignalA().getPM().getID();

                   auto PMT_B_3_first = firstHit.getSignalB().getPM().getID();
                   auto PMT_B_3_fifth = fifthHit.getSignalB().getPM().getID();

                   double TOT_A_3_first = CalcTOT_A_3(firstHit);
                   double TOT_A_3_fifth = CalcTOT_A_3(fifthHit);
                   double TOT_B_3_first = CalcTOT_B_3(firstHit);
                   double TOT_B_3_fifth = CalcTOT_B_3(fifthHit);

           getStatistics().getHisto2D("TOT_A_3_PMT_A_3_first")->Fill(TOT_A_3_first,PMT_A_3_first);
           getStatistics().getHisto2D("TOT_A_3_PMT_A_3_fifth")->Fill(TOT_A_3_fifth,PMT_A_3_fifth);
           getStatistics().getHisto2D("TOT_B_3_PMT_B_3_first")->Fill(TOT_B_3_first,PMT_B_3_first);
           getStatistics().getHisto2D("TOT_B_3_PMT_B_3_fifth")->Fill(TOT_B_3_fifth,PMT_B_3_fifth);





                   auto PMT_A_4_first = firstHit.getSignalA().getPM().getID();
                   auto PMT_A_4_fifth = fifthHit.getSignalA().getPM().getID();

                   auto PMT_B_4_first = firstHit.getSignalB().getPM().getID();
                   auto PMT_B_4_fifth = fifthHit.getSignalB().getPM().getID();

                   double TOT_A_4_first = CalcTOT_A_4(firstHit);
                   double TOT_A_4_fifth = CalcTOT_A_4(fifthHit);
                   double TOT_B_4_first = CalcTOT_B_4(firstHit);
                   double TOT_B_4_fifth = CalcTOT_B_4(fifthHit);

           getStatistics().getHisto2D("TOT_A_4_PMT_A_4_first")->Fill(TOT_A_4_first,PMT_A_4_first);
           getStatistics().getHisto2D("TOT_A_4_PMT_A_4_fifth")->Fill(TOT_A_4_fifth,PMT_A_4_fifth);
           getStatistics().getHisto2D("TOT_B_4_PMT_B_4_first")->Fill(TOT_B_4_first,PMT_B_4_first);
           getStatistics().getHisto2D("TOT_B_4_PMT_B_4_fifth")->Fill(TOT_B_4_fifth,PMT_B_4_fifth);




	  getStatistics().getHisto2D("Y_vs_X_first")->Fill(firstHit.getPosY(),firstHit.getPosX());
	  getStatistics().getHisto2D("Y_vs_X_fifth")->Fill(fifthHit.getPosY(),fifthHit.getPosX());







	





		

		}




	else if(timeScat51 < 120.0 && timeScat51 > 40.0)

        {

        getStatistics().getHisto2D("TOT_ID_40_to_120_first")->Fill(fTOT, scinID_first);
        getStatistics().getHisto2D("TOT_ID_40_to_120_fifth")->Fill(fiTOT,scinID_fifth);

        getStatistics().getHisto1D("TOT_40_to_120_first")->Fill(fTOT);
        getStatistics().getHisto1D("TOT_40_to_120_fifth")->Fill(fiTOT);





                                                                        }



                                  				


	else if(timeScat51 <= 150.0 && timeScat51 >= 120.0)

        {

        getStatistics().getHisto2D("TOT_ID_120_to_150_first")->Fill(fTOT, scinID_first);
        getStatistics().getHisto2D("TOT_ID_120_to_150_fifth")->Fill(fiTOT,scinID_fifth);

        getStatistics().getHisto1D("TOT_120_to_150_first")->Fill(fTOT);
        getStatistics().getHisto1D("TOT_120_to_150_fifth")->Fill(fiTOT);





									}





				}
      

			}

		}



	}






   else {
    return false;
  }
  return true;
	}



bool EventCategorizer::terminate()
{

  INFO("More than one hit Events done. Writing conrtrol histograms.");
  return true;
}

void EventCategorizer::saveEvents(const vector<JPetEvent>& events)
{
  for (const auto& event : events) {
    fOutputEvents->add<JPetEvent>(event);
  }
}

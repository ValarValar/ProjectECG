#ifndef ANALYSIS_FUNCS_H
#define ANALYSIS_FUNCS_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

//This class is for holding information about ECG and about second standart diversion concretly
class WavesData {
	
	//Storage for heights of waves
	std::vector<double> heights;

	//Storage for lengths of waves
	std::vector<double> lengths;

	//Storage for starting positions of waves
	std::vector<double> poses;

	//Storage for lengths of intervals
	std::vector<double> intervals;

	//ECG tape`s speed
	double speed;


public:

	//Copy constructor
	WavesData(WavesData & other) :heights(other.heights), lengths(other.lengths), poses(other.poses) {};

	//It initializes class`s fields by values from vectors h,l and p, which hold values of lengths, heights and poses of waves respectively
	WavesData(std::vector<double> h, std::vector<double> l, std::vector<double> p) :heights(h), lengths(l), poses(p) {}

	//It initializes class`s fields by values from file 
	WavesData(std::string filename)
	{
		std::ifstream fin(filename);

		std::string h = "";
		std::string l = "";
		std::string p = "";

		getline(fin, h);
		getline(fin, l);
		getline(fin, p);

		std::vector<double> res;

		std::istringstream is1(h);
		double tmp = 0.0;
		while (is1 >> tmp)
			heights.push_back(tmp);

		std::istringstream is2(l);
		while (is2 >> tmp)
			lengths.push_back(tmp);

		std::istringstream is3(p);
		while (is3 >> tmp)
			poses.push_back(tmp);

	}

	//It checks patient`s heart for arrhythmia
	bool Check_arrhythmia();

	//return patient`s hearth rate
	double count_heart_rate();

	//It checks patient`s hearth rate for Bradycardia
	bool Check_Bradycardia();

	//It checks patient`s hearth rate for Tachycardia
	bool Check_Tachycardia();
};





#endif

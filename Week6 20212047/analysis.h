#pragma once
#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <string>
#include <vector>
#include "Student_info.h"

using namespace std;

bool did_all_hw(const Student_info&);
double average_analysis(const vector<Student_info>&);
double median_analysis(const vector<Student_info>&);
double optimistic_median_analysis(const vector<Student_info>&);
void write_analysis(ostream& out, string& name,
	double analysis(vector<Student_info>&),
	const vector<Student_info>&,
	const vector<Student_info>&
);

#endif
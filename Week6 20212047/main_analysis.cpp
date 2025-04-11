#include <vector>
#include <iostream>

#include "Student_info.h"
#include "analysis.h"

using namespace std;

int main() {
	vector<Student_info> did, didnt;

	// 학생 기록 읽고 나눠요
	Student_info record;
	while (read(cin, record)) {
		if (did_all_hw(record))
			did.push_back(record);
		else
			didnt.push_back(record);
	}

	// 빈 벡터 확인
	if (did.empty()) {
		cout << "No student did HW!" << endl;
		return 1;
	}
	if (didnt.empty()) {
		cout << "Every student did HW!" << endl;
		return 1;
	}

	// 분석하기
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of HW turned in", 
		optimistic_median_analysis, did, didnt);

	return 0;
}
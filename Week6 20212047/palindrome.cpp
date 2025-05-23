//palindrome.cpp(회문)
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string& s) {
	return equal(s.begin(), s.end(), s.rbegin());
}

int main() {
	string s;
	while (cin >> s) {
		if (is_palindrome(s))
			cout << s << "은/는 회문입니다." << endl;
		else
			cout << s << "은/는 회문이 아닙니다." << endl;
	}
	return 0;
}
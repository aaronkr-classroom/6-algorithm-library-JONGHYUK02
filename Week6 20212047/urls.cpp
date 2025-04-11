#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string::const_iterator iter;

bool not_url_char(char c) {
	// url에 들어갈 수 있는 아파벳과 숫자 이외의 문자
	static const string url_ch = "~;/?:@=&-_.+!*'(), ";

	// c가 url에 들어갈 수 있는 문자인지 확인하면 음수를 변환
	return !(isalnum(c)
		|| find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}




iter url_end(iter b, iter e)
	{
		return find_if(b, e, not_url_char);
	}



iter url_begin(iter b, iter e) {
	static const string sep = "://";

	// i는 구분 기호를 발견한위치를 표시
	iter i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e) {
			// 구분 기호가 현재 탐색 범위의 처음
			// 또는 마지막에 있는지 확인
		if (i != b && i + sep.size() != e) {
				// beg은 프로토콜 이름의 시작 위치를 표시
			iter beg = i; // :위치부터 시작하기
			while (beg != b && isalpha(beg[-1])) {
				--beg; // 역방향 가기
				}

				// 구분 기호 앞뒤로 url의 일부에서
				// 유효한 문자가 하나라도 있는지 확인
			if (beg != b && !not_url_char(i[sep.size()])) {
					return beg;
				}
			}

			// 발견한 구분 기호는 url 일부가 아니므로 해당 구분 기호 이후로 표시하도록 i를 증가시킴

		i += sep.size();
		}
	}

vector<string> find_urls(const string& s) {
	vector<string> urls;
	iter b = s.begin(), e = s.end();

	// 인수로 전달받은 문자열 전체를 탐색
	while (b != e) {
		// ://의 앞쪽에서 하나 이상의 문자를 탐색
		b = url_begin(b, e);

		if (b != e) {
			// 해당 문자를 찾았다면 url의 나머지 부분을 탐색
			iter after = url_end(b, e); // 프로토콜 이름 후

			// url을 찾았으면 저장
			urls.push_back(string(b, after));

			// 인수로 전달받은 문자열에서 또
			// 다른 url을 찾기 위해 b를 이동(증가)

			b = after;
		}
	}
	return urls;
}

int main() {
	string s;
	while(getline(cin, s)) {
		vector<string> v = find_urls(s);

		for (vector<string>::const_iterator i = v.begin();
			i != v.end(); i++){
			cout << *i << endl;
		}
	}
	return 0;
}
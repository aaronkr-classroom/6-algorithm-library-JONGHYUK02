#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string::const_iterator iter;

bool not_url_char(char c) {
	// url�� �� �� �ִ� ���ĺ��� ���� �̿��� ����
	static const string url_ch = "~;/?:@=&-_.+!*'(), ";

	// c�� url�� �� �� �ִ� �������� Ȯ���ϸ� ������ ��ȯ
	return !(isalnum(c)
		|| find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}




iter url_end(iter b, iter e)
	{
		return find_if(b, e, not_url_char);
	}



iter url_begin(iter b, iter e) {
	static const string sep = "://";

	// i�� ���� ��ȣ�� �߰�����ġ�� ǥ��
	iter i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e) {
			// ���� ��ȣ�� ���� Ž�� ������ ó��
			// �Ǵ� �������� �ִ��� Ȯ��
		if (i != b && i + sep.size() != e) {
				// beg�� �������� �̸��� ���� ��ġ�� ǥ��
			iter beg = i; // :��ġ���� �����ϱ�
			while (beg != b && isalpha(beg[-1])) {
				--beg; // ������ ����
				}

				// ���� ��ȣ �յڷ� url�� �Ϻο���
				// ��ȿ�� ���ڰ� �ϳ��� �ִ��� Ȯ��
			if (beg != b && !not_url_char(i[sep.size()])) {
					return beg;
				}
			}

			// �߰��� ���� ��ȣ�� url �Ϻΰ� �ƴϹǷ� �ش� ���� ��ȣ ���ķ� ǥ���ϵ��� i�� ������Ŵ

		i += sep.size();
		}
	}

vector<string> find_urls(const string& s) {
	vector<string> urls;
	iter b = s.begin(), e = s.end();

	// �μ��� ���޹��� ���ڿ� ��ü�� Ž��
	while (b != e) {
		// ://�� ���ʿ��� �ϳ� �̻��� ���ڸ� Ž��
		b = url_begin(b, e);

		if (b != e) {
			// �ش� ���ڸ� ã�Ҵٸ� url�� ������ �κ��� Ž��
			iter after = url_end(b, e); // �������� �̸� ��

			// url�� ã������ ����
			urls.push_back(string(b, after));

			// �μ��� ���޹��� ���ڿ����� ��
			// �ٸ� url�� ã�� ���� b�� �̵�(����)

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
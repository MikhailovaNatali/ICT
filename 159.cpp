#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int check(string a, vector<pair<string, int>> T) {
	for (int i = 0; i < T.size(); i++) {
		if (T[i].first == a) {
			return T[i].second;
		}
	}
	return -1;
}
int main() {
	vector<char> A;
	for (int i = 0; i <= 256; i++) {
		A.push_back(i);
	}
	string str; cin >> str;
	vector<pair<string, int>> T;
	for (int i = 0; i < A.size(); i++) {
		string s(1, A[i]);
		T.push_back({s, i});
	}
	vector<int> rez;
	string now;
	string last;
	int k = 256;
	for(int i = 0; i < str.size(); i++){
		last = now;
		now = now + str[i];
		if (check(now, T) == -1) {
			k = k + 1;
			T.push_back({ now, k});
			rez.push_back(check(last, T));
			now = now[now.size() - 1];
			if (i == str.size() - 1) {
				string p(1,now[now.size() - 1]); 
				rez.push_back(check(p, T)); 
			}
		}
		else {
			continue;
		}
	}
	for (int i = 0; i < rez.size(); i++) {
		cout << rez[i] << " ";
	}
}
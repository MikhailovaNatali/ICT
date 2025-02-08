#include<iostream>
#include <string>
#include<vector>
using namespace std;
bool checking(vector<string> S) {
	int a = 0;
	for (int i = 0; i < S.size(); i++) {
		if (a == 0 && S[i] == "(") { a = 1; }
		else if (a == 0 && isdigit(S[i]) && S[i] != "0") { a = 2; }
		else if (a == 1 && isdigit(S[i]) && S[i] != "0") { a = 2; }
		else if (a == 2 && (S[i] == "+" || S[i] == "-" || S[i] == "/" || S[i] == "*")) { a = 3; }
		else if (a == 2 && isdigit(S[i])) { a = 2; }
		else if (a == 3 && isdigit(S[i]) && S[i] != "0") { a = 4; }
		else if (a == 4 && (S[i] == "+" || S[i] == "-" || S[i] == "/" || S[i] == "*")) { a = 3; }
		else if (a == 4 && isdigit(S[i])) { a = 4; }
		else if (a == 4 && S[i] == "(") { a = 5; }
		else if (a == 5 && (S[i] == "+" || S[i] == "-" || S[i] == "/" || S[i] == "*")) { a = 3; }
		else { a = -1; }
	}
	if (a == 2 || a == 4) { return true; }
	else { return false; }
}
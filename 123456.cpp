#include<iostream>

using namespace std;

int main(void) {
	string str; cin >> str;
	int a = 45;
	
	for (int i = 0; i < str.size(); i++) {
		if (a == 0 && str[i] % 3 == 0) { a = 0; }
		else if (a == 0 && str[i] % 3 == 1) { a = 1; }
		else if (a == 0 && str[i] % 3 == 2) { a = 2; }
		else if (a == 1 && str[i] % 3 == 0) { a = 1; }
		else if (a == 1 && str[i] % 3 == 1) { a = 2; }
		else if (a == 1 && str[i] % 3 == 2) { a = 0; }
		else if (a == 2 && str[i] % 3 == 0) { a = 2; }
		else if (a == 2 && str[i] % 3 == 1) { a = 0; }
		else if (a == 2 && str[i] % 3 == 2) { a = 1; }
		else { a = 4; }
	}

	if (a == 0) { cout << "true"; }
	else { cout << "false"; }
}
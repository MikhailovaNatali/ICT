#include<iostream>
#include <string>
#include<vector>
using namespace std;
class Operator {
public:
	virtual double eval() = 0;
};
class SumOp : public Operator {
public:
	SumOp(Operator* L, Operator* R) {
		left = L; right = R;
	}
	double eval() override{
		double a = left->eval(); double b = right->eval();
		return a + b;
	}
private:
	Operator* left;	Operator* right;
};
class DivOp : public Operator {
public:
	DivOp(Operator* L, Operator* R) {
		left = L; right = R;
	}
	double eval() override {
		double a = left->eval(); double b = right->eval();
		return a / b;
	}
private:
	Operator* left;	Operator* right;
};
class SubOp : public Operator {
public:
	SubOp(Operator* L, Operator* R) {
		left = L; right = R;
	}
	double eval() override {
		double a = left->eval(); double b = right->eval();
		return a - b;
	}
private:
	Operator* left;	Operator* right;
};
class MulOp : public Operator {
public:
	MulOp(Operator* L, Operator* R) {
		left = L; right = R;
	}
	double eval() override {
		double a = left->eval(); double b = right->eval();
		return a * b;
	}
private:
	Operator* left;	Operator* right;
};
class NumOp : public Operator {
public:
	NumOp(double num) {
		Num = num; 
	}
	double eval() override {
		return Num;
	}
private:
	double Num;
};
bool isdigit(string d){
	if (d == "0" || d == "1" || d == "2" || d == "3" || d == "4" || d == "5" || d == "6" || d == "7" || d == "8" || d == "9") { return true; }
	else { return false; }
}
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
int main(void) {
	vector <Operator*> Op;
	string S; cin >> S; 
	string num;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == ',' && num != "") {
			Op.push_back(new NumOp(stoi(num)));
			num = "";
		}
		if (isdigit(S[i])) {
			num += S[i];
		}
		if (S[i] == '+' || S[i] == '-' || S[i] == '/' || S[i] == '*') {
			Operator* sec; Operator* fst;
			if (!(Op.empty())) {
				sec = Op[Op.size() - 1];
				Op.pop_back();
			}
			else { cout << "uncorrect line"; return 0; }
			if (!(Op.empty())) {
				fst = Op[Op.size() - 1];
				Op.pop_back();
			}
			else { cout << "uncorrect line"; return 0; }
			if (S[i] == '+') { Op.push_back(new SumOp(fst, sec)); }
			if (S[i] == '-') { Op.push_back(new SubOp(fst, sec)); }
			if (S[i] == '/') { Op.push_back(new DivOp(fst, sec)); }
			if (S[i] == '*') { Op.push_back(new MulOp(fst, sec)); }
		}
	}
	if (Op.size() == 1) { cout << Op[0]->eval(); }
	else { cout << "uncorrect line "; }
}
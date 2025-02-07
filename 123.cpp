#include<iostream>
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
	double eval() override {
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
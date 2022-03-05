#include "douDig.h"
#include <iostream>
#include <random>
using namespace std;
douDig::douDig(double init_val)
{
	val = init_val;
	inc = 1.0;
	dec = 1.0;
}

douDig::~douDig(void){}

void douDig::setInc(double* new_inc)
{
	inc = *new_inc;
}

void douDig::setDec(double* new_dec)
{
	dec = *new_dec;
}

void douDig::show(void)
{
	cout << "Value now: " << this->val << endl;
}

douDig douDig::operator++(void)
{
	this->val = this->val + this->inc;
	return *this;
}

douDig operator++(douDig& ob, int notused)
{
	//от 0 до 19.99
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());
	double rnd = (double)(gen() % 2000) / 100;
	cout << "Icrement value: " << rnd << endl;
	douDig new_ob = ob;
	ob.val += rnd;
	return new_ob;
}

douDig douDig::operator--(void)
{
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());
	double rnd = (double)(gen() % 2000) / 100;
	cout << "Decrement value: " << rnd << endl;
	this->val = this->val - rnd;
	return *this;
}

douDig operator--(douDig& ob, int notused)
{
	douDig new_ob = ob;
	ob.val -= ob.dec;
	return new_ob;
}

douDig douDig::operator!(void)
{
	douDig new_ob = *this;
	new_ob.val *= (-1);
	return new_ob;
}

douDig::operator float()
{
	return val;
}
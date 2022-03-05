#pragma once
class douDig
{
private:
	double val;
	double inc;
	double dec;
public:
	explicit douDig(double init_val = 0.0);
	~douDig(void);
	void setInc(double* new_inc);
	void setDec(double* new_dec);
	void show(void);
	douDig operator++(void);
	friend douDig operator++(douDig& ob, int notused);
	douDig operator--(void);
	friend douDig operator--(douDig& ob, int notused);
	douDig operator!(void);
	operator float();
};

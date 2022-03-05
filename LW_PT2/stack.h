#pragma once

struct elem
{
	int val;
	elem* down;
};

class stack
{
private:
	elem* top;
	int size;
public:
	explicit stack(void);
	stack(const stack& in);
	~stack(void);
	void show(void);
	void push(void);
	void pop(void);
	int getsize(void);
	stack& operator=(stack r);
	stack operator+(stack r);
	stack operator-(stack& r);
	stack operator*(stack r);
	stack operator/(stack& r);
	stack* operator+=(stack r);
	stack operator-=(stack& r);
	stack* operator*=(stack r);
	stack operator/=(stack& r);
};

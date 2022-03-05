#include "stack.h"
#include <iostream>
#include <random>
using namespace std;

stack::stack(void)
{
	//кол-во: от 1 до 10, значения: от 0 до 100
	int i;
	elem* temp=0;
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());
	size = gen() % 10 + 1;
	for (i = 0; i < size; i++)
	{
		top = new elem;
		top->val = gen() % 101;
		top->down = temp;
		temp = top;
	}
}

stack::stack(const stack& in)
{
	top = new elem;
	size = 0;
	elem* temp1 = top;
	elem* temp2 = in.top;
	while (temp2->down)
	{
		temp1->val = temp2->val;
		temp1->down = new elem;
		temp1 = temp1->down;
		temp2 = temp2->down;
		this->size++;
	}
	temp1->val = temp2->val;
	temp1->down = 0;
	size++;
}

stack::~stack(void)
{
	int i;
	if (!size)
	{
		return;
	}
	elem* temp = top;
	for (i = 0; i < size; i++)
	{
		temp = top;
		top = top->down;
		delete temp;
	}
}

void stack::show(void)
{
	int i;
	elem* temp = top;
	for (i = 0; i < size; i++)
	{
		cout << "Element " << i + 1 << " with value: " << temp->val << ';' << endl;
		temp = temp->down;
	}
}

void stack::push(void)
{
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());
	elem* temp = top;
	top = new elem;
	top->val = gen() % 101;
	top->down = temp;
	size++;
}

void stack::pop(void)
{
	if (!size)
	{
		return;
	}
	elem* temp = top;
	top = top->down;
	delete temp;
	size--;
}

int stack::getsize(void)
{
	return size;
}

stack& stack::operator=(stack r)
{
	elem* temp1 = top;
	while (size)
	{
		temp1 = top;
		top = top->down;
		delete temp1;
		size--;
	}
	top = new elem;
	elem* temp2 = r.top;
	temp1 = top;
	while (temp2->down)
	{
		temp1->val = temp2->val;
		temp1->down = new elem;
		temp1 = temp1->down;
		temp2 = temp2->down;
		this->size++;
	}
	temp1->val = temp2->val;
	temp1->down = 0;
	size++;
	return *this;
}

stack stack::operator+(stack r)
{
	if (!this->size && !r.size)
	{
		cout << "The stacks have null sizes;" << endl;
		return *this;
	}
	if (this->size != r.size)
	{
		cout << "The stacks have different sizes;" << endl;
		return(this->size > r.size) ? (*this) : r;
	}
	int i;
	elem* r_ptr = r.top;
	elem* this_ptr = this->top;
	for (i = 0; i < this->size; i++)
	{
		r_ptr->val = r_ptr->val + this_ptr->val;
		r_ptr = r_ptr->down;
		this_ptr = this_ptr->down;
	}
	return r;
}

stack stack::operator-(stack& r)
{
	if (!this->size && !r.size)
	{
		cout << "The stacks have null sizes;" << endl;
		return *this;
	}
	if (this->size != r.size)
	{
		cout << "The stacks have different sizes;" << endl;
		return(this->size > r.size) ? (*this) : r;
	}
	int i;
	stack res = *this;
	elem* r_ptr = r.top;
	elem* res_ptr = res.top;
	for (i = 0; i < res.size; i++)
	{
		res_ptr->val = res_ptr->val - r_ptr->val;
		r_ptr = r_ptr->down;
		res_ptr = res_ptr->down;
	}
	return res;
}

stack stack::operator*(stack r)
{
	if (!this->size && !r.size)
	{
		cout << "The stacks have null sizes;" << endl;
		return *this;
	}
	if (this->size != r.size)
	{
		cout << "The stacks have different sizes;" << endl;
		return(this->size > r.size) ? (*this) : r;
	}
	int i;
	elem* r_ptr = r.top;
	elem* this_ptr = this->top;
	for (i = 0; i < this->size; i++)
	{
		r_ptr->val = r_ptr->val * this_ptr->val;
		r_ptr = r_ptr->down;
		this_ptr = this_ptr->down;
	}
	return r;
}

stack stack::operator/(stack& r)
{
	if (!this->size && !r.size)
	{
		cout << "The stacks have null sizes;" << endl;
		return *this;
	}
	if (this->size != r.size)
	{
		cout << "The stacks have different sizes;" << endl;
		return(this->size > r.size) ? (*this) : r;
	}
	int i;
	stack res = *this;
	elem* r_ptr = r.top;
	elem* res_ptr = res.top;
	for (i = 0; i < res.size; i++)
	{
		res_ptr->val = res_ptr->val / r_ptr->val;
		r_ptr = r_ptr->down;
		res_ptr = res_ptr->down;
	}
	return res;
}

stack* stack::operator+=(stack r)
{
	if (!this->size && !r.size)
	{
		cout << "The stacks have null sizes;" << endl;
		return this;
	}
	if (this->size != r.size)
	{
		cout << "The stacks have different sizes;" << endl;
		return(this->size > r.size) ? (this) : (&r);
	}
	int i;
	elem* r_ptr = r.top;
	elem* this_ptr = this->top;
	for (i = 0; i < this->size; i++)
	{
		this_ptr->val = r_ptr->val + this_ptr->val;
		r_ptr = r_ptr->down;
		this_ptr = this_ptr->down;
	}
	return this;
}

stack stack::operator-=(stack& r)
{
	if (!this->size && !r.size)
	{
		cout << "The stacks have null sizes;" << endl;
		return *this;
	}
	if (this->size != r.size)
	{
		cout << "The stacks have different sizes;" << endl;
		return(this->size > r.size) ? (*this) : r;
	}
	int i;
	elem* r_ptr = r.top;
	elem* this_ptr = this->top;
	for (i = 0; i < this->size; i++)
	{
		this_ptr->val = this_ptr->val - r_ptr->val;
		r_ptr = r_ptr->down;
		this_ptr = this_ptr->down;
	}
	return *this;
}

stack* stack::operator*=(stack r)
{
	if (!this->size && !r.size)
	{
		cout << "The stacks have null sizes;" << endl;
		return this;
	}
	if (this->size != r.size)
	{
		cout << "The stacks have different sizes;" << endl;
		return(this->size > r.size) ? this : (&r);
	}
	int i;
	elem* r_ptr = r.top;
	elem* this_ptr = this->top;
	for (i = 0; i < this->size; i++)
	{
		this_ptr->val = r_ptr->val * this_ptr->val;
		r_ptr = r_ptr->down;
		this_ptr = this_ptr->down;
	}
	return this;
}

stack stack::operator/=(stack& r)
{
	if (!this->size && !r.size)
	{
		cout << "The stacks have null sizes;" << endl;
		return *this;
	}
	if (this->size != r.size)
	{
		cout << "The stacks have different sizes;" << endl;
		return(this->size > r.size) ? (*this) : r;
	}
	int i;
	elem* r_ptr = r.top;
	elem* this_ptr = this->top;
	for (i = 0; i < this->size; i++)
	{
		this_ptr->val = this_ptr->val / r_ptr->val;
		r_ptr = r_ptr->down;
		this_ptr = this_ptr->down;
	}
	return *this;
}
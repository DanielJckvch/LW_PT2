#include <iostream>
#include "douDig.h"
#include "stack.h"
using namespace std;
//�������:
/*
������� �16
1) ������� ����� ������������� �����. ���������� ����������� ��������� ���������:
�������� ����������� ����������������� ��� ����� ��� ���������� �������� ��
���������������� �����; �������� ������������ ����������������� ��� ������������� �������
��� ���������� �������� �� ��������� ����� (�� 0 �� 19.99); �������� �����������
����������������� ��� ����� ��� ���������� �������� �� ��������� �����(�� 0 �� 19.99);
�������� ������������ ����������������� ��� ������������� ������� ��� ��� ����������
�������� �� ���������������� �����; �������� ! ��� ����� ��� ����������� ��������������
��������; �������� �������������� � ��� float.

2) ������� ����� "����".������ � �������� ������� ����� �������� ��������� �������.
���������� ����������� ��������� ��������� ��� ������ � ������� ������������ ������ : +, *,
=, / , -, +=, *=, /=, -=.�� ���������� �������� �������� ������� ����� �������� ����� ����������
�������(����� ��� ������������� �������). 
*/
void douDigfunc(void);
void stackfunc(void);
int main(void)
{
	int sw;
	cout << "Enter class mode: 0-exit, 1-double digit, 2-stack;" << endl;
	cin >> sw;
	cout << endl;
	while (sw) {
		
		switch (sw)
		{
		case 0:
			return 0;
		case 1:
			douDigfunc();
			cout << endl;
			break;
		case 2:
			stackfunc();
			cout << endl;
			break;
		default:
			cout << "Uncorrect mode. Try again:" << endl;
		}
		cout << "Enter class mode: 0-exit, 1-double digit, 2-stack;" << endl;
		cin >> sw;
	}
	return 0;
}
void douDigfunc(void)
{
	double val;
	int sw;
	float f_val = 0.0;
	cout << "Enter init value for ob1" << endl;
	cin >> val;
	douDig ob1(val);
	douDig ob2;
	cout << endl;
	cout << "Enter double object mode: 0-exit, 1-set incr step, 2-set decr step, 3-pref incr, 4-post incr, 5-pref decr, 6-post decr, 7-invert; 8-convert to float;" << endl;
	cin >> sw;
	while (sw)
	{
		switch (sw)
		{
		case 1:
			cout << endl;
			double inc_step;
			cout << "Enter increment step;" << endl;
			cin >> inc_step;
			ob1.setInc(inc_step);
			cout << endl;
			break;
		case 2:
			cout << endl;
			double dec_step;
			cout << "Enter decrement step;" << endl;
			cin >> dec_step;
			ob1.setDec(dec_step);
			cout << endl;
			break;
		case 3:
			cout << endl;
			ob1.show();
			cout << "++ob1: " << ++ob1 << endl;
			ob1.show();
			cout << endl;
			break;
		case 4:
			cout << endl;
			ob1.show();
			cout << "ob1++: " << ob1++ << endl;
			ob1.show();
			cout << endl;
			break;
		case 5:
			cout << endl;
			ob1.show();
			cout << "--ob1: " << --ob1 << endl;
			ob1.show();
			cout << endl;
			break;
		case 6:
			cout << endl;
			ob1.show();
			cout << "ob1--: " << ob1-- << endl;
			ob1.show();
			cout << endl;
			break;
		case 7:
			cout << endl;
			cout << "ob1: " << endl;
			ob1.show();
			cout << "ob2 = !ob1: " << endl;
			ob2 = !ob1;
			ob2.show();
			cout << endl;
			break;
		case 8:
			cout << endl;
			cout << "ob1: " << endl;
			ob1.show();
			f_val = float(ob1);
			cout << "f_val = float(ob1): "<< f_val << endl;
			cout << endl;
			break;
		default:
			cout << "Uncorrect mode. Try again:" << endl;
		}
		cout << "Enter double object mode: 0-exit, 1-set incr step, 2-set decr step, 3-pref incr, 4-post incr, 5-pref decr, 6-post decr, 7-invert; 8-convert to float;" << endl;
		cin >> sw;
	}
}
void stackfunc(void)
{
	
}
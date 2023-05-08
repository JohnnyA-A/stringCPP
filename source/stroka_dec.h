#ifndef STROKA_DEC_H
#define STROKA_DEC_H

#include "stroka.h"
#include <iostream>

using namespace std;

class stroka_dec : public stroka{
private:
	static int copy_stroka_dec;
	void true_form();
public:
	stroka_dec(int = 0);
	stroka_dec(char);
	stroka_dec(const char*);
	stroka_dec(const stroka_dec&);
	~stroka_dec();
	bool is_long(void);
	stroka_dec& operator = (const stroka_dec&);
	stroka_dec& operator ~();
	friend stroka_dec operator - (const stroka_dec&, const stroka_dec&);
	friend void getCopy(int);
	friend int operator + (const stroka_dec&, const stroka_dec&);
	friend int operator+(const stroka_dec& pobj1, int numb);
	friend int operator+(int numb, const stroka_dec& pobj2);
};

#endif STROKA_DEC_H
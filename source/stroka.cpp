#include "stroka.h"
#include <iostream>
#include <string.h>

using namespace std;

int stroka::copy_stroka = 0;

stroka::stroka(int val) : len(val), pCh(new char[len + 1]) {
	pCh[len] = '\0';
}
stroka::stroka(char ch) : len(1), pCh(new char[len + 1]) {
	pCh[0] = ch;
	pCh[1] = '\0';
}
stroka::stroka(const char* S) : len(strlen(S)), pCh(new char[len + 1]) {
	strcpy_s(pCh, len + 1, S);
}
stroka::stroka(const stroka& from) : len(from.len), pCh(new char[len + 1]) {
	strcpy_s(pCh, len + 1, from.pCh);
	copy_stroka++;
}
stroka::~stroka(void) {
	if (pCh) delete[] pCh;
}
bool stroka::empty(void) {
	if (!len)return true;
	else return false;
}

char* stroka::get_str(void) const {
	return pCh;
}
int stroka::get_len(void) const {
	return len;
}

stroka& stroka::operator = (const stroka& S){
	if (&S != this) {
		delete[] pCh;
		len = S.len;
		pCh = new char[len + 1];
		strcpy_s(pCh, len + 1, S.pCh);
	}
	return *this;
}
void stroka::Show(void) {
	std::cout << "pCh = " << pCh << endl;
	std::cout << "len = " << len << endl;
}
#include "stroka.h"
#include "stroka_dec.h"
#include <iostream>
#include <algorithm>

using namespace std;
extern "C" int _stdcall asm_fun(int, int);

int stroka_dec::copy_stroka_dec = 0;


int operator+(const stroka_dec& pobj1, const stroka_dec& pobj2) {
	if ((pobj1.len == 0) && (pobj2.len == 0)) {
		std::cout << "Слагаемые нулевые " << endl;
		return 0;
	}
	if ((pobj1.len == 0) || (pobj2.len == 0)) {
		std::cout << "Одно из слагаемых равно нулю " << endl;
		return  asm_fun(atoi(pobj1.get_str()), atoi(pobj2.get_str()));
	}
	if ((pobj1.get_str() == "0") || (pobj2.get_str() == "0")) {
		std::cout << "Одно из слагаемых равно нулю " << endl;
		return  asm_fun(atoi(pobj1.get_str()), atoi(pobj2.get_str()));
	}
	return asm_fun(atoi(pobj1.get_str()), atoi(pobj2.get_str()));
}

int operator+(const stroka_dec& pobj1, int numb) {
	return asm_fun(atoi(pobj1.get_str()), numb);
}


int operator+(int numb, const stroka_dec& pobj2) {
	return asm_fun(numb, atoi(pobj2.get_str()));

}

stroka_dec& stroka_dec:: operator ~() {
	int i,j;
	char tmp;
	if ('0' <= pCh[len - 1] && pCh[len - 1] <= '9') {
		std::cout << "Недопустимый символ" << pCh[len - 1] << endl;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return *this;
	}
}

void stroka_dec::true_form() {
	int i = 0, j = 0, temp_len = len;
	char* temp = new char[temp_len + 1]{};
	temp[temp_len] = '\0';
	for (i = 0; i <= temp_len; i++)temp[i] = pCh[i];
	i = 0;
	if (temp[0] == '-' || temp[0] == '+') i++;
	while (temp[i] == '0') i++;
	if (i == temp_len) {
		len = 1;
		delete[] pCh;
		pCh = new char[len + 1];
		pCh[len] = '\0';
		pCh[0] = '0';
	}
	else if (pCh[0] == '-') {
		len = temp_len - i + 1;
		delete[] pCh;
		pCh = new char[len + 1];
		pCh[len] = '\0';
		pCh[j++] = '-';
	}
	else {
		len = temp_len - i;
		delete[] pCh;
		pCh = new char[len + 1];
		pCh[len] = '\0';
	}
	for (; i < temp_len; i++)
		pCh[j++] = temp[i]; 
	delete[] temp;
}

stroka_dec::stroka_dec(int val) : stroka(val) {}

stroka_dec::stroka_dec(char ch) : stroka(ch){
	if (ch < '0' || ch > '9') {
		std::cout << "Некорректное десятичное число"<< endl;
		delete[] pCh;
		len = 1;
		pCh = new char[len + 1];
		pCh[0] = '0';
		pCh[1] = '\0';
	}
}
stroka_dec::stroka_dec(const char* S) : stroka(S){
	bool correct = true;
	for (int i = 0; i < len; i++) {
		if ((pCh[i] < '0' || pCh[i] > '9') && pCh[i] != '-' && pCh[i] != '+') {
			std::cout << "Некорректное десятичное число" << endl;
			correct = false;
			break;
		}
		if (i && (pCh[i] == '-' || pCh[i] == '+')) {
			std::cout << "Некорректное десятичное число" << endl;
			correct = false;
			break;
		}
	}
	if (!correct) {
		delete[] pCh;
		len = 1;
		pCh = new char[len + 1];
		pCh[0] = '0';
		pCh[1] = '\0';
	}
	else this->true_form();
}

stroka_dec::stroka_dec(const stroka_dec& from) : stroka(from) {
	copy_stroka_dec++;
}

stroka_dec::~stroka_dec(){
}

bool stroka_dec::is_long(void) {
	const char nlimit[11] = "2147483648";
	const char plimit[11] = "2147483647";
	int i = 0, j = 0;
	if (pCh[0] == '-')i++;
	if (len - i < 10)return true;
	if (len - i > 10)return false;
	if (pCh[0] == '-')
		for (; i < len; i++, j++) {
			if (pCh[i] < nlimit[j])return true;
			if (pCh[i] > nlimit[j])return false;
		}
	else
		for (; i < len; i++, j++) {
			if (pCh[i] < plimit[j])return true;
			if (pCh[i] > plimit[j])return false;
		}
	return true;
}



stroka_dec& stroka_dec::operator = (const stroka_dec& S) {
	*((stroka*)this) = (stroka)S;
	return *this;
}

stroka_dec operator - (const stroka_dec& left, const stroka_dec& right) {
	int max_len = 0, i = 0, t = 0, new_len = 0, j = 0, p = 0;
	char ch;
	char* temp_a;
	char* temp_b;
	if (left.pCh[0] == '-' && right.pCh[0] != '-') {
		max_len = max(left.len, right.len + 1);
		temp_a = new char[max_len + 1];
		temp_a[max_len] = '\0';
		temp_b = new char[max_len + 1];
		temp_b[max_len] = '\0';

		for (i = 0; i < max_len; i++) {
			if (left.len - i - 1 > 0)temp_a[i] = left.pCh[left.len - i - 1];
			else temp_a[i] = '0';
			if (right.len - i - 1 >= 0)temp_b[i] = right.pCh[right.len - i - 1];
			else temp_b[i] = '0';
			ch = (temp_a[i] + temp_b[i] - 2 * '0' + t) % 10 + '0';
			t = (temp_a[i] + temp_b[i] - 2 * '0') / 10;
			temp_a[i] = ch;
		}
		new_len = max_len;
		if (temp_a[max_len - 1] == '0')new_len--;
		stroka_dec temp(new_len + 1);
		temp.pCh[j++] = '-';
		for (i = new_len - 1; i >= 0; i--)
			temp.pCh[j++] = temp_a[i];
		delete[] temp_a;
		delete[] temp_b;
		return temp;
	}
	else if (left.pCh[0] != '-' && right.pCh[0] == '-') {
		max_len = max(left.len + 1, right.len);
		temp_a = new char[max_len + 1];
		temp_a[max_len] = '\0';
		temp_b = new char[max_len + 1];
		temp_b[max_len] = '\0';

		for (i = 0; i < max_len; i++) {
			if (left.len - i - 1 >= 0)temp_a[i] = left.pCh[left.len - i - 1];
			else temp_a[i] = '0';
			if (right.len - i - 1 > 0)temp_b[i] = right.pCh[right.len - i - 1];
			else temp_b[i] = '0';
			ch = (temp_a[i] + temp_b[i] - 2 * '0' + t) % 10 + '0';
			t = (temp_a[i] + temp_b[i] - 2 * '0') / 10;
			temp_a[i] = ch;
		}
		new_len = max_len;
		if (temp_a[max_len - 1] == '0')new_len--;
		stroka_dec temp(new_len);
		for (i = new_len - 1; i >= 0; i--)
			temp.pCh[j++] = temp_a[i];
		delete[] temp_a;
		delete[] temp_b;
		return temp;
	}
	else if (left.pCh[0] == '-' && right.pCh[0] == '-') {
		max_len = max(left.len, right.len);
		temp_a = new char[max_len + 1];
		temp_a[max_len] = '\0';
		temp_b = new char[max_len + 1];
		temp_b[max_len] = '\0';
		if (left.len > right.len)p = 1;
		else if (left.len < right.len)p = 2;
		else for (i = 1; i < max_len; i++) {
			if (left.pCh[i] > right.pCh[i]) {
				p = 1;
				break;
			}
			if (left.pCh[i] < right.pCh[i]) {
				p = 2;
				break;
			}
		}
		if (p == 0) stroka_dec temp = "0";
		else if (p == 1) {
			for (i = 0; i < max_len; i++) {
				if (left.len - i - 1 > 0)temp_a[i] = left.pCh[left.len - i - 1];
				else temp_a[i] = '0';
				if (right.len - i - 1 > 0)temp_b[i] = right.pCh[right.len - i - 1];
				else temp_b[i] = '0';
				ch = (temp_a[i] - temp_b[i] - t + 10) % 10 + '0';
				t = temp_a[i] - temp_b[i] >= 0 ? 0 : 1;
				temp_a[i] = ch;
			}
			i = max_len - 1;
			while (temp_a[i] == '0')i--;
			new_len = i + 1;
			stroka_dec temp(new_len + 1);
			temp.pCh[j++] = '-';
			for (i = new_len - 1; i >= 0; i--)
				temp.pCh[j++] = temp_a[i];
			delete[] temp_a;
			delete[] temp_b;
			return temp;
		}
		else if (p == 2) {
			for (i = 0; i < max_len; i++) {
				if (right.len - i - 1 > 0)temp_a[i] = right.pCh[right.len - i - 1];
				else temp_a[i] = '0';
				if (left.len - i - 1 > 0)temp_b[i] = left.pCh[left.len - i - 1];
				else temp_b[i] = '0';
				ch = (temp_a[i] - temp_b[i] - t + 10) % 10 + '0';
				t = (temp_a[i] - temp_b[i] >= 0 ? 0 : 1);
				temp_a[i] = ch;
			}
			i = max_len - 1;
			while (temp_a[i] == '0')i--;
			new_len = i + 1;
			stroka_dec temp(new_len);
			for (i = new_len - 1; i >= 0; i--)
				temp.pCh[j++] = temp_a[i];
			delete[] temp_a;
			delete[] temp_b;
			return temp;
		}

	}
	else {
		max_len = max(left.len + 1, right.len + 1);
		temp_a = new char[max_len + 1];
		temp_a[max_len] = '\0';
		temp_b = new char[max_len + 1];
		temp_b[max_len] = '\0';
		if (left.len > right.len)p = 1;
		else if (left.len < right.len)p = 2;
		else for (i = 0; i < max_len; i++) {
			if (left.pCh[i] > right.pCh[i]) {
				p = 1;
				break;
			}
			if (left.pCh[i] < right.pCh[i]) {
				p = 2;
				break;
			}
		}
		if (p == 0) stroka temp = "0";
		else if (p == 1) {
			for (i = 0; i < max_len; i++) {
				if (left.len - i - 1 >= 0)temp_a[i] = left.pCh[left.len - i - 1];
				else temp_a[i] = '0';
				if (right.len - i - 1 >= 0)temp_b[i] = right.pCh[right.len - i - 1];
				else temp_b[i] = '0';
				ch = (temp_a[i] - temp_b[i] - t + 10) % 10 + '0';
				t = temp_a[i] - temp_b[i] >= 0 ? 0 : 1;
				temp_a[i] = ch;
			}
			i = max_len - 1;
			while (temp_a[i] == '0')i--;
			new_len = i + 1;
			stroka_dec temp(new_len);
			for (i = new_len - 1; i >= 0; i--)
				temp.pCh[j++] = temp_a[i];
			delete[] temp_a;
			delete[] temp_b;
			return temp;
		}
		else if(p == 2) {
			for (i = 0; i < max_len; i++) {
				if (right.len - i - 1 >= 0)temp_a[i] = right.pCh[right.len - i - 1];
				else temp_a[i] = '0';
				if (left.len - i - 1 >= 0)temp_b[i] = left.pCh[left.len - i - 1];
				else temp_b[i] = '0';
				ch = (temp_a[i] - temp_b[i] - t + 10) % 10 + '0';
				t = temp_a[i] - temp_b[i] >= 0 ? 0 : 1;
				temp_a[i] = ch;
			}
			i = max_len - 1;
			while (temp_a[i] == '0')i--;
			new_len = i + 1;
			stroka_dec temp(new_len + 1);
			temp.pCh[j++] = '-';
			for (i = new_len - 1; i >= 0; i--)
				temp.pCh[j++] = temp_a[i];
			delete[] temp_a;
			delete[] temp_b;
			return temp;
		}

	}
}



#include "stroka_id.h"
#include "stroka.h"
#include <string.h>
#include <iostream>

using namespace std;

int stroka_id::copy_stroka_id = 0;

stroka_id::stroka_id(int val) : stroka(val) {}
stroka_id::stroka_id(char ch) : stroka(ch) {
	if (!(pCh[0] >= 'a' && pCh[0] <= 'z' || pCh[0] >= 'A' && pCh[0] <= 'Z' || pCh[0] == '_'))
	{
		std::cout << "Некорректный идентификатор" << endl;
		delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
	}
}
stroka_id::stroka_id(const char* S) : stroka(S) {
	const char* keyword[] = { "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "char16_t", "char32_t", "class", "compl", "const", "constexpr", "const_cast", "continue", "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq" };
	int size = 84;
	if (!(pCh[0] >= 'a' && pCh[0] <= 'z' || pCh[0] >= 'A' && pCh[0] <= 'Z' || pCh[0] == '_'))
	{
		std::cout << "Некорректный идентификатор" << endl;
		delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
	}

	for (int i = 0; i < size; i++) {
		if (strcmp(pCh, keyword[i]) == 0) {
			std::cout << "Строка является ключевым словом" << pCh << endl;
			if (pCh) delete[]pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}
	for (int i = 0; i < len; i++)
		if (!(pCh[i] >= 'a' && pCh[0] <= 'z' || pCh[i] >= 'A' && pCh[i] <= 'Z' || pCh[i] == '_' || pCh[i] >= '0' && pCh[i] <= '9')) {
			std::cout << "Некорректный идентификатор" << endl;
			delete[] pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			break;
		}

}
stroka_id::stroka_id(const stroka_id& from) : stroka(from){copy_stroka_id ++;}

stroka_id::~stroka_id(){}



void stroka_id :: tolow(void) {
	for (int i = 0; i < len; i++)
		if (pCh[i] >= 'A' && pCh[i] <= 'Z')
			pCh[i] += 32;
}

stroka_id& stroka_id::operator = (const stroka_id& S) {
	*((stroka*)this) = (stroka)S;
	return *this;
}


stroka_id& stroka_id:: operator ~() {
	int i, j;
	char tmp;
	if ('0' <= pCh[len - 1] && pCh[len - 1] <= '9') {
		std::cout << "Недопустимый символ" << pCh[len - 1] << endl;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return *this;
	}
	for (i = 0, j = len - 1; i < len / 2; i++, j--) {
		tmp = pCh[i];
		pCh[i] = pCh[j];
		pCh[j] = tmp;
	}

	const char* keyword[] = { "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "char16_t", "char32_t", "class", "compl", "const", "constexpr", "const_cast", "continue", "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq" };
	int size = 84;

	for (int i = 0; i < size; i++) {
		if (strcmp(pCh, keyword[i]) == 0) {
			std::cout << "Реверсивная строка является ключевым словом " << pCh << endl;
			if (pCh) delete[]pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return *this;
		}
	}
	std::cout << "Реверс успещно выполнен:  ";
	return *this;
}

char& stroka_id::operator [] (int Index) {
	if (Index >= 0 && Index < len) return pCh[Index];
	else return pCh[0];
}

stroka_id operator - (const stroka_id& left, const stroka_id& right) {
	bool* not_sub = new bool[left.len];
	int i, j, new_len = left.len;
	for (i = 0; i < left.len; i++)not_sub[i] = true;
	for (i = 0; i < left.len; i++) {
		for (j = 0; j < right.len; j++) {
			if (left.pCh[i] == right.pCh[j]) {
				not_sub[i] = false;
				new_len--;
				break;
			}
		}
	}
	stroka_id temp(new_len);
	j = 0;
	for (i = 0; i < left.len; i++)
		if (not_sub[i]) {
			temp.pCh[j++] = left.pCh[i];
		}
	delete[] not_sub;
	return temp;
}

stroka_id operator - (const stroka_id& left, const char* right_pCh) {
	int right_len = strlen(right_pCh);
	bool* not_sub = new bool[left.len];
	int i, j, new_len = left.len;
	for (i = 0; i < left.len; i++)not_sub[i] = true;
	for (i = 0; i < left.len; i++) {
		for (j = 0; j < right_len; j++) {
			if (left.pCh[i] == right_pCh[j]) {
				not_sub[i] = false;
				new_len--;
				break;
			}
		}
	}
	stroka_id temp(new_len);
	j = 0;
	for (i = 0; i < left.len; i++)
		if (not_sub[i]) {
			temp.pCh[j++] = left.pCh[i];
		}
	delete[] not_sub;
	return temp;
}

stroka_id operator - (const char* left_pCh, const stroka_id& right) {
	int left_len = strlen(left_pCh);
	bool* not_sub = new bool[left_len];
	int i, j, new_len = left_len;
	for (i = 0; i < left_len; i++)not_sub[i] = true;
	for (i = 0; i < left_len; i++) {
		for (j = 0; j < right.len; j++) {
			if (left_pCh[i] == right.pCh[j]) {
				not_sub[i] = false;
				new_len--;
				break;
			}
		}
	}
	stroka_id temp(new_len);
	j = 0;
	for (i = 0; i < left_len; i++)
		if (not_sub[i]) {
			temp.pCh[j++] = left_pCh[i];
		}
	delete[] not_sub;
	return temp;
}
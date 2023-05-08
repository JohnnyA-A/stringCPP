#ifndef STROKA_ID_H
#define STROKA_ID_H

#include "stroka.h"

class stroka_id : public stroka {
private:
	static int copy_stroka_id;
public:
	stroka_id(int = 0);
	stroka_id(char);
	stroka_id(const char*);
	stroka_id(const stroka_id&);
	virtual ~stroka_id();
	void tolow(void);
	stroka_id& operator = (const stroka_id&);
	char& operator [] (int);
	stroka_id& operator ~();

	friend stroka_id operator - (const stroka_id&, const stroka_id&);
	friend stroka_id operator - (const stroka_id&, const char*);
	friend stroka_id operator - (const char*, const stroka_id&);
	friend void getCopy(int);
};


#endif STROKA_ID_H
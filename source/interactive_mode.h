#ifndef INTERACTIVE_MODE_H
#define INTERACTIVE_MODE_H

struct  position{
	int m_main = 0;
	int m_sub = 0;
};
void interactive_mode(void);
void show_current_strings(void);
void setNum(void);
void initVal(void);
void getLen(void);
void getStr(void);
void setAssign(int);
void setSub(int);
void setIdentToLow(void);
void getIdentIndex(void);
void checkNumLong(void);
bool ñorrectNum(void);
bool correctn(void);
bool correctInit(void);
bool correctType(int);
void getCopy(int);

#endif INTERACTIVE_MODE_H
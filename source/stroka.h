#ifndef STROKA_H
#define STROKA_H
class stroka {
private:
	static int copy_stroka;
protected:
	int len;
	char* pCh;
public:
	stroka(int = 0);
	stroka(char);
	stroka(const char*);
	stroka(const stroka&);
	~stroka();
	bool empty();
	char* get_str(void) const;
	int get_len(void) const;
	void Show();
	stroka& operator = (const stroka&);
	friend void getCopy(int);
};

#endif STROKA_H
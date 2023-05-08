#include "stroka.h"
#include "stroka_id.h"
#include "stroka_dec.h"
#include "interactive_mode.h"
#include <iostream>

using namespace std;

int N = 0, n = 0; // N - ����� ���������, n - ����� �������� ��������
stroka** object;  // ������ �����
int* objectType;   

void interactive_mode(void) {
	position pos = { 0,0 };
	while (true) {
		system("cls");
		show_current_strings();
		switch (pos.m_main) {
		case 0: // ������� ����
			std::cout << "(1)��������������" << endl;
			std::cout << "(2)T�����������" << endl;
			std::cout << "(3)�����" << endl;
			break;
		case 1: // �������������
			std::cout << "(0)���������" << endl;
			std::cout << "(1)����� ���������" << endl;
			std::cout << "(2)��������� �������" << endl;
			break;
		case 2: // ������������
			switch (pos.m_sub) {
			case 0: // ���� ������������
				std::cout << "(0)���������" << endl;
				std::cout << "(1)������_�������������" << endl;
				std::cout << "(2)����������_������" << endl;
				std::cout << "(3)�������� ����� ������" << endl;
				std::cout << "(4)�������� ������" << endl;
				std::cout << "(5)������ ���������� ������� ������������ �����������" << endl;
				break;
			case 1: // ������������ ������ ������_�������������
				std::cout << "(0)���������" << endl;
				std::cout << "(1)������� ���� �������� ������ (����� ����) � ������ �������" << endl;
				std::cout << "(2)�������� ���������� (����� ��������)" << endl;
				std::cout << "(3)�������� ������������" << endl;
				std::cout << "(4)��������� �����" << endl;
				break;
			case 2: // ������������ ������ ����������_������
				std::cout << "(0)���������" << endl;
				std::cout << "(1)�������� ������������" << endl;
				std::cout << "(2)�������������� ���������" << endl;
				std::cout << "(3)���������, ����� �� ����� ����������� ����� long" << endl;
				break;
			case 5: // ���������� ������ ������������ �����������
				std::cout << "(0)���������" << endl;
				std::cout << "(1)���������� ������� ������������ ����������� ������ ������" << endl;
				std::cout << "(2)���������� ������� ������������ ����������� ������ ������_�������������" << endl;
				std::cout << "(3)���������� ������� ������������ ����������� ������ ����������_������" << endl;
				break;
			}

			break;
		case 3: // �����
			return;
			break;
		}


		int choise;
		try {
			std::cin >> choise;
		}
		catch(int){
			std::cout << "�� ����� ������������ �����";
			system("pause");
			continue;
		}
		switch (pos.m_main) {
		case 0: // ������� ����
			switch (choise) {
			case 1:
				pos.m_main = 1;
				continue;
				break;
			case 2:
				pos.m_main = 2;
				continue;
				break;
			case 3:
				pos.m_main = 3;
				continue;
				break;
			
			default:
				continue;
				break;
			}

		case 1: // �������������
			switch (choise) {
			case 0:
				pos = { 0, 0 };
				continue;
				break;
			case 1:
				setNum();
				continue;
				break;
			case 2:
				initVal();
				continue;
				break;
			default:
				std::cout << "�������� ������� ���� �� ������������ �������" << endl;
				system("pause");
			}
			break;
		case 2: // ������������
			switch (pos.m_sub) {
			case 0:
				switch (choise) {
				case 0:
					pos = { 0, 0 };
					continue;
					break;
				case 1:
					pos.m_sub = 1;
					continue;
					break;
				case 2:
					pos.m_sub = 2;
					continue;
					break;
				case 3:
					getLen();
					continue;
					break;
				case 4:
					getStr();
					continue;
					break;
				case 5:
					pos.m_sub = 5;
					continue;
					break;
				default:
					std::cout << "�������� ������� ���� �� ����������� �������" << endl;
					system("pause");
				}
				break;
			case 1: // ������������ ������ ������_�������������
				switch (choise) {
				case 0:
					pos = { 2, 0 };
					continue;
					break;
				case 1:
					setIdentToLow();
					continue;
					break;
				case 2:
					getIdentIndex();
					continue;
					break;
				case 3:
					setAssign(1);
					continue;
					break;
				case 4:
					setSub(1);
					continue;
					break;
				default:
					std::cout << "�������� ������� ���� �� ����������� �������" << endl;
					system("pause");
				}
				break;
			case 2: // ������������ ������ ����������_������
				switch (choise) {
				case 0:
					pos = { 2, 0 };
					continue;
					break;
				case 1:
					setAssign(2);
					continue;
					break;
				case 2:
					setSub(2);
					continue;
					break;
				case 3:
					checkNumLong();
					continue;
					break;
				default:
					std::cout << "�������� ������� ���� �� ����������� �������" << endl;
					system("pause");
				}
				break;
			case 5: // ���������� ������� ������������ �����������
				switch (choise) {
				case 0:
					pos = { 2, 0 };
					continue;
					break;
				case 1:
					getCopy(1);
					continue;
					break;
				case 2:
					getCopy(2);
					continue;
					break;
				case 3:
					getCopy(3);
					continue;
					break;
				default:
					std::cout << "�������� ������� ���� �� ����������� �������" << endl;
					system("pause");
				}
				break;
			}
			break;
		default:
			continue;
			break;
		}


	}
}






void setNum(void) {
	if (N != 0) {
		std::cout << "����� ��������� ��� ����������" << endl;
		system("pause");
		return;
	}
	std::cout << "������� ����� ���������(1 <= N <= 6): " ;
	std::cin >> N;
	if (N < 1 || N > 6) {
		N = 0;
		std::cout << "���������� ������ ���������� ����� ���������" << endl;
		system("pause");
		return;
	}
	object = new stroka*[N] {};
	objectType = new int[N] {};
	for (int i = 0; i < N; i++) objectType[i] = 0;
}

void initVal(void) {
	if (!�orrectNum())return;
	std::cout << "������� ����� �������: " ;
	std::cin >> n;
	if (!correctn())return;
	n--;
	int n1 = n;
	int choise1;
	std::cout << "(1)���������� ������ �� ��� ���������������������� �������" << endl;
	std::cout << "(2)������ ����� ������" << endl;
	std::cin >> choise1;
	switch (choise1) {
	case 1:
		std::cout << "������� ����� ������������������� �������: ";
		std::cin >> n;
		if (!correctn())return;
		n--;
		if (!correctInit())return;
		if (objectType[n] == 1) {
			object[n1] = new stroka_id(*((stroka_id*)(object[n])));
			objectType[n1] = 1;
		}
		if (objectType[n] == 2) {
			object[n1] = new stroka_dec(*((stroka_dec*)(object[n])));
			objectType[n1] = 2;
		}
		std::cout << "�������� ��������� �������" << endl;
		break;
	case 2:
		int choiseClass;
		std::cout << "(1)C�����_�������������" << endl;
		std::cout << "(2)����������_������" << endl;
		std::cin >> choiseClass;
		char buf[256];
		switch (choiseClass) {
		case 1:
			std::cout << "������� ��������������: ";
			std::cin.ignore();
			std::cin.getline(buf, 256);
			object[n] = new stroka_id(buf);
			objectType[n] = 1;
			std::cout << "�������� ��������� �������" << endl;
			break;
		case 2:
			std::cout << "������� ���������� �����: ";
			std::cin.ignore();
			std::cin.getline(buf, 256);
			object[n] = new stroka_dec(buf);
			objectType[n] = 2;
			std::cout << "�������� ��������� �������" << endl;
			break;
		default:
			std::cout << "���������� ������� ���� �� ����������� �������" << endl;
		}
		break;
	default:
		std::cout << "���������� ������� ���� �� ����������� �������" << endl;
	}
	
	system("pause");
}

void getLen(void) {
	if (!�orrectNum())return;
	std::cout << "������� ����� �������: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	std::cout << "����� ������ �" << n + 1 << " : " << object[n]->get_len() << endl;
	system("pause");
}

void getStr(void) {
	if (!�orrectNum())return;
	std::cout << "������� ����� �������: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	std::cout << "������ �" << n + 1 << " : " << object[n]->get_str() << endl;
	system("pause");
}

void setAssign(int type) {
	if (!�orrectNum())return;
	std::cout << "������� ����� ��������1: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(type))return;
	int n1 = n;
	std::cout << "������� ����� ��������2: " << endl;
	std::cin >> n;
	n--;
	if (!correctInit())return;
	if (!correctType(type))return;
	int n2 = n;
	if (type == 1) *(((stroka_id*)object[n1])) = *(((stroka_id*)object[n2]));
	if (type == 2) *(((stroka_dec*)object[n1])) = *(((stroka_dec*)object[n2]));
	std::cout << "�������� ��������� �������" << endl;
	system("pause");
}

void setSub(int type) {
	if (!�orrectNum())return;
	std::cout << "������� ����� ��������1: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(type))return;
	int n1 = n;
	std::cout << "������� ����� ��������2: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(type))return;
	int n2 = n;
	std::cout << "�������� ����� �������, � ������� �������� ��������" << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(type))return;
	if (type == 1) *(((stroka_id*)object[n])) = *(((stroka_id*)object[n1])) - *(((stroka_id*)object[n2]));
	if (type == 2)* (((stroka_dec*)object[n])) = *(((stroka_dec*)object[n1])) - *(((stroka_dec*)object[n2]));
	std::cout << "�������� ��������� �������" << endl;
	system("pause");
}

void setIdentToLow(void) {
	if (!�orrectNum())return;
	std::cout << "������� ����� �������: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(1))return;
	((stroka_id*)object[n])->tolow();
	std::cout << "�������� ��������� �������" << endl;
	system("pause");

}

void getIdentIndex(void) {
	if (!�orrectNum())return;
	std::cout << "������� ����� �������: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(1))return;
	int index = 0;
	std::cout << "�������� ����� �������� ��������������" << endl;
	std::cin >> index;
	std::cout << "������� �" << index << " : " << (*((stroka_id*)object[n]))[index - 1] << endl;
	system("pause");
}

void checkNumLong(void) {
	if (!�orrectNum())return;
	std::cout << "������� ����� ��������1: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(2))return;
	if ((((stroka_dec*)object[n]))->is_long())
		std::cout << "����� ����� ����������� ����� long" << endl;
	else std::cout << "����� ������ ����������� ����� long" << endl;
	system("pause");
}

void getCopy(int c) {
	if (c == 1)
		std::cout << "���������� ������� ������������ ����������� ������ ������ : " 
			 << stroka::copy_stroka << endl;
	if(c == 2)
		std::cout << "���������� ������� ������������ ����������� ������ ������_������������� : "
		<< stroka_id::copy_stroka_id << endl;
	if (c == 3)
		std::cout << "���������� ������� ������������ ����������� ������ ����������_������ : "
		<< stroka_dec::copy_stroka_dec << endl;
	//std::cout << "�������� ��������� �������" << endl;
	//system("pause");
}
 

bool �orrectNum(void) {
	if (N == 0) {
		std::cout << "��� ������ ���������� ������ ����� ���������" << endl;
		system("pause");
		return false;
	}
	return true;
}

bool correctn(void) {
	if (n < 1 || n > N) {
		std::cout << "���������� ������ ���������� ����� �������" << endl;
		system("pause");
		return false;
	}
	return true;
}

bool correctInit(void) {
	if (objectType[n] == 0) {
		std::cout << "���������� ������� ������������������ ������" << endl;
		system("pause");
		return false;
	}
	return true;
}

bool correctType(int type) {
	if (objectType[n] != type) {
		if (type == 1) std::cout << "���������� ������� �������������, � �� �����" << endl;
		if (type == 2) std::cout << "���������� ������� �����, � �� �������������" << endl;
		system("pause");
		return false;
	}
	return true;
	return true;
}


void show_current_strings() {
	if ((N > 0)){
		std::cout << "########################################################################" << endl;
		for (int i = 0; i < N; i++) {
			if (object[i]){
				std::cout << object[i]->get_str() << "\t##\t";
			}
				

		}
		std::cout << endl;
		std::cout << "########################################################################" << endl;

	}
}

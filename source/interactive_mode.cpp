#include "stroka.h"
#include "stroka_id.h"
#include "stroka_dec.h"
#include "interactive_mode.h"
#include <iostream>

using namespace std;

int N = 0, n = 0; // N - число элементов, n - номер текущего элемента
stroka** object;  // Массив строк
int* objectType;   

void interactive_mode(void) {
	position pos = { 0,0 };
	while (true) {
		system("cls");
		show_current_strings();
		switch (pos.m_main) {
		case 0: // главное меню
			std::cout << "(1)Иннициализация" << endl;
			std::cout << "(2)Tестирование" << endl;
			std::cout << "(3)Выход" << endl;
			break;
		case 1: // инициализация
			std::cout << "(0)Вернуться" << endl;
			std::cout << "(1)Число элементов" << endl;
			std::cout << "(2)Начальное значние" << endl;
			break;
		case 2: // тестирование
			switch (pos.m_sub) {
			case 0: // меню тестирование
				std::cout << "(0)Вернуться" << endl;
				std::cout << "(1)СТРОКА_ИДЕНТИФИКАТОР" << endl;
				std::cout << "(2)ДЕСЯТИЧНАЯ_СТРОКА" << endl;
				std::cout << "(3)Получить длину строки" << endl;
				std::cout << "(4)Получить строку" << endl;
				std::cout << "(5)Узнать количество вызовов конструктора копирования" << endl;
				break;
			case 1: // тестирование класса Строка_Идентивикатор
				std::cout << "(0)Вернуться" << endl;
				std::cout << "(1)Перевод всех символов строки (кроме цифр) в нижний регистр" << endl;
				std::cout << "(2)Оператор индексации (Выбор элемента)" << endl;
				std::cout << "(3)Оператор присваивания" << endl;
				std::cout << "(4)Вычитание строк" << endl;
				break;
			case 2: // тестирование класса Десятичная_строка
				std::cout << "(0)Вернуться" << endl;
				std::cout << "(1)Оператор присваивания" << endl;
				std::cout << "(2)Арифметическое вычитание" << endl;
				std::cout << "(3)Проверить, можно ли число представить типом long" << endl;
				break;
			case 5: // количество вызово конструктора копирования
				std::cout << "(0)Вернуться" << endl;
				std::cout << "(1)количество вызовов конструктора копирования класса СТРОКА" << endl;
				std::cout << "(2)количество вызовов конструктора копирования класса СТРОКА_ИДЕНТИФИКАТОР" << endl;
				std::cout << "(3)количество вызовов конструктора копирования класса ДЕСЯТИЧНАЯ_СТРОКА" << endl;
				break;
			}

			break;
		case 3: // выход
			return;
			break;
		}


		int choise;
		try {
			std::cin >> choise;
		}
		catch(int){
			std::cout << "Вы ввели некорректный номер";
			system("pause");
			continue;
		}
		switch (pos.m_main) {
		case 0: // главное меню
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

		case 1: // инициализация
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
				std::cout << "Попробуй выбрать один из предложенных пунктов" << endl;
				system("pause");
			}
			break;
		case 2: // тестирование
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
					std::cout << "Попробуй выбрать один из преложенных пунктов" << endl;
					system("pause");
				}
				break;
			case 1: // тестирование класса СТРОКА_ИДЕНТИФИКАТОР
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
					std::cout << "Попробуй выбрать один из преложенных пунктов" << endl;
					system("pause");
				}
				break;
			case 2: // тестирование класса ДЕСЯТИЧНАЯ_СТРОКА
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
					std::cout << "Попробуй выбрать один из преложенных пунктов" << endl;
					system("pause");
				}
				break;
			case 5: // количество вызовов конструктора копирования
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
					std::cout << "Попробуй выбрать один из преложенных пунктов" << endl;
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
		std::cout << "Число элементов уже определено" << endl;
		system("pause");
		return;
	}
	std::cout << "Введите число элементов(1 <= N <= 6): " ;
	std::cin >> N;
	if (N < 1 || N > 6) {
		N = 0;
		std::cout << "Попробуйте ввести корректное число элементов" << endl;
		system("pause");
		return;
	}
	object = new stroka*[N] {};
	objectType = new int[N] {};
	for (int i = 0; i < N; i++) objectType[i] = 0;
}

void initVal(void) {
	if (!сorrectNum())return;
	std::cout << "Введите номер объекта: " ;
	std::cin >> n;
	if (!correctn())return;
	n--;
	int n1 = n;
	int choise1;
	std::cout << "(1)Копировать строку из уже проинициализированного объекта" << endl;
	std::cout << "(2)Ввести новую строку" << endl;
	std::cin >> choise1;
	switch (choise1) {
	case 1:
		std::cout << "Введите номер инициализированного объекта: ";
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
		std::cout << "Операция выполнена успешно" << endl;
		break;
	case 2:
		int choiseClass;
		std::cout << "(1)CТРОКА_ИДЕНТИФИКАТОР" << endl;
		std::cout << "(2)ДЕСЯТИЧНАЯ_СТРОКА" << endl;
		std::cin >> choiseClass;
		char buf[256];
		switch (choiseClass) {
		case 1:
			std::cout << "Введите индентификатор: ";
			std::cin.ignore();
			std::cin.getline(buf, 256);
			object[n] = new stroka_id(buf);
			objectType[n] = 1;
			std::cout << "Операция выполнена успешно" << endl;
			break;
		case 2:
			std::cout << "Введите десятичное число: ";
			std::cin.ignore();
			std::cin.getline(buf, 256);
			object[n] = new stroka_dec(buf);
			objectType[n] = 2;
			std::cout << "Операция выполнена успешно" << endl;
			break;
		default:
			std::cout << "Попробуйте выбрать один из преложенных пунктов" << endl;
		}
		break;
	default:
		std::cout << "Попробуйте выбрать один из преложенных пунктов" << endl;
	}
	
	system("pause");
}

void getLen(void) {
	if (!сorrectNum())return;
	std::cout << "Введите номер объекта: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	std::cout << "Длина строки №" << n + 1 << " : " << object[n]->get_len() << endl;
	system("pause");
}

void getStr(void) {
	if (!сorrectNum())return;
	std::cout << "Введите номер объекта: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	std::cout << "Строка №" << n + 1 << " : " << object[n]->get_str() << endl;
	system("pause");
}

void setAssign(int type) {
	if (!сorrectNum())return;
	std::cout << "Введите номер операнда1: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(type))return;
	int n1 = n;
	std::cout << "Введите номер операнда2: " << endl;
	std::cin >> n;
	n--;
	if (!correctInit())return;
	if (!correctType(type))return;
	int n2 = n;
	if (type == 1) *(((stroka_id*)object[n1])) = *(((stroka_id*)object[n2]));
	if (type == 2) *(((stroka_dec*)object[n1])) = *(((stroka_dec*)object[n2]));
	std::cout << "Операция выполнена успешно" << endl;
	system("pause");
}

void setSub(int type) {
	if (!сorrectNum())return;
	std::cout << "Введите номер операнда1: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(type))return;
	int n1 = n;
	std::cout << "Введите номер операнда2: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(type))return;
	int n2 = n;
	std::cout << "Выберите номер объекта, в который записать разность" << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(type))return;
	if (type == 1) *(((stroka_id*)object[n])) = *(((stroka_id*)object[n1])) - *(((stroka_id*)object[n2]));
	if (type == 2)* (((stroka_dec*)object[n])) = *(((stroka_dec*)object[n1])) - *(((stroka_dec*)object[n2]));
	std::cout << "Операция выполнена успешно" << endl;
	system("pause");
}

void setIdentToLow(void) {
	if (!сorrectNum())return;
	std::cout << "Введите номер объекта: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(1))return;
	((stroka_id*)object[n])->tolow();
	std::cout << "Операция выполнена успешно" << endl;
	system("pause");

}

void getIdentIndex(void) {
	if (!сorrectNum())return;
	std::cout << "Введите номер объекта: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(1))return;
	int index = 0;
	std::cout << "Выберите номер элемента идентификатора" << endl;
	std::cin >> index;
	std::cout << "Элемент №" << index << " : " << (*((stroka_id*)object[n]))[index - 1] << endl;
	system("pause");
}

void checkNumLong(void) {
	if (!сorrectNum())return;
	std::cout << "Введите номер операнда1: " << endl;
	std::cin >> n;
	if (!correctn())return;
	n--;
	if (!correctInit())return;
	if (!correctType(2))return;
	if ((((stroka_dec*)object[n]))->is_long())
		std::cout << "Число можно представить типом long" << endl;
	else std::cout << "Число нельзя представить типом long" << endl;
	system("pause");
}

void getCopy(int c) {
	if (c == 1)
		std::cout << "количество вызовов конструктора копирования класса СТРОКА : " 
			 << stroka::copy_stroka << endl;
	if(c == 2)
		std::cout << "количество вызовов конструктора копирования класса СТРОКА_ИДЕНТИФИКАТОР : "
		<< stroka_id::copy_stroka_id << endl;
	if (c == 3)
		std::cout << "количество вызовов конструктора копирования класса ДЕСЯТИЧНАЯ_СТРОКА : "
		<< stroka_dec::copy_stroka_dec << endl;
	//std::cout << "Операция выполнена успешно" << endl;
	//system("pause");
}
 

bool сorrectNum(void) {
	if (N == 0) {
		std::cout << "Для начала попробуйте ввести число элементов" << endl;
		system("pause");
		return false;
	}
	return true;
}

bool correctn(void) {
	if (n < 1 || n > N) {
		std::cout << "Попробуйте ввести корректный номер объекта" << endl;
		system("pause");
		return false;
	}
	return true;
}

bool correctInit(void) {
	if (objectType[n] == 0) {
		std::cout << "Попробуйте выбрать инициализированный объект" << endl;
		system("pause");
		return false;
	}
	return true;
}

bool correctType(int type) {
	if (objectType[n] != type) {
		if (type == 1) std::cout << "Попробуйте выбрать идентификатор, а не число" << endl;
		if (type == 2) std::cout << "Попробуйте выбрать число, а не идентификатор" << endl;
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

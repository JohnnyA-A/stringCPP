#include "stroka.h"
#include "stroka_id.h"
#include "stroka_dec.h"
#include "interactive_mode.h"
#include <iostream>
#include <string.h>

extern "C" int _stdcall asm_fun(int, int);
extern "C" char* _stdcall asm_fun1(int);
void easy_way();
void asm_vstavka();

int main() {
	setlocale(LC_ALL, "rus");

	while (true) {
	system("cls");
	std::cout << "(1) Упрощенный вариант\n(2) Интерактивный режим\n(3) Ассемблерная вставка\n(9) Выход\n";
	std::cout << "##################################################" << endl;
	std::cout << "Выберите номер из предложенных вариантов :   ";
	int choice;
	std::cin >> choice;
	if ((std::cin.fail() == 1) || (std::cin.get() != '\n')  ) {
		std::cin.sync();
		std::cin.clear();
		std::cin.sync();
		continue;
	}


	switch (choice) {
		case 1:
			easy_way();
			break;
		case 2:
			interactive_mode();
			break;
		case 3:
			asm_vstavka();
			break;
		case 9: 
			return 0;
		default:
			continue;
		}
	}

	return 0;
}


void easy_way() {
	system("cls");
	stroka** ptr;
	ptr = new stroka * [5];
	ptr[0] = new stroka("simple_stroka");
	ptr[1] = new stroka_id("tni");
	ptr[2] = new stroka_id("IdENT");
	ptr[3] = new stroka_dec("+123123123");
	ptr[4] = new stroka_dec("-123211");

	std::cout << "Строка 1: " << ptr[0]->get_str() << endl;
	std::cout << "Строка 2: " << ptr[1]->get_str() << endl;
	std::cout << "Строка 3: " << ptr[2]->get_str() << endl;
	std::cout << "Строка 4: " << ptr[3]->get_str() << endl;
	std::cout << "Строка 5: " << ptr[4]->get_str() << endl;

	// Тестирование базового класса строка
	std::cout << "Проверка, пуста ли строка: " << ptr[0]->empty() << endl;
	std::cout << "Длина строки 1: " << ptr[0]->get_len() << endl;
	std::cout << "Создаем копию строки 1" << endl;
	stroka* ptr_copy0;
	ptr_copy0 = new stroka(*ptr[0]);
	getCopy(1);
	std::cout << endl;

	// Тестирование класса СТРОКА_ИДЕНТИФИКАТОР
	std::cout << "Переводим строку 2 в нижний регистр: ";
	((stroka_id*)ptr[1])->tolow();
	std::cout << ptr[1]->get_str() << endl;

	std::cout << "Выполняем реверс 2 строки: " << endl;
	~(* (stroka_id*)ptr[1]);
	std::cout << ptr[1]->get_str() << endl;


	std::cout << "Переводим строку 3 в нижний регистр: ";
	((stroka_id*)ptr[2])->tolow();
	std::cout << ptr[2]->get_str() << endl;

	std::cout << "Вычитаем из строки 2 строку 3 и записываем в строку 2: ";
	*(((stroka_id*)ptr[1])) = *(((stroka_id*)ptr[1])) - *(((stroka_id*)ptr[2]));
	std::cout << ptr[1]->get_str() << endl;

	std::cout << "3 элемент в новой строке 2: " << (*((stroka_id*)ptr[1]))[2] << endl;

	stroka_id* ptr_copy1, * ptr_copy2, * ptr_copy3;
	std::cout << "Создаем копию строки 2" << endl;
	ptr_copy1 = new stroka_id(*((stroka_id*)(ptr[1])));
	std::cout << "Создаем 2 копии строки 3" << endl;;
	ptr_copy2 = new stroka_id(*((stroka_id*)(ptr[2])));
	ptr_copy3 = new stroka_id(*((stroka_id*)(ptr[2])));
	getCopy(2);
	std::cout << endl;

	// Тестирование класса ДЕСЯТИЧНАЯ_СТРОКА
	std::cout << "Проверяем, можно ли представить данное число в строке 4 в формате long:  " << ((stroka_dec*)ptr[3])->is_long() << endl;
	std::cout << "Проверяем, можно ли представить данное число в строке 5 в формате long:  " << ((stroka_dec*)ptr[4])->is_long() << endl;
	std::cout << "Вычитаем из числа в строке 4 число в строке 5 и записываем в строку 4:  ";
	*((stroka_dec*)ptr[3]) = *((stroka_dec*)ptr[3]) - *((stroka_dec*)ptr[4]);
	std::cout << ptr[3]->get_str() << endl;
	stroka_dec* ptr_copy4, * ptr_copy5, * ptr_copy6;
	std::cout << "Создаем 2 копии строки 4" << endl;
	ptr_copy4 = new stroka_dec(*((stroka_dec*)(ptr[3])));
	ptr_copy5 = new stroka_dec(*((stroka_dec*)(ptr[3])));
	std::cout << "Создаем копию строки 5" << endl;
	ptr_copy6 = new stroka_dec(*((stroka_dec*)(ptr[4])));
	getCopy(3);
	std::cout << endl;

	std::cout << "Удаление всех копий" << endl;
	delete ptr_copy0, ptr_copy1, ptr_copy2, ptr_copy3, ptr_copy4, ptr_copy5, ptr_copy6;
	std::cout << "Удаление массива указателей на базовый класс" << endl;
	delete[] ptr;
	


	std::cout << "new" << endl << endl;
	stroka_id *obj1;
	obj1 = new stroka_id("3ITMO");
	obj1[0] = 'x';
	obj1->Show();

	
	stroka_dec *obj2, *obj3;
	obj2 = new stroka_dec("2255");
	obj3 = new stroka_dec("65536");

	
	std::cout << "Сумма чисел: " << *obj2 + *obj3 << endl;

	stroka_dec* obj4, *obj5;
	obj4 = new stroka_dec();
	obj5 = new stroka_dec();
	std::cout << "Сумма других чисел:  " << *obj4 + *obj5<< endl;


	int some_nmb(0);
	obj4 = obj4 + 0;
	std::cout << "Третья сумма: ";
	obj4->Show();


	stroka_dec *obj6;
	obj5 = new stroka_dec("255");
	obj6 = new stroka_dec("105");
	stroka_dec *obj7 = new stroka_dec(*obj5 + *obj6);
	~(*obj7);
	*obj5 = stroka_dec(*obj5 + *obj6);
	obj7->Show();



	system("pause");

}


void asm_vstavka()
{
	system("cls");
	std::cout << " >> Ассемблерная вставка 1\nВведите 2 числа x y: ";
	int x, y;
	std::cin >> x >> y;
	std::cout << asm_fun(x, y) << endl;

	std::cout << " >> Ассемблерная вставка 2\nВведите число: ";
	std::cin >> x;
	std::cout << asm_fun1(x) << endl;
	system("pause");
}
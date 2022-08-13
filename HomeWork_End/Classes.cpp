#include "Classes.h"
#include "Func.h"

void Screen::ScreenShow() {	//функция вывода на экран класса Screen
	cout << "***********************************************************************************" << endl;
	cout << "*                 Э К З А М Е Н А Ц И О Н Н А Я   Р А Б О Т А                     *" << endl;
	cout << "*     по объектно-ориентированному программированию с использованием языка С++    *" << endl;
	cout << "*          студент: Круталевич А.И., группа: П43018, курс 'ОСЕНЬ 2020 ЕКО'        *" << endl;
	cout << "***********************************************************************************" << endl;
}

void steel::set_d(float d_steel) { d = d_steel; } // Сеттер для переменной диаметра отпечатка
void steel::set_HB(double p_HB) { HB = p_HB; }	  // Сеттер для переменной твердости по Бринеллю

void steel::choise_steel_type() { //Метод класса steel для выбора типов стали и запуска функции для их расчетов
	int steel_type;
	double loc_HB;
	steel_type = menu_choise_steel_type();	//Выбор типа стали
	switch (steel_type){	//Анализ типа стали
	case 1:
		cout << "\nРезультат исследования" << endl;
		cout << "----------------------------------" << endl;
		cout << "Выбран материал: Сталь 20 (0.2% C)" << endl;
		setshow_steel("20 (0.2% C)");
		steel::set_d(4.5);
		loc_HB = steel_calculation(steel::get_d());
		steel::set_HB(loc_HB);
		break;
	case 2:
		cout << "\nРезультат исследования" << endl;
		cout << "-----------------------------------" << endl;
		cout << "Выбран материал: Сталь 45 (0.45% C)" << endl;
		setshow_steel("45 (0.45% C)");
		steel::set_d(4.3);
		loc_HB = steel_calculation(steel::get_d());
		steel::set_HB(loc_HB);
		break;
	case 3:
		cout << "\nРезультат исследования" << endl;
		cout << "----------------------------------" << endl;
		cout << "Выбран материал: Сталь 98 (0.8% C)" << endl;
		setshow_steel("98 (0.8% C)");
		steel::set_d(3.87);
		loc_HB = steel_calculation(steel::get_d());
		steel::set_HB(loc_HB);
		break;
	default:
		break;
	}
}

ostream& operator <<(ostream& out, const steel& w) {	//Перегрузка оператора вывода для класса steel
	out << "Параметры расчета:" << endl;
	out << " - Давление пресса P = " << P << " кг" << endl;
	out << " - Диаметр шарика D = " << D << " мм" << endl;
	out << " - Диаметр отпечатка на испытуемой поверхности d = " << w.get_d() << " мм" << endl;
	out << "Результат расчета:" << endl;
	out << " - твердость Cтали " << w.show_steel << " по Бринеллю HB = " << w.get_HB() << endl << endl;
	out << "------------------------------------------------" << endl;
	out << "Результат исследования сохранен в файл " << file_res << endl;
	return out;
}
ostream& operator <<(ostream& out, const aluminum& w) {	//Перегрузка оператора вывода для класса aluminum
	out << "\nРезультат исследования" << endl;
	out << "------------------------------------------------" << endl;
	out << "Выбран материал: Алюминий" << endl;
	out << "Параметры расчета:" << endl;
	out << " - Давление пресса P = " << P_alum << " кг" << endl;
	out << " - Диаметр шарика D = " << D << " мм" << endl;
	out << " - Диаметр отпечатка на испытуемой поверхности d = " << w.get_d() << " мм" << endl;
	out << "Результат расчета:" << endl;
	out << " - твердость Алюминия по Бринеллю HB = " << w.get_HB() << endl << endl;
	out << "------------------------------------------------" << endl;
	out << "Результат исследования сохранен в файл " << file_res << endl;
	return out;
}
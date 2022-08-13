#pragma once
#include "Libs.h"

class Screen {
public:
	Screen() { ScreenShow(); }	//конструктор по умолчанию класса Screen
	~Screen() {  }	//деструктор класса Screen
	void ScreenShow();	//определение идентификатора функции ScreenShow()
};

class steel {	// Класс steel (сталь)
	double d = 0;
	double HB;
	string show_steel;
public:
	steel() {choise_steel_type();}
	~steel() {}

	void choise_steel_type();
	void setshow_steel(string p_st) { show_steel = p_st; }
	void set_d(float d_steel = 0);
	void set_HB(double p_HB = 0);
	double get_HB() const { return HB; }
	double get_d() const { return d; }
	string getshow_steel() { return show_steel; }
	
	void write_Res() {	// метод записи результатов в файл (класс steel)
		string str;
		ofstream file; // открываем файл
		file.open(file_res, ios::app);

		if (!file.is_open()) {
			cout << "Файл не может быть открыт!\n";
		}
		else
		{
			file << "----------------------------------------------------------------------" << endl;
			file << "Дата исследования: ";

			time_t t = time(0);
			tm* now = localtime(&t);
			file << now->tm_mday << '.'
				<< (now->tm_mon + 1) << '.'
				<< (now->tm_year + 1900) << ' '
				<< now->tm_hour << ':'
				<< now->tm_min << ':'
				<< now->tm_sec
				<< "\n";

			file << "Исследуемый материал: Сталь " << getshow_steel() << endl;
			file << "Параметры расчета:" << endl;
			file << " - Давление пресса P = " << P << " кг" << endl;
			file << " - Диаметр шарика D = " << D << " мм" << endl;
			file << " - Диаметр отпечатка на испытуемой поверхности d = " << get_d() << " мм" << endl;
			file << "Результат расчета:" << endl;
			file << " - твердость Cтали " << show_steel << " по Бринеллю HB = " << get_HB() << endl << endl;
			file << endl;
			file.close();
		}
	}

	friend ostream& operator <<(ostream&, const steel&); //Дружественная функция для перегрузки вывода
};

class aluminum {	// Класс aluminum (алюминий)
	double d = 3.24;
	double HB;
public:
	aluminum() { HB = aluminum_calculation(d); }
	~aluminum() {}

	double aluminum_calculation(double d) {	//функция расчета твердости по Бринеллю для алюминия
		double calcHB = 0;
		double S;
		double D_calc = pow(D, 2);
		double d_calc = pow(d, 2);
		double root;
		double calc_S;
		double calc_P = 2 * P_alum;

		root = sqrt(D_calc - d_calc);
		calc_S = D - root;
		S = PI * D * calc_S;
		calcHB = calc_P / S;
		return calcHB;
	}
	double get_HB() const { return HB; }
	double get_d() const { return d; }

	void write_ResA() {	// метод записи результатов в файл (класс aluminum)
		string str;
		ofstream file; // открываем файл
		file.open(file_res, ios::app);

		if (!file.is_open()) {
			cout << "Файл не может быть открыт!\n";
		}
		else
		{
			file << "----------------------------------------------------------------------" << endl;
			file << "Дата исследования: ";

			time_t t = time(0);
			tm* now = localtime(&t);
			file << now->tm_mday << '.'
				<< (now->tm_mon + 1) << '.'
				<< (now->tm_year + 1900) << ' '
				<< now->tm_hour << ':'
				<< now->tm_min << ':'
				<< now->tm_sec
				<< "\n";

			file << "Исследуемый материал: Алюминий" << endl;
			file << "Параметры расчета:" << endl;
			file << " - Давление пресса P = " << P_alum << " кг" << endl;
			file << " - Диаметр шарика D = " << D << " мм" << endl;
			file << " - Диаметр отпечатка на испытуемой поверхности d = " << get_d() << " мм" << endl;
			file << "Результат расчета:" << endl;
			file << " - твердость Алюминия по Бринеллю HB = " << get_HB() << endl << endl;
			file << endl;
			file.close();
		}
	}

	friend ostream& operator << (ostream&, const aluminum&);	//Дружественная функция для перегрузки вывода
};
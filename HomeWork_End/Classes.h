#pragma once
#include "Libs.h"

class Screen {
public:
	Screen() { ScreenShow(); }	//����������� �� ��������� ������ Screen
	~Screen() {  }	//���������� ������ Screen
	void ScreenShow();	//����������� �������������� ������� ScreenShow()
};

class steel {	// ����� steel (�����)
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
	
	void write_Res() {	// ����� ������ ����������� � ���� (����� steel)
		string str;
		ofstream file; // ��������� ����
		file.open(file_res, ios::app);

		if (!file.is_open()) {
			cout << "���� �� ����� ���� ������!\n";
		}
		else
		{
			file << "----------------------------------------------------------------------" << endl;
			file << "���� ������������: ";

			time_t t = time(0);
			tm* now = localtime(&t);
			file << now->tm_mday << '.'
				<< (now->tm_mon + 1) << '.'
				<< (now->tm_year + 1900) << ' '
				<< now->tm_hour << ':'
				<< now->tm_min << ':'
				<< now->tm_sec
				<< "\n";

			file << "����������� ��������: ����� " << getshow_steel() << endl;
			file << "��������� �������:" << endl;
			file << " - �������� ������ P = " << P << " ��" << endl;
			file << " - ������� ������ D = " << D << " ��" << endl;
			file << " - ������� ��������� �� ���������� ����������� d = " << get_d() << " ��" << endl;
			file << "��������� �������:" << endl;
			file << " - ��������� C���� " << show_steel << " �� �������� HB = " << get_HB() << endl << endl;
			file << endl;
			file.close();
		}
	}

	friend ostream& operator <<(ostream&, const steel&); //������������� ������� ��� ���������� ������
};

class aluminum {	// ����� aluminum (��������)
	double d = 3.24;
	double HB;
public:
	aluminum() { HB = aluminum_calculation(d); }
	~aluminum() {}

	double aluminum_calculation(double d) {	//������� ������� ��������� �� �������� ��� ��������
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

	void write_ResA() {	// ����� ������ ����������� � ���� (����� aluminum)
		string str;
		ofstream file; // ��������� ����
		file.open(file_res, ios::app);

		if (!file.is_open()) {
			cout << "���� �� ����� ���� ������!\n";
		}
		else
		{
			file << "----------------------------------------------------------------------" << endl;
			file << "���� ������������: ";

			time_t t = time(0);
			tm* now = localtime(&t);
			file << now->tm_mday << '.'
				<< (now->tm_mon + 1) << '.'
				<< (now->tm_year + 1900) << ' '
				<< now->tm_hour << ':'
				<< now->tm_min << ':'
				<< now->tm_sec
				<< "\n";

			file << "����������� ��������: ��������" << endl;
			file << "��������� �������:" << endl;
			file << " - �������� ������ P = " << P_alum << " ��" << endl;
			file << " - ������� ������ D = " << D << " ��" << endl;
			file << " - ������� ��������� �� ���������� ����������� d = " << get_d() << " ��" << endl;
			file << "��������� �������:" << endl;
			file << " - ��������� �������� �� �������� HB = " << get_HB() << endl << endl;
			file << endl;
			file.close();
		}
	}

	friend ostream& operator << (ostream&, const aluminum&);	//������������� ������� ��� ���������� ������
};
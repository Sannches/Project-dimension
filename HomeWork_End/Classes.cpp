#include "Classes.h"
#include "Func.h"

void Screen::ScreenShow() {	//������� ������ �� ����� ������ Screen
	cout << "***********************************************************************************" << endl;
	cout << "*                 � � � � � � � � � � � � � � �   � � � � � �                     *" << endl;
	cout << "*     �� ��������-���������������� ���������������� � �������������� ����� �++    *" << endl;
	cout << "*          �������: ���������� �.�., ������: �43018, ���� '����� 2020 ���'        *" << endl;
	cout << "***********************************************************************************" << endl;
}

void steel::set_d(float d_steel) { d = d_steel; } // ������ ��� ���������� �������� ���������
void steel::set_HB(double p_HB) { HB = p_HB; }	  // ������ ��� ���������� ��������� �� ��������

void steel::choise_steel_type() { //����� ������ steel ��� ������ ����� ����� � ������� ������� ��� �� ��������
	int steel_type;
	double loc_HB;
	steel_type = menu_choise_steel_type();	//����� ���� �����
	switch (steel_type){	//������ ���� �����
	case 1:
		cout << "\n��������� ������������" << endl;
		cout << "----------------------------------" << endl;
		cout << "������ ��������: ����� 20 (0.2% C)" << endl;
		setshow_steel("20 (0.2% C)");
		steel::set_d(4.5);
		loc_HB = steel_calculation(steel::get_d());
		steel::set_HB(loc_HB);
		break;
	case 2:
		cout << "\n��������� ������������" << endl;
		cout << "-----------------------------------" << endl;
		cout << "������ ��������: ����� 45 (0.45% C)" << endl;
		setshow_steel("45 (0.45% C)");
		steel::set_d(4.3);
		loc_HB = steel_calculation(steel::get_d());
		steel::set_HB(loc_HB);
		break;
	case 3:
		cout << "\n��������� ������������" << endl;
		cout << "----------------------------------" << endl;
		cout << "������ ��������: ����� 98 (0.8% C)" << endl;
		setshow_steel("98 (0.8% C)");
		steel::set_d(3.87);
		loc_HB = steel_calculation(steel::get_d());
		steel::set_HB(loc_HB);
		break;
	default:
		break;
	}
}

ostream& operator <<(ostream& out, const steel& w) {	//���������� ��������� ������ ��� ������ steel
	out << "��������� �������:" << endl;
	out << " - �������� ������ P = " << P << " ��" << endl;
	out << " - ������� ������ D = " << D << " ��" << endl;
	out << " - ������� ��������� �� ���������� ����������� d = " << w.get_d() << " ��" << endl;
	out << "��������� �������:" << endl;
	out << " - ��������� C���� " << w.show_steel << " �� �������� HB = " << w.get_HB() << endl << endl;
	out << "------------------------------------------------" << endl;
	out << "��������� ������������ �������� � ���� " << file_res << endl;
	return out;
}
ostream& operator <<(ostream& out, const aluminum& w) {	//���������� ��������� ������ ��� ������ aluminum
	out << "\n��������� ������������" << endl;
	out << "------------------------------------------------" << endl;
	out << "������ ��������: ��������" << endl;
	out << "��������� �������:" << endl;
	out << " - �������� ������ P = " << P_alum << " ��" << endl;
	out << " - ������� ������ D = " << D << " ��" << endl;
	out << " - ������� ��������� �� ���������� ����������� d = " << w.get_d() << " ��" << endl;
	out << "��������� �������:" << endl;
	out << " - ��������� �������� �� �������� HB = " << w.get_HB() << endl << endl;
	out << "------------------------------------------------" << endl;
	out << "��������� ������������ �������� � ���� " << file_res << endl;
	return out;
}
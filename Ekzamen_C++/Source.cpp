
#include "File_Manager.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size=-1;
	while (size != 0)
	{
		Interface inter;
		inter.Munyu();

		int vub = 0;
		cout << "�������� ����� � ����: ";

		cin >> vub;
		cin.ignore();
		switch (vub)
		{
		case 1:
		{
			string buf;
			cout << "������� ��� �����: ";
			getline(cin, buf);
			File_Manager a(buf);
			cout << endl << endl;
			cout << "���� ����� �����" << endl << endl;
			a.Search();
			a.Content();
			break;
		}
		case 2:
		{
			string buf;
			cout << "������� ��� (��� ����� ������ � ��������): ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			a.Create();
			break;
		}
		case 3:
		{
			string buf;
			cout << "������� ��� (��� ����� ������ � ��������): ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			a.Delete();
			break;
		}
		case 4:
		{
			string buf;
			cout << "������� ���: ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			cout << "���� ����� �����" << endl << endl;
			a.Search();
			a.Rename();
			break;
		}
		case 5:
		{
			string buf;
			cout << "������� ��� �� �������� ��������: ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			cout << "���� ����� �����" << endl << endl;
			string per = a.Search();
			cout << "������� ��� � ������� ��������: ";
			getline(cin, buf);
			File_Manager b(buf);
			string next = b.Search();
			b.Copy_File(per, next);
			break;
		}
		case 6:
		{
			string buf;
			cout << "������� ��� �����: ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			cout << "���� ����� �����" << endl << endl;
			string per = a.Search();
			a.Size();
			break;
		}
		case 7:
		{
			string buf;
			cout << "������� ��� �����: ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			cout << "���� ����� �����" << endl << endl;
			a.Search();
			cout << "���� � �����-> " << a.getWay() << endl;
		}
		default:
		{
			cout << "������ ������ � ���� ���" << endl;
			break;
		}
		}
		cout << "��������� ��������? (��-> 0)";
		cin >> size;
	}
 	return 0;
}
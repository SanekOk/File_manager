
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
		cout << "Выберите пункт в меню: ";

		cin >> vub;
		cin.ignore();
		switch (vub)
		{
		case 1:
		{
			string buf;
			cout << "Введите имя файла: ";
			getline(cin, buf);
			File_Manager a(buf);
			cout << endl << endl;
			cout << "Идет поиск файла" << endl << endl;
			a.Search();
			a.Content();
			break;
		}
		case 2:
		{
			string buf;
			cout << "Введите имя (имя файла вводим с форматом): ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			a.Create();
			break;
		}
		case 3:
		{
			string buf;
			cout << "Введите имя (имя файла вводим с форматом): ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			a.Delete();
			break;
		}
		case 4:
		{
			string buf;
			cout << "Введите имя: ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			cout << "Идет поиск файла" << endl << endl;
			a.Search();
			a.Rename();
			break;
		}
		case 5:
		{
			string buf;
			cout << "Введите имя из которого копируем: ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			cout << "Идет поиск файла" << endl << endl;
			string per = a.Search();
			cout << "Введите имя в который копируем: ";
			getline(cin, buf);
			File_Manager b(buf);
			string next = b.Search();
			b.Copy_File(per, next);
			break;
		}
		case 6:
		{
			string buf;
			cout << "Введите имя файла: ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			cout << "Идет поиск файла" << endl << endl;
			string per = a.Search();
			a.Size();
			break;
		}
		case 7:
		{
			string buf;
			cout << "Введите имя файла: ";
			getline(cin, buf);
			cout << endl;
			File_Manager a(buf);
			cout << "Идет поиск файла" << endl << endl;
			a.Search();
			cout << "Путь к файлу-> " << a.getWay() << endl;
		}
		default:
		{
			cout << "Такого пункта в меню нет" << endl;
			break;
		}
		}
		cout << "Завершить прогдаму? (да-> 0)";
		cin >> size;
	}
 	return 0;
}
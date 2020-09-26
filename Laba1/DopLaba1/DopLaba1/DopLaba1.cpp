// DopLaba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

struct Railway
{
    int trainnum;
    char endline[80];
    char timeleft[100];
};
int main()
{
    setlocale(0, "rus");

    int type;
    const int size = 3;
    string s;
    string str;
    Railway num[size];
    do
    {
        cout << " || 1 || Ввод данных в структуру " << endl;
        cout << " || 2 || Вывод элементов в консольное окно " << endl;
        cout << " || 3 || Удаление заданой структурированной переменной " << endl;
        cout << " || 4 || Поиск информации " << endl;
        cout << " || 5 || Запись в файл " << endl;
        cout << " || 6 || Чтение из файла " << endl;
        cout << " || 7 || Сортировка по алфавиту " << endl;
        cout << " || 8 || Выход " << endl;
        cout << endl;
        cin >> type;
        switch (type)
        {
            ///////////////////////////////
        case 1:
        {
            for (int i = 0; i < size; i++)
            {
                cout << endl << " || Введите номер поезда: " << i + 1 << ' ';
                cin >> num[i].trainnum;
                cout << endl << " || Введите пункт назначения: ";
                cin >> num[i].endline;
                cout << endl << " || Введите время отбытия: ";
                cin >> num[i].timeleft;
                cout << endl;
            }
            cout << endl;
            break;
        }
        ///////////////////////////////
        case 2:
        {
            for (int i = 0; i < size; i++)
            {
                cout << " Номер поезда: " << num[i].trainnum << endl;
                cout << " Пункт назначения: " << num[i].endline << endl;
                cout << " Время отбытия: " << num[i].timeleft << endl;
                cout << endl;

            }
            cout << endl;
            break;
        }
        //////////////////////////////
        case 3:
        {
            char namedel[50];
            cout << " Введите номер поезда для удаления: ";
            getchar();
            cin.getline(namedel, 40);
            for (int i = 0; i < size; i++)
            {
                if (*num[i].endline == *namedel)
                {
                    *num[i].endline = '\0';
                    i++;
                }
                else{
                   break;
            }
            }
            cout << endl;
            break;
        }
        //////////////////////////////
        case 4:
        {
            char name[80];
            cout << " Введите время отбытия "; cin >> name;
            for (int i = 0; i < size; i++)
            {
                if (strcmp(num[i].timeleft, name) == 0)
                {
                    cout << " Номер поезда: " << num[i].trainnum << endl;
                    cout << " Пункт назначения: " << num[i].endline << endl;
                    cout << " Время отбытия: " << num[i].timeleft << endl;
                    cout << endl;
                }
                else {
                    cout << "Такого поезда нет";
                    break;
                }
            }
            cout << endl;
            break;
        }
        //////////////////////////////
        case 5:
        {
            ofstream file("D:\\Railway.txt");
            for (int i = 0; i < size; i++)
            {
                file << num[i].trainnum << ' ' << num[i].endline << ' ' << num[i].timeleft << endl;
            }
            file.close();
            cout << endl;
            break;
        }
        /////////////////////////////
        case 6:
        {
            ifstream fileA("D:\\Railway.txt");
            while (!fileA.eof())
            {
                getline(fileA, str);
                cout << str << endl;
            }
            fileA.close();
            cout << endl;
            break;
        }
        case 7: {
            cout << "пока не придумала"<<endl;
            break; };
        case 8: { break; };
        }
    } while (type != 8);
}
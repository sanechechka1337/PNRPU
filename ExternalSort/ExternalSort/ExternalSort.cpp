#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void OutputM() 
{
    ifstream M("M.txt");
    int d;

    while (M >> d) {
        cout << d << ' ';
    }

    M.close();
}

void Merge(int series, int size_M) 
{
    ofstream M("M.txt");
    ifstream F1("F1.txt");
    ifstream F2("F2.txt");

    int el_1, el_2, cnt_1, cnt_2;

    int count_part = ceil((double)size_M / series);
    int count_pair = ceil(count_part / 2);
    for (int i = 1; i <= count_pair; i++) {
        F1 >> el_1;
        F2 >> el_2;
        cnt_1 = 1;
        cnt_2 = 1;

        bool contin_m = true; //типа продолжаем слияние
        while (contin_m)
        {
            if (el_1 < el_2) 
            {
                M << ' ' << el_1;
                F1.get();

                contin_m = !F1.eof() && cnt_1 < series;
                if (contin_m)
                {
                    F1 >> el_1;
                    cnt_1 += 1;
                }
                else 
                {
                    M << ' ' << el_2;
                    F2.get();
                }
            }
            else 
            {
                M << ' ' << el_2;
                F2.get();

                contin_m = !F2.eof() && cnt_2 < series;
                if (contin_m)
                {
                    F2 >> el_2;
                    cnt_2 += 1;
                }
                else
                {
                    M << ' ' << el_1;
                    F1.get();
                }
            }
        }

        while (!F1.eof() && cnt_1 < series) 
        {
            F1 >> el_1;
            M << ' ' << el_1;
            cnt_1 += 1;
            F1.get();
        }

        while (!F2.eof() && cnt_2 < series) 
        {
            F2 >> el_1;
            M << ' ' << el_1;
            cnt_2 += 1;
            F2.get();
        }
    }

    while (F1 >> el_1) 
    {
        M << ' ' << el_1;
    }

    F1.close();
    F2.close();
    M.close();
}

void Slice(int series, int size_M) 
{
    int cur_file = 0;
    ifstream M("M.txt");
    ofstream F1("F1.txt");
    ofstream F2("F2.txt");
    int d;

    while (M >> d) 
    {
        if (cur_file)
        {
            F2 << ' ' << d;
        }
        else 
        {
            F1 << ' ' << d;
        }

        for (int i = 1; i < series && M >> d; i++) 
        {
            if (cur_file)
            {
                F2 << ' ' << d;
            }
            else 
            {
                F1 << ' ' << d;
            }
        }
        cur_file = (cur_file + 1) % 2;
    }

    F1.close();
    F2.close();
    M.close();
    Merge(series, size_M);
}

void CreateM(int& size_M) 
{
    ofstream M("M.txt");

    cout << "Введите размер массива: ";
    do 
    {
        cin >> size_M;
        if (size_M < 2)
        {
            cout << "Количество элементов должно быть больше 1! Введите новое значение n: ";
        }
    } while (size_M < 2);

    int d;
    M << ' ';

    for (int i = 0; i < size_M; i++)
    {
        cout << "Введите " << i + 1 << "-й элемент массива: ";
        cin >> d;
        M << d;

        if (i < size_M - 1)
        {
            M << ' ';
        }
    }

    M.close();
}

int main() 
{
    system("chcp 1251>NULL");
    int size_M = 0;
    int series = 1;

    CreateM(size_M);

    while (series < size_M)
    {
        Slice(series, size_M);
        series *= 2;
    }

    OutputM();
}
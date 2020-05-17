#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>   
#include <cctype>   
#include <random>

#define DOT '.'
#define MINUS '-'

using namespace std;

void rand_gen (float **Matrix, int rows, int columns);
void ztype (float **Matrix, int rows, int columns);
void delmatrix (float **Matrix, int rows);
float checkinput (string limit);
int checkint (string dimensions);

void manualPopulation(float **Matrix, int rows, int columns);

int main()
{

    SetConsoleOutputCP(CP_UTF8);

    string dimensions = "Количество рядов: ";
    int rows = checkint(dimensions);
    dimensions = "Количество колоно: ";
    int columns = checkint(dimensions);

    float **Matrix = new float*[rows];
    for (int i = 1; i < rows; ++i)
        Matrix[i] = new float[columns];

    char ans;
    do
    {
        cout << "Ввести значения вручную (если нет, то значения будут случайными)?  y/n: ";
        cin >> ans;
        if (ans != 'y' && ans != 'n') cout << "Введите 'y' или 'n'" << endl;
        else break;

    } while (true);

    if(ans == 'n') rand_gen(Matrix, rows, columns);
    if(ans == 'y')
    {
        cout << "Введите " << rows * columns << " значений:"  << endl;
        manualPopulation(Matrix, rows, columns);
    }

    int fullSum;

    ztype(Matrix, rows, columns);

    delmatrix(Matrix, rows);

    system("pause");
    return 0;
}


// Functions

void rand_gen(float **Matrix, int rows, int columns)
{
    srand((unsigned) time(NULL));

    string limit = "Введите нижнюю границу диапазона: ";
    float min = checkinput(limit);
    limit = "Введите верхнюю границу диапазона: ";
    float max = checkinput(limit);

    random_device rd;
    mt19937 eng(rd());
    uniform_real_distribution<float> distr(min, max);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++) {

            Matrix[i][j] = distr((eng));
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cout << fixed << setprecision(3) << Matrix[i][j] << "\t ";

        cout << endl;
    }
}

void ztype(float **Matrix, int rows, int columns) {

    float fullSum = 0;
    float diagSum = 0;
    float total;

    if (rows == columns) {

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
                fullSum += Matrix[i][j];
        }

        for (int i = 0; i < rows; i++) {
            diagSum += Matrix[i][i];
        }

        if (fullSum - diagSum <= 0){
            cout << "Матрица Z-образная" << endl;

            for (int i = 0; i < rows; i++) {
                total = 0;
                for (int j = 0; j < columns; j++) {
                    total += Matrix[i][j];
                }
                cout << "сумма строки " << i+1 << ": " << total << endl;
            }
        }
        else cout << "Матрица не Z-образная" << endl;
    }

    //cout << "Sum diag: " << diagSum << endl; //   CHECK for correct diagSum calculation
    //cout << "Full sum: " << fullSum << endl; //     CHECK for correct fullSum calculation
}


void delmatrix(float **Matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        delete [] Matrix[i];
    delete [] Matrix;
}

float checkinput (string limit) {
    string minstr;
    int count = 0;
    int count_dot = 0;
    int count_minus = 0;
    bool flag = true;
    bool flag_dot = false;
    bool flag_minus = false;
    bool correct = false;

    do {
        cout << limit;
        cin >> minstr;
        for (int i = 0; i < (int) minstr.length(); i++) {
            if (minstr[i] == DOT) {
                count_dot++;
                flag_dot = true;
            }
            if (minstr[i] == MINUS) {
                flag_minus = true;
                count_minus++;
            }
            if (((!isdigit(minstr[i])) && (!flag_dot) && (!flag_minus)) || (count_dot >= 2)) {
                cout << "Введено не число, попробуйте еще раз" << endl;
                cin.ignore(10000, '\n');
                flag = true;
                break;
            }
            else
                count++;
        }
        if ((((count == (int) minstr.length()) && (atof(minstr.c_str()) > -9223372036854775808.0) &&
              (atoi(minstr.c_str()) < 9223372036854775807.0))) || (count_minus == 1) &&
                                                                  (((int(count + 1) == (int) minstr.length()) && (atof(minstr.c_str()) > -9223372036854775808.0) &&
                                                                    (atoi(minstr.c_str()) < 9223372036854775807.0))))

        {
            correct = true;
        }
        else if (flag) {
            correct = false;
        }
    } while (correct == false);

    float min = stof(minstr);

    return min;

}

int checkint (string dimensions) {

    string str;
    bool flag = true;
    int count = 0;
    bool flag_dot = false;
    bool correct = false;

    do {
        cout << dimensions;
        cin >> str;
        for (int i = 0; i < (int) str.length(); i++) {
            if (str[i] == DOT) {
                flag_dot = true;
            }
            if (((!isdigit(str[i])) || (flag_dot))) {
                cout << "Ошибка, введите целое число" << endl;
                cin.ignore(10000, '\n');
                flag = true;
                break;
            }
            else
                count++;
        }
        if ((((count == (int) str.length()) && (atoi(str.c_str()) > 0.0)))) {
            correct = true;
        }
        else if (flag) {
            correct = false;
        }
    } while (correct == false);

    int rows = stoi(str);

    return rows;
}

void manualPopulation(float **Matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++) {
            cout << '[' << int(i + 1) << ']' << '[' << int(j + 1) << "] ";
            string limit = "";
            Matrix[i][j] = checkinput(limit);
        }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cout << fixed << setprecision(3) << Matrix[i][j] << "\t ";

        cout << endl;
    }
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>   // std::setprecision
#include <cctype>   // для функции isdigit
#include <random>
#include <fstream>
#include <string>
#include <sstream>

#define DOT '.'
#define MINUS '-'
#define ZERO '0'

using namespace std;

void rand_gen (float **Matrix, int rows, int columns);
void ztype (float **Matrix, int rows, int columns);
void delmatrix (float **Matrix, int rows);
float checkinput (string limit);
int checkint (string dimensions);


void manualPopulation(float **Matrix, int rows, int columns);

int n;
FILE *f1, *f2, *f3;


int main()
{

    SetConsoleOutputCP(CP_UTF8);

    char name1[90] = "\0", name2[90] = "\0", name3[90] = "\0";

    int rows, columns = 0;
    /*float** Matrix;*/

    cout << "Введите имя файла с размерами матрицы : ";
    gets(name1);
    int l = 1;
    if ((f1 = fopen(name1, "r")) == NULL) {
        while (l == 1) {
            if ((f1 = fopen(name1, "r")) == NULL) {
                printf("Файл не найден\n");
                printf("Введите имя файла с размерами матрицы : ");
                memset(&name1[0], 0, sizeof(name1));
                gets(name1);
            }
            else
            {
                l = 0;
            }
        }
    }
    fscanf(f1, "%i %i", &rows, &columns);
    fclose(f1);

    float **Matrix = new float*[rows];
    for (int i = 1; i < rows; ++i)
        Matrix[i] = new float[columns];
    /*for (i = 1; i <= rows*columns; i++) {
        Matrix[i] = new float[rows*columns + 1];
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            Matrix[i][j] = (abs(j - 3) - 1.3)* pow((6.5 - j), (2 * (j - 1))) * (2 * abs(3.3 - i) - 1.5);
        }

    }*/

    int elementsAmount = rows * columns;
    cout << "Elements in Matrix = " << elementsAmount << endl;
    ////////////////////////////////////////////////////////////
    char ans;
    do {
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


   /* ifstream inFile;
    inFile.open("1.txt");

    if (inFile.fail()) {
        cerr << "Error opening file";
        exit(1);
    }

    inFile >> rows >> columns;
    cout << "rows = " << rows << endl;
    cout << "columns = " << columns << endl;
    inFile.close();*/



    //generateElements (elementsAmount);


/*    string dimensions = "Количество рядов: ";
    int rows = checkint(dimensions);
    dimensions = "Количество колонок: ";
    int columns = checkint(dimensions);*/

    /*float **Matrix = new float*[rows];
    for (int i = 1; i < rows; ++i)
        Matrix[i] = new float[columns];*/

    /////// Populate file 2 (elements of matrix)?   [YES   /    NO]  ///////////////////////////////





    ///////

    /*char ans;
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
    }*/

    int fullSum;

    ztype(Matrix, rows, columns);

    delmatrix(Matrix, rows);

    char rerun;
    cout << "Запустить программу снова? (Y = да) "; // Запрос на повторный запуск
    cin >> rerun;
    if (rerun == 'y' or rerun == 'Y')
        main();
    else
        system("pause");

    return 0;
}


// Functions

void rand_gen(float **Matrix, int rows, int columns)
{
    srand((unsigned) time(NULL));

    string limit = "Введите нижнюю границу диапазона: ";
    double min = checkinput(limit);
    limit = "Введите верхнюю границу диапазона: ";
    double max = checkinput(limit);

    random_device rd;
    mt19937 eng(rd());
    uniform_real_distribution<double> distr(min, max);

    cout << endl;

    char name2[90] = "\0", name3[90] = "\0";
    float element;

    printf("Введите название файла для элеменетов матрицы: ");
    cin.ignore();
    gets(name2);

    int l = 1;
    if ((f2= fopen(name2, "w")) == NULL) {
        while (l == 1) {
            if ((f2 = fopen(name2, "w")) == NULL) {
                printf("Файл не найден\n");
                printf("Введите имя файла для элеменетов матрицы : ");
                memset(&name2[0], 0, sizeof(name2));
                gets(name2);
            }
            else
            {
                l = 0;
            }
        }
    }

    double value;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            value = distr((eng));
            fprintf(f2, "%.3f", value);
            fprintf(f2, "\n");
        }
    }
    fclose(f2);

  /*  for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            outFile << distr((eng)) << endl;
        }
    }
    outFile.close();

    ifstream inFile;
    inFile.open("2.txt");
    if (inFile.fail()) {
        cerr << "Error opening file 2";
        exit(1);
    }
    cout << endl;*/

    /*for (int i = 0; i < rows; i++) {
        Matrix[i] = new float[columns];
        for (int j = 0; j < columns; j++) {
            inFile >> Matrix[i][j];
        }
    }*/

    int k = 1;
    f2 = fopen(name2, "r");
    if ((f2= fopen(name2, "r")) == NULL) {
        while (k == 1) {
            if ((f2 = fopen(name2, "r")) == NULL) {
                printf("Файл не найден\n");
                printf("Введите имя файла для элеменетов матрицы : ");
                memset(&name2[0], 0, sizeof(name2));
                gets(name2);
            }
            else
            {
                k = 0;
            }
        }
    }


    cout << "\nМатрица" << endl;
    for (int i = 0; i < rows; i++) {
        Matrix[i] = new float[columns];
        for (int j = 0; j < columns; j++) {
            fscanf(f2, "%f", &element);
            Matrix[i][j] = element;
            cout << fixed << setprecision(3) << Matrix[i][j] << "\t ";
        }
        cout << endl;
    }
    fclose(f2);
////////////////////////////////////
    printf("\nВведите название файла для Хранения матрицы: ");
    cout << "\ngets(name3)" << endl;
    //cin.ignore();
    gets(name3);
    f3 = fopen(name3, "w");
    int m = 1;
    if ((f3= fopen(name3, "w")) == NULL) {
        while (m == 1) {
            if ((f3 = fopen(name3, "w")) == NULL) {
                printf("Файл не найден\n");
                printf("Введите имя файла для элеменетов матрицы : ");
                memset(&name3[0], 0, sizeof(name3));
                gets(name3);
            }
            else
            {
                m = 0;
            }
        }
    }


    cout << "\nat 3  name 3" << endl;

    double valueOutput;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            valueOutput = Matrix[i-1][j-1];
            fprintf(f3, "%.3f", valueOutput);
            fprintf(f3, "\n");
            cout << "\n" << valueOutput;
        }
    }

    fclose(f3);









    //ofstream outFile;
    //outFile.open("2.txt");

/*    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            outFile << distr((eng)) << endl;
        }
    }
    outFile.close();

    ifstream inFile;
    inFile.open("2.txt");
    if (inFile.fail()) {
        cerr << "Error opening file 2";
        exit(1);
    }
    cout << endl;*/


    //ofstream outFile3;
    //outFile3.open("3.txt");


    /*for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++) {
            cout << fixed << setprecision(3) << Matrix[i][j] << "\t ";
            outFile3 << Matrix[i][j] << endl;
        }

        cout << endl;
    }
    outFile3.close();*/
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
        for (int i = 0; i < rows; i++)
            diagSum += Matrix[i][i];

        if (fullSum - diagSum <= 0){
            cout << "\nМатрица Z-образная" << endl;

            for (int i = 0; i < rows; i++) {
                total = 0;
                for (int j = 0; j < columns; j++)
                    total += Matrix[i][j];

                cout << "сумма строки " << i+1 << ": " << total << endl;
            }
        }
        else
            cout << "\nМатрица не Z-образная" << endl;
    }
    else
        cout << "\nМатрица не Z-образная" << endl;
    //cout << "Sum diag: " << diagSum << endl; //   CHECK for correct diagSum calculation
    //cout << "Full sum: " << fullSum << endl; //     CHECK for correct fullSum calculation
}


void delmatrix(float **Matrix, int rows) {
    for (int i = 0; i < rows; i++)
        delete [] Matrix[i];
    delete [] Matrix;
}

float checkinput (string limit) {

    string input;
    int count = 0;
    int count_dot = 0;
    int count_minus = 0;
    int count_zero = 0;
    bool flag = true;
    bool flag_dot = false;
    bool flag_minus = false;
    bool flag_zero = false;
    bool correct = false;

    do {
        cout << limit;
        cin >> input;
        for (int i = 0; i < (int) input.length(); i++) {
            if (input[i] == DOT) {
                count_dot++;
                flag_dot = true;
            }
            if (input[i] == MINUS) {
                flag_minus = true;
                count_minus++;
            }
            if (input[i] == ZERO) {
                flag_zero = true;
                count_zero++;
            }
            if (((!isdigit(input[i])) && (!flag_dot) && (!flag_minus) && (!flag_zero)) || (count_dot >= 2)) {
                cout << "Введено не число, попробуйте еще раз" << endl;
                cin.ignore(10000, '\n');
                flag = true;
                count = 0;
                count_dot = 0;
                count_minus = 0;
                break;
            } else
                count++;
        }
        if (((((count == (int) input.length()) && (atof(input.c_str()) > -9223372036854775808.0) &&
               (atof(input.c_str()) < 9223372036854775807.0))) || (count_minus == 1) &&
                                                                  (((int(count + 1) == (int) input.length()) && (atof(input.c_str()) > -9223372036854775808.0) &&
                                                                    (atof(input.c_str()) < 9223372036854775807.0))) || (count_zero == 1) &&
                                                                                                                       (((int(count) == (int) input.length()) && (atof(input.c_str()) > -9223372036854775808.0) &&
                                                                                                                         (atof(input.c_str()) < 9223372036854775807.0))) || (count_dot == 1) &&
                                                                                                                                                                            (((int(count + 1) == (int) input.length()) && (atof(input.c_str()) > -9223372036854775808.0) &&
                                                                                                                                                                              (atof(input.c_str()) < 9223372036854775807.0)))) || (count_minus == 1) &&
                                                                                                                                                                                                                                  (((int(count + 1) == (int) input.length()) && (atof(input.c_str()) > -9223372036854775808.0) &&
                                                                                                                                                                                                                                    (atof(input.c_str()) < 9223372036854775807.0))) || (count_zero == 1) && (count_dot == 1) &&
                                                                                                                                                                                                                                                                                       (((int(count + 1) == (int) input.length()) && (atof(input.c_str()) > -9223372036854775808.0) &&
                                                                                                                                                                                                                                                                                         (atof(input.c_str()) < 9223372036854775807.0))) || (count_zero == 1) && (count_minus == 1) && (count_dot == 1) &&
                                                                                                                                                                                                                                                                                                                                            (((int(count + 2) == (int) input.length()) )) || (count_zero == 1) && (count_minus == 0) && (count_dot == 0) &&
                                                                                                                                                                                                                                                                                                                                                                                             (int(count) == 0)) {
            correct = true;
        } else if (flag) {
            correct = false;
        }
    } while (correct == false);
    float min = stof(input);
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
            if ((!isdigit(str[i])) || (flag_dot)) {
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

    int rows = stod(str);

    return rows;
}

void manualPopulation(float **Matrix, int rows, int columns)
{
    /*for (int i = 0; i < rows; i++) {
        Matrix[i] = new float[columns];
        for (int j = 0; j < columns; j++) {
            cout << '[' << int(i + 1) << ']' << '[' << int(j + 1) << "] ";
            string limit = "";
            Matrix[i][j] = checkinput(limit);
        }
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cout << fixed << setprecision(3) << Matrix[i][j] << "\t ";

        cout << endl;
    }
    cout << endl;*/


    char name2[90] = "\0", name3[90] = "\0";
    float element;

    printf("Введите название файла для элеменетов матрицы: ");
    cin.ignore();
    gets(name2);

    int l = 1;
    if ((f2= fopen(name2, "w")) == NULL) {
        while (l == 1) {
            if ((f2 = fopen(name2, "w")) == NULL) {
                printf("Файл не найден\n");
                printf("Введите имя файла для элеменетов матрицы : ");
                memset(&name2[0], 0, sizeof(name2));
                gets(name2);
            }
            else
            {
                l = 0;
            }
        }
    }

    double value;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            cout << '[' << int(i + 1) << ']' << '[' << int(j + 1) << "] ";
            string limit = "";
            value = checkinput(limit);
            fprintf(f2, "%.3f", value);
            fprintf(f2, "\n");
        }
    }
    fclose(f2);

    int k = 1;
    f2 = fopen(name2, "r");
    if ((f2= fopen(name2, "r")) == NULL) {
        while (k == 1) {
            if ((f2 = fopen(name2, "r")) == NULL) {
                printf("Файл не найден\n");
                printf("Введите имя файла для элеменетов матрицы : ");
                memset(&name2[0], 0, sizeof(name2));
                gets(name2);
            }
            else
            {
                k = 0;
            }
        }
    }


    cout << "\nМатрица" << endl;
    for (int i = 0; i < rows; i++) {
        Matrix[i] = new float[columns];
        for (int j = 0; j < columns; j++) {
            fscanf(f2, "%f", &element);
            Matrix[i][j] = element;
            cout << fixed << setprecision(3) << Matrix[i][j] << "\t ";
        }
        cout << endl;
    }
    fclose(f2);

    printf("\nВведите название файла для Хранения матрицы: ");
    cout << "\ngets(name3)" << endl;
    cin.ignore();
    gets(name3);
    f3 = fopen(name3, "w");
    int m = 1;
    if ((f3= fopen(name3, "w")) == NULL) {
        while (m == 1) {
            if ((f3 = fopen(name3, "w")) == NULL) {
                printf("Файл не найден\n");
                printf("Введите имя файла для элеменетов матрицы : ");
                memset(&name3[0], 0, sizeof(name3));
                gets(name3);
            }
            else
            {
                m = 0;
            }
        }
    }

    double valueOutput;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            valueOutput = Matrix[i-1][j-1];
            fprintf(f3, "%.3f", valueOutput);
            fprintf(f3, "\n");
            //cout << "\n" << valueOutput;
        }
    }

    fclose(f3);



    /*ofstream outFile;
    outFile.open("2.txt");
    float input;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << '[' << int(i + 1) << ']' << '[' << int(j + 1) << "] ";
            string limit = "";
            input = checkinput(limit);
            outFile << input << endl;
        }
    }
    outFile.close();*/

    /*ifstream inFile;
    inFile.open("2.txt");
    if (inFile.fail()) {
        cerr << "Error opening file 2";
        exit(1);
    }

    cout << "\nElements in file 2" << endl;
    for (int i = 0; i < rows; i++) {
        Matrix[i] = new float[columns];
        for (int j = 0; j < columns; j++) {
            inFile >> Matrix[i][j];
        }
    }
    inFile.close();

    ofstream outFile3;
    outFile3.open("3.txt");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++) {
            cout << fixed << setprecision(3) << Matrix[i][j] << "\t ";
            outFile3 << Matrix[i][j] << endl;
        }

        cout << endl;
    }
    outFile3.close();*/
}

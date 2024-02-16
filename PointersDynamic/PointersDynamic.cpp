#include <iostream>
#include <random>
using namespace std;

//указатели нужны чтобы хранить в себе адрес ссылки на элемент и иметь возможность с ним взаимодействовать
//нельзя записывать по нулевому адресу
//если есть данные, которые не используешь, ос не знает, нужны ли тебе они, поэтому нужно удалять, чтобы память освобождалась и программа не сломалась
//выдаем память вручную и освобождаем ее тоже
//дважды освобождать указатель  нельзя
// не нарушаем процесс - 1) аллоцирование 2) использование 3) удаление 
//утечка памяти - аллоцируем каждый раз новые учатски памяти, но не освобождаем ее после использования для других данных

//void f(int* p) {
//    *p = 100;
//}
//
//double* allocMemory(int count) {
//    double* ptr = new double[count];
//    return ptr;
//}
//
//void freeMemory(double* ptr) {
//    delete[] ptr;
//}
//
//void useMemory(double* ptr, int count){
//    for (int i = 0; i < count; i++) {
//        ptr[i] = 1.5 + i;
//    }
//}

void deallocateMemory(int** nums, int rows) {
    
    for (int i = 0; i < rows; i++) {
        delete[] nums[i];
    }
    delete[] nums;
}
void findDiagonalWithIdenticalNums(int** nums, int rows, int cols) {
    for (int i = 0; i < rows - 2; i++) {
        for (int j = 0; j < cols - 2; j++) {
            if (nums[i][j] == nums[i + 1][j + 1] && nums[i][j] == nums[i + 2][j + 2]) {
                cout << "Diagonal [" << i + 1 << "][" << j + 1 << "], [" << i + 2 << "][" << j + 2 << "], [" << i + 3 << "][" << j + 3 << "]" << endl;
            }
        }
    }
}
void findCoulumnsWithIdenticalNums(int** nums, int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows - 2; i++) {
            if (nums[i][j] == nums[i + 1][j] && nums[i][j] == nums[i + 2][j]) {
                cout << "Column " << j + 1 << ": " << nums[i][j] << " " << nums[i + 1][j] << " " << nums[i + 2][j] << endl;
            }
        }
    }
}
void findRowsWithIdenticalNums(int** nums, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 2; j++) {
            if (nums[i][j] == nums[i][j + 1] && nums[i][j] == nums[i][j + 2]) {
                cout << "Row " << i + 1 << ": " << nums[i][j] << " " << nums[i][j + 1] << " " << nums[i][j + 2] << endl;
            }
        }
    }
}
int** generateMatrix(int rows, int cols) {
    int** nums = new int* [rows];
    for (int i = 0; i < rows; i++) {
        nums[i] = new int[cols];
    }
    return nums;
}
int** generateRandNums(int** nums, int rows, int cols) {
    random_device rd;    // Создание объекта для генерации случайных чисел
    mt19937 gen(rd());   // Инициализация генератора случайных чисел с использованием случайного устройства

    // Создание распределения случайных чисел в диапазоне от 1 до 5
    uniform_int_distribution<> distribution(1, 5);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            nums[i][j] = distribution(gen);
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return nums;
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    
    int** nums = generateMatrix(rows, cols);
    generateRandNums(nums, rows, cols);
    findRowsWithIdenticalNums(nums, rows, cols);
    findCoulumnsWithIdenticalNums(nums, rows, cols);
    findDiagonalWithIdenticalNums(nums, rows, cols);
    deallocateMemory(nums, rows);


    //int* p;
    //int count;
    //cout << "how many items do u need? ";
    //cin >> count;
    //p = new int[count];
    //for (int i = 0; i < 10; i++) {
    //    p[i] = i;
    //    cout << p[i] << " ";
    //}
    //delete[] p;



    /*double* ptr;
    allocMemory(20);
    useMemory(ptr, )*/


    //аллоцируем память чтобы хранять указатели, а после аллоцируем составные его части. деаллоцировать нужно в обратном порядке - сначала составляющие части, потом глувную

    //int* row1 = new int[3];
    //int* row2 = new int[3];
    //int* row3 = new int[3];

    /*int count;
    cout << "how many items do u need? ";
    cin >> count;
    int** matrix = new int* [count];
    for (int i = 0; i < count; i++) {
        matrix[i] = new int[count];
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            matrix[i][j] = 0;
            if (i == j) {
                matrix[i][j] = 1;
            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < count; i++) {
            delete[] matrix[i];
    }
    delete[] matrix;*/
}
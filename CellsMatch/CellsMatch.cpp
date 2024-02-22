#include <iostream>
#include <random>

using namespace std;

class Cell {
public:
    char symbol; //'1','2','3', 'A', '0', 'X'
    int x, y;

    static void findRowsWithIdenticalNums(Cell** nums, int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols - 2; j++) {
                if (nums[i][j].symbol == nums[i][j + 1].symbol && nums[i][j].symbol == nums[i][j + 2].symbol) {
                    cout << "Row " << i + 1 << ": " << nums[i][j].symbol << " " << nums[i][j + 1].symbol << " " << nums[i][j + 2].symbol << endl;
                }
            }
        }
    }

    static void findCoulumnsWithIdenticalNums(Cell** nums, int rows, int cols) {
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows - 2; i++) {
                if (nums[i][j].symbol == nums[i + 1][j].symbol && nums[i][j].symbol == nums[i + 2][j].symbol) {
                    cout << "Column " << j + 1 << ": " << nums[i][j].symbol << " " << nums[i + 1][j].symbol << " " << nums[i + 2][j].symbol << endl;
                }
            }
        }
    }

    static void findDiagonalWithIdenticalNums(Cell** nums, int rows, int cols) {
        for (int i = 0; i < rows - 2; i++) {
            for (int j = 0; j < cols - 2; j++) {
                if (nums[i][j].symbol == nums[i + 1][j + 1].symbol && nums[i][j].symbol == nums[i + 2][j + 2].symbol) {
                    cout << "Diagonal [" << i + 1 << "][" << j + 1 << "], [" << i + 2 << "][" << j + 2 << "], [" << i + 3 << "][" << j + 3 << "]" << endl;
                }
            }
        }
    }
};

void deallocateMemory(Cell** nums, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] nums[i];
    }
    delete[] nums;
}

Cell** generateMatrix(int rows, int cols) {
    Cell** matrix = new Cell * [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new Cell[cols];
    }
    return matrix;
}

void generateRandNums(Cell** nums, int rows, int cols) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(0, 25); // Generating values for letters

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int randValue = distribution(gen); // Generate a random value
            if (randValue < 10)
                nums[i][j].symbol = '0' + randValue; // Convert to character for numbers '0' to '9'
            else
                nums[i][j].symbol = 'A' + (randValue - 10); // Convert to character for letters 'A' to 'Z'
            cout << nums[i][j].symbol << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    Cell** nums = generateMatrix(rows, cols);
    generateRandNums(nums, rows, cols);
    Cell::findRowsWithIdenticalNums(nums, rows, cols);
    Cell::findCoulumnsWithIdenticalNums(nums, rows, cols);
    Cell::findDiagonalWithIdenticalNums(nums, rows, cols);
    deallocateMemory(nums, rows);

    return 0;
}

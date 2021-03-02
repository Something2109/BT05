#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

void input(int& n);
void chooseRange(int& m, int& n, int& K);
void setMineRange(bool** mineRange, const int& m, const int& n, int K);
void playGame(bool** mineRange, char** playField, const int& m, const int& n, const int& K);
void getGuessCoordinate(char** playField, const int& m, const int& n, int& x, int& y);
void checkGuessCoordinate(bool** mineRange, char** playField, const int& m, const int& n, int row, int col, int& playerGuess, bool &gameOver);
bool checkDuplicate(char** playField, int row, int col);
char mineNumber(bool** mineRange, const int& m, const int& n, int x, int y);
void spreadZero(bool** mineRange, char** playField, const int& m, const int& n, int x, int y, int& playerGuess);
void printPlayField(char** playField, const int& m, const int& n);
void printMineField(bool** mineRange, char** playField, const int& m, const int& n);

int main() {
    srand(time(NULL));
    int m, n, K;
    chooseRange(m, n, K);
    bool** mineRange = new bool* [m];
    char** playField = new char* [m];
    for (int i = 0; i < m; i++) {
        mineRange[i] = new bool[n];
        playField[i] = new char[n];
        for (int j = 0; j < n; j++) {
            mineRange[i][j] = false;
            playField[i][j] = '.';
        }
    }
    setMineRange(mineRange, m, n, K);
    playGame(mineRange, playField, m, n, K);
    for (int i = 0; i < m; i++) {
        delete[] mineRange[i];
        delete[] playField[i];
    }
    delete[] mineRange;
    delete[] playField;
}

void input(int& n) {
    string input;
    cin >> input;
    while (input[0] > '9' || input[0] <= '0') {
        cout << "Enter a valid number: ";
        cin >> input;
    }
    n = atoi(&input[0]);
}

void chooseRange(int &m, int &n, int &K) {
    cout << "Choose row number: ";
    input(m);
    cout << "Choose column number: ";
    input(n);
    do {
        cout << "Choose mine number: ";
        cin >> K;
    } while (K >= m * n);
}

void setMineRange(bool** mineRange, const int& m, const int& n, int K) {
    while (K != 0) {
        int i = rand() % m,
            j = rand() % n;
        if (!mineRange[i][j]) {
            mineRange[i][j] = true;
            K--;
        }
    }
}

void playGame(bool** mineRange, char** playField, const int& m, const int& n, const int &K) {
    int row, col, playerGuess = 0, maxGuess = m * n - K;
    bool gameOver = false;
    while (!gameOver) {
        printPlayField(playField, m, n);
        getGuessCoordinate(playField, m, n, row, col);
        cout << endl;
        checkGuessCoordinate(mineRange, playField, m, n, row, col, playerGuess, gameOver);
        if (playerGuess == maxGuess && !gameOver) {
            printMineField(mineRange, playField, m, n);
            cout << "YOU WIN";
            gameOver = true;
        }
    }
}

void getGuessCoordinate(char** playField, const int& m, const int& n, int& x, int& y) {
    do {
        cout << "Enter row coordinate: ";
        input(x);
        cout << "Enter column coordinate: ";
        input(y);
        x--; y--;
    } while (x >= m || y >= n || checkDuplicate(playField, x, y));
}

bool checkDuplicate(char** playField, int row, int col) {
    if (playField[row][col] == '.') {
        return false;
    }
    return true;
}

void checkGuessCoordinate(bool** mineRange, char** playField, const int& m, const int& n, int row, int col, int& playerGuess, bool &gameOver) {
    if (mineRange[row][col] == true) {
        printMineField(mineRange, playField, m, n);
        cout << "YOU'RE DEAD!" << endl;
        gameOver = false;
    }
    playField[row][col] = mineNumber(mineRange, m, n, row, col);
    if (playField[row][col] == '0') {
        spreadZero(mineRange, playField, m, n, row, col, playerGuess);
    }
    playerGuess++;
    cout << endl;
}

char mineNumber(bool** mineRange, const int& m, const int& n, int x, int y) {
    int mineCount = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        if (i >= 0 && i < m) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (j >= 0 && j < n) {
                    if (mineRange[i][j]) {
                        mineCount++;
                    }
                }
            }
        }
    }
    return (mineCount + '0');
}

void spreadZero(bool** mineRange, char** playField, const int &m, const int &n, int x, int y, int &playerGuess) {
    for (int i = x - 1; i <= x + 1; i++) {
        if (i >= 0 && i < m) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (j >= 0 && j < n && playField[i][j] == '.' && !mineRange[i][j]) {
                    playField[i][j] = mineNumber(mineRange, m, n, i, j);
                    playerGuess++;
                    if (playField[i][j] == '0') {
                        spreadZero(mineRange, playField, m, n, i, j, playerGuess);
                    }
                }
            }
        }
    }
}

void printPlayField(char** playField, const int& m, const int& n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i < m) {
                cout << playField[i][j] << "  ";
            }
            else {
                cout << (j + 1) << "  ";
            }
        }
        cout << (i + 1) << endl;
        cout << endl;
    }
}

void printMineField(bool** mineRange, char** playField, const int& m, const int& n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i < m) {
                cout << (mineRange[i][j] ? '*' : playField[i][j]) << "  ";
            }
            else {
                cout << (j + 1) << "  ";
            }
        }
        cout << (i + 1) << endl;
        cout << endl;
    }
}
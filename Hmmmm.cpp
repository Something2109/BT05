#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

//số liệu có được khi sử dụng compiler của Visual Studio 2019 Community 

//BaiA1;
/*int main() {
    int x;
    int arr[3];
    int y;
    char a;
    char charArr[3];
    char b;
    cout << &x << endl; //địa chỉ cách 1 đoạn khá xa so với phần tử đầu của mảng (36 ô aka 9 biến int)
    cout << &arr[0] << ' ' << &arr[1] << ' ' << &arr[2] << endl; //địa chỉ cách nhau 3 ô nhưng các biến xếp liền mạch do int cần 4 byte (ô) để ghi  
    cout << &y << endl; //địa chỉ cách 1 đoạn khá xa so với phần tử cuối của mảng (36 ô aka 9 biến int)
    cout << (void*)&a << endl; //địa chỉ cách 1 đoạn khá xa so với phần tử đầu của mảng (32 ô aka 32 biến char)
    cout << (void*)&charArr[0] << ' ' << (void*)&charArr[1] << ' ' << (void*)&charArr[2] << endl; //địa chỉ và biến xếp liền mạch do char cần 1 byte (ô) để ghi
    cout << (void*)&b << endl; //địa chỉ cách 1 đoạn khá xa so với phần tử cuối của mảng (30 ô aka 30 biến char)
}*/

//Bai A2
/*int factorial(int n) {
    cout << "n = " << n << " at " << &n << endl;
    if (n > 1) {
        n = n * factorial(n - 1);
    }
    return n;
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n); 
}*/
// các địa chỉ của n khi đệ quy cách đều nhau một khoảng 256 ô nhớ 
// => 1 stack frame của hàm chiếm khoảng 256 ô

//Bai A3
/*template <typename T>
void passBy(T x, T &y) {
    cout << "Pass By Value: " << (void*)&x << endl; // địa chỉ khác x trong main
    cout << "Pass By Reference: " << (void*)&y << endl; // địa chỉ giống biến trong main 
}

int main() {
    int x = 0;
    cout << "x: " << &x << endl;
    passBy<int>(x, x);
}*/

//Bai A4
/*template <typename T>
void passByArr(T x[], T &y[]) {
    cout << "Pass By Value: " << (void*)&x << endl; // địa chỉ khác x trong main
    cout << "Pass By Reference: " << "Error" << endl; // lỗi trong code E0251
}

void passBy(string x, string& y) {
    cout << "Pass By Value: " << (void*)&x << endl; // địa chỉ khác x trong main
    cout << "Pass By Reference: " << (void*)&y << endl; // địa chỉ giống biến trong main 
}

int main() {
    int a[3];
    string str;
    cout << "a[]: " << &a << endl;
    passByArr<int>(a, a);
    cout << "string: " << &str << endl;
    passBy(str, str);
}*/
// Array chỉ có thể truyền value
// C++ String có thể dùng cả hai cách truyền

//Bai A5
/*int main() {
    int a;
    int& b = a;
    cout << "a: " << &a << " a_ref: " << &b << endl; 
    //int& c; 
    int c = 12;
    b = c;
    cout << "c: " << &c << " c_ref: " << &c << endl;
}*/
//biến + tham chiếu đều là 1 biến
//lỗi E0252 => ko thể dùng tham chiếu mà ko chiếu nó đến 1 biến khác 
//có thể chiếu tham chiếu đến 1 biến khác biến ban đầu

//Bai A6
/*int searchRecursion(int key, int arr[], int low, int high) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (key == arr[mid]) {
        return mid;
    }
    else {
        if (key > arr[mid]) {
            searchRecursion(key, arr, mid + 1, high);
        }
        else {
            searchRecursion(key, arr, low, mid - 1);
        }
    }
}

int searchLoop(int key, int arr[], int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key == arr[mid]) {
            return mid;
        }
        else {
            if (key > arr[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    const int arrNumber = 11;
    int a[arrNumber] = {1, 12, 23, 34, 45, 56, 67, 78, 89, 90, 100};
    int key,
        low = 0,
        high = arrNumber - 1;
    cin >> key;
    cout << "Recursion:" << endl;
    int result = searchRecursion(key, a, low, high);
    if (result >= 0) {
        cout << "Number's position: " << (result + 1) << endl;
    }
    else {
        cout << "Number not find" << endl;
    }
    cout << "Loop:" << endl;
    result = searchLoop(key, a, low, high);
    if (result >= 0) {
        cout << "Number's position: " << (result + 1) << endl;
    }
    else {
        cout << "Number not find" << endl;
    }
}*/

//Bai B1
/*bool majority(bool first, bool second, bool third) {;
    bool majority = (first & second) | (first & third) | (second & third);
    return majority;
}

int main() {
    bool a, b, c;
    cin >> a >> b >> c;
    cout << majority(a, b, c);
}*/

//BaiB2
/*bool dupCheck(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int b[10];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    cout << (dupCheck(a, b, 10) ? "true" : "false");
}*/

//Bai B5
/*int min(int a, int b) {
    if (a <= b) return a;
    else        return b;
}
int min(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}

void f(int x, double y) {
    cout << "f(int, double)";
}

void f(double x, int y) {
    cout << "f(double, int)";
}
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min(a, b, c, d) << endl;
    f(1, 2);
}*/

//Bai C5
/*bool primary(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i < n; i++) {
        if (primary(i)) {
            cout << i << ' ';
        }
    }
}*/

//Bai C6
/*int ucln(int x, int y) {
    while (x * y != 0) {
        if (x > y) {
            x = x % y;
        }
        else {
            y = y % x;
        }
    }
    return x + y;
}

int main() {
    int x, y;
    cin >> x >> y;
    if (ucln(x, y) == 1) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
}*/

//Bai C7
/*void print(int m, int n) {
    for (int i = 0; i < m; i++) {
        cout << ' ';
    }
    for (int i = 0; i < n; i++) {
        cout << '*';
    }
    cout << endl;
}
int main() {
    int row;
    cin >> row;
    for (int i = 0; i < row; i++) {
        int m = row - i - 1;
        int n = 2 * i + 1;
        print(m, n);
    }
}*/

//Bai C8
/*int roundNumber(double n) {
    int m = n;
    if (n > (m + 0.5)) {
        return ceil(n);
    }
    else {
        return floor(n);
    }
}

int roundNumberFunc(double n) {
    int decimal = n;
    n -= decimal;
    if (n > 0.5) {
        decimal++;
    }
    return decimal;
}

int main() {
    double n;
    cin >> n;
    cout << roundNumber(n) << endl;
    cout << roundNumberFunc(n);
}*/

//Bai C9
/*int randomNumber(int n) {
    return rand() % n;
}

int main() {
    srand(time(NULL));
    int n;
    cin >> n;
    cout << randomNumber(n);
}*/

//Bai C10
/*void sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                int swap = arr[j];
                arr[j] = arr[i];
                arr[i] = swap;
            }
        }
    }
}

void dividable(int* arr, int n) {
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((arr[i] + arr[j] + arr[k]) % 25 == 0) {
                    cout << arr[i] << ' ' << arr[j] << ' ' << arr[k] << endl;
                }
                while (arr[k] == arr[k + 1]) {
                    k++;
                }
            }
            while (arr[j] == arr[j + 1]) {
                j++;
            }
        }
        while (arr[i] == arr[i + 1]) {
            i++;
        }
    }
}

int main() {
    srand(time(NULL));
    int n = rand() % 50;
    int* arr = new int [n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50;
    }
    sort(arr, n);
    dividable(arr, n);
    delete[] arr;
}*/

//Bai C11
/*string intBinary(int n, int base) {
    if (n == 0) {
        return "0";
    }
    string binary;
    while (n) {
        binary += ('0' + (n % base));
        n /= base;
    }
    int strlength = binary.length() - 1;
    for (int i = 0; i <= strlength / 2; i++) {
        char swap = binary[i];
        binary[i] = binary[strlength - i];
        binary[strlength - i] = swap;
    }
    return binary;
}

string binary(double n, int base) {
    int nature = n,
        presition = 0;
    n -= nature;
    string binary = intBinary(nature, base) + '.';
    if (n == 0) {
        binary += "0";
    }
    else {
        while (n != 0 && presition != 10) {
            int bit = n * base;
            char digit = bit + '0';
            binary = binary + digit;
            n = n * base - bit;
            presition++;
        }
    }
    return binary;
}

int main() {
    double n, base;
    cin >> n;
    cout << "He so: ";
    cin >> base;
    string numb = binary(n, base);
    cout << numb;
}*/

//Bai C12
/*int combination(int n, int k) {
    int factorialN = 1,
        factorialK = 1,
        factorialN_K = 1;
    for (int i = 1; i <= n; i++) {
        factorialN *= i;
        if (i == k) {
            factorialK = factorialN;
        }
        if (i == (n - k)) {
            factorialN_K = factorialN;
        }
    }
    int combination = factorialN / (factorialK * factorialN_K);
    return combination;
}

int main() {
    int n = 0, k = 0;
    while (n != -1 || k != -1) {
        cin >> k >> n;
        cout << combination(n, k) << endl;
    }
}*/
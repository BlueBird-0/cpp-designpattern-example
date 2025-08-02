#include <iostream>
using namespace std;

// 2D 배열용 Value 함수
template <typename T, size_t ROW, size_t COL>
inline T& Value(T (&array2D)[ROW][COL], int index) {
    return array2D[index / COL][index % COL];
}

// 1D 배열용 Value 함수
template <typename T, size_t COL>
inline T& Value(T (&array)[COL], int index) {
    return array[index];
}

// 비교 함수
template<typename T, typename U>
void Compare(T& in1, U& in2) {
    for (int i = 0; i < 8; i++) {
        cout << "arr1 = " << Value(in1, i) << endl;
        cout << "arr2 = " << Value(in2, i) << endl;

        if (Value(in1, i) == Value(in2, i)) {
            cout << "in1 == in2" << endl;
            Value(in1, i) = -1;
        } else {
            cout << "in1 != in2" << endl;
        }
    }
}

int main() {
    int in1[8] = {1, 2, 3, 4, 5};                     // 나머지 요소는 0으로 자동 초기화
    int in2[2][4] = {{1, 2, 3, 4}, {5, 6}};           // 남은 값은 0으로 자동 초기화

    Compare(in1, in2);

    cout << "Modified in1: ";
    for (int i = 0; i < 8; ++i) {
        cout << in1[i] << " ";
    }
    cout << endl;

    return 0;
}
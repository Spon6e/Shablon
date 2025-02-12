#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

class distance2 {
private:
    int cel;
    float fut;
public:
    class ErrorD {
    public:
        string name;
        float fut1;
        ErrorD(string h, float f1) {
            name = h;
            fut1 = f1;
        }
    };
    distance2() : cel(0), fut(0.0) {};
    distance2(int r, float v) {
        cel = r;
        if (v >= 12.0 || v < 0.0)
            throw ErrorD("Ошибка при конструкторе с двумя значениями: ", v);
        fut = v;
    }
    void add() {
        cout << "Введите целую часть: ";
        cin >> cel;
        cout << "Введите футы: ";
        cin >> fut;
        if (fut >= 12.0 || fut < 0.0)
            throw ErrorD("Ошибка при вводе чисел пользователем", fut);
    }
    void display() {
        cout << "C=" << cel << " / " << fut << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        distance2 k(12, 11.3);
        k.display();
        distance2 l(10, 12.22);
        l.display();
        distance2 jy;
        jy.add();
        jy.display();
    }
    catch (distance2::ErrorD l) {
        cout << "Емае, да ты клоун дружище"<< l.name;
    }
    _getch();
}

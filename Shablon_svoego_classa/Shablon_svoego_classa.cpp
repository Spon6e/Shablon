#include <iostream>
#include <conio.h>
using namespace std;

class rabotaga {
private:
    char name[20];
    int age;
public:
    friend istream& operator>>(istream&, rabotaga&);
    friend ostream& operator<<(ostream&, rabotaga&);
};

istream& operator>>(istream& s, rabotaga& r) {
    cout << "Введи имя работяги: ";
    cin >> r.name;
    cout << "А возраст бедолаги? : ";
    cin >> r.age;
    return s;
}

ostream& operator<<(ostream& s, rabotaga& r) {
    cout << "Имя работяги: " << r.name << endl;
    cout << "Возраст работяги: " << r.age << endl;
    return s;
}

template <class TYPE>
struct list {
    TYPE neob;
    list* next;
};

template <class TYPE>
class linklist {
private:
    list<TYPE>* FF;
public:
    linklist() {
        FF = NULL;
    }
    void add(TYPE);
    void display();
};

template <class TYPE>
void linklist<TYPE>::add(TYPE n) {
    list<TYPE>* k = new list<TYPE>;
    k->neob = n;
    k->next = FF;
    FF = k;
}

template <class TYPE>
void linklist<TYPE>::display() {
    list<TYPE>* p = FF;
    while (p != NULL) {
        cout << p->neob << endl;
        p = p->next;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    rabotaga G[3];
    linklist<rabotaga> m;
    for (int i = 0; i < 3; i++) {
        cout << "Поясни за работягу номер " << i + 1 << endl;
        cin >> G[i];
        m.add(G[i]);
    }
    m.display();
    _getch();
}
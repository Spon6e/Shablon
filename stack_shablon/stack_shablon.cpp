#include <iostream>
using namespace std;

const int MAX = 100;

template <class TTP>
class Stack {
private:
    TTP mas[MAX];
    int n;
public:
    Stack();
    void push(TTP);
    TTP pop();
};
template <class TTP>
Stack<TTP>::Stack() {
    n = -1;
}

template <class TTP>
void Stack<TTP>::push(TTP g) {
    mas[++n] = g;
}

template <class TTP>
TTP Stack<TTP>::pop() {
    return mas[n--];
}

int main()
{
    Stack<int> k;
    k.push(12);
    k.push(931);
    k.push(4);
    cout << k.pop() << endl;
    cout << k.pop() << endl;
    cout << k.pop() << endl;
}


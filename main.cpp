#include <iostream>
using  namespace  std;
class IPAdress{
private:
    unsigned char a, b, c, d;

public:
    unsigned char GetA (){  //геттеры
        return (a);
    }
    unsigned char GetB (){
        return (b);
    }
    unsigned char GetC (){
        return (c);
    }
    unsigned char GetD () {
        return (d);
    }
    void SetA (unsigned char ValueA) {     //сеттеры
        a = ValueA;
    }
    void SetB (unsigned char ValueB) {
        b = ValueB;
    }
    void SetC (unsigned char ValueC) {
        c = ValueC;
    }
    void SetD (unsigned char ValueD) {
        d = ValueD;
    }

    IPAdress(unsigned char ValueA0, unsigned char ValueB0, unsigned char ValueC0, unsigned char ValueD0){     //конструктор
        a = ValueA0;
        b = ValueB0;
        c = ValueC0;
        d = ValueD0;
    }

    ~IPAdress(){     //деструктор
    }

    IPAdress & operator = (const IPAdress &other) { //перегрузка присваивания
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;
        this->d = other.d;
        return *this;
    }

    IPAdress operator - (const IPAdress &other){ //перегрузка вычетания
        IPAdress temp(0, 0, 0, 0);
        if ((int(this->a)-int(other.a) >= 0) && (int(this->b)-int(other.b) >= 0) && (int(this->b)-int(other.b) >= 0) && (int(this->b)-int(other.b) >= 0)){
            temp.a = this->a - other.a;
            temp.b = this->b - other.b;
            temp.c = this->c - other.c;
            temp.d = this->d - other.d;
            return temp;
        }
        cout << "out of range" << endl; //сообщение о выходе за пределы допустимых значений (меньше 0)
    }

    IPAdress operator + (const IPAdress &other){ //перегрузка сложения
        IPAdress temp(0, 0, 0, 0);
        if ((int(this->a)+int(other.a) <= 255) && (int(this->b)+int(other.b) <= 255)&& (int(this->b)+int(other.b) <= 255)&& (int(this->b)+int(other.b) <= 255)){
            temp.a = this->a + other.a;
            temp.b = this->b + other.b;
            temp.c = this->c + other.c;
            temp.d = this->d + other.d;
            return temp;
        }
        cout << "out of range" << endl; //сообщение о выходе за пределы допустимых значений (больше 255)
    }

    bool operator > (const IPAdress &other) {   //перегрузка сравнения "больше"
        return (this->a > other.a) || (this->a == other.a && this->b > other.b) ||
               (this->a == other.a && this->b == other.b && this->c > other.c) ||
               (this->a == other.a && this->b == other.b && this->c == other.c && this->d > other.d);
    }

    bool operator <(const IPAdress &other) {   //перегрузка сравнения "меньше"
        return (this->a < other.a) || (this->a == other.a && this->b < other.b) ||
               (this->a == other.a && this->b == other.b && this->c < other.c) ||
               (this->a == other.a && this->b == other.b && this->c == other.c && this->d < other.d);
    }

    bool affiliation (const IPAdress &mask, const IPAdress &subnet){ //определение принадлежит ли адрес к подсети с данной маской
        return (((this->a & mask.a) == subnet.a) && ((this->b & mask.b) == subnet.b) && ((this->c & mask.c) == subnet.c) & ((this->d & mask.d) == subnet.d));
    }
};

int main() {

    IPAdress ip_1_1(100, 111, 1, 30);
    IPAdress ip_1_3(100, 111, 1, 30);
    IPAdress ip_1_2(255, 255, 255, 255);

    bool i = ip_1_1.affiliation(ip_1_2,ip_1_3);
    cout << i << endl;
    cout << int(ip_1_3.GetA()) << "." << int(ip_1_3.GetB())  << "." << int(ip_1_3.GetC())  << "." << int(ip_1_3.GetD())  << endl;
    return 0;
}
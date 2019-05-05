#include <iostream>
#include <string>
using namespace std;

class Kuriye
{
private:
    string name;
    string surname;
    string TC;
    int age;
public:
void setName(string x){name = x;}
void setSurname(string x){surname = x;}
void setTC(string x){TC = x;}
void setAge(int x){age = x;}

};

class Islem
{
public:
    void find() {}
    void list() {}
    void update() {}
    void del() {}
    void add() {}
};

class Mainclass: public Kuriye, public Islem
{
};

int main(void)
{

    return 0;
}

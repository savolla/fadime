#include <iostream>
#include <string>
#inclute <fstream>
using namespace std;

class Kuriye
{
    private:
        string name;
        string surname;
        string TC;
        int age;
    public:
        // setters
        void setName(string x){name = x;}
        void setSurname(string x){surname = x;}
        void setTC(string x){TC = x;}
        void setAge(int x){age = x;}
        // getters
        string getName(){return name;}
        string getSurname(){return surname;}
        string getTC(){return TC;}
        int getAge(){return Age;}
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

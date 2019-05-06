#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Carrier
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
        int getAge(){return age;}
};

class Operation
{
    public:
        void find() {}
        void list() {}
        void update() {}
        void del() {}
        void add() {}
};

class UserInterface
{
        public:
        UserInterface()
        {
                cout << " .--------------------------------------------." << endl;
                cout << "| Olexy Kargo Otomasyon Sistemine Hos Geldiniz |" << endl;
                cout << " `--------------------------------------------'" << endl;
                cout << "  `-> Su anda ne yapmak istersiniz ?" << endl;
                cout << "      `-> 1 ~ LISTELE  " << endl;
                cout << "      `-> 2 ~ BUL      " << endl;
                cout << "      `-> 3 ~ EKLE     " << endl;
                cout << "      `-> 4 ~ GUNCELLE " << endl;
                cout << "      `-> 5 ~ SIL      " << endl;
        }
        ~UserInterface()
        {
                cout << "Iyi Gunler !" << endl;
        }
};

class Automation: public Carrier, public Operation
{
};

int main(void)
{
        UserInterface GUI;
        return 0;
}

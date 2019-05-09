#include <iostream> // basic I/O
#include <string> // KATARS
#include <fstream> // file I/O
#include <iomanip> // another I/O but with "sauce"
using namespace std;

class Carrier
{
    private:
        string name;
        string surname;
        string TC;
        string order;
        int age;
    public:
        // setters
        void setName(string x){name = x;}
        void setSurname(string x){surname = x;}
        void setTC(string x){TC = x;}
        void setOrder(string x){order = x;}
        void setAge(int x){age = x;}
        // getters
        string getName(){return name;}
        string getSurname(){return surname;}
        string getTC(){return TC;}
        string getOrder(){return order;}
        int getAge(){return age;}
};

class Operation
{
    public:
        void find() {}
        void list() {}
        void update() {}
        void del() {}
        void add()
        {
                system("clear");
                string record[5];
                cout << "TC     " << endl; cout << "`-> "; cin >> record[0];
                cout << "Isim   " << endl; cout << "`-> "; cin >> record[1];
                cout << "Soyisim" << endl; cout << "`-> "; cin >> record[2];
                cout << "Yas    " << endl; cout << "`-> "; cin >> record[3];
                cout << "Siparis" << endl; cout << "`-> "; cin >> record[4];
                system("clear");

                ofstream file("database.txt", ios::app);
                for(int i=0 ;i<6 ;i++)
                {
                        file << '|'<< record[i]<< setw(16 - (record[i].size()));
                }
                file << "|" << endl;
                file << "\r\n";
                file.close();
        }
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
                        cout << "      |                " << endl;
                        cout << "      `-> 1 ~ LISTELE  " << endl;
                        cout << "      `-> 2 ~ BUL      " << endl;
                        cout << "      `-> 3 ~ EKLE     " << endl;
                        cout << "      `-> 4 ~ GUNCELLE " << endl;
                        cout << "      `-> 5 ~ SIL      " << endl;
                        cout << "      |                " << endl;
                        cout << "      `-> 0 ~ [CIKIS]  " << endl;
                        cout << ">> ";
                }
                ~UserInterface()
                {
                        cout << "Iyi Gunler !" << endl;
                }
                void getChoise()
                {
                        int choiseFromMenu;
                        Operation operationObject;
                        cin >> choiseFromMenu;
                        if (choiseFromMenu == 1){operationObject.list();}
                        else if (choiseFromMenu == 2){operationObject.find();}
                        else if (choiseFromMenu == 3){operationObject.add();}
                        else if (choiseFromMenu == 4){operationObject.update();}
                        else if (choiseFromMenu == 5){operationObject.del();}
                        else {cout << "Yanlış bir karakter girdiniz" << endl;}
                }
};

class Automation:
        public Carrier,
        public Operation,
        public UserInterface
{};

int main(void)
{
        Automation object;
        object.getChoise();
        return 0;
}

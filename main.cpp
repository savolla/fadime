#include <iostream> // basic I/O
#include <string> // KATARS
#include <fstream> // file I/O
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
        void add()
        {
        goBackHereIfUserIsStupid:
        ifstream infile;
        infile.open("database.txt",ios::in);
        int size=80;
        char line[size];
        int howManyRecords;
        cout << "Kac kayıt girilecek? : ";
        cin >> howManyRecords;
        Carrier newCarrier;
        string tmp;
        while(howManyRecords > 0)
        {
               infile.getline(line,size);
               cout<<"Name : "; cin >> tmp; newCarrier.setName(tmp);
               infile.getline(line,size);
               cout<<"Surname : "<<line<<endl;
               infile.getline(line,size);
               cout<<"LANGUAGE : "<<line<<endl;
               howManyRecords--;
        }
        infile.close();
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
                        cout << "      `-> 1 ~ LISTELE  " << endl;
                        cout << "      `-> 2 ~ BUL      " << endl;
                        cout << "      `-> 3 ~ EKLE     " << endl;
                        cout << "      `-> 4 ~ GUNCELLE " << endl;
                        cout << "      `-> 5 ~ SIL      " << endl;
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

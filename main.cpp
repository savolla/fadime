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
        string age;
        unsigned char gender;
        string location;

    public:
        // setters
        void setName(string x){name = x;}
        void setSurname(string x){surname = x;}
        void setTC(string x){TC = x;}
        void setOrder(string x){order = x;}
        void setAge(string x){age = x;}
        void setGender(unsigned char x){gender = x;}
        void setLocation(string x){location = x;}
        // getters
        string getName(){return name;}
        string getSurname(){return surname;}
        string getTC(){return TC;}
        string getOrder(){return order;}
        string getAge(){return age;}
        unsigned char getGender(){return gender;}
        string getLocation(){return location;}
};

class Operation
{
    public:
        void find() {}
        void list()
        {
                system("clear");
                fstream file;
                string contentsOfDatabase;
                file.open("database.txt",ios::in);
                while(!file.eof())
                {
                        getline(file,contentsOfDatabase);
                        cout << contentsOfDatabase << endl;
                }
                // Drawing a line below the database.
                for (int i=0; i<170; i++) {cout << "\b";}
                cout << "\'";
                for (int i=0; i<=110; i++) {cout << "-";}
                cout << "\'\n" << endl;
        }
        void update() {}
        void del()
                {
                system("clear");
                list();
                string TCno;cout << "Silinecek Kuryenin TC kimlik numarası: " << endl;cout << "`-> "; cin >> TCno;
                ifstream originalFile("database.txt", ios::in);
                ofstream temporaryFile("tmp.txt", ios::app);
                string placeHolderString = "";

                while (getline(originalFile, placeHolderString))
                {
                        if (placeHolderString.find(TCno) != string::npos) {
                                continue;
                        }
                        temporaryFile << placeHolderString << endl;
                }
                originalFile.close();
                temporaryFile.close();

                remove("database.txt");
                rename("tmp.txt","database.txt");
                system("clear");
                list();

                // nice message with candies :)
                system("echo \".-------------------------.\" | lolcat");
                system("echo \"|Kayit basarıyla silindi!!|\" | lolcat");
                system("echo \"'-------------------------'\" | lolcat");

        }
        void add()
        {
                system("clear");
                string record[7];

                system("echo \".--------------------------------------------------.\" | lolcat");
                system("echo \"| Eklemek istediğiniz Kuryenin bilgilerini giriniz |\" | lolcat");
                system("echo \"'--------------------------------------------------'\" | lolcat");
                cout << "`->";

                string cppIsOdd; getline(cin,cppIsOdd); // This line is just for preventing C++'s obscurity.
                cout << " TC            " << endl; cout << "     `-> "; getline(cin,record[0]);
                cout << " Isim          " << endl; cout << "     `-> "; getline(cin,record[1]);
                cout << " Soyisim       " << endl; cout << "     `-> "; getline(cin,record[2]);
                cout << " Yas           " << endl; cout << "     `-> "; getline(cin,record[3]);
                cout << " Siparis       " << endl; cout << "     `-> "; getline(cin,record[4]);
                cout << " Cinsiyet      " << endl; cout << "     `-> "; getline(cin,record[5]);
                cout << " Teslimat Nok. " << endl; cout << "     `-> "; getline(cin,record[6]);
                system("clear");

                ofstream file("database.txt", ios::app);
                for(int i=0 ;i<7 ;i++)
                {
                        file << '|'<< record[i]<< setw(16 - (record[i].size()));
                }
                file << "|"<< endl;
                file.close();
                system("clear");
                list();

                system("echo \".--------------------------.\" | lolcat");
                system("echo \"| Kayit basariyla eklendi! |\" | lolcat");
                system("echo \"'--------------------------'\" | lolcat");
        }
};

class UserInterface
{
        public:
                UserInterface()
                {
                        cout << ".-------------------------------------------------------------------------------." << endl;
                        cout << "|             _         _             _                                         |"<< endl;
                        cout << "|            | | ____ _| | __ _ ___  | | ____ _ _ __ __ _  ___                  |"<< endl;
                        cout << "|            | |/ / _` | |/ _` / __| | |/ / _` | '__/ _` |/ _ \\                 |"<< endl;
                        cout << "|            |   < (_| | | (_| \\ __\\ |   < (_| | | | (_| | (_) |                |"<< endl;
                        cout << "|            |_|\\_\\__,_|_|\\__,_|___/ |_|\\_\\__,_|_|  \\__, |\\___/                 |"<< endl;
                        cout << "|                                                   |___/                       |"<< endl;
                        cout << "'-------------------------------------------------------------------------------'" << endl;
                        cout << "`-> Su anda ne yapmak istersiniz ?" << endl;
                        cout << "|                                 " << endl;
                }
                int menu()
                {
                        while (true)
                        {
                                cout << "`-> 1 ~ LISTELE  " << endl;
                                cout << "`-> 2 ~ BUL      " << endl;
                                cout << "`-> 3 ~ EKLE     " << endl;
                                cout << "`-> 4 ~ GUNCELLE " << endl;
                                cout << "`-> 5 ~ SIL      " << endl;
                                cout << "                " << endl;
                                cout << "`-> 0 ~ [CIKIS]  " << endl;
                                cout << ">> ";

                                int choiseFromMenu;
                                Operation operationObject;
                                cin >> choiseFromMenu;
                                if      (choiseFromMenu == 1){operationObject.list();}
                                else if (choiseFromMenu == 2){operationObject.find();}
                                else if (choiseFromMenu == 3){operationObject.add();}
                                else if (choiseFromMenu == 4){operationObject.update();}
                                else if (choiseFromMenu == 5){operationObject.del();}
                                //else if (choiseFromMenu == 0){cout << "Güle güle :)"; return 0;}
                                else if (choiseFromMenu == 0){system("clear && echo \"Güle Güle! :)\" | lolcat"); return 0;}
                                else {cout << "Yanlış bir karakter girdiniz" << endl;}
                        }
                        cout << endl;
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
        object.menu();
        return 0;
}

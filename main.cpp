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
                // fake but nice separator. not mendatory but still nice also with sauce ;)
                cout << "'-------------------------------------------------------------------------------'" << endl;
        }
        void update() {}
        void del()
                {
                system("clear");
                list();
                string TCno;cout << "Silinecek degeri giriniz" << endl;cout << "`-> "; cin >> TCno;
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
                //cout << ".--------------------------." << endl;
                //cout << "| Kayıt başarıyla silindi! |" << endl;
                //cout << "'--------------------------'" << endl;

                // nice message with candy
                system("echo \".-------------------------.\" | lolcat");
                system("echo \"|Kayit basarıyla silindi!!|\" | lolcat");
                system("echo \"'-------------------------'\" | lolcat");

        }
        void add()
        {
                system("clear");
                string record[5];
                //cout << ".--------------------------------------------------." << endl;
                //cout << "| Eklemek istediğiniz Kuryenin bilgilerini giriniz |" << endl;
                //cout << "'--------------------------------------------------'" << endl;

                // candies MOORE CANDIEEEES!!
                system("echo \".--------------------------------------------------.\" | lolcat");
                system("echo \"| Eklemek istediğiniz Kuryenin bilgilerini giriniz |\" | lolcat");
                system("echo \"'--------------------------------------------------'\" | lolcat");
                cout << "`->";
                cout << " TC     " << endl; cout << "     `-> "; cin >> record[0];
                cout << " Isim   " << endl; cout << "     `-> "; cin >> record[1];
                cout << " Soyisim" << endl; cout << "     `-> "; cin >> record[2];
                cout << " Yas    " << endl; cout << "     `-> "; cin >> record[3];
                cout << " Siparis" << endl; cout << "     `-> "; cin >> record[4];
                system("clear");

                //ofstream file("database.txt", ios::out | ios::app);
                ofstream file("database.txt", ios::app);
                for(int i=0 ;i<5 ;i++)
                {
                        file << '|'<< record[i]<< setw(16 - (record[i].size()));
                }
                file << "|"<< endl;
                file.close();
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
                                cout << "|                " << endl;
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

#include <iostream>
#include <string>
#include <cstring>
#include <ctime> //Anlık saati cekmek icin kullanilan kutuphane,saat ve servis bilgileri uzerınde ıslem yapicaz//
using namespace std;
bool kgiris;

class Kurye
{
private:
    string ad;
    string soyad;
    string TC;
    int yas;
};

class Islem1
{
public:
    void ekle() {}
    void listele() {}
    void ara() {}
};

class Islem2 {
    public:
   void sil() {}
   void guncelle() {}
};

class Giris {
    protected:
    string kullaniciadi;
    string sifre;
};

class Anaclass: public Kurye, public Islem1, public Islem2, public Giris {
    public:
        void giris();
        void secim();
        void listele_guncelle();
        void serviskayidi_ekleme();
        void serviskayidi_silme();
        void set_kullaniciadi(string *adres);
        void set_sifre(string *adres);
        string get_kullaniciadi();
        string get_sifre();

        Anaclass() {
            kullaniciadi = "oleksi";
            sifre = "kadir";
        }
};

void yazdir(string deger, bool durum) {
	for (int i = 0; i < deger.length(); i++)
	{
		cout << deger[i];
	}
    if (durum)
	{
		cout << endl;
	}
}   
string sdonusturme(char *deger) {
	string deger2;
	for (int i = 0; i < strlen(deger); i++) {
		deger2 += deger[i];
	}
	return deger2;
}
    
// Anaclass'ın fonksiyonları
string Anaclass::get_kullaniciadi() {
	return kullaniciadi;
}
string Anaclass::get_sifre() {
	return sifre;
}
void Anaclass::set_kullaniciadi(string *adres) {
	kullanici = *adres;
}
void Anaclass::set_sifre(string *adres) {
	sifre = *adres;
}
void Anaclass::giris() {
	char kullaniciadi[50], sifre[50];
	string kullanici = "", parola = "";
	yazdir("Kullanici Adi:", true);
	gets_s(kullaniciadi);
	yazdir("Sifre", true);
	gets_s(sifre);
	for (int i = 0; i < strlen(kullaniciadi); i++)
	{
		kullanici += kullaniciadi[i];
	}
	for (int i = 0; i < strlen(sifre); i++)
	{
		parola += sifre[i];
	}
	if (get_kullaniciadi() == kullanici && get_sifre() == parola)
	{
		bgiris = true;
		secim();
	}
	else
	{
		kgiris = false;
		yazdir("Hatali giris yaptiniz,lutfen yeniden deneyiniz.", true);
		giris();
	}
}

int main(void)
{
    return 0;
}

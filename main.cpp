#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>//Anlık saati cekmek icin kullanilan kutuphane,saat ve servis bilgileri uzerınde ıslem yapicaz//
#include<fstream>
using namespace std;
bool kgiris;



class Islem1
{
public:
	void ekle(string veri) {}
	void listele() {}
	void ara() {}
private:
	string ad;
	string soyad;
	string TC;
	int yas;
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

class Anaclass : public Islem1, public Islem2, public Giris {
public:
	void giris();
	void secim();
	void listele_guncelle();
	void serviskayidi_ekleme();
	void serviskayidi_silme();
	void serviskayidi_arama();
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
void Anaclass::secim() {
	if (kgiris)
	{
		system("cls");
		yazdir("Hos geldiniz yapmak istediginiz secimi secin",true);
		yazdir("1-Servis kayidi ekleme", true);
		yazdir("2-Servis kayidi silme", true);
		yazdir("3-Servis kayidi listele veya guncelle", true);
		yazdir("4-Servis kayidi arama", true);
		yazdir("5-Cikis", true);
		int secim;
		cin >> secim;
		while (secim < 1 && secim>5)
		{
			cout << "Lutfen 1 ile 5 arasinda bir secim yapiniz" << endl;
			cin >> secim;
		}
		switch (secim)
		{
		case 1:
		{
			serviskayidi_ekleme();
			break;
		}
		case 2:
		{
			serviskayidi_silme();
			break;
		}
		case 3:
		{
			listele_guncelle();
			break;
		}
		case 4:
		{
			serviskayidi_arama();
			break;
		}
		case 5:
		{
			
		}
		default:
			break;
		}


	}
	else
	{
		giris();
	}




}
void Islem1::ekle(string veri) {

	fstream dosyayaz("bilgi.txt", ios::out); {
		cout << "Kuryenin adini giriniz." << endl;
		cin >> ad;
		cout << "Kuryenin soyadini giriniz." << endl;
		cin >> soyad;
		cout << "Kuryenin TC kimlik numarasini giriniz." << endl;
		cin >> TC;
		cout << "Kuryenin  yasini giriniz." << endl;
		cin >> yas;
	}
	dosyayaz <<ad<<' '<<soyad<<' '<<TC<<' '<<yas<<endl;
	dosyayaz.close();



}

// Anaclass'ın fonksiyonları
string Anaclass::get_kullaniciadi() {
	return kullaniciadi;
}
string Anaclass::get_sifre() {
	return sifre;
}
void Anaclass::set_kullaniciadi(string *adres) {
	kullaniciadi = *adres;
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
		kgiris = true;
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

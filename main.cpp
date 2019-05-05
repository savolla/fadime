#include <iostream>
#inlcude <string>
#include <ctime> //Anlık saati cekmek icin kullanilan kutuphane,saat ve servis bilgileri uzerınde ıslem yapicaz//
using namespace std;
bool kgiris;

Class kurye
{
private:
    string ad;
    string soyad;
    string TC;
    int yas;
};

Class islem1
{
public:
    void ekle() {}
    void listele() {}
    void ara() {}
    
};
class islem2 {
    public:
   void sil() {}
   void guncelle() {}
    
    
};
class kullaniciadi_sifre {
    protected:
    string kullaniciadi;
    string sifre;
};
class anaclass:public kurye,public islem1,public islem2,public kullaniciadi_sifre {
    public:
	void secim();//kullaniciya en basta secim yaptırıcaz servis kaydı ekle çıkış gibi//
    void giris();//yonetim giris paneli olacak, asagıda  yazdım bakabilirsin kanka//
	void listele_guncelle();
	void serviskayidi_ekleme();
	void serviskayidi_silme();
	void set_kullaniciadi(string *adres);//kullanici adini setle gonderdim yazdım asagıda da//
	void set_sifre(string *adres);//sifreyi setle gonderdim yazdım asagıda da//
	string get_kullaniciadi();//kullanici adini getle cagirdim yazdım asagıda da//
	string get_sifre();//sifreyi getle cagırdım yazdım asagıda da//
	anaclass() {
		kullaniciadi = "oleksi";
		sifre = "kadir";
	}
	

};
void yazdir(string deger, bool durum) {
	for (int i = 0; i < deger.length(); i++)
	{
		cout << deger[i];
		

	}if (durum)
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
    
    
    
    
string anaclass::get_kullaniciadi() {
	return kullaniciadi;
}
string anaclass::get_sifre() {
	return sifre;
}
void anaclass::set_kullaniciadi(string *adres) {
	kullanici = *adres;
}
void anaclass::set_sifre(string *adres) {
	sifre = *adres;
}
void anaclass::giris() {
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

return 0;

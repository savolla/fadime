
# Table of Contents

1.  [Giriş](#org1d4610c)
2.  [Kullanım](#org62b619e)
3.  [Programın iç yapısı](#org82d4a10)
    1.  [database.txt](#orgfd41afc)
    2.  [main.cpp](#org398ae50)
        1.  [Classlar ve Açıklamaları](#orgca5413a)



<a id="org1d4610c"></a>

# Giriş

-   Bu projede, "Kalas Kargo" adlı bir kargo şirketinin, Kuryelerin şahsi
    bilgileri ve teslimatını yapacakları ürünlerin bilgileri kayıt edilir.

-   Kayıt edilen bilgiler sırasıyla;
    1.  TC kimlik numarası
    2.  İsim
    3.  Soy İsim
    4.  Yaş
    5.  Kuryenin taşıdığı ürün (Sipariş)
    6.  Cinsiyet
    7.  Tesliman noktası


<a id="org62b619e"></a>

# Kullanım

-   Kullanıcı Programı açtığında, karşısına şirketin adı ve altında sıralanmış
    işlem seçenekleri sunulur
-   Bu seçenekleri seçmek için, başında bulunan numaraların yazılıp `Enter` tuşuna
    basılması gerekir
-   Seçenekler kullanıcıyı adım adım yönlendirme özelliğine sahiptir.


<a id="org82d4a10"></a>

# Programın iç yapısı

-   Proje içinde 2 temel dosya bulunur;
    -   main.cpp
    -   database.txt


<a id="orgfd41afc"></a>

## database.txt

-   Kalas Kargo'nun Kurye bilgilerinin kayıt edildiği dosya
-   Program her işlemde bu dosyayı modifiye eder


<a id="org398ae50"></a>

## main.cpp

-   Program temelde 4 class'dan oluşur
    1.  Carrier *(kurye)*
    2.  UserInterface *(Kullanıcı arayüzü)*
    3.  Operation *(işlem)*
    4.  Automation *(otomasyon)*


<a id="orgca5413a"></a>

### Classlar ve Açıklamaları

1.  Carrier

    -   Kuryenin bütün bilgilerinin ve metodlarının bulunduğu klastır
    -   Yapısı:
        
        ![img](uml/c.png)

2.  UserInterface

    -   Kullanıcının programla olan etkileşimini sağlayan klastır
    -   Yapısı:
        
        ![img](uml/ui.jpg)

3.  Operation

    -   **database.txt** dosyasında değişiklik yapan klastır
    -   Yapısı:
        
        ![img](uml/op.png)

4.  Automation

    -   **Carrier**, **UserInterface**, **Operation** klaslarının tek çatı altında birleştiği
        klastır
    -   Yapısı
        
        ![img](uml/auto.png)


# Otomatik Sınav Simülasyonu ve Değerlendirme Sistemi

Bu proje, çoktan seçmeli sınavlara yönelik bir otomatik sınav simülasyon ve değerlendirme sistemidir. Projede, rastgele cevap anahtarı üretilip öğrencilere bu sınav uygulanır. Öğrenci cevapları, boş bırakma ve doğru cevap verme olasılıklarına göre belirlenir. Sınav sonuçları değerlendirilerek her öğrencinin HBN (Ham Başarı Notu), T-Skoru ve harf notu hesaplanır. Ayrıca sınıf ortalaması ve standart sapması gibi istatistiksel ölçümler de sunulur.

## 🔧 Özellikler

- Rastgele cevap anahtarı üretimi (`A-E` arası)
- Öğrencilerin cevaplarının otomatik simülasyonu
- Boş bırakma ve doğru cevaplama ihtimaline göre değerlendirme
- 4 yanlışın 1 doğruyu götürdüğü HBN puanlama sistemi
- Sınıf ortalaması ve standart sapması hesaplama
- T-Skoru bazlı harf notu tayini (AA, BA, BB, vb.)
- Sınıf başarısını `Üstün Başarı`, `Mükemmel`, `Çok İyi` gibi seviyelere ayırma

## 📁 Dosya İçeriği

Tek bir `.c` dosyasından oluşmaktadır. Kodu derlemek ve çalıştırmak için aşağıdaki adımları takip edebilirsiniz:

## 🚀 Derleme ve Çalıştırma

```bash
gcc sinav_simulasyonu.c -o sinav_simulasyonu -lm
./sinav_simulasyonu
Not: -lm bayrağı math.h kütüphanesini bağlamak için gereklidir.

🧠 Kullanılan Fonksiyonlar
cevap_anahtari_uret: Sınavın doğru cevaplarını üretir.

cevap_anahtari_yazdir: Üretilen cevap anahtarını ekrana yazdırır.

sinavi_uygula: Öğrencilere sınavı uygular (cevapları oluşturur).

ogrenci_cevabini_yazdir: Belirli bir öğrencinin cevaplarını gösterir.

ogrencileri_puanla: Öğrencilerin puanlarını hesaplar (HBN).

sinif_ortalamasi_hesapla: Sınıfın ortalama HBN değerini hesaplar.

standart_sapma_hesapla: HBN puanlarının standart sapmasını hesaplar.

T_skoru_hesapla: Her öğrencinin T-skorunu hesaplayıp harf notunu verir.

📊 Hesaplama Formülleri
Ham Başarı Notu (HBN):

𝐻
𝐵
𝑁
=
(
Do
g
˘
ru Sayısı
−
Yanlı
s
¸
 Sayısı
4
)
×
(
100
Soru Sayısı
)
HBN=(Do 
g
˘
​
 ru Sayısı− 
4
Yanlı 
s
¸
​
  Sayısı
​
 )×( 
Soru Sayısı
100
​
 )
Sınıf Ortalaması:

Ortalama
=
∑
𝐻
𝐵
𝑁
O
¨
g
˘
renci Sayısı
Ortalama= 
O
¨
  
g
˘
​
 renci Sayısı
∑HBN
​
 
Standart Sapma:

𝜎
=
1
𝑛
∑
𝑖
=
1
𝑛
(
𝐻
𝐵
𝑁
𝑖
−
Ortalama
)
2
σ= 
n
1
​
  
i=1
∑
n
​
 (HBN 
i
​
 −Ortalama) 
2
 
​
 
T-Skoru:

𝑇
=
60
+
10
×
(
𝐻
𝐵
𝑁
−
Ortalama
)
Standart Sapma
T=60+10× 
Standart Sapma
(HBN−Ortalama)
​
 
📌 Notlar
Öğrenci cevapları "A", "B", "C", "D", "E" seçeneklerinden oluşur. Boş bırakılan sorular "X" ile işaretlenir.

Tüm hesaplamalar 100 puan üzerinden normalize edilmiştir.

Projede zaman tabanlı rastgelelik (srand(time(0))) kullanıldığı için her çalıştırmada farklı sonuçlar elde edilir.

👨‍💻 Geliştirici
Bu proje C dili kullanılarak geliştirilmiştir. Eğitim amaçlı sınav simülasyonlarında kullanılabilir.

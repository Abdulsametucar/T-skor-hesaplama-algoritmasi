# Otomatik Sınav Değerlendirme Sistemi (C)

Bu proje, çoktan seçmeli sınavların değerlendirilmesi için yazılmış bir C programıdır. Öğrencilere rastgele cevaplar verilerek sınav simülasyonu yapılır, sonuçlar değerlendirilir ve istatistiksel analiz gerçekleştirilir.

## 🚀 Özellikler

- Rastgele cevap anahtarı üretme
- Belirli oranlarda boş, doğru ve yanlış cevap üretme
- Öğrencilerin cevaplarını yazdırma
- Doğru ve yanlış cevaplara göre **Ham Başarı Notu (HBN)** hesaplama
- Sınıfın ortalamasını ve **standart sapmasını** hesaplama
- **T-skoru** ile öğrencileri başarı düzeylerine göre sınıflandırma ve harf notu verme

## 🔧 Kullanılan Fonksiyonlar

| Fonksiyon Adı | Açıklama |
|---------------|----------|
| `cevap_anahtari_uret` | Sınav için rastgele bir cevap anahtarı üretir. |
| `cevap_anahtari_yazdir` | Üretilen cevap anahtarını ekrana yazdırır. |
| `sinavi_uygula` | Öğrencilere boş/doğru/yanlış cevaplar üretir. |
| `ogrenci_cevabini_yazdir` | İstenilen öğrencinin cevaplarını gösterir. |
| `ogrencileri_puanla` | Her öğrenci için doğru/yanlışlara göre HBN hesaplar. |
| `sinif_ortalamasi_hesapla` | Tüm öğrencilerin HBN'lerinin ortalamasını bulur. |
| `standart_sapma_hesapla` | HBN'lerin standart sapmasını hesaplar. |
| `T_skoru_hesapla` | Her öğrenci için T-skoru hesaplayıp harf notu verir. |

## 📊 Değerlendirme Sistemi

- **Her doğru cevap**: +1 puan
- **4 yanlış cevap**: -1 doğruyu götürür
- **Boş cevaplar (X)**: Nötr

> HBN = (Doğru - Yanlış / 4) × (100 / Soru Sayısı)

## 🎓 T-Skoru ve Harf Notu

T-skoru; sınıf ortalaması ve standart sapmaya göre her öğrenciye özel olarak hesaplanır. 
Bu T-skoru sonucuna göre aşağıdaki gibi harf notu verilir:

> **Not çizelgesi**, sınıf ortalamasına göre farklılık göstermektedir (örn. Üstün Başarı, Mükemmel vb.).

| T-Skor Aralığı | Harf Notu |
|----------------|-----------|
| 67 ve üstü     | AA        |
| 62 - 66.99     | BA        |
| 57 - 61.99     | BB        |
| 52 - 56.99     | CB        |
| 47 - 51.99     | CC        |
| 42 - 46.99     | DC        |
| 37 - 41.99     | DD        |
| 32 - 36.99     | FD        |
| 32 altı        | FF        |

## ⚙️ Derleme

Bu projeyi derlemek için terminalde aşağıdaki komutu kullanabilirsin:

```bash
gcc main.c -o sinav
./sinav
```
## 📁 Dosya Yapısı
📦 sinav-projesi/
 ┣ 📄 main.c        # Tüm fonksiyonları içeren ana dosya
 ┗ 📄 README.md     # Proje açıklaması
## 👨‍💻 Geliştirici Notları
srand(time(0)) kullanılarak her çalıştırmada farklı rastgelelik sağlanmıştır.

X karakteri öğrencilerin boş bıraktığı soruları temsil eder.

Öğrencilerin notu 0’ın altına düşerse otomatik olarak 0 yapılır.

## 📜 Lisans
Bu proje eğitim amaçlı geliştirilmiştir ve açık kaynak olarak kullanılabilir.

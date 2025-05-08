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

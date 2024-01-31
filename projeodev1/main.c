#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void cevap_anahtari_uret(char cevap_anahtari[], int sorusayisi)
{
    srand(time(0)); //fonksiyon her cagirildiginda farkli cevap anahtari üretmesi icin kullanildi.
    for(int i=0;i<sorusayisi;i++)
    {
        int a=1+rand()%5;   //[1,5] araliginda rastgele sayi uretilir.
        if(a==1)
            cevap_anahtari[i]='A';
        else if(a==2)
            cevap_anahtari[i]='B';
        else if(a==3)
            cevap_anahtari[i]='C';
        else if(a==4)
            cevap_anahtari[i]='D';
        else
            cevap_anahtari[i]='E';
    }
}
void cevap_anahtari_yazdir(char cevap_anahtari[], int sorusayisi)
{
    printf("Cevap Anahtari:\n");
    for(int i=0;i<sorusayisi;i++)
        printf("%03d:%c | ",i+1,cevap_anahtari[i]);
    printf("\n");
}
void sinavi_uygula(char ogrenci_cevaplari[][100],char cevap_anahtari[],int ogrencisayisi,int sorusayisi,double bosihtimal,double dogruihtimal)
{
    for(int i=0;i<ogrencisayisi;i++)
    {
        for(int j=0;j<sorusayisi;j++)
        {
            double rastgelesayi=(1+rand()%100)/100.0;   //[0,1] araliginda rastgele sayi uretilir.(.0) rastgelesayinin double olmasi icin kullanildi.
            if(rastgelesayi<bosihtimal)//ihtimal sartina gore soru bos birakilir.
                ogrenci_cevaplari[i][j]='X';
            else                                    //sorunun bos olmama durumu.
            {
                rastgelesayi=(1+rand()%100)/100.0;  //[0,1] araliginda rastgele sayi uretilir,ihtimal sartina gore soru dogru ya da yanlis birakilir.
                if(rastgelesayi<dogruihtimal)
                    ogrenci_cevaplari[i][j] = cevap_anahtari[j];
                else // sorunun yanlis olma durumu.
                {
                    do{
                        ogrenci_cevaplari[i][j] =(char)('A' + (int)(rand() % 5));//[0,4] araliginda rastgele sayiyi uretip 'A'nin ascii koduna ekleyerek 5 secenek arasindan cevap uretilir.
                    }while(ogrenci_cevaplari[i][j] == cevap_anahtari[j]);//Bu dongu rastgele uretilen cevabin dogru cevaba esit olmasi istenilmedigi icin yazildi.
                }
            }
        }
    }
}
void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100],int ogrenci_ID,int sorusayisi)
{
    printf("%03d.ogrencinin cevaplari:\n",ogrenci_ID+1);
    for(int i=0;i<sorusayisi;i++)
            printf("%03d:%c | ",i+1,ogrenci_cevaplari[ogrenci_ID][i]);
    printf("\n");
}
void ogrencileri_puanla(char ogrenci_cevaplari[][100],char cevap_anahtari[],double HBN[],int ogrencisayisi, int sorusayisi)
{
    double puanlama=(double)100/sorusayisi;//puanlama degiskeni ogrencinin 100 uzerinden soru basi alacagi puana esit.
    for(int i=0;i<ogrencisayisi;i++)
    {
        int dogru=0,yanlis=0;   //bir onceki ogrencinin dogru ve yanlis sayisi yeni ogrencininkiyle karismasin diye burada tanimlandi.
        for(int j=0;j<sorusayisi;j++)
        {
            if(ogrenci_cevaplari[i][j]==cevap_anahtari[j])
                dogru++;
            else if(ogrenci_cevaplari[i][j]!='X')
                yanlis++;
        }
        HBN[i]=(double)(dogru-(yanlis/4.0))*puanlama;// 4 yanlisin 1 dogruyu goturmesini matematiksel isleme dokup soru basina esit puan ile çarparak HBN hesaplandi.
        if(HBN[i]<0)    //ogrenci notu negatif cikarsa 0 olsun.
            HBN[i]=0;
    }
}
double sinif_ortalamasi_hesapla(double HBN[],int ogrencisayisi)
{
    double sonuc=0.0;
    for(int i=0;i<ogrencisayisi;i++)
        sonuc+=HBN[i];  //sonuc adli degiskene dongu icerisinde her ogrencinin HBN'si eklenir.
    return sonuc/ogrencisayisi;// bu matematik islemle sinifin ortalamasi bulunur.
}
double standart_sapma_hesapla(double ortalama,double HBN[],int ogrencisayisi)
{
    double sonuc=0.0;
    for(int i=0;i<ogrencisayisi;i++)
        sonuc=sonuc+pow((HBN[i]-ortalama),2);
    sonuc=sqrt(sonuc/ogrencisayisi);    //90 ve 91.satir standart sapma formulunun koda cevrilmis halidir.
    return sonuc;
}
void T_skoru_hesapla(double ortalama,double HBN[],int ogrencisayisi,double std,double T_skoru[ ])
{
    if(ortalama>80 && ortalama<=100)    //listeye gore ortalamanin hangi aralikta oldugunu belirleme
    {
        printf("Sinif duzeyi: Ustun Basari\n\nOgrenci notlari:\n");
        for(int i=0;i<ogrencisayisi;i++)
        {
            T_skoru[i]=(60+(10*((HBN[i]-ortalama)/std)));   //her bir öðrenci için T skoru hesaplama formulu.
            if(T_skoru[i]>=67)                              //ogrencinin sinif duzeyine gore harf notunu belirleme
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:AA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=62&&T_skoru[i]<=66.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=57&&T_skoru[i]<=61.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=52&&T_skoru[i]<=56.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=47&&T_skoru[i]<=51.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=42&&T_skoru[i]<=46.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=37&&T_skoru[i]<=41.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=32&&T_skoru[i]<=36.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]<32)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FF\n",i+1,HBN[i],T_skoru[i]);
        }
    }
    else if(ortalama>70 && ortalama<=80)
    {
        printf("Sinif duzeyi: Mukemmel\n\nOgrenci notlari:\n");
        for(int i=0;i<ogrencisayisi;i++)
        {
            T_skoru[i]=(60+(10*((HBN[i]-ortalama)/std)));
            if(T_skoru[i]>=69)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:AA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=64&&T_skoru[i]<=68.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=59&&T_skoru[i]<=63.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=54&&T_skoru[i]<=58.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=49&&T_skoru[i]<=53.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=44&&T_skoru[i]<=48.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=39&&T_skoru[i]<=43.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=34&&T_skoru[i]<=38.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]<34)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FF\n",i+1,HBN[i],T_skoru[i]);
        }
    }
    else if(ortalama>62.5 && ortalama<=70.0)
    {
        printf("Sinif duzeyi: Cok iyi\n\nOgrenci notlari:\n");
        for(int i=0;i<ogrencisayisi;i++)
        {
            T_skoru[i]=(60+(10*((HBN[i]-ortalama)/std)));
            if(T_skoru[i]>=71)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:AA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=66&&T_skoru[i]<=70.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=61&&T_skoru[i]<=65.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=56&&T_skoru[i]<=60.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=51&&T_skoru[i]<=55.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=46&&T_skoru[i]<=50.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=41&&T_skoru[i]<=45.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=36&&T_skoru[i]<=40.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]<36)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FF\n",i+1,HBN[i],T_skoru[i]);
        }
    }
    else if(ortalama>57.5 && ortalama<=62.5)
    {
        printf("Sinif duzeyi: Iyi\n\nOgrenci notlari:\n");
        for(int i=0;i<ogrencisayisi;i++)
        {
            T_skoru[i]=(60+(10*((HBN[i]-ortalama)/std)));
            if(T_skoru[i]>=73)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:AA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=68&&T_skoru[i]<=72.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=63&&T_skoru[i]<=67.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=58&&T_skoru[i]<=62.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=53&&T_skoru[i]<=57.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=48&&T_skoru[i]<=52.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=43&&T_skoru[i]<=47.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=38&&T_skoru[i]<=42.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]<38)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FF\n",i+1,HBN[i],T_skoru[i]);
        }
    }
    else if(ortalama>52.5 && ortalama<=57.5)
    {
        printf("Sinif duzeyi: Ortanin Ustu\n\nOgrenci notlari:\n");
        for(int i=0;i<ogrencisayisi;i++)
        {
            T_skoru[i]=(60+(10*((HBN[i]-ortalama)/std)));
            if(T_skoru[i]>=75)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:AA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=70&&T_skoru[i]<=74.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=65&&T_skoru[i]<=69.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=60&&T_skoru[i]<=64.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=55&&T_skoru[i]<=59.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=50&&T_skoru[i]<=54.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=45&&T_skoru[i]<=49.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=40&&T_skoru[i]<=44.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]<40)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FF\n",i+1,HBN[i],T_skoru[i]);
        }
    }
    else if(ortalama>47.5 && ortalama<=52.5)
    {
        printf("Sinif duzeyi: Orta\n\nOgrenci notlari:\n");
        for(int i=0;i<ogrencisayisi;i++)
        {
            T_skoru[i]=(60+(10*((HBN[i]-ortalama)/std)));
            if(T_skoru[i]>=77)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:AA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=72&&T_skoru[i]<=76.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=67&&T_skoru[i]<=71.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=62&&T_skoru[i]<=66.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=57&&T_skoru[i]<=61.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=52&&T_skoru[i]<=56.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=47&&T_skoru[i]<=51.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=42&&T_skoru[i]<=46.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]<42)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FF\n",i+1,HBN[i],T_skoru[i]);
        }
    }
    else if(ortalama>42.5 && ortalama<=47.5)
    {
        printf("Sinif duzeyi: Zayif\n\nOgrenci notlari:\n");
        for(int i=0;i<ogrencisayisi;i++)
        {
            T_skoru[i]=(60+(10*((HBN[i]-ortalama)/std)));
            if(T_skoru[i]>=79)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:AA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=74&&T_skoru[i]<=78.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=69&&T_skoru[i]<=73.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=64&&T_skoru[i]<=68.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=59&&T_skoru[i]<=63.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=54&&T_skoru[i]<=58.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=49&&T_skoru[i]<=53.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=44&&T_skoru[i]<=48.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]<44)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FF\n",i+1,HBN[i],T_skoru[i]);
        }
    }
    else if(ortalama<=42.5)
    {
        printf("Sinif duzeyi: Kotu\n\nOgrenci notlari:\n");
        for(int i=0;i<ogrencisayisi;i++)
        {
            T_skoru[i]=(60+(10*((HBN[i]-ortalama)/std)));
            if(T_skoru[i]>=81)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:AA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=76&&T_skoru[i]<=80.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BA\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=71&&T_skoru[i]<=75.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:BB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=66&&T_skoru[i]<=70.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CB\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=61&&T_skoru[i]<=65.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:CC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=56&&T_skoru[i]<=60.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DC\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=51&&T_skoru[i]<=55.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:DD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]>=46&&T_skoru[i]<=50.99)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FD\n",i+1,HBN[i],T_skoru[i]);
            else if(T_skoru[i]<46)
                printf("%03d. ogrencinin HBN: %.2lf,T-skoru: %.2lf, harf notu:FF\n",i+1,HBN[i],T_skoru[i]);
        }
    }
}
int main()
{
    int ogrencisayisi,sorusayisi,ogrenci_ID=0;
    double bosihtimal,dogruihtimal,HBN[100],ortalama,std,T_skoru[100];
    char cevap_anahtari[100],ogrenci_cevaplari[100][100];
    printf("ogrenci sayisini giriniz(max 100):");
    scanf("%d",&ogrencisayisi);
    printf("soru sayisini giriniz(max 100):");
    scanf("%d",&sorusayisi);
    printf("bos birakilma ihtimali giriniz(0.0~1.0):");
    scanf("%lf",&bosihtimal);
    printf("dogru cevaplanma ihtimali (0.0~1.0):");
    scanf("%lf",&dogruihtimal);
    printf("\n");
    cevap_anahtari_uret(cevap_anahtari,sorusayisi);
    cevap_anahtari_yazdir(cevap_anahtari,sorusayisi);
    printf("\n");
    sinavi_uygula(ogrenci_cevaplari,cevap_anahtari,ogrencisayisi,sorusayisi,bosihtimal,dogruihtimal);
    for(int i=0;i<ogrencisayisi;i++,ogrenci_ID++)   //bu dongu ogrenci_ID'sinin indis(ogrenci_ID++) olarak gonderilmesi ve ogrenci sayisi kadar artmasi icin yazildi.
        ogrenci_cevabini_yazdir(ogrenci_cevaplari,ogrenci_ID,sorusayisi);
    ogrencileri_puanla(ogrenci_cevaplari,cevap_anahtari,HBN,ogrencisayisi,sorusayisi);
    ortalama=sinif_ortalamasi_hesapla(HBN,ogrencisayisi);
    std=standart_sapma_hesapla(ortalama,HBN,ogrencisayisi);
    printf("\nSinif ortalamasi: %.2lf, standart sapma: %.2lf\n",ortalama,std);
    T_skoru_hesapla(ortalama,HBN,ogrencisayisi,std,T_skoru);
    return 0;
}

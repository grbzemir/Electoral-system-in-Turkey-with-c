#include <stdio.h>
#include <stdlib.h>


int tempsira,tempGecerliOy,tempMVSay,EnBuyuk,x,y;
float OyYuzdesi[100],tempyuzde,MVYuzdesi[100],ToplamOyYuzdesi[100];
int PartiSayisi,GecerliOySayisi,temp=0,YarilanmisOy[50],ToplamMVSay[50],TopilMVSay,GenelTopOy;
int ilPlaka,ilMilletvekili,OySayisi[50],ToplamOySayisi[50],PartiToplam[50],OySirasi[50],MVSay[50],YedekOySayisi[50],MsiOlmayan[50],ildeBirinci[50];
char Partiler[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T'};
int i,j;
int main()
{
    

    ilHesaplama();
}
void ilHesaplama()
{
    printf("Seçime katilan parti sayisi:");
    scanf("%d",&PartiSayisi);

    do{
        GecerliOySayisi=0;

        printf("il Plaka Kodunu Giriniz:");
        scanf("%d",&ilPlaka);
    if (ilPlaka==0)
        {
            TurkiyeGeneli();
        }
    else
    {

        printf("ilin milletvekili kontenjanini giriniz: ");
        scanf("%d",&ilMilletvekili);
        for ( i=0; i<PartiSayisi; i++)
        {
            printf("%c. Partisi’nin oy sayisini giriniz: ",Partiler[i]);
            scanf("%d",&OySayisi[i]);
            ToplamOySayisi[i]+=OySayisi[i];
            GecerliOySayisi+=OySayisi[i];
            tempGecerliOy=GecerliOySayisi;
        }
        GenelTopOy+=tempGecerliOy;
        printf("\n\n\nil Plaka Kodu: %d",ilPlaka);
        printf("\nMilletvekili Kontenjani: %d",ilMilletvekili);
        printf("\nGecerli Oy Sayisi:%d",GecerliOySayisi);
            for (i=0;i<PartiSayisi;i++)
    {
        OyYuzdesi[i]=((float)OySayisi[i]/(float)tempGecerliOy)*100;
        ToplamOyYuzdesi[i]=((float)ToplamOySayisi[i]/(float)GenelTopOy)*100;
    }
        MilletVekiliSay();

    }
    }while(ilPlaka!=0);
}
void Mılletvekılısay ()
{
    TopilMVSay+=ilMilletvekili;
    for (i=0;i<PartiSayisi;i++)
    {
    MVSay[i]=0;
    YedekOySayisi[i]=OySayisi[i];
    }
    do
    {
        EnBuyuk = YedekOySayisi[0];
        for (i=0;i<PartiSayisi;i++)
        {
            if (YedekOySayisi[i]>EnBuyuk)
            {
                EnBuyuk=YedekOySayisi[i];
            }
            else
            {
                continue;
            }
        }
        for (i=0;i<PartiSayisi;i++)
        {
            if (EnBuyuk==YedekOySayisi[i])
            {
                MVSay[i]+=1;
                YedekOySayisi[i]=YedekOySayisi[i]/2;
                ilMilletvekili--;
            }
        }
    }

    while(ilMilletvekili!=0);
    for (i=0;i<PartiSayisi;i++)
    ToplamMVSay[i]+=MVSay[i];

    for (i=0;i<PartiSayisi;i++)
    {
        MVYuzdesi[i]=((float)ToplamMVSay[i]/(float)TopilMVSay)*100;
    }


    Siralama();
}
void Sıralama()
{

    for(i=0;i<50;i++){OySirasi[i]=i;}/*Oy sýrasýna göre parti yazdýrmak için yapýldý. OySirasi[i] deki i sýrayý belirtirken;
    i partinin numarasýný belirtiyor*/


    for ( i=0; i<PartiSayisi-1; i++)
        {
            for (j=0;j<PartiSayisi-i-1;j++)
            {
                if (OySayisi[j]<OySayisi[j+1])
                {
                    temp = OySayisi[j];
                    tempsira = OySirasi[j];
                    tempMVSay= MVSay[j];
                    MVSay[j]=MVSay[j+1];
                    OySirasi[j] = OySirasi[j+1];
                    OySayisi[j] =OySayisi[j+1];
                    OySayisi[j+1]= temp;
                    OySirasi[j+1]=tempsira;
                    MVSay[j+1]=tempMVSay;
                }
            }
        }
        ildeBirinci[OySirasi[0]]+=1;
        for ( i=0; i<PartiSayisi-1; i++)
        {
            for (j=0;j<PartiSayisi-i-1;j++)
            {
                if (OyYuzdesi[j]<OyYuzdesi[j+1])
                {
                    tempyuzde = OyYuzdesi[j];
                    OyYuzdesi[j]=OyYuzdesi[j+1];
                    OyYuzdesi[j+1]=tempyuzde;
                }
            }
        }
        for (i=0;i<PartiSayisi;i++)
        {
            if (MVSay[i]==0)
            {
                MsiOlmayan[i]+=1;
            }
        }



        printf("\n\t\tOy Sayisi\t\tOy Yüzdesi\t\tMV Sayisi");
        printf("\n\t\t---------\t\t----------\t\t---------");

        for (i=0; i<PartiSayisi; i++)
        {
            printf("\n%c Partisi\t  %d\t\t\t    %.2f\t\t   %d",Partiler[OySirasi[i]],OySayisi[i],OyYuzdesi[i],MVSay[i]);
        }
         printf("\n\n");
}
void TurkıyeGeneli()
{
        printf("\nTürkiye Geneli\nMilletvekili Kontenjani:%d\nGeçerli Oy Sayisi:%d\n",TopIlMVSay,GenelTopOy);
        printf("\n\t\tOy Sayisi\t\tOy Yüzdesi\t\tMV Sayisi\t\tMV Yüzdesi\t\t1.lik Sayisi\t\t0 MV Sayisi");
        printf("\n\t\t---------\t\t----------\t\t---------\t\t----------\t\t------------\t\t-----------\t\t");
for (i=0; i<PartiSayisi; i++)
    {
        printf("\n%c Partisi\t  %d\t\t\t",Partiler[i],ToplamOySayisi[i]);
        printf("    %.2f\t\t   %d\t\t\t",ToplamOyYuzdesi[i],ToplamMVSay[i]);
        printf("    %.2f\t\t     %d\t\t\t   %d",MVYuzdesi[i],IldeBirinci[i],MsiOlmayan[i]);
    }

int tempIktidOy=ToplamOySayisi[0];
int IktidPart=ToplamMVSay[0];
for (i=0;i<PartiSayisi;i++)
{
    if (IktidPart<ToplamMVSay[i])
    {
        IktidPart=ToplamMVSay[i];
        tempIktidOy=ToplamOySayisi[i];
        x=i;
    }
    else if (IktidPart==ToplamMVSay[i])
    {
        if (ToplamOySayisi[i]>tempIktidOy)
        {
            IktidPart=ToplamMVSay[i];
            tempIktidOy=ToplamOySayisi[i];
            x=i;
        }
    }
}
int MuhPart=0;
int tempMuhOy=0;
for (i=0;i<PartiSayisi;i++)
{
    if (x==i)
    {
        continue;
    }
    else if (MuhPart<ToplamMVSay[i])
    {
        MuhPart=ToplamMVSay[i];
        tempMuhOy=ToplamOySayisi[i];
        y=i;
    }
    else if (MuhPart==ToplamMVSay[i])
    {
        if (ToplamOySayisi[i]>tempMuhOy)
        {
            MuhPart=ToplamMVSay[i];
            tempMuhOy=ToplamOySayisi[i];
            y=i;
        }
    }
}
printf("\n\niktidar Partisi= %c",Partiler[x]);
printf("\nAna Muhalifet Partisi= %c",Partiler[y]);


}











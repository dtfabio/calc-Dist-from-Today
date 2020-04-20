#include <iostream>
#include <ctime>
#include <new>
using namespace std;

int* getData()
{
time_t data = time(NULL);//data salvata in data
tm* tempo = localtime(&data);//inizializza struttura tm
int* times = new int[3];//array che contiene gm, m, a
times[0] = tempo->tm_mday;//giorno mese
times[1] = tempo->tm_mon;//mese
times[2] = tempo->tm_year;//anno

return times;
}

int Calcolagiorni(int g, int m, int a)
{
    int gm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int ris=0;
    int k;
    if(a%4==0)
      gm[2]=29;
         for(k=1;k<=m-1;k++)
             ris=ris+gm[k];
         ris=ris+g;
    return ris;
}

int Dist(int giorno1, int mese1, int anno1, int giorno2, int mese2, int anno2)
{
    int k;
    int Operazione=0;
    if(anno1==anno2)
          Operazione=Calcolagiorni(giorno2,mese2,anno2)-Calcolagiorni(giorno1,mese1,anno1);
    else
    {
    for(k=anno1+1;k<=anno2-1;k++)
     {
     if(k%4==0)
          Operazione=Operazione+366;
     else
          Operazione=Operazione+365;
     }
     Operazione=Operazione+(365-Calcolagiorni(giorno1,mese1,anno1)+Calcolagiorni(giorno2,mese2,anno2));

     if(anno1%4==0)
          Operazione=Operazione+1;
    }
    return Operazione;
}


int main()
{
int ng;


int* oggi = new int[3];
oggi = getData();

ng=Calcolagiorni(oggi[0], oggi[1]+ 1, oggi[2]+ 1900);
cout<<"Sono trascorsi dall'inizio dell anno "<<ng<<" giorni"<<endl;


system("pause");
}

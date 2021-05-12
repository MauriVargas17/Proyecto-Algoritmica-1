//
//  EncriptadorDeLocacion.cpp
//  Proyecto Algoritmica 1
//
//  Created by Mauricio Vargas on 5/11/21.
//


#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
const long long MAX_SIZE = 1000001;

using namespace std;
string locaciones[] = {"Argentina", "Bolivia", "Chile", "Dinamarca", "Ecuador", "Francia", "Guyana", "Holanda", "Islandia", "Jerusalem","Kyoto", "Libano", "Marruecos", "Nigeria", "Oslo", "Perú", "Quito", "Rumania", "Serbia", "Taiwán", "Uganda", "Venezuela", "Washington", "Xian", "Yakarta", "Zambia"};
vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);

void manipulated_sieve(int N)
{

    isprime[0] = isprime[1] = false ;


    for (long long int i=2; i<N ; i++)
    {

        if (isprime[i])
        {

            prime.push_back(i);


            SPF[i] = i;
        }


        for (long long int j=0;
             j < (int)prime.size() &&
             i*prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i*prime[j]]=false;


            SPF[i*prime[j]] = prime[j] ;
        }
    }
}


int convertToASCII(string letter)
{
    int v;
        char x = letter.at(0);
        v = int(x);
    return v;
}



int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}
    
void creadorLlaves(int seguridad, int rnd1, int rnd2, string message){
    manipulated_sieve(seguridad);
    
    
    double p = prime[(rnd1 % prime.size())];
    double q = prime[(rnd2 % prime.size())];
    double n = p * q;
    double track;
    double phi= (p-1)*(q-1);
    
    double e=2;
    
    while(e<phi) {
       track = gcd(e,phi);
       if(track==1)
          break;
       else
          e++;
    }

    double d1=1/e;
    double d=fmod(d1,phi);

    double msg = convertToASCII(message);
    double c = pow(msg,e);
   
    cout<<"Las llaves privadas son las siguientes: "<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"q: "<<q<<endl;
    cout<<"d: "<<d<<endl;
    cout<<"Las llaves públicas son las siguientes: "<<endl;
    cout<<"n: "<<n<<endl;
    cout<<"e: "<<e<<endl;
 cout<<"Mensaje original: "<<message;

    cout<<"\n"<<"Mensaje encriptado = "<<c<<endl;

    
}


void desencriptador(double p, double q, double d, double mensaje){
    double n = p * q;
    double c = mensaje;
    double m = pow(c,d);

    m=fmod(m,n);
    int res1 = (int) (m+0.001);
    
    char inicial = res1;
    
    for (int i = 0; i < sizeof(locaciones)/sizeof(locaciones[0]); i++){
        if (locaciones[i].at(0) == inicial){
            cout<<"\n"<<"Mensaje desencriptado = "<<locaciones[i]<<endl;
        }
    }
    
}
    

int main() {
   
   double p;
   double q;
   double d;
   
  
    int respuesta = 0;
    while (respuesta != 4){
        cout<<endl;
        cout<<"¡Bienvenido al Encriptador de Locación!"<<endl;
        cout<<"Escoja una opción: "<<endl;
        
        cout<<"1. Encriptar una locación"<<endl;
        cout<<"2. Desencriptar una locación"<<endl;
        cout<<"3. Mostrar la lista de locaciones"<<endl;
        cout<<"4. Terminar el programa"<<endl;
    cin>>respuesta;
    if (respuesta == 1){
        int seguridad;
        string mensaje;
        cout<<"Ingrese a continuación el nivel de seguridad"<<endl;
        cout<<"1. +"<<endl;
        cout<<"2. ++"<<endl;
        cout<<"3. +++"<<endl;
        cin>>seguridad;
        int rnd1, rnd2;
        cout<<"Ingrese a continuación dos números a elección no mayores a 2^32"<<endl;
        cin>>rnd1>>rnd2;
        rnd1 += 10;
        rnd2 += 10;
        cout<<"Ingrese a continuación el nombre de la locación que desea encriptar: "<<endl;
        cin>>mensaje;
        if (seguridad == 1){
            
            creadorLlaves(100, rnd1, rnd2, mensaje);
        } else if (seguridad == 2){
            creadorLlaves(1000, rnd1, rnd2, mensaje);
        } else if (seguridad == 3){
            creadorLlaves(10000, rnd1, rnd2, mensaje);
        }
    }  else if (respuesta == 3){
        for (int i = 0; i < sizeof(locaciones)/sizeof(locaciones[0]); i++){
            cout<<locaciones[i]<<" ";
        }
        cout<<endl;
    } else if (respuesta == 2){
        double mensaje;
        int exp;
         cout<<"Ingrese a continuación la llaves privadas: "<<endl;
         cout<<"| p | q | d |"<<endl;
         cin>>p>>q>>d;
         
         cout<<"Ingrese a continuación el código que desea desencriptar: "<<endl;
         cin>>mensaje;
        cout<<"Ingrese a continuación el exponente de su código (si no aplica coloque 0): "<<endl;
        cin>>exp;
        mensaje = mensaje * pow(10, exp);
         desencriptador(p,q,d,mensaje);
    }
    }
    
    
}

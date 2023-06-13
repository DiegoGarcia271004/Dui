#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void escribir(char Dui);
int comparar(char Dui);
void ingreso_Dui();

//case 2:
//{


int main()
{
    ingreso_Dui();

    return 0;
}

//}

void ingreso_Dui()
{
    system("cls");
    int validacion_While = 1;
    while(validacion_While == 1)
    {
        cout << "Ingrese su DUI:";
        char Dui[8];
        cin >> Dui[8];

        validacion_While = comparar(Dui[8]);

        if(validacion_While == 1)
        {
            escribir(Dui[8]);
            //Se valida el proceso de votación y se procede a votar
        }
    }
}


//Funcion escribir terminada
void escribir(char Dui)
{
    fstream duitxt;
    //duitxt debe cambiarse por el documento .txt en el cual se guarden los duis que ya han votado
    system("cls");
    duitxt.open("Dui2.txt", ios::out);

    if(duitxt.fail())
    {
        cout << "El archivo de escritura no se pudo abrir" << endl;
        exit(1);
    }

    duitxt << Dui << endl;
    duitxt.close();
}




int comparar(char Dui)
{
    
    ifstream lectura;
    
    lectura.open("Dui2.txt",ios::in);

    char duiArchivado[8];
    bool encontrado = false;
    if(lectura.fail())
    {
        cout << "El archivo de lectura no se pudo abrir" << endl;
        exit(1);
    }

    lectura >> duiArchivado;
    while(!lectura.eof() && !encontrado)
    {
        lectura >> duiArchivado;

        if(duiArchivado[8] == Dui)
        {
            cout << "Usted ya ha votado\n";
            return 0;
        }
        else 
        {
            cout << "Bienvenido\n";
            return 1;
        }
    }
}

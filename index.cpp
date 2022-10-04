#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


struct prodotto{
    string codice;
    string nome;
    float prezzo;
    string categoria;
};

void visualizza(prodotto tabella[], int n);
void leggi(prodotto tabella[], int &n);

void visualizza(prodotto tabella[], int n){
    for(int i=0; i<n; i++){
        cout << tabella[i].codice << " ";
        cout << tabella[i].nome << " ";
        cout << tabella[i].prezzo << " ";
        cout << tabella[i].categoria << endl;
    }
}

void leggi(prodotto tabella[], int &n){
    ifstream in("restourantdb.csv");
    if(!in){
        cout << "Errore nell'apertura del file";
        exit(1);
    }
    n = 0;
    string riga;
    while(getline(in, riga)){
        int pos = riga.find(';');
        tabella[n].codice = riga.substr(0, pos);
        riga = riga.substr(pos+1);
        pos = riga.find(';');
        tabella[n].nome = riga.substr(0, pos);
        riga = riga.substr(pos+1);
        pos = riga.find(';');
        tabella[n].prezzo = stof(riga.substr(0, pos));
        riga = riga.substr(pos+1);
        tabella[n].categoria = riga;
        n++;
    }
    in.close();
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "funkcje.hpp"


using namespace std;

enum class ETRYB {
    SZYFROWANIE, DESZYFROWANIE, BRAK
};

struct parametry {
    bool arg_wej_ok;
    ETRYB tryb_pracy;
    string nazwa_pliku_wej;
    string nazwa_pliku_klucz;
};

parametry analiza_param_wej(int argc, char* argv[])
{
    parametry p;

    // wczytywanie arg wej
    std::vector<std::string> arg;
    for (int i = 0; i < argc; ++i) {
        arg.push_back(argv[i]);
    }

    // analiza arg wej.
    p.tryb_pracy = ETRYB::BRAK;
    p.arg_wej_ok = true;
    p.nazwa_pliku_wej = "";
    p.nazwa_pliku_klucz = "";
    for (int i = 0; i < arg.size(); ++i)
    {
        if (arg[i] == "-en") {
            if (p.tryb_pracy != ETRYB::BRAK) {
                p.arg_wej_ok = false;
                break;
            }
            //referencja do szyfrowania
            p.tryb_pracy = ETRYB::SZYFROWANIE;
        }

        if (arg[i] == "-de") {
            if (p.tryb_pracy != ETRYB::BRAK) {
                p.arg_wej_ok = false;
                break;
            }
            //referencja do deszyfrowania
            p.tryb_pracy = ETRYB::DESZYFROWANIE;
        }

        if (arg[i] == "-i") { // plik do szyfr.
            if ((i + 1) >= arg.size()) {

                p.arg_wej_ok = false; break;
            }
            p.nazwa_pliku_wej = arg[i + 1];
        }

        if (arg[i] == "-k") { // klucz
            if ((i + 1) >= arg.size()) {

                p.arg_wej_ok = false; break;
            }
            p.nazwa_pliku_klucz = arg[i + 1];
        }

        if (arg[i] == "help") {
            cout << "Dostêpne tryby dzia³ania programu: \n"
                "-en szyfrowanie \n"
                "-de deszyfrowanie \n"
                "-i plik.txt plik w formacie txt zawierajacy tekst jawny \n"
                "-k klucz.txt klucz do zaszyfrowania tekstu w formacie txt \n"
                "-o nazwa.txt nazwa pliku z tekstem zaszyfrowanym ktory utworzy program \n" << endl; break;
            }
            
        
    }

    return p;
}


std::string szyfruj(std::string jawny, std::string klucz) {
	
	std::string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int dlug_alfabetu = alfabet.length();

	transform(jawny.begin(), jawny.end(), jawny.begin(), ::toupper);

	transform(klucz.begin(), klucz.end(), klucz.begin(), ::toupper);
	std::cout << jawny << std::endl;
	std::cout << klucz << std::endl;
	int index = 0;
	std::string zaszyfrowany = "";

    for (int i = 0; i < jawny.length(); i++) {//
        char litera = jawny[i];
        if (isalpha(litera)) {
            int position = (alfabet.find(litera) + alfabet.find(klucz[index])) % 26;
            char e_litera = alfabet[position];
            zaszyfrowany += e_litera;
            index++;
            if (index >= klucz.length()) {
                index %= klucz.length();
            }
        }
        else {
            zaszyfrowany += litera;
            index = 0;
        }
    }
    cout << zaszyfrowany << endl;
    return zaszyfrowany;
    

}


#ifndef FUNKCJE_HPP
#define FUNKCJE_HPP

enum class ETRYB {
    SZYFROWANIE, DESZYFROWANIE, BRAK
};

struct parametry {
    bool arg_wej_ok;
    ETRYB tryb_pracy;
    string nazwa_pliku_wej;
    string nazwa_pliku_klucz;
};
parametry analiza_param_wej(int argc, char* argv[]);

std::string szyfruj(std::string jawny, std::string klucz);

#endif
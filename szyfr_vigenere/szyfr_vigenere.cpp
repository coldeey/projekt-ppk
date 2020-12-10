#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "funkcje.hpp";

//NIE ZAPOMINAJ O DEBUGGERZE F5 F10 F10

using namespace std;
/*void szyfruj_plik(std::string klucz) {
    std::ifstream plik_wejsciowy;
    std::string nazwa_pliku, dane;
    std::cout << "Podaj nazwe pliku : ";
    std::cin >> nazwa_pliku;

    //czytannie z pliku
    try {
        plik_wejsciowy.open(nazwa_pliku);
        std::stringstream ss;
        ss << plik_wejsciowy.rdbuf();
        dane = ss.str();
        //std::cout << "Plik został wczytany" << std::endl;
    }
    catch (std::exception e) { //nie potrzebne
        std::cout << e.what(); //nie potrzebne
    }

    //szyfrowanie stringa
    std::string zaszyfrowane_dane = szyfruj(dane, klucz);
    std::cout << "Plik zostal pomyslnie zaszyfrowany!" << std::endl;
    std::ofstream plik_wyjsciowy;
    //zapis zaszyfrowanego pliku na pulpit
    try {
        plik_wyjsciowy.open("C:\\Users\\user\\Desktop\\zaszyfrowany.txt");
        plik_wyjsciowy << zaszyfrowane_dane;
        plik_wyjsciowy.close();
        std::cout << "Zaszyfrowany plik został umieszczony na pulpicie!" << std::endl;
    }
    catch (std::exception ee) { //nie potrzebne
        std::cout << ee.what(); //nie potrzebne
    }


}*/
int main(int argc, char * argv[])
{ 
    
    parametry param = analiza_param_wej(argc, argv);
    
    

    if (!param.arg_wej_ok) {
        // informacja o błędzie, instrukcja obslugi programu
        //std::cout << "Wystapil blad w lini polecen..." << endl;

        std::cout << "Program do implementacji szyfru Vigenerea" << std::endl;
        std::cout << "..";

        return 0;
    }

    //param jako argument do szyfrujaca
    //rozbudowac na pliki naglowkowe


    switch (param.tryb_pracy) {
    case ETRYB::SZYFROWANIE:
        //wywolanie funkcji szyfrowanie
        break;

    case ETRYB::DESZYFROWANIE:
        //wywolanie funkcji deszyfrowanie
        break;


    }
}











/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string alp = "abcdefghijklmnopqrstuvwxyz";

int pozycjaAlfabet(char znak){

	for(int i=0;i<alphabet.size();i++){

		if (alphabet[i]==znak||alp[i]==znak) {

			return i;

		}

	}

    return -1;

}*/

/*std::string encryption(std::string text, std::string klucz)
{
    std::string result;
    std::ifstream ifs("do_zaszyfrowania.txt" "tekst.txt"); std::string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    for (int i = 0; i < text.size(); i++) {

        int pozycjaLiteryKlucza = pozycjaAlfabet(klucz[i % klucz.size()]);

        int pozycjaLiteryTekstu = pozycjaAlfabet(text[i]);

        result += alphabet[(pozycjaLiteryTekstu + pozycjaLiteryKlucza) % alphabet.size()];

        std::cout << result << std::endl;

        return result;
    }
}*/

/*
int main()
{   





}
 */






/*std::string str = "C++ Programming is awesome";
    char checkCharacter = 'a';
    int count = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] ==  checkCharacter)
        {
            ++ count;
        }
    }

    cout << "Number of " << checkCharacter << " = " << count;*/
/*
using namespace std;

class Vigenere
{
public:
    string key;

    Vigenere(string key)
    {
        for (int i = 0; i < key.size(); ++i)
        {
            if (key[i] >= 'A' && key[i] <= 'Z')
                this->key += key[i];
            else if (key[i] >= 'a' && key[i] <= 'z')
                this->key += key[i] + 'A' - 'a';
        }
    }

    string encrypt(string text)
    {
        string out;

        for (int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];

            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;

            out += (c + key[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % key.length();
        }

        return out;
    }

    string decrypt(string text)
    {
        string out;

        for (int i = 0, j = 0; i < text.length(); ++i)
        {
            char c = text[i];

            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;

            out += (c - key[j] + 26) % 26 + 'A';
            j = (j + 1) % key.length();
        }

        return out;
    }
};

int main()
{
    Vigenere cipher("VIGENERECIPHER");

    string original;
    cout << "tekst: " << endl;
    cin >> original;
    string encrypted = cipher.encrypt(original);
    string decrypted = cipher.decrypt(encrypted);

    cout << original << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
}
*/
/*char alphabet[32][32] = { 'A','Ą','B','C','D','E','F','G','H','I','J','K','L','Ł','M','N','O','Ó','P','Q','R','S','Ś','T','U','V','W','X','Y','Z','Ź','Ż' };



    std::string readPlain(const std::string& filename)
    {
        std::string line;
        std::string to_table;

        std::ifstream plain(filename);
        if (plain.is_open())
        {
            getline(plain, line);
            plain.close();
        }
        else std::cout << "cant open file" << std::endl;
        return to_table;
    }

    std::string readKey(const std::string& key)
    {
        std::string line;
        std::string to_table;

        std::ifstream plain(key);
        if (plain.is_open())
        {
            getline(plain, line);

            plain.close();
        }
        else std::cout << "cant open file" << std::endl;

        return to_table;
    }

    int tableArr[26][26];
    void tworzenieTabeli() {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                int temp;
                if ((i + 65) + j > 90) {
                    temp = ((i + 65) + j) - 26;


                    tableArr[i][j] = temp;
                }
                else {
                    temp = (i + 65) + j;


                    tableArr[i][j] = temp;
                }
            }
        }

    }

    void encipher(std::string plaintext, std::vector<std::string> key)
    {
        tworzenieTabeli();
        string zaszyfrowanytekst = "";
        for (int i = 0; i < tekst.length(); i++)
        {
            if (tekst[i] == 32 && klucz[i] == 32)
            {
                zaszyfrowanytekst += " ";
            }
            else
            {
                std::string x = (int)tekst[i] - 65;
                std::string y = (int)klucz[i] - 65;
                zaszyfrowanytekst += (char)tableArr[x][y];
            }
        }
    }
    void messageAndKey() {
        m
            string msg;
        cout << "Enter message: ";
        getline(cin, msg);
        cin.ignore();


        for (int i = 0; i < msg.length(); i++) {
            msg[i] = toupper(msg[i]);
        }

        string key;
        cout << "Enter key: ";
        getline(cin, key);
        cin.ignore();


        for (int i = 0; i < key.length(); i++) {
            key[i] = toupper(key[i]);
        }

        string message;
        string mappedKey;



        string keyMap = "";
        for (int i = 0, j = 0; i < msg.length(); i++) {
            if (msg[i] == 32) {
                keyMap += 32;
            }
            else {
                if (j < key.length()) {
                    keyMap += key[j];
                    j++;
                }
                else {
                    j = 0;
                    keyMap += key[j];
                    j++;
                }
            }
        }
        message = msg;
        mappedKey = keyMap;


        int main()
        {




            auto text = readPlain("do_zaszyfrowania.txt");
            auto key = readKey("Tekst.txt");

            for (const auto& line : text)
            {
                std::cout << line << std::endl;

            }
            for (const auto& line : key)
            {
                std::cout << line << std::endl;

            }

        }*/



/*
int main() {
	string linijka;
	ifstream jawny("do_zaszyfrowania.txt");
	if (jawny.is_open())
	{
		while (getline(jawny, linijka))
		{
			cout << linijka << '\n';
		}
		jawny.close();
	}

	else cout << "Unable to open file";

	return 0;



}






#include <iostream>

using namespace std;


*/
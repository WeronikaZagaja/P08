
//deklaracja bibliotek
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void foo(fstream& output) // funkcja zewnetrzna
{
    int rozmiar, roznica , *Z; //deklaracja zmiennych

    cout <<endl<<endl<< "podaj ilosc liczb: ";
    cin >> rozmiar;
	double liczba[rozmiar];
    Z = new int [rozmiar]; //tablica dynamiczna

    for (int j=0; j<rozmiar; j++)
        {
        cout << "podaj " << j+1 << " liczbe: "; //wpisywanie kolejnych danych wejsciowych przez uzytkownika
        cin >> liczba[j];
        }
    cout <<endl<< "podaj wartosc roznicy: ";
    cin >> roznica;

//wyszukiwanie liczb ktorych roznica jest rowna podanej wartosci
    for(int i=0; i<rozmiar; i++)
    {
        double x = liczba[i];
        if(x-floor(x) != 0) continue;

		for(int j=0; j<rozmiar; j++) {
			int y = liczba[j];
            if (y - x == roznica)
			{   cout << endl<<"[" << x << "," << y << "]"; //wypisanie danych wyjsciowych w programie
				output << "[" << x<< "," << y << "]" << endl; //wypisanie danych wyjsciowych w pliku .txt
                cout<<endl<<endl;
            // ograniczenie powtarzajacych sie danych wyjsciowych
				for(int i2=0; i2<rozmiar; i2++)
                    { if(liczba[i2] == x) liczba[i2] += 0.5; }
				break;
			}
        }
    }
    delete[] Z;
}
int main()
{
    fstream output;
    output.open("wyniki.txt", ios::out); //utworzenie pliku wyjsciowego .txt

    foo(output); //odwołanie sie do funkcji zewnetrznej - test1
    foo(output); //odwołanie sie do funkcji zewnetrznej - test2
    foo(output); //odwołanie sie do funkcji zewnetrznej - test3
    output.close();

    return 0; //zakończenie programu
}


#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int nummeric();
int reverse();
int output();
struct Sortering;
inline bool operator<(const Sortering& a, const Sortering& b);

struct Sortering
{
    Sortering(int siffror, string bokstaver, string romerska)
    {
        this->siffror = siffror;
        this->bokstaver = bokstaver;
        this->romerska = romerska;
    }
    int siffror;
    string bokstaver;
    string romerska;
};

inline bool operator<(const Sortering& a, const Sortering& b)
{
    return a.siffror < b.siffror;
}

int main(int argc, char* argv[])
{
    char option;
    string file;
    while(cin>>file)
    {
        while ((option = getopt(argc, argv, ":nrovh")) !=-1)
        {
            switch(option)
            {
                case 'n' :
                    nummeric();
                    break;
                case 'r' :
                    reverse();
                    break;
                case 'o' :
                    output();
                    break;
                case 'v' :
                    cout << "Version 1" << endl;
                    break;
                case 'h' :
                    cout << "Tillgängliga switchar: " << endl;
                    cout << "-n Sorterar indatat" << endl;
                    cout << "-r Sorterar indatat i omvänd  ordning" << endl;
                    cout << "-o Skriver ut resultatet till filen file" << endl;
                    cout << "-v Skriver ut versionsnummret" << endl;
                    cout << "-h Skriver ut denna text" << endl;
                    break;
            }
        }
    }
    return 0;
}

int nummeric()
{
    int siffror;
    string bokstaver;
    string romerska;
    vector<Sortering> vecSortering;
    ifstream in("projekt.txt");
	if (in.is_open())
	{
		while (in >> siffror >> bokstaver >> romerska)
		{
			vecSortering.push_back(Sortering(siffror, bokstaver, romerska));
		}
	}
	else
	{
		cout << "Filen öppnades ej korrekt" << endl;
	}

    sort(vecSortering.begin(),vecSortering.end());

    for(size_t i=0; i<vecSortering.size(); ++i)
    {
        cout << vecSortering[i].siffror << " " << vecSortering[i].bokstaver << " " << vecSortering[i].romerska << endl;
    }
    return 0;
}

int reverse()
{
    int siffror;
    string bokstaver;
    string romerska;
    vector<Sortering> vecSortering;
    ifstream in("projekt.txt");
	if (in.is_open())
	{
		while (in >> siffror >> bokstaver >> romerska)
		{
			vecSortering.push_back(Sortering(siffror, bokstaver, romerska));
		}
	}
	else
	{
		cout << "Filen öppnades ej korrekt" << endl;
	}

    sort(vecSortering.rbegin(),vecSortering.rend());

    for(size_t i=0; i<vecSortering.size(); ++i)
    {
        cout << vecSortering[i].siffror << " " << vecSortering[i].bokstaver << " " << vecSortering[i].romerska << endl;
    }
    return  0;
}

int output()
{
    int siffror;
    string bokstaver;
    string romerska;
    vector<Sortering> vecSortering;
    ifstream in("projekt.txt");
    ofstream out("output.txt");
    if (in.is_open())
	{
		while (in >> siffror >> bokstaver >> romerska)
		{
			vecSortering.push_back(Sortering(siffror, bokstaver, romerska));
		}
	}
	else
	{
		cout << "Filen öppnades ej korrekt" << endl;
	}

    for(size_t i=0; i<vecSortering.size(); ++i)
    {
        out << vecSortering[i].siffror << " " << vecSortering[i].bokstaver << " " << vecSortering[i].romerska << endl;
    }
    in.close();
    out.close();
    return 0;
}

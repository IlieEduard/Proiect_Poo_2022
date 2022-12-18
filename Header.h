#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Bilet {

private:
	float Pret;
	char* Denumire_eveniment;
	int Tip_bilet; //( 1-5 pt tip bilet 0 pt invalid)
	static float Id;
	const bool Reducere;
public:
	Bilet() :Reducere(false)
	{
		this->Pret = 0;
		this->Denumire_eveniment = new char[strlen("NULL") + 1];
		strcpy(this->Denumire_eveniment, "NULL");
		this->Tip_bilet = 0;
		this->Id = 0;
	}
	Bilet(float pret, char* denumire, int tip, bool reducere) :Reducere(reducere)
	{
		this->Pret = pret;
		this->Denumire_eveniment = new char[strlen(denumire) + 1];
		strcpy(this->Denumire_eveniment, denumire);
		this->Tip_bilet = tip;
	}
	Bilet(Bilet& b) :Reducere(b.Reducere)
	{
		this->Pret = b.Pret;
		this->Denumire_eveniment = new char[strlen(b.Denumire_eveniment) + 1];
		strcpy(this->Denumire_eveniment, b.Denumire_eveniment);
		this->Tip_bilet;
	}

	void set_pret(float pret)
	{
		this->Pret = pret;
	}

	void set_denumire_eveniment(char* n)
	{
		if (n != NULL)
		{
			if (this->Denumire_eveniment != NULL)
			{
				delete[] this->Denumire_eveniment;
				this->Denumire_eveniment = new char[strlen(n) + 1];
				strcpy(this->Denumire_eveniment, n);
			}
			else
			{
				this->Denumire_eveniment = new char[strlen(n) + 1];
				strcpy(this->Denumire_eveniment, n);
			}
		}
	}
	void set_tip_bilet(int n)
	{
		if (n >= 1 && n <= 5)
		{
			this->Tip_bilet = n;
		}
	}
	void Aplica_reducere(float R)
	{
		if (this->Reducere == true)
		{
			if (R > 0 && R <= 100)
			{
				this->Pret = this->Pret - (this->Pret * R) / 100;
			}
		}
	}

	void modifica_pret_in_functie_de_tip_bilet()
	{
		switch (this->Tip_bilet)
		{
		case 0:
			cout << endl << "nici o schimbare tip bilet invalid !!! " << endl;
			break;
		case 2:
			this->Pret = this->Pret + this->Pret * 0.15;
			break;
		case 3:
			this->Pret = this->Pret + (this->Pret * 0.25);
			break;
		case 4:
			this->Pret = this->Pret + (this->Pret * 0.4);
			break;
		case 5:
			this->Pret = this->Pret + (this->Pret * 0.7);
			break;
		}
	}
	friend istream& operator>>(istream&, Bilet&);
	friend ostream& operator<<(ostream&, Bilet);


	~Bilet()
	{
		if (this->Denumire_eveniment != NULL)
		{
			delete[] this->Denumire_eveniment;
		}
	}
};
istream& operator>>(istream& in, Bilet& b)
{
	cout << endl;
	cout << "Introdu pret bilet: ";
	in >> b.Pret;
	cout << endl;
	cout << "Introdu denumire: ";
	char n[100];
	in >> n;
	b.Denumire_eveniment = new char[strlen(n) + 1];
	strcpy(b.Denumire_eveniment, n);
	cout << endl;
	cout << "Introdu Tip_bilet (valoare intre 1-5) :";
	in >> b.Tip_bilet;
	cout << endl;

	return in;
}
ostream& operator<<(ostream& out, Bilet b)
{
	out << endl;
	out << "Pretul este: " << b.Pret << endl;
	out << "Evenimentul se numeste: ";
	for (int i = 0; i < strlen(b.Denumire_eveniment); i++)
	{
		out << b.Denumire_eveniment[i];
	}
	out << endl << "ai bilet tip: " << b.Tip_bilet;

	return out;
}


class Locatie {

private:
	string adresa;
	int Nr_maxim_locuri;
	int Nr_randuri;
	int Zone;
	int* Cod_scaun;
public:
	Locatie()
	{
		this->adresa = "Necunoscuta ";
		this->Nr_maxim_locuri = 0;
		this->Nr_randuri = 0;
		this->Zone = 0;
		this->Cod_scaun = NULL;
	}
	Locatie(string adress, int nr_max_loc, int nr_randuri, int zone, int* cod_scaun)
	{
		this->adresa = adress;
		this->Nr_maxim_locuri = nr_max_loc;
		this->Nr_randuri = nr_randuri;
		this->Zone = zone;
		this->Cod_scaun = new int[10];
		for (int i = 0; i < 10; i++)
		{
			this->Cod_scaun[i] = cod_scaun[i];
		}
	}
	void set_adresa(string adress)
	{
		this->adresa = adress;
	}
	void set_Nr_maxim_locuri(int nr)
	{
		if (nr > 0 && nr <= 250000)
		{
			this->Nr_maxim_locuri = nr;
		}
	}
	void set_Nr_randuri(int nr)
	{
		if (nr > 0 && nr <= 2500)
		{
			this->Nr_randuri = nr;
		}
	}
	void set_cod_scaun(int* n)
	{
		if (n != NULL)
		{
			if (Cod_scaun != NULL)
			{
				delete[] this->Cod_scaun;
				this->Cod_scaun = new int[10];
				for (int i = 0; i < 10; i++)
				{
					this->Cod_scaun[i] = n[i];
				}
			}
			else
			{
				this->Cod_scaun = new int[10];
				for (int i = 0; i < 10; i++)
				{
					this->Cod_scaun[i] = n[i];
				}
			}
		}

	}
	friend istream& operator>>(istream&, Locatie&);
	friend ostream& operator<<(ostream&, Locatie);
	~Locatie()
	{
		if (Cod_scaun != NULL)
		{
			delete[] this->Cod_scaun;
		}
	}
};
istream& operator>>(istream& in, Locatie& l)
{
	cout << endl << "Introdu locatie: ";
	in >> l.adresa;
	cout << endl << "Introdu nr maxim locuri: ";
	in >> l.Nr_maxim_locuri;
	cout << endl << "Introdu nr randuri: ";
	in >> l.Nr_randuri;
	cout << endl << "Introdu nr zone: ";
	in >> l.Zone;
	int v[10];
	cout << endl << "Introdu cod scaun (10 numere necesare): ";
	for (int i = 0; i < 10; i++)
	{ 
		cout <<i+1<<" : ";
		in >> v[i];
		cout << endl;
	}
	l.Cod_scaun = new int[10];
	for (int i = 0; i < 10; i++)
	{
		l.Cod_scaun[i] = v[i];
	}

	return in;
}
ostream& operator<<(ostream& out, Locatie l)
{
	out << endl;
	out << "Evenimentul se tine la: " << l.adresa << " Cu un numar maxim de " << l.Nr_maxim_locuri << " spectatori " << endl << " Are " << l.Nr_randuri << " randuri si " << l.Zone << " zone " << endl;
	return out;
}



class Eveniment {
private:
	char* Denummire;
	int Zi;
	int Luna;
	int An;
	int Ora;
	int Minut;
	int Durata_ore;
	int Durata_minute;
public:
	Eveniment()
	{
		this->Denummire = new char[strlen("Necunoscuta") + 1];
		strcpy(this->Denummire, "Necunoscuta");
		this->Zi = 0;
		this->Luna = 0;
		this->An = 0;
		this->Ora = 0;
		this->Minut = 0;
		this->Durata_minute = 0;
		this->Durata_ore = 0;
	}
	Eveniment(char* n, int zi, int luna, int an, int ora, int minut, int durata_ore, int durata_minute)
	{
		if (n != NULL)
		{
			this->Denummire = new char[strlen(n) + 1];
			strcpy(this->Denummire, n);
		}
		this->Zi = zi;
		this->Luna = luna;
		this->An = an;
		this->Ora = ora;
		this->Minut = minut;
		this->Durata_minute = durata_minute;
		this->Durata_ore = durata_ore;
	}
	void set_denumire(char* n)
	{
		if (n != NULL)
		{
			if (this->Denummire != NULL)
			{
				delete[] this->Denummire;
				this->Denummire = new char[strlen(n) + 1];
				strcpy(this->Denummire, n);
			}
			else
			{
				this->Denummire = new char[strlen(n) + 1];
				strcpy(this->Denummire, n);
			}
		}
	}
	void set_ora(int ora, int minut)
	{
		if (ora >= 0 && ora <= 24 && minut >= 0 && minut <= 60)
		{
			this->Minut = minut;
			this->Ora = ora;
		}
	}
	void set_data(int zi, int luna, int an)
	{
		if (zi >= 1 && zi <= 31 && luna >= 1 && luna <= 12 && an >= 2022 && an <= 2028)
		{
			this->Zi = zi;
			this->Luna = luna;
			this->An = an;
		}
	}
	void set_durata_spectacol(int ore, int minute)
	{
		if (ore >= 0 && ore <= 8 && minute >= 1 && minute <= 59)
		{
			this->Durata_ore = ore;
			this->Durata_minute = minute;
		}
	}

	friend istream& operator>>(istream&, Eveniment&);
	friend ostream& operator<<(ostream&, Eveniment);

	~Eveniment()
	{
		if (this->Denummire != NULL)
		{
			delete[] this->Denummire;
		}
	}
};
istream& operator>>(istream& in, Eveniment& e)
{
	char n[100];
	cout << endl << "Introdu denumirea evenimentului: ";
	in >> n;
	for (int i = 0; i < strlen(n); i++)
	{
		e.Denummire = new char[strlen(n) + 1];
		e.Denummire[i] = n[i];
	}
	cout << endl << "Introdu data zi/luna/an: ";
	in >> e.Zi;
	in >> e.Luna;
	in >> e.An;
	cout << endl << "Introdu ora ora/minut: ";
	in >> e.Ora;
	in >> e.Minut;
	cout << endl << "Introdu durata evenimentului: ";
	in >> e.Durata_ore;
	in >> e.Durata_minute;
	return in;
}
ostream& operator<<(ostream& out, Eveniment e)
{
	out << endl << "Evenimentul se numeste: ";
	for (int i = 0; i < strlen(e.Denummire); i++)
	{
		out << e.Denummire[i];
	}
	out << endl << "In data de: " << e.Zi << "/" << e.Luna << "/" << e.An << endl << "La ora: " << e.Ora << ":" << e.Minut << "Evenimenutl dureaza: " << e.Durata_ore << " si " << e.Durata_minute << "minute";
	return out;
}

float Bilet::Id = 0;

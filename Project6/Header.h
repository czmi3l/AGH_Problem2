//Przykladowe wejscie:
//d
//1
//Trol Trol 12345678901 4563876 2000
//q
//

#ifndef _HEADER_PRACOWNIK_
#define _HEADER_PRACOWNIK_

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

//PRACOWNIK
class Pracownik{ // KLASA ABSTRAKCYJNA
private:
	string imie;
	string nazwisko;
	string nip;
	string pesel;
protected:
	int pensja;
	string typ;
public:
	Pracownik(){}
	Pracownik(string Imie, string Nazwisko, string Pesel, string Nip);
	virtual ~Pracownik(){ cout << "Destruktor Pracownik\n"; }
	virtual void print();
	virtual void wylicz_zarobki() = 0; // METODA ABSTRAKCYJNA

};

// PRACOWNIK NA STALE
class PracownikNaStale : public Pracownik{
private:
	int wynagrodzenie;
public:
	PracownikNaStale(){}
	PracownikNaStale(string Imie, string Nazwisko, string Pesel, string
		Nip, int Wynagrodzenie) :
		Pracownik(Imie, Nazwisko, Pesel, Nip){
		wynagrodzenie = Wynagrodzenie;
		typ = "Pracownik na stale";
	}
	~PracownikNaStale(){ cout << "Destruktor PracownikNaStale\n"; }
	virtual void wylicz_zarobki();
	virtual void print();

};

//PRACOWNIK NA ZLECENIE
class PracownikNaZlecenie : public Pracownik{
private:
	int iloscGodzin;
	int stawkaZaGodzine;
public:
	PracownikNaZlecenie(){}
	PracownikNaZlecenie(string Imie, string Nazwisko, string Pesel,
		string Nip, int IloscGodzin, int StawkaZaGodzine) :
		Pracownik(Imie, Nazwisko, Pesel, Nip){
		iloscGodzin = IloscGodzin;
		stawkaZaGodzine = StawkaZaGodzine;
		typ = "Pracownik na zlecenie";
	}
	virtual ~PracownikNaZlecenie(){ cout << "Destruktor PracownikNaZlecenie\n"; }
	virtual void wylicz_zarobki();
	virtual void print();

};

//PRACOWNIK HANDLOWIEC
class PracownikHandlowiec : public Pracownik{
private:
	int zysk;
	int procent; //pensja = zysk * procent
public:
	PracownikHandlowiec(){}
	PracownikHandlowiec(string Imie, string Nazwisko, string Pesel,
		string Nip, int Zysk, int Procent) :
		Pracownik(Imie, Nazwisko, Pesel, Nip){
		zysk = Zysk;
		procent = Procent;
		typ = "Pracownik handlowiec";
	}
	virtual ~PracownikHandlowiec(){ cout << "Destruktor PracownikHandlowiec\n"; }
	virtual void wylicz_zarobki();
	virtual void print();

};

#endif
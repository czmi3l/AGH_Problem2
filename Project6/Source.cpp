#include "Header.h"

//PRACOWNIK
Pracownik::Pracownik(string Imie, string Nazwisko, string Pesel, string Nip){
	imie = Imie;
	nazwisko = Nazwisko;
	nip = Nip;
	pesel = Pesel;
}

void Pracownik::print(){
	cout << "Imie: " << imie << endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "Typ: " << typ << endl;
	cout << "NIP: " << nip << endl;
	cout << "Pesel: " << pesel << endl;
	cout << "Pensja: " << pensja << " zl" << endl;
}




// PRACOWNIK NA STALE
void PracownikNaStale::wylicz_zarobki(){
	pensja = wynagrodzenie;
}

void PracownikNaStale::print(){
	Pracownik::print();
}


//PRACOWNIK NA ZLECENIE
void PracownikNaZlecenie::wylicz_zarobki(){
	pensja = iloscGodzin * stawkaZaGodzine;
	if (iloscGodzin > 40)
		pensja *= 1.5;
}

void PracownikNaZlecenie::print(){
	Pracownik::print();
	cout << "Ilosc Godzin: " << iloscGodzin << endl;
	cout << "Stawka za godzinê: " << stawkaZaGodzine << endl;
}



//PRACOWNIK HANDLOWIEC
void PracownikHandlowiec::wylicz_zarobki(){
	pensja = zysk * procent;
}

void PracownikHandlowiec::print(){
	Pracownik::print();
	cout << "Zysk: " << zysk << endl;
	cout << "Procent: " << procent << endl;
}




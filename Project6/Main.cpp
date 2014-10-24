#include "Header.h"

void Dodawanie(vector<Pracownik*> &wektor);//dodawanie pozycji do wektora
void Wyswietlanie(vector<Pracownik*> &wektor);//wywietlanie pozycji z wektora


//==================================== MAIN =====================================
int main(){


	vector<Pracownik*> wektor; //wektor pointerow na pracownikow
	char menu; //char do obslugi menu
	int tmp; //int do usuwania danego elementu
	system("cls");
	cout << "MENU:\nd - DODAJ PRACOWNIKA \nw - WYSWIETL PRACOWNIKA \nu - USUN PRACOWNIKA \nq - WYJSCIE" << endl;
	cin >> menu;
	while (menu != 'q'){
		switch (menu)
		{
		case 'd':
			Dodawanie(wektor);
			break;
		case 'w':
			Wyswietlanie(wektor);
			break;
		case 'u':
			cout << "Wpisz numer pracownika ktorego chcesz usunac: ";
			cin >> tmp;
			delete wektor[tmp - 1];
			wektor.erase(wektor.begin() + tmp - 1);
			cout << "Rekord usuniety!" << endl;
			break;
		default:
			break;
		}
		cout << "MENU:\nd - DODAJ PRACOWNIKA \nw - WYSWIETL PRACOWNIKA \nu - USUN PRACOWNIKA \nq - WYJSCIE" << endl;
		cin >> menu;
	}
	//wywolywanie destruktorow
	for (int i = 0; i < wektor.size(); i++)
	{
		delete wektor[i];
	}

	cin.get();

	return 0;
}

//================================ DODAWANIE POZYCJI DO WEKTORA ==========================

void Dodawanie(vector<Pracownik*> &wektor){
	vector<string> wektorNaAtrybuty;//wektor na imie, nazwisko etc.
	char menu;//char do obslugi menu
	string temp; // string do wpisywania atrybutow do wektora
	system("cls");
	cout << "Wybierz typ pracownika: \n1 - Pracownik na stale \n2 - Pracownik na zlecenie \n3 - pracownik handlowiec" << endl;
	menu = '\0';
	cin >> menu;
	system("cls");
	switch (menu)
	{
	case '1':
		cout << "Wpisz: [imie] [nazwisko] [pesel] [nip] [wynagrodzenie]" << endl;
		for (int i = 0; i < 5; i++)
		{
			cin >> temp;
			wektorNaAtrybuty.push_back(temp);
		}
		wektor.push_back(new PracownikNaStale(wektorNaAtrybuty[0], wektorNaAtrybuty[1], wektorNaAtrybuty[2], wektorNaAtrybuty[3], strtol(wektorNaAtrybuty[4].c_str(), NULL, 10)));
		cout << "\nRekord dodany!\n" << endl;
		(*wektor.back()).wylicz_zarobki();
		break;
	case '2':
		cout << "Wpisz: [imie] [nazwisko] [pesel] [nip] [ilosc godzin] [stawka za godzine]" << endl;
		for (int i = 0; i < 6; i++)
		{
			cin >> temp;
			wektorNaAtrybuty.push_back(temp);
		}
		wektor.push_back(new PracownikNaZlecenie(wektorNaAtrybuty[0], wektorNaAtrybuty[1], wektorNaAtrybuty[2], wektorNaAtrybuty[3], strtol(wektorNaAtrybuty[4].c_str(), NULL, 10), strtol(wektorNaAtrybuty[5].c_str(), NULL, 10)));
		cout << "\nRekord dodany!\n" << endl;
		(*wektor.back()).wylicz_zarobki();
		break;
	case '3':
		cout << "Wpisz: [imie] [nazwisko] [pesel] [nip] [zysk] [procent]" << endl;
		for (int i = 0; i < 6; i++)
		{
			cin >> temp;
			wektorNaAtrybuty.push_back(temp);
		}
		wektor.push_back(new PracownikNaZlecenie(wektorNaAtrybuty[0], wektorNaAtrybuty[1], wektorNaAtrybuty[2], wektorNaAtrybuty[3], strtol(wektorNaAtrybuty[4].c_str(), NULL, 10), strtol(wektorNaAtrybuty[5].c_str(), NULL, 10)));
		cout << "\nRekord dodany!\n" << endl;
		(*wektor.back()).wylicz_zarobki();
		break;
	default:
		cout << "Tylko z zakresu 1 - 3!" << endl;
		break;
	}
	wektorNaAtrybuty.clear();


}

//===================================== WYSWIETLANIE POZYCJI Z WEKTORA ======================
void Wyswietlanie(vector<Pracownik*> &wektor){
	int tmp;
	system("cls");
	cout << "Od 1 do ilosci pracownikow lub \n0 - wszystkie pozycje" << endl;
	cin >> tmp;
	system("cls");
	if (tmp == 0){
		for (int i = 0; i < wektor.size(); i++)
		{
			cout << "Pracownik nr: " << i + 1 << endl;
			(*wektor[i]).print();
			cout << endl;
		}
	}
	else if (tmp > 0 && tmp <= wektor.size()){
		cout << "Pracownik nr: " << tmp << endl;
		(*wektor[tmp - 1]).print();
	}
}
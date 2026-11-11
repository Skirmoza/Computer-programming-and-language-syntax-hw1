#include <iostream>
#include <fstream> //librariile folosite
#include <iomanip>
using namespace std;

int main() {
	//declar toate variabilele despre prima companie
	int zi1, colete_procesate1, colete_livrate1, colete_livrate_la_timp1;
	double cost_operational1;
	ifstream fisier_in1("centrul-1.txt");//afisez valorile din primul document text
	fisier_in1 >> zi1 >> colete_procesate1 >> colete_livrate1 >> colete_livrate_la_timp1 >> cost_operational1;//dau valorile fiecarui int
	cout << "Datele primului centru sunt: " << endl;
	cout << "Ziua: " << zi1 << endl;
	cout << "Coletele procesate: " << colete_procesate1 << endl;
	cout << "Coletele livrate: " << colete_livrate1 << endl;
	cout << "Coletele livrate la timp: " << colete_livrate_la_timp1 << endl;
	cout << "Costul operational: " << fixed << setprecision(2) << cost_operational1 << " lei" << endl << endl;
	fisier_in1.close();
	//informatiile despre a doua companie
	int zi2, colete_procesate2, colete_livrate2, colete_livrate_la_timp2;
	double cost_operational2;
	ifstream fisier_in2("centrul-2.txt");
	fisier_in2 >> zi2 >> colete_procesate2 >> colete_livrate2 >> colete_livrate_la_timp2 >> cost_operational2;//dau valorile fiecarui int
	cout << "Datele celui de al doilea centru sunt: " << endl;
	cout << "Ziua: " << zi1 << endl;
	cout << "Coletele procesate: " << colete_procesate2 << endl;
	cout << "Coletele livrate: " << colete_livrate2 << endl;
	cout << "Coletele livrate la timp: " << colete_livrate_la_timp2 << endl;
	cout << "Costul operational: " << fixed << setprecision(2) << cost_operational2 << " lei" << endl << endl;
	fisier_in2.close();
	if (zi1 == zi2) {
		//Conditii de indeplinit
		if (colete_procesate1 > 0 && colete_procesate2 > 0 && //prima conditie
			0 <= colete_livrate1 && colete_livrate1 <= colete_procesate1 && //a doua
			0 <= colete_livrate2 && colete_livrate2 <= colete_procesate2 && 
			0 <= colete_livrate_la_timp1 && colete_livrate_la_timp1 <= colete_livrate1 &&  //a treia
			0 <= colete_livrate_la_timp2 && colete_livrate_la_timp2 <= colete_livrate2 &&  
			cost_operational1 >= 0 && cost_operational2 >= 0) {   //a patra
			//1.Rata de livrare
			double rata_de_livrare1, rata_de_livrare2;
			rata_de_livrare1 = colete_livrate1 * 100 / colete_procesate1;
			rata_de_livrare2 = colete_livrate2 * 100 / colete_procesate2;
			//2.Rata de livrarilor la timp
			double rata_livrarilor_la_timp1, rata_livrarilor_la_timp2;
			rata_livrarilor_la_timp1 = colete_livrate_la_timp1 * 100 / colete_livrate1;
			rata_livrarilor_la_timp2 = colete_livrate_la_timp2 * 100 / colete_livrate2;
			//3.Costul mediu pentru un colet livrat
			double colet_mediu1, colet_mediu2;
			colet_mediu1 = cost_operational1 / colete_livrate1;
			colet_mediu2 = cost_operational2 / colete_livrate2;
			//Programul va compara cele doua centre:
			    //i)centrul cu rata mai mare de livrare
			if (rata_de_livrare1 > rata_de_livrare2) { cout << "Centrul 1 are rata de livrare mai mare. " << fixed << setprecision(2) << rata_de_livrare1 << " %" << endl;
			}
			else {
				cout << "Centrul 2 are rata de livrare mai mare. " << fixed << setprecision(2) << rata_de_livrare2 << " %" << endl;
			}
				//ii)centrul cu rata livrarilor la timp mai mare
			if (rata_livrarilor_la_timp1 > rata_livrarilor_la_timp2) { cout << "Centrul 1 are rata livrarilor la timp mai mare. " << fixed << setprecision(2) << rata_livrarilor_la_timp1 << " %" << endl;
			}
			else {
				cout << "Centrul 2 are rata livrarilor la timp mai mare. " << fixed << setprecision(2) << rata_livrarilor_la_timp2 << " %" << endl;
			}
				//iii)centrul cu costul mediu pe colet mai mic
			if (colet_mediu1 < colet_mediu2) {
				cout << "Centrul 1 are costul mediu pe colet mai mic. " << fixed << setprecision(2) << colet_mediu1 << " lei" << endl;
			}
			else{ 
				cout << "Centrul 2 are costul mediu pe colet mai mic. " << fixed << setprecision(2) << colet_mediu2 << " lei" << endl; 
			}
			ofstream fisier_out("comparatie.txt");  //rezultatele o sa fie transmise in "comparatie.txt"
			fisier_out << "Compararea centrelor logistice" << endl;
			fisier_out << "Ziua: " << zi1;  //oricare dintre cele doua variabile de zile pot fi alese
			fisier_out << endl << endl; //pentru a lasa doua randuri intre lucrurile importante
			fisier_out << "Centrul 1" << endl;
			fisier_out << "Rata de livrare: " << fixed << setprecision(2) << rata_de_livrare1 << " %" << endl; //pun toate variabilele cu doua zecimale dupa virgula
			fisier_out << "Rata livrarilor la timp: " << fixed << setprecision(2) << rata_livrarilor_la_timp1 << " %" << endl; 
			fisier_out << "Cost mediu / colet livrat: " << fixed << setprecision(2) << colet_mediu1 << " lei" ;
			fisier_out << endl << endl;
			fisier_out << "Centrul 2" << endl;
			fisier_out << "Rata de livrare: " << fixed << setprecision(2) << rata_de_livrare2 << " %" << endl; //pun toate variabilele cu doua zecimale dupa virgula
			fisier_out << "Rata livrarilor la timp: " << fixed << setprecision(2) << rata_livrarilor_la_timp2 << " %" << endl;
			fisier_out << "Cost mediu / colet livrat: " << fixed << setprecision(2) << colet_mediu2 << " lei";
			fisier_out << endl << endl;
			fisier_out << "Comparatie" << endl;   //folosesc if-urile de mai sus pentru comparatia in "comparatie.txt"
			fisier_out << "Cea mai mare rata de livrare: ";
			if (rata_de_livrare1 > rata_de_livrare2) {
				fisier_out << "Centrul 1 / " << fixed << setprecision(2) << rata_de_livrare1 << " %" << endl;
			}
			else {
				fisier_out << "Centrul 2 / " << fixed << setprecision(2) << rata_de_livrare2 << " %" << endl;
			} 
			fisier_out << "Cea mai mare rata a livrarilor la timp: ";
			if (rata_livrarilor_la_timp1 > rata_livrarilor_la_timp2) {
				fisier_out << "Centrul 1 / " << fixed << setprecision(2) << rata_livrarilor_la_timp1 << " %" << endl;
			}
			else {
				fisier_out << "Centrul 2 / " << fixed << setprecision(2) << rata_livrarilor_la_timp2 << " %" << endl;
			}
			fisier_out << "Cel mai mic cost mediu: ";
			if (colet_mediu1 < colet_mediu2) {
				fisier_out << "Centrul 1 / " << fixed << setprecision(2) << colet_mediu1 << " lei" << endl;
			}
			else {
				fisier_out << "Centrul 2 / " << fixed << setprecision(2) << colet_mediu2 << " lei" << endl;
			}
			fisier_out.close(); //terminarea citirii rezultatelor
		}
		else { cout << "Conditiile nu au fost indeplinite!"; //din cele patru conditii una nu a fost indeplinita
		return -2;
		}
	}
	else { cout << "Informatiile stranse sunt din zile diferite, nu pot fi comparate."; //zilele trebuie sa aibe aceeasi valoare
	return -1;
	} 
}
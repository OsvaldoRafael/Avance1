#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <cstring>
#include <cstdlib>

#define t 3

using namespace std;

struct Articulos 
{

	string NumArt, VDJ, Consola, Lanz, Clasif, Carac, Desc, Gener;
	double Precio;


}Item[t];


int main()
{
	
	int Opc, x = 0, y = 0;
	
	do
	{
		setlocale(LC_CTYPE, "Spanish");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		system("cls");
		
		
		int x = 0, y = 0;
		double Total, Imp = 16;
		string YN;

		SetConsoleTextAttribute(hConsole, 7);
		cout << "Seleccione la opción deseada: \n1-. Agregar Artículo \n2-. Modificar artículo \n3-. Eliminar Artículo \n4-. Lista de artículos vigentes \n5-. Limpiar pantalla \n6-. Salir" << endl;
		cin >> Opc;

		switch (Opc)
		{

		case 1:

			system("cls");

			do
			{

				if (Item[x].VDJ != "")
				{

					x = x + 1;

				}

			} while (Item[x].VDJ != "");

			//cout << x << endl; // Comprobamos el valor de X en este punto del codigo

			if (x <= 2)
			{

				cout << "Ingrese el número de su artículo" << endl;
				cin >> Item[x].NumArt;
				cout << "Ingrese el nombre de su artículo" << endl;
				cin.ignore();
				getline(cin,Item[x].VDJ);
				cout << "Ingrese la plataforma de su artículo" << endl;
				getline(cin, Item[x].Consola);
				cout << "Ingrese la fecha de lanzamiento de su artículo" << endl;
				getline(cin, Item[x].Lanz);
				cout << "Ingrese la clasificación de su artículo" << endl;
				getline(cin, Item[x].Clasif);
				cout << "Ingrese características para su artículo" << endl;
				getline(cin, Item[x].Carac);
				cout << "Ingrese una descripción para su artículo" << endl;
				getline(cin, Item[x].Desc);
				cout << "Ingrese el genero de su artículo" << endl;
				getline(cin, Item[x].Gener);
				cout << "Ingrese el precio de su artículo" << endl;
				cin >> Item[x].Precio;
				//cout << "Se le agregará un impuesto de 16%, precione 'Y' para continuar o 'N' para establecer un nuevo impuesto:" << endl;
				Total = Item[x].Precio * (1 + (Imp / 100));

				cout << "El precio total de su artículo es: " << Total << endl  << endl << endl << endl;

				//do {
					//cin >> YN;

					//if (YN == "Y" || YN == "y")
					//{

						//Total = Item[x].Precio * (1 + (Imp / 100));

						//cout << "El precio total de su artículo es: " << Total << endl;

						//system("pause");
						//return main();

//					}
	//				else if (YN == "N" || YN == "n")
		//			{

			//			cout << "Ingrese el nuevo impuesto: ";
				//		cin >> Imp;

					//	Total = Item[x].Precio * (1 + (Imp / 100));

						//cout << "El precio total de su artículo es: " << Total << endl;

						//system("pause");
						//return main();

					//}


					//else if (YN != "N" && YN != "n" && YN != "Y" && YN != "y")
					//{

						//cout << "Ingrese una opción válida" << endl;

					//}
			//	} while (YN != "N" && YN != "n" && YN != "Y" && YN != "y");

				cout << "Ésta es la lista de sus artículos en stock" << endl;
				//cout << x << " " << y << endl; // Muestra el valor de X y Y en este punto del codigo

				do
				{

					if (Item[x].VDJ != "")
					{

						x = x + 1;

					}

				} while (Item[x].VDJ != "");

				if (x == 0)
				{

					SetConsoleTextAttribute(hConsole, 2);
					cout << "\n		Espera, Aún no tiene artículos registrados\n" << endl;
					SetConsoleTextAttribute(hConsole, 7);

				}
				else
				{

					do
					{
						SetConsoleTextAttribute(hConsole, 2);
						cout << "- " << Item[y].VDJ << endl;
						SetConsoleTextAttribute(hConsole, 7);
						cout << "	No. de Artículo:	" << Item[y].NumArt << endl << "	Consola:	" << Item[y].Consola << endl << "	Fecha de Lanzamiento:	" << Item[y].Lanz << endl << "	Clasificación:	" << Item[y].Clasif << endl << "	Características:	" << Item[y].Carac << endl << "		Descripción:\n	" << Item[y].Desc << endl << endl << "	Genero:	" << Item[y].Gener << endl << "	Precio:	" << Item[y].Precio << endl << endl << endl;
						y = y + 1;

					} while (y < x);

				}

				system("pause");

			}
			else if (x >= 3)
			{

				cout << "Ya no quedan espacios libres para más artículos" << endl;
				system("pause");

			}

			break;

		case 2:

			system("cls");
			cout << "Elija el artículo para modificar" << endl;
			system("pause");
			return main();

			break;

		case 3:

			system("cls");
			cout << "Elija el artículo que desea eliminar" << endl;

			system("pause");
			return main();

			break;

		case 4:

			system("cls");
			cout << "Ésta es la lista de sus artículos en stock" << endl;
			//cout << x << " " << y << endl; // Muestra el valor de X y Y en este punto del codigo

			do
			{

				if (Item[x].VDJ != "")
				{

					x = x + 1;

				}

			} while (Item[x].VDJ != "");

			if (x == 0)
			{

				SetConsoleTextAttribute(hConsole, 2);
				cout << "\n		Espera, Aún no tiene artículos registrados\n" << endl;
				SetConsoleTextAttribute(hConsole, 7);

			}
			else
			{
				
				do
				{
					SetConsoleTextAttribute(hConsole, 2);
					cout << "- " << Item[y].VDJ << endl;
					SetConsoleTextAttribute(hConsole, 7);
					cout << "	No. de Artículo:	" << Item[y].NumArt << endl << "	Consola:	" << Item[y].Consola << endl << "	Fecha de Lanzamiento:	" << Item[y].Lanz << endl << "	Clasificación:	" << Item[y].Clasif << endl << "	Características:	" << Item[y].Carac << endl << "		Descripción:\n	" << Item[y].Desc << endl << endl << "	Genero:	" << Item[y].Gener << endl << "	Precio:	" << Item[y].Precio << endl << endl << endl;
					y = y + 1;

				} while (y < x);

			}

			system("pause");
			return main();

			break;

		case 5:

			system("cls");
			cout << "Su ventana ahora esta limpia :P" << endl;
			system("pause");
			return main();

			break;

		case 6:

			system("cls");
			cout << "Gracias por visitar nuestra página" << endl;
			system("pause");

			break;

		default:

			system("cls");

			SetConsoleTextAttribute(hConsole, 4);
			cout << "Seleccione una opción válida" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			system("pause");
			return main();

		}

	}while (Opc != 6);
}
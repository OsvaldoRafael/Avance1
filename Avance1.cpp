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
		cout << "Seleccione la opci�n deseada: \n1-. Agregar Art�culo \n2-. Modificar art�culo \n3-. Eliminar Art�culo \n4-. Lista de art�culos vigentes \n5-. Limpiar pantalla \n6-. Salir" << endl;
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

				cout << "Ingrese el n�mero de su art�culo" << endl;
				cin >> Item[x].NumArt;
				cout << "Ingrese el nombre de su art�culo" << endl;
				cin.ignore();
				getline(cin,Item[x].VDJ);
				cout << "Ingrese la plataforma de su art�culo" << endl;
				getline(cin, Item[x].Consola);
				cout << "Ingrese la fecha de lanzamiento de su art�culo" << endl;
				getline(cin, Item[x].Lanz);
				cout << "Ingrese la clasificaci�n de su art�culo" << endl;
				getline(cin, Item[x].Clasif);
				cout << "Ingrese caracter�sticas para su art�culo" << endl;
				getline(cin, Item[x].Carac);
				cout << "Ingrese una descripci�n para su art�culo" << endl;
				getline(cin, Item[x].Desc);
				cout << "Ingrese el genero de su art�culo" << endl;
				getline(cin, Item[x].Gener);
				cout << "Ingrese el precio de su art�culo" << endl;
				cin >> Item[x].Precio;
				//cout << "Se le agregar� un impuesto de 16%, precione 'Y' para continuar o 'N' para establecer un nuevo impuesto:" << endl;
				Total = Item[x].Precio * (1 + (Imp / 100));

				cout << "El precio total de su art�culo es: " << Total << endl  << endl << endl << endl;

				//do {
					//cin >> YN;

					//if (YN == "Y" || YN == "y")
					//{

						//Total = Item[x].Precio * (1 + (Imp / 100));

						//cout << "El precio total de su art�culo es: " << Total << endl;

						//system("pause");
						//return main();

//					}
	//				else if (YN == "N" || YN == "n")
		//			{

			//			cout << "Ingrese el nuevo impuesto: ";
				//		cin >> Imp;

					//	Total = Item[x].Precio * (1 + (Imp / 100));

						//cout << "El precio total de su art�culo es: " << Total << endl;

						//system("pause");
						//return main();

					//}


					//else if (YN != "N" && YN != "n" && YN != "Y" && YN != "y")
					//{

						//cout << "Ingrese una opci�n v�lida" << endl;

					//}
			//	} while (YN != "N" && YN != "n" && YN != "Y" && YN != "y");

				cout << "�sta es la lista de sus art�culos en stock" << endl;
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
					cout << "\n		Espera, A�n no tiene art�culos registrados\n" << endl;
					SetConsoleTextAttribute(hConsole, 7);

				}
				else
				{

					do
					{
						SetConsoleTextAttribute(hConsole, 2);
						cout << "- " << Item[y].VDJ << endl;
						SetConsoleTextAttribute(hConsole, 7);
						cout << "	No. de Art�culo:	" << Item[y].NumArt << endl << "	Consola:	" << Item[y].Consola << endl << "	Fecha de Lanzamiento:	" << Item[y].Lanz << endl << "	Clasificaci�n:	" << Item[y].Clasif << endl << "	Caracter�sticas:	" << Item[y].Carac << endl << "		Descripci�n:\n	" << Item[y].Desc << endl << endl << "	Genero:	" << Item[y].Gener << endl << "	Precio:	" << Item[y].Precio << endl << endl << endl;
						y = y + 1;

					} while (y < x);

				}

				system("pause");

			}
			else if (x >= 3)
			{

				cout << "Ya no quedan espacios libres para m�s art�culos" << endl;
				system("pause");

			}

			break;

		case 2:

			system("cls");
			cout << "Elija el art�culo para modificar" << endl;
			system("pause");
			return main();

			break;

		case 3:

			system("cls");
			cout << "Elija el art�culo que desea eliminar" << endl;

			system("pause");
			return main();

			break;

		case 4:

			system("cls");
			cout << "�sta es la lista de sus art�culos en stock" << endl;
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
				cout << "\n		Espera, A�n no tiene art�culos registrados\n" << endl;
				SetConsoleTextAttribute(hConsole, 7);

			}
			else
			{
				
				do
				{
					SetConsoleTextAttribute(hConsole, 2);
					cout << "- " << Item[y].VDJ << endl;
					SetConsoleTextAttribute(hConsole, 7);
					cout << "	No. de Art�culo:	" << Item[y].NumArt << endl << "	Consola:	" << Item[y].Consola << endl << "	Fecha de Lanzamiento:	" << Item[y].Lanz << endl << "	Clasificaci�n:	" << Item[y].Clasif << endl << "	Caracter�sticas:	" << Item[y].Carac << endl << "		Descripci�n:\n	" << Item[y].Desc << endl << endl << "	Genero:	" << Item[y].Gener << endl << "	Precio:	" << Item[y].Precio << endl << endl << endl;
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
			cout << "Gracias por visitar nuestra p�gina" << endl;
			system("pause");

			break;

		default:

			system("cls");

			SetConsoleTextAttribute(hConsole, 4);
			cout << "Seleccione una opci�n v�lida" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			system("pause");
			return main();

		}

	}while (Opc != 6);
}
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
	
	int Opc = 0, x = 0, y = 0;
	
	do
	{
		setlocale(LC_CTYPE, "Spanish");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		system("cls");
		
		int x = 0, y = 0, falso = 0;
		double Total, Imp = 16;
		string YN;

		SetConsoleTextAttribute(hConsole, 7);
		printf("Seleccione la opci�n deseada: \n1-. Agregar Art�culo \n2-. Modificar art�culo \n3-. Eliminar Art�culo \n4-. Lista de art�culos vigentes \n5-. Limpiar pantalla \n6-. Salir\n\n");
		scanf_s("%d", &Opc);

		switch (Opc)
		{

		case 1:

			system("cls");

			printf("Ingrese 1 para continuar o 0 para cancelar:\n");
			scanf_s("%d", &falso);

			if (falso == 1)
			{

				system("cls");

				do
				{

					if (Item[x].VDJ != "")
					{

						x = x + 1;

					}

				} while (Item[x].VDJ != "");

				if (x <= 2)
				{

					printf("Ingrese el n�mero de su art�culo:\n");
					cin.ignore();
					getline(cin, Item[x].NumArt);

					do
					{

						if (y == x)
						{

							y = y + 1;

						}

						if (Item[y].NumArt != Item[x].NumArt)
						{

							y = y + 1;

						}
						else
						{

							system("cls");
							printf("�ste n�mero de art�culo ya est� en uso, ingrese otro:\n");
							getline(cin, Item[x].NumArt);
							y = 0;

						}

					} while (y < 3);

					y = 0;
					printf("Ingrese el nombre de su art�culo\n");
					getline(cin, Item[x].VDJ);
					printf("Ingrese la plataforma de su art�culo\n");
					getline(cin, Item[x].Consola);
					printf("Ingrese la fecha de lanzamiento de su art�culo\n");
					getline(cin, Item[x].Lanz);
					printf("Ingrese la clasificaci�n de su art�culo\n");
					getline(cin, Item[x].Clasif);
					printf("Ingrese caracter�sticas para su art�culo\n");
					getline(cin, Item[x].Carac);
					printf("Ingrese una descripci�n para su art�culo\n");
					getline(cin, Item[x].Desc);
					printf("Ingrese el genero de su art�culo\n");
					getline(cin, Item[x].Gener);
					printf("Ingrese el precio de su art�culo\n");
					scanf_s("%lf", &Item[x].Precio);
					Total = Item[x].Precio * (1 + (Imp / 100));
					printf("\n\nArt�culo Registrado\n\nEl precio total de su art�culo es:\t%f\n\n\n\n", Total);

					system("pause");

				}
				else if (x >= 3)
				{

					printf("Ya no quedan espacios libres para m�s art�culos\n\n");
					system("pause");

				}

			}

			break;

		case 2:

			system("cls");
			printf("Elija el art�culo para modificar\n\n");
			system("pause");
			return main();

			break;

		case 3:

			system("cls");
			printf("Elija el art�culo que desea eliminar\n\n");

			system("pause");
			return main();

			break;

		case 4:

			system("cls");
			printf("�sta es la lista de sus art�culos en stock\n\n");

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
				printf("\t\tEspera, A�n no tiene art�culos registrados\n\n");
				SetConsoleTextAttribute(hConsole, 7);

			}
			else
			{
				
				do
				{
					SetConsoleTextAttribute(hConsole, 2);
					printf("- %s\n\n", Item[y].VDJ.c_str());
					SetConsoleTextAttribute(hConsole, 7);
					printf("\tNo. de Art�culo:\t%s\n\tConsola:\t%s\n\tFecha de Lanzamiento:\t%s\n\tClasificaci�n:\t%s\n\tCaracter�sticas:\t%s\n\tDescripci�n:\n\n\t%s\n\n\tG�nero:\t%s\n\tPrecio:\t%lf\n\n\n", Item[y].NumArt.c_str(), Item[y].Consola.c_str(), Item[y].Lanz.c_str(), Item[y].Clasif.c_str(), Item[y].Carac.c_str(), Item[y].Desc.c_str(), Item[y].Gener.c_str(), Item[y].Precio);
					y = y + 1;

				} while (y < x);

			}

			system("pause");
			return main();

			break;

		case 5:

			system("cls");
			printf("Su ventana ahora esta limpia :P\n\n");
			system("pause");
			return main();

			break;

		case 6:

			system("cls");
			printf("Gracias por visitar nuestra p�gina\n\n");
			system("pause");

			break;

		default:

			system("cls");

			SetConsoleTextAttribute(hConsole, 4);
			printf("Seleccione una opci�n v�lida\n\n");
			SetConsoleTextAttribute(hConsole, 7);
			system("pause");
			return main();

		}

	}while (Opc != 6);
}
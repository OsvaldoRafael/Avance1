#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <fstream>

#define t 100

using namespace std;

struct Articulos
{

	string NumArt, VDJ, Consola, Lanz, Clasif, Carac, Desc, Gener;
	double Precio;


}Item[t], *PuntItem = Item;

int limite(int limit)
{

	printf("¿Cuántos Items quiere registrar?\n");
	scanf_s("%d", &limit);

	return limit;

}

int compvacioeliminado(int x, int limit)
{

	int y = 0;
	do
	{

		if (Item[x].VDJ != "")
		{

			x = x + 1;

		}

		if (x == 0 && Item[x].VDJ == "")
		{

			do
			{

				if (Item[y].VDJ == "")
				{

					x = x + 1;

				}

				y = y + 1;

			} while (y < limit);

			if (x == limit)
			{

				x = 0;
				break;

			}
			else if (x < limit)
			{

				x = limit;
				break;

			}

		}

	} while (Item[x].VDJ != "");

	return x;

}

void listaItems(int x, int y)
{
	double Total = 0, Imp = 16;
	do
	{
		PuntItem = &Item[y];
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		if (Item[y].VDJ != "")
		{

			SetConsoleTextAttribute(hConsole, 2);
			printf("- %s\n\n", PuntItem->VDJ.c_str());
			SetConsoleTextAttribute(hConsole, 7);
			printf("\tNo. de Artículo:\t%s\n\tConsola:\t%s\n\tFecha de Lanzamiento:\t%s\n\tClasificación:\t%s\n\tCaracterísticas:\t%s\n\tDescripción:\n\n\t%s\n\n\tGénero:\t%s\n\tPrecio:\t%lf\n", PuntItem->NumArt.c_str(), PuntItem->Consola.c_str(), PuntItem->Lanz.c_str(), PuntItem->Clasif.c_str(), PuntItem->Carac.c_str(), PuntItem->Desc.c_str(), PuntItem->Gener.c_str(), PuntItem->Precio);
			printf("\tIVA: %f\n", Item[y].Precio*(Imp/100));
			Total = Item[y].Precio * (1 + (Imp / 100));
			printf("\tEl precio total de su artículo es:\t%f\n\n\n\n", Total);
			y = y + 1;

		}
		else
		{

			y = y + 1;

		}
		

	} while (y < x);

}

void listasimp(int x, int y)
{

	do
	{
		PuntItem = &Item[y];
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 2);
		if (Item[y].VDJ != "")
		{

			printf("%d- %s\n\n", y + 1, PuntItem->NumArt.c_str());
			SetConsoleTextAttribute(hConsole, 7);
			y = y + 1;

		}
		else
		{

			y = y + 1;

		}

	} while (y < x);

}

void menudinamicoClasif(int x, int y, int j, int limit)
{

	do
	{

		if (Item[x].Clasif != "")
		{

			if (y == 1)
			{

				printf("%d- %s\n", y, Item[x].Clasif.c_str());
				y = y + 1;

			}
			else
			{

				for (j = 0; j < x; j++)
				{

					if (Item[x].Clasif == Item[j].Clasif)
					{

						break;

					}
					else if (j + 1 == x)
					{

						printf("%d- %s\n", y, Item[x].Clasif.c_str());
						y = y + 1;

					}

				}

			}


		}

		x = x + 1;

	} while (x < limit);

}

int clasifelegida(int x, int y, int Opc2)
{

	do
	{

		if (Item[x].Clasif != "")
		{

			y = y + 1;

		}

		x = x + 1;

	} while (y <= Opc2);

	return x;

}

void listadinamicaclasif(int x, int y, int limit)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	do
	{
		double Total = 0, Imp = 16;
		PuntItem = &Item[y];

		if (Item[x].Clasif == Item[y].Clasif)
		{

			SetConsoleTextAttribute(hConsole, 2);
			printf("- %s\n\n", PuntItem->VDJ.c_str());
			SetConsoleTextAttribute(hConsole, 7);
			printf("\tNo. de Artículo:\t%s\n\tConsola:\t%s\n\tFecha de Lanzamiento:\t%s\n\tClasificación:\t%s\n\tCaracterísticas:\t%s\n\tDescripción:\n\n\t%s\n\n\tGénero:\t%s\n\tPrecio:\t%lf\n", PuntItem->NumArt.c_str(), PuntItem->Consola.c_str(), PuntItem->Lanz.c_str(), PuntItem->Clasif.c_str(), PuntItem->Carac.c_str(), PuntItem->Desc.c_str(), PuntItem->Gener.c_str(), PuntItem->Precio);
			printf("\tIVA: %f\n", Item[y].Precio * (Imp / 100));
			Total = Item[y].Precio * (1 + (Imp / 100));
			printf("\tEl precio total de su artículo es:\t%f\n\n\n\n", Total);

		}

		y = y + 1;

	} while (y < limit);

}

void menudinamicoGen(int x,int y,int j,int limit)
{

	do
	{

		if (Item[x].Gener != "")
		{

			if (y == 1)
			{

				printf("%d- %s\n", y, Item[x].Gener.c_str());
				y = y + 1;

			}
			else
			{

				for (j = 0; j < x; j++)
				{

					if (Item[x].Gener == Item[j].Gener)
					{

						break;

					}
					else if (j + 1 == x)
					{

						printf("%d- %s\n", y, Item[x].Gener.c_str());
						y = y + 1;

					}

				}

			}


		}

		x = x + 1;

	} while (x < 3);

}

int genelegido(int x, int y, int Opc2)
{

	do
	{

		if (Item[x].Gener != "")
		{

			y = y + 1;

		}

		x = x + 1;

	} while (y <= Opc2);

	return x;

}

void listadinamicagen(int x, int y, int limit)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	do
	{
		double Total = 0, Imp = 16;
		PuntItem = &Item[y];

		if (Item[x].Gener == Item[y].Gener)
		{

			SetConsoleTextAttribute(hConsole, 2);
			printf("- %s\n\n", PuntItem->VDJ.c_str());
			SetConsoleTextAttribute(hConsole, 7);
			printf("\tNo. de Artículo:\t%s\n\tConsola:\t%s\n\tFecha de Lanzamiento:\t%s\n\tClasificación:\t%s\n\tCaracterísticas:\t%s\n\tDescripción:\n\n\t%s\n\n\tGénero:\t%s\n\tPrecio:\t%lf\n", PuntItem->NumArt.c_str(), PuntItem->Consola.c_str(), PuntItem->Lanz.c_str(), PuntItem->Clasif.c_str(), PuntItem->Carac.c_str(), PuntItem->Desc.c_str(), PuntItem->Gener.c_str(), PuntItem->Precio);
			printf("\tIVA: %f\n", Item[y].Precio * (Imp / 100));
			Total = Item[y].Precio * (1 + (Imp / 100));
			printf("\tEl precio total de su artículo es:\t%f\n\n\n\n", Total);

		}

		y = y + 1;

	} while (y < limit);

}

int compvacio(int x)
{

	do
	{

		if (Item[x].VDJ != "")
		{

			x = x + 1;

		}

	} while (Item[x].VDJ != "");

	return x;

}

void compexist(int y, int x, int limit)
{

	do
	{
		PuntItem = &Item[x];

		if (y == x)
		{

			y = y + 1;

		}

		if (Item[y].NumArt != PuntItem->NumArt)
		{

			y = y + 1;

		}
		else
		{

			system("cls");
			printf("Éste número de artículo ya está en uso, ingrese otro:\n");
			getline(cin, PuntItem->NumArt);
			y = 0;

		}

	} while (y < limit);

}

void agregar(int limit)
{

	system("cls");
	int falso = 0, x = 0, y = 0;
	double Total, Imp = 16;
	printf("¿Desea continuar?\n\n1-Continuar\n2-Cancelar\n\n");
	scanf_s("%d", &falso);

	if (falso == 1)
	{

		system("cls");

		x = compvacio(x);

		if (x <= limit-1)
		{

			PuntItem = &Item[x];

			printf("Ingrese el número de su artículo:\n");
			cin.ignore();
			getline(cin, PuntItem->NumArt);

			compexist(y, x, limit);

			y = 0;
			printf("Ingrese el nombre de su artículo\n");
			getline(cin, PuntItem->VDJ);
			printf("Ingrese la plataforma de su artículo\n");
			getline(cin, PuntItem->Consola);
			printf("Ingrese la fecha de lanzamiento de su artículo\n");
			getline(cin, PuntItem->Lanz);
			printf("Ingrese la clasificación de su artículo\n");
			getline(cin, PuntItem->Clasif);
			printf("Ingrese características para su artículo\n");
			getline(cin, PuntItem->Carac);
			printf("Ingrese una descripción para su artículo\n");
			getline(cin, PuntItem->Desc);
			printf("Ingrese el genero de su artículo\n");
			getline(cin, PuntItem->Gener);
			printf("Ingrese el precio de su artículo\n");
			scanf_s("%lf", &Item[x].Precio);
			printf("IVA: %f\n", Item[x].Precio * (Imp / 100));
			Total = Item[x].Precio * (1 + (Imp / 100));
			printf("\n\nArtículo Registrado\n\nEl precio total de su artículo es:\t%f\n\n\n\n", Total);

			system("pause");

		}
		else if (x >= limit)
		{

			printf("Ya no quedan espacios libres para más artículos\n\n");
			system("pause");

		}

	}

}

void menusec(int Opc2, int limit)
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int x = 0, y = 0, j = 0, k = 0;
	do
	{

		system("cls");

		printf("Seleccione una opción para mostrar\n\n1-Lista Completa\n2-Por Clasificación\n3-Por género\n4-Regresar\n\n");
		scanf_s("%d", &Opc2);

		switch (Opc2)
		{

		case 1:

			system("cls");

			x = 0, y = 0;
			printf("Ésta es la lista de sus artículos en stock\n\n");
			x = compvacioeliminado(x, limit);

			if (x == 0)
			{

				SetConsoleTextAttribute(hConsole, 2);
				printf("\t\tEspera, Aún no tiene artículos registrados\n\n");
				SetConsoleTextAttribute(hConsole, 7);

			}
			else
			{

				listaItems(limit, y);

			}

			system("pause");

			break;

		case 2:

			system("cls");
			k = 0, x = 0, y = 0;
			k = compvacioeliminado(k,limit);

			if (k == 0)
			{

				SetConsoleTextAttribute(hConsole, 2);
				printf("\t\tEspera, Aún no tiene artículos registrados\n\n");
				SetConsoleTextAttribute(hConsole, 7);

			}
			else
			{

				x = 0, y = 1, j = 0;

				printf("Seleccione una de las clasificaciones disponibles:\n\n");

				menudinamicoClasif(x, y, j, limit);

				scanf_s("%d", &Opc2);
				x = 0, y = 1;

				x = clasifelegida(x, y, Opc2) - 1;
				y = 0;

				listadinamicaclasif(x, y, limit);

			}

			system("pause");

			break;

		case 3:

			system("cls");
			k = 0, x = 0, y = 0;
			k = compvacioeliminado(k, limit);

			if (k == 0)
			{

				SetConsoleTextAttribute(hConsole, 2);
				printf("\t\tEspera, Aún no tiene artículos registrados\n\n");
				SetConsoleTextAttribute(hConsole, 7);

			}
			else
			{

				x = 0, y = 1;

				printf("Seleccione una de los géneros disponibles:\n\n");

				menudinamicoGen(x, y, j, limit);

				scanf_s("%d", &Opc2);
				x = 0, y = 1;

				x = genelegido(x, y, Opc2) - 1;
				y = 0;

				listadinamicagen(x, y, limit);

			}

			system("pause");

			break;

		case 4:

			system("cls");
			Opc2 = 4;

			break;

		default:

			system("cls");

			SetConsoleTextAttribute(hConsole, 4);
			printf("Seleccione una opción válida\n\n");
			SetConsoleTextAttribute(hConsole, 7);
			system("pause");

			break;

		}

	} while (Opc2 != 4);

}

void modificar(int Opc2, int limit, double Total, double Imp)
{

	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int x = 0, y = 0, z = 0, falso = 0;
	x = compvacioeliminado(x, limit);

	if (x == 0)
	{

		SetConsoleTextAttribute(hConsole, 2);
		printf("\t\tEspera, Aún no tiene artículos registrados\n\n");
		SetConsoleTextAttribute(hConsole, 7);

	}
	else
	{
		printf("Seleccione el prodcto que desea Modificar:\n\n");

		listasimp(limit,y);

		scanf_s("%d", &z);
		x = 0, y = 0;

		PuntItem = &Item[z-1];
		printf("Éstos son los datos de su producto:\n\n");
		SetConsoleTextAttribute(hConsole, 2);
		printf("- %s\n\n", PuntItem->VDJ.c_str());
		SetConsoleTextAttribute(hConsole, 7);
		printf("\tNo. de Artículo:\t%s\n\tConsola:\t%s\n\tFecha de Lanzamiento:\t%s\n\tClasificación:\t%s\n\tCaracterísticas:\t%s\n\tDescripción:\n\n\t%s\n\n\tGénero:\t%s\n\tPrecio:\t%lf\n\n\n", PuntItem->NumArt.c_str(), PuntItem->Consola.c_str(), PuntItem->Lanz.c_str(), PuntItem->Clasif.c_str(), PuntItem->Carac.c_str(), PuntItem->Desc.c_str(), PuntItem->Gener.c_str(), PuntItem->Precio);
		printf("¿Desea continuar?\n\n1-Continuar\n2-Cancelar\n\n");
		scanf_s("%d", &falso);
		if (falso == 1)
		{

			printf("Ingrese el número de su artículo:\n");
			cin.ignore();
			getline(cin, PuntItem->NumArt);

			compexist(y, z-1, limit);

			y = 0;
			printf("Ingrese el nombre de su artículo\n");
			getline(cin, PuntItem->VDJ);
			printf("Ingrese la plataforma de su artículo\n");
			getline(cin, PuntItem->Consola);
			printf("Ingrese la fecha de lanzamiento de su artículo\n");
			getline(cin, PuntItem->Lanz);
			printf("Ingrese la clasificación de su artículo\n");
			getline(cin, PuntItem->Clasif);
			printf("Ingrese características para su artículo\n");
			getline(cin, PuntItem->Carac);
			printf("Ingrese una descripción para su artículo\n");
			getline(cin, PuntItem->Desc);
			printf("Ingrese el genero de su artículo\n");
			getline(cin, PuntItem->Gener);
			printf("Ingrese el precio de su artículo\n");
			scanf_s("%lf", &Item[z-1].Precio);
			printf("\tIVA: %f\n", Item[z-1].Precio * (Imp / 100));
			Total = Item[z-1].Precio * (1 + (Imp / 100));
			printf("\n\nArtículo Registrado\n\nEl precio total de su artículo es:\t%f\n\n\n\n", Total);

			system("pause");

		}

	}

}

void eliminar(int Opc2, int limit, double Total, double Imp)
{

	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int x = 0, y = 0, z = 0, falso = 0;
	x = compvacioeliminado(x, limit);

	if (x == 0)
	{

		SetConsoleTextAttribute(hConsole, 2);
		printf("\t\tEspera, Aún no tiene artículos registrados\n\n");
		SetConsoleTextAttribute(hConsole, 7);

	}
	else
	{
		printf("Seleccione el prodcto que desea Eliminar:\n\n");

		listasimp(limit, y);

		scanf_s("%d", &z);
		x = 0, y = 0;

		PuntItem = &Item[z - 1];
		printf("Éstos son los datos de su producto:\n\n");
		printf("\tNo. de Artículo:\t%s\n\tConsola:\t%s\n\tFecha de Lanzamiento:\t%s\n\tClasificación:\t%s\n\tCaracterísticas:\t%s\n\tDescripción:\n\n\t%s\n\n\tGénero:\t%s\n\tPrecio:\t%lf\n\n\n", PuntItem->NumArt.c_str(), PuntItem->Consola.c_str(), PuntItem->Lanz.c_str(), PuntItem->Clasif.c_str(), PuntItem->Carac.c_str(), PuntItem->Desc.c_str(), PuntItem->Gener.c_str(), PuntItem->Precio);
		printf("¿Desea continuar?\n\n1-Continuar\n2-Cancelar\n\n");
		scanf_s("%d", &falso);
		if (falso == 1)
		{

			PuntItem->NumArt = "";
			PuntItem->VDJ = "";
			PuntItem->Consola = "";
			PuntItem->Lanz = "";
			PuntItem->Clasif = "";
			PuntItem->Carac = "";
			PuntItem->Desc = "";
			PuntItem->Gener = "";
			Item[z - 1].Precio = NULL;
			printf("\n\nEL PRODUCTO A SIDO ELIMINADO\n\n");

			system("pause");

		}

	}

}

void lista(int Opc2, int limit)
{

	menusec(Opc2, limit);

}

void archivo(int limit)
{

	ofstream basededatos;
	string nomarchivo, datosstr;
	int datosint;
	double datosdouble;

	nomarchivo = "MaruStore";

	basededatos.open(nomarchivo.c_str(), ios::out);

	if (basededatos.fail())
	{

		printf("ERROR NO SE PUDO CREAR EL ARCHIVO");
		system("pause");
		exit(1);

	}

	basededatos << "NumArt" << "\t\t\t";
	basededatos << "VDJ" << "\t\t\t";
	basededatos << "Consola" << "\t\t\t";
	basededatos << "Lanz" << "\t\t\t";
	basededatos << "Clasif" << "\t\t\t";
	basededatos << "Carac" << "\t\t\t";
	basededatos << "Precio" << "\t\t\t";
	basededatos << "Gener" << "\t\t";
	basededatos << "Desc" << "\t\t\t\n";

	for (int i = 0; i < limit; i++)
	{
		datosstr = Item[i].NumArt;
		basededatos << datosstr << "\t" << "\t";
		datosstr = Item[i].VDJ;
		basededatos << datosstr << "\t " << "\t";
		datosstr = Item[i].Consola;
		basededatos << datosstr << "\t" << "\t";
		datosstr = Item[i].Lanz;
		basededatos << datosstr << "\t" << "\t";
		datosstr = Item[i].Clasif;
		basededatos << datosstr << "\t" << "\t";
		datosstr = Item[i].Carac;
		basededatos << datosstr << "\t" << "\t";
		datosstr = Item[i].Gener;
		basededatos << datosstr << "\t" << "\t";
		datosdouble = Item[i].Precio;
		basededatos << datosdouble << "\t" << "\t";
		datosstr = Item[i].Desc;
		basededatos << datosstr << "\t" << "\t\n";
	}

	basededatos.close();

}

void menuprinc()
{
	int Opc = 0, Opc2 = 0, Opc3 = 0, x = 0, y = 0, limit = 3;

	limit = limite(limit);

	do
	{

		system("cls");

		setlocale(LC_ALL, "Spanish");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		int x = 0, y = 0, j = 0, k = 0, falso = 0;
		double Total = 0, Imp = 16;
		string YN;

		SetConsoleTextAttribute(hConsole, 7);
		printf("Seleccione la opción deseada: \n1-. Agregar Artículo \n2-. Modificar artículo \n3-. Eliminar Artículo \n4-. Lista de artículos vigentes \n5-. Limpiar pantalla \n6-. Salir\n\n");
		scanf_s("%d", &Opc);

		switch (Opc)
		{

		case 1:

			agregar(limit);

			break;

		case 2:

			modificar(Opc2, limit, Total, Imp);

			break;

		case 3:

			eliminar(Opc2, limit, Total, Imp);

			break;

		case 4:

			lista(Opc2, limit);

			break;

		case 5:

			system("cls");
			printf("Su ventana ahora esta limpia :P\n\n");
			system("pause");

			break;

		case 6:

			system("cls");
			archivo(limit);
			printf("Gracias por visitar nuestra página\n\n");

			break;

		default:

			system("cls");

			SetConsoleTextAttribute(hConsole, 4);
			printf("Seleccione una opción válida\n\n");
			SetConsoleTextAttribute(hConsole, 7);
			system("pause");

		}

	} while (Opc != 6);

}

int main()
{

	setlocale(LC_CTYPE, "Spanish");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	menuprinc();

}
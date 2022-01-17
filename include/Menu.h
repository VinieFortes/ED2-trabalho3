#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <vector>

#include "../include/MenuTrees.h"
#include "../include/Review.h"

using namespace std;
using namespace chrono;

// Constantes
int const M_NUMBER = 3;
string const ARQ_SAIDA = "saida.txt";

class Menu
{
public:
	Menu() {};
	~Menu() {};

	static void BTree();
	static void RBTree();
	
	static void iniciar();
};

#endif // MENU_H

#ifndef MENUTREE_H
#define MENUTREE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>

#include "RedBlackTree.h"
#include "BTree.h"
#include "Timer.h"

class MenuTrees
{
public:
	
	MenuTrees() {};
	~MenuTrees() {};
	static void startRb();
	static void startB();
	static void modTestRb();
	static void modTestB();

};

#endif

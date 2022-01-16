#include "../include/Menu.h"
#include "../include/MenuTrees.h"

void BTree();
void RBTree();

void Menu::iniciar()
{
    int opt;
    system("clear");
menu:
    cout << "\n| ---   Menu   --- |" << endl
        << endl
        << "Selecione uma opcao: " << endl
        << "1. Arvore Vermelho-Preto\n2. Arvore B\n3. Sair" << endl
        << endl
        << ">> ";

    cin >> opt;

    switch (opt)
    {
    case 1:
        RBTree();
        break;

    case 2:
        BTree();
        break;

    case 3:
        exit(2);
        break;

    default:
        goto menu;
        break;
    }
    goto menu;
}

void Menu::RBTree()
{
    int optRB;
menu:
    cout << "\n| ---   Arvore Vermelho-Preto   --- |" << endl
        << endl
        << "Selecione uma opcao: " << endl
        << "1. Modo de analise\n2. Modo de Teste\n3. Sair" << endl
        << endl
        << ">> ";

    cin >> optRB;

    switch (optRB)
    {
    case 1:
        MenuTrees::startRb();
        break;

    case 2:
        MenuTrees::modTestRb();
        break;

    case 3:
        return;
        break;

    default:
        goto menu;
        break;
    }
    goto menu;
}

void Menu::BTree()
{
    int optB;
menu:
    cout << "\n | ---   Arvore B   --- |" << endl
        << endl
        << "Selecione uma opcao: " << endl
        << "1. Modo de analise\n2. Modo de Teste\n3. Sair" << endl
        << endl
        << ">> ";

    cin >> optB;

    switch (optB)
    {
    case 1:
        MenuTrees::startB();
        break;

    case 2:
        MenuTrees::modTestB();
        break;

    case 3:
        return;
        break;

    default:
        goto menu;
        break;
    }
    goto menu;
}
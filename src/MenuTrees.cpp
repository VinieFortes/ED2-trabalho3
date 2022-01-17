#include "../include/MenuTrees.h"
#include "../include/Review.h"


const int N = 1000;
const int M = 100000;

struct statisticSearch
{
    bool find;
    int nComparer;
    double time_spent;
    Data result;
    infoB resultB;

    statisticSearch(int n, double time, Data result, bool find)
    {
        this->nComparer = n;
        this->time_spent = time;
        this->result = result;
        this->find = find;
    }

    statisticSearch(int n, double time, infoB resultB, bool find)
    {
        this->nComparer = n;
        this->time_spent = time;
        this->resultB = resultB;
        this->find = find;
    }

    statisticSearch() {};
};

struct statisticRbTree
{
    int nComparerSearch;
    double time_search;
    double time_index;
    Data result;

    statisticRbTree(int nComparerSearch, double time_search, double time_index, Data result)
    {
        this->nComparerSearch = nComparerSearch;
        this->time_search = time_search;
        this->time_index = time_index;
        this->result = result;
    }

    statisticRbTree(int nComparerSearch, double time_search, double time_index)
    {
        this->nComparerSearch = nComparerSearch;
        this->time_search = time_search;
        this->time_index = time_index;
    }
};

struct statisticBTree
{
    int nComparerSearch;
    double time_search;
    double time_index;
    infoB result;

    statisticBTree(int nComparerSearch, double time_search, double time_index, infoB result)
    {
        this->nComparerSearch = nComparerSearch;
        this->time_search = time_search;
        this->time_index = time_index;
        this->result = result;
    }

    statisticBTree(int nComparerSearch, double time_search, double time_index)
    {
        this->nComparerSearch = nComparerSearch;
        this->time_search = time_search;
        this->time_index = time_index;
    }
};

statisticSearch searchRbTree(RedBlackTree* tree, string key)
{
    Timer* timer = new Timer();
    int* counter = new int();

    timer->start();
    Node* node = tree->search(key, counter);

    double time_spent = timer->stop().count();
    Data result = Data();
    bool find;

    if (node == NULL)
    {
        result = Data();
        find = false;
    }
    else
    {
        result = node->data;
        find = true;
    }

    return statisticSearch(*counter, time_spent, result, find);
}

double indexRbTree(RedBlackTree* tree, int n)
{
    Timer timer = Timer();

    timer.start();
    tree->indexReview(n);
    double time_spent = timer.stop().count();

    return time_spent;
}

statisticRbTree handlerTestRbTree()
{
    RedBlackTree tree = RedBlackTree();

    double time_search = indexRbTree(&tree, N);
    statisticSearch searchResult = searchRbTree(&tree, tree.getRandomID());

    return statisticRbTree(searchResult.nComparer, searchResult.time_spent, time_search, searchResult.result);
}

statisticSearch searchBTree(BTree* Btree, string key)
{
    Timer* timer = new Timer();
    int* counter = new int();

    timer->start();
    BTreeNode* node = Btree->search(key, counter);

    int i = 0;
    while (node->getKeys(i).id != key && i < node->getN())
    {
        i++;
    }

    double time_spent = timer->stop().count();
    infoB resultB = infoB();
    bool find;

    if (node == NULL)
    {
        resultB = infoB();
        find = false;
    }
    else
    {
        resultB = node->getKeys(i);
        find = true;
    }

    return statisticSearch(*counter, time_spent, resultB, find);
}

double indexBTree(BTree* tree, int n)
{
    Timer timer = Timer();

    timer.start();
    tree->indexReview(n);
    double time_spent = timer.stop().count();

    return time_spent;
}

statisticBTree handlerTestBTree(int t)
{
    BTree tree = BTree(t);

    double time_search = indexBTree(&tree, M);
    statisticSearch searchResult = searchBTree(&tree, tree.getIdIN());

    return statisticBTree(searchResult.nComparer, searchResult.time_spent, time_search, searchResult.resultB);
}

void reviewOutput(int position)
{
    Review review = Review::readReviewBinary(position);

    ofstream arq;
    arq.open("saida.txt", ios::app);
    if (arq.is_open())
    {
        arq << "Review Buscado:" << endl;
      
        arq << review.id << " , ";
        arq << review.text << " , ";
        arq << review.upvotes << " , ";
        arq << review.app_version << " , ";
        arq << review.posted_date << endl;
        
        arq << endl;
    }
    else
    {
        cout << "Erro ao abrir arquivo de sa�da" << endl;
    }
    arq.close();
}

void statisticOutput(statisticRbTree data, int i)
{
    ofstream arq;
    arq.open("saida.txt", ios::app);
    if (arq.is_open())
    {
        arq << " --*-- Resultado " << i << "� busca --*--" << endl;
        arq << "Tempo de indexa��o: " << data.time_index << "s" << endl
            << "Tempo de busca: " << data.time_search << "s" << endl
            << "Numero de compara��es: " << data.nComparerSearch << endl;
    }
    else
    {
        cout << "Erro ao abrir arquivo de sa�da" << endl;
    }
    arq.close();
}

void meanOutput(statisticRbTree data)
{
    ofstream arq;
    arq.open("saida.txt", ios::app);
    if (arq.is_open())
    {
        arq << " --*-- Resultado Media --*--" << endl;
        arq << "Tempo medio de indexa��o: " << data.time_index << "s" << endl
            << "Tempo medio de busca: " << data.time_search << "s" << endl
            << "Numero medio de compara��es: " << data.nComparerSearch << endl;

        arq << endl;
    }
    else
    {
        cout << "Erro ao abrir arquivo de sa�da" << endl;
    }
    arq.close();
}

statisticRbTree CalcMean(vector<statisticRbTree> list)
{
    int nCompare = 0;
    double time_index, time_search = 0;

    for (unsigned int i = 0; i < list.size(); i++)
    {
        nCompare = nCompare + list[i].nComparerSearch;
        time_search = time_search + list[i].time_search;
        time_index = time_index + list[i].time_index;
    }

    statisticRbTree mean = statisticRbTree(nCompare / 5, time_search / 5, time_index / 5);
    return mean;
}

void statisticOutput(statisticBTree data, int i)
{
    ofstream arq;
    arq.open("saida.txt", ios::app);
    if (arq.is_open())
    {
        arq << " --*-- Resultado " << i << "� busca --*--" << endl;
        arq << "Tempo de indexa��o: " << data.time_index << "s" << endl
            << "Tempo de busca: " << data.time_search << "s" << endl
            << "Numero de compara��es: " << data.nComparerSearch << endl;
    }
    else
    {
        cout << "Erro ao abrir arquivo de sa�da" << endl;
    }
    arq.close();
}

void meanPrintOutput(statisticBTree data)
{
    ofstream arq;
    arq.open("saida.txt", ios::app);
    if (arq.is_open())
    {
        arq << " --*-- Resultado Media --*--" << endl;
        arq << "Tempo medio de indexa��o: " << data.time_index << "s" << endl
            << "Tempo medio de busca: " << data.time_search << "s" << endl
            << "Numero medio de compara��es: " << data.nComparerSearch << endl;

        arq << endl;
    }
    else
    {
        cout << "Erro ao abrir arquivo de sa�da" << endl;
    }
    arq.close();
}

statisticBTree CalcMeanB(vector<statisticBTree> list)
{
    int nCompare = 0;
    double time_index, time_search = 0;

    for (unsigned int i = 0; i < list.size(); i++)
    {
        nCompare = nCompare + list[i].nComparerSearch;
        time_search = time_search + list[i].time_search;
        time_index = time_index + list[i].time_index;
    }

    statisticBTree mean = statisticBTree(nCompare / 5, time_search / 5, time_index / 5);
    return mean;
}

void MenuTrees::startRb()
{
    ofstream arq;
    arq.open("saida.txt");
    arq.close();

    vector<statisticRbTree> list;
    for (int i = 0; i < 5; i++)
    {
        statisticRbTree data = handlerTestRbTree();
        statisticOutput(data, i + 1);
        reviewOutput(data.result.pos);
        list.push_back(data);
    }

    statisticRbTree mean = CalcMean(list);
    meanOutput(mean);
}

void MenuTrees::startB()
{
    ofstream arq;
    arq.open("saida.txt");
    arq.close();

    arq.open("saida.txt", ios::app);
    arq << "|      -------------   Arbore B   -------------      |" << endl
        << endl
        << "Teste para t = 20: "
        << endl
        << endl;
    arq.close();

    vector<statisticBTree> listB;
    for (int i = 0; i < 5; i++)
    {
        int test1 = 20;
        statisticBTree infoB = handlerTestBTree(test1);
        statisticOutput(infoB, i + 1);
        reviewOutput(infoB.result.pos);
        listB.push_back(infoB);
    }

    statisticBTree meanB = CalcMeanB(listB);
    meanPrintOutput(meanB);

    arq.open("saida.txt", ios::app);
    arq << "Teste para t = 200: " << endl
        << endl;
    arq.close();

    vector<statisticBTree> listB2;
    for (int i = 0; i < 5; i++)
    {
        int test2 = 200;
        statisticBTree dataB2 = handlerTestBTree(test2);
        statisticOutput(dataB2, i + 1);
        reviewOutput(dataB2.result.pos);
        listB2.push_back(dataB2);
    }

    statisticBTree meanB2 = CalcMeanB(listB2);
    meanPrintOutput(meanB2);
}

void MenuTrees::modTestRb()
{
    RedBlackTree tree = RedBlackTree();
    string key;

    double time_index = indexRbTree(&tree, 50);
    cout << endl << "-*- Mod teste -*-" << endl;

    tree.order();

    cout << endl
        << "Digite o ID a ser pesquisado: ";

    cin >> key;

    statisticSearch statistic = searchRbTree(&tree, key);

    if (statistic.find)
    {
        Review review = Review::readReviewBinary(statistic.result.pos);
        cout << endl << " --*-- Resultado --*--" << endl;
        cout << "Tempo de indexa��o: " << time_index << "s" << endl
            << "Tempo de busca: " << statistic.time_spent << "s" << endl
            << "Numero de compara��es: " << statistic.nComparer << endl;
        cout << "ID: " << review.id << ", Text: " << review.text << ", Upvotes: "
            << review.upvotes << ", App-version: " << review.app_version << ", Posted-date: " << review.posted_date << endl;
    }
    else
    {
        cout << endl << " --*-- Resultado --*--" << endl;
        cout << "Tempo de indexa��o: " << time_index << "s" << endl
            << "Tempo de busca: " << statistic.time_spent << "s" << endl
            << "Numero de compara��es: " << statistic.nComparer << endl;
        cout << "Nenhum registro com esse ID foi encontrado na arvore" << endl;
    }
}

void MenuTrees::modTestB()
{
    BTree tree = BTree(20);
    string key;

    double time_index = indexBTree(&tree, 50);
    cout << "-*- Mod teste -*-" << endl << endl;

    tree.print();

    cout << endl
        << "Digite o ID a ser pesquisado: ";

    cin >> key;

    statisticSearch statistic = searchBTree(&tree, key);

    if (statistic.find)
    {
        Review review = Review::readReviewBinary(statistic.resultB.pos);
        cout << endl << " --*-- Resultado --*--" << endl;
        cout << "Tempo de indexa��o: " << time_index << "s" << endl
            << "Tempo de busca: " << statistic.time_spent << "s" << endl
            << "Numero de compara��es: " << statistic.nComparer << endl;
        cout << "ID: " << review.id << ", Text: " << review.text << ", Upvotes: "
            << review.upvotes << ", App-version: " << review.app_version << ", Posted-date: " << review.posted_date << endl;
    }
    else
    {
        cout << endl << " --*-- Resultado --*--" << endl;
        cout << "Tempo de indexa��o: " << time_index << "s" << endl
            << "Tempo de busca: " << statistic.time_spent << "s" << endl
            << "Numero de compara��es: " << statistic.nComparer << endl;
        cout << "Nenhum registro com esse ID foi encontrado na arvore" << endl;
    }
}
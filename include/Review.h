#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;

struct ReviewPosition
{
	string id;
	int pos;

	ReviewPosition(string review_id, int pos)
	{
		this->id = review_id;
		this->pos = pos;
	}

	ReviewPosition() {};
};


class Review
{
public:

	Review() {};
	~Review() {};

	string id;
	string text;
	int upvotes;
	string app_version;
	string posted_date;

	static vector<Review> readCsv(string path);
	static void writeBinary(Review* data, int n);
	static Review* readBinaryN(int n);
	static void writeElementTxt(Review* data, int n);
	//static Review* accessBinaryI(int i);
	static Review readReviewBinary(int position);
	static ReviewPosition* getReviewPosition(int n);
	void printElement();

private:
	static int sizeArq(fstream& arq);
	static Review builder(string* object);
};

#endif // REVIEW_H


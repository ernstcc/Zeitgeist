#include "Trends.h"

#include "BST.h"

class ourTrends : public Trends {
public:
	virtual void increaseCount(std::string s, unsigned int amount);
	virtual unsigned int getCount(std::string s);
	virtual std::string getNthPopular(unsigned int n);
	virtual unsigned int numEntries();

protected:
	BST<std::string, int> trendTree;
};
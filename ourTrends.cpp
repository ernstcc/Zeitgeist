#include "ourTrends.h"

void ourTrends::increaseCount(std::string s, unsigned int amount){
	if (trendTree.keyExists(s)){
		Node<std::string,int>* temp=trendTree.find(s,trendTree.root);
		temp->data += amount;

		for (int x = 0; x < 10; x++){
			if (temp->data > top10[x].data){
				updateTop10(x, *(temp));
			}
		}
	}
	else{
		if (trendTree.size < 10){
			top10[trendTree.size].data = amount;
			top10[trendTree.size].k = s;
		}
		trendTree.add(s, amount);

	}
}

void ourTrends::updateTop10(int index, Node<std::string,int> n){
	std::string lastName = top10[index].k;
	int lastNum = top10[index].data;

	std::string currentName;
	int currentNum;

	top10[index].k = n.k;
	top10[index].data = n.data;

	for (int x = index + 1; x < 10; x++){
		currentName = top10[x].k;
		currentNum = top10[x].data;

		top10[x].k = lastName;
		top10[x].data = lastNum;

		lastName = currentName;
		lastNum = currentNum;
	}
}

unsigned int ourTrends::getCount(std::string s){
	Node<std::string, int>* temp = trendTree.find(s, trendTree.root);
	return temp->data;
}


std::string ourTrends::getNthPopular(unsigned int n){
	if (n <= 10){
		return top10[n].k;
	}
}

unsigned int ourTrends::numEntries(){
	return trendTree.size();
}
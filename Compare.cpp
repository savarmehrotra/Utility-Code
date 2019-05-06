#include<iostream>
#include<ctype.h>
#include<new>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<list>

using namespace std;

class Object
{
public:
	Object()
	{

	}

	Object(int id, int rating, string s)
	{
		mId = id;
		mRating = rating;
		mText = s;
	}
	
	int mId;
	int mRating;
	string mText;
};



bool compareFunction(Object * p1, Object * p2)
{
	if ( stoi(p1->mText) > stoi(p2->mText) )
		return true;

	return false;
}



class compareObject
{
public:

	bool operator()(Object * p1, Object * p2)
	{
		if (p1->mRating > p2->mRating)
			return true;

		return false;
	} 
};


int main()
{
	vector<Object *> vRepo;
	list<Object *> lRepo;

	set<Object *, compareObject> sRepo;
	map<Object *, int, compareObject> mRepo;
	priority_queue<Object *, vector<Object *>, compareObject> pRepo;

	for (int i = 0; i < 10; ++i)
	{
		Object * pObj = new Object(i, (rand() % 100) + 1, to_string(i + 1000) );
		vRepo.push_back(pObj);
		sRepo.insert(pObj);
		mRepo.insert(make_pair(pObj, i));
		pRepo.push(pObj);
	}

	sort(vRepo.begin(), vRepo.end(), compareFunction);
	cout << "\n\tvector : " << endl;
	for (int i = 0; i < vRepo.size(); ++i)
	{
		cout << (vRepo[i])->mText << "  ";
	}
	
	lRepo.sort(compareFunction);
	
	cout << "\n\tlist : " << endl;
	for (list<Object *>::iterator it = lRepo.begin(); it != lRepo.end(); ++it)
	{
		cout << (*it)->mRating << "  ";
	}

	cout << "\n\tset : " << endl;
	for (set<Object *>::iterator it = sRepo.begin(); it != sRepo.end(); ++it)
	{
		cout << (*it)->mRating << "  ";
	}

	cout << "\n\tmap : " << endl;
	for (map<Object *, int>::iterator it = mRepo.begin(); it != mRepo.end(); ++it)
	{
		cout << it->first->mRating << "  "; //" : " << it->second<<
	}


	cout << "\n\theap : " << endl;
	
	while( pRepo.empty() == false)
	{
		cout << pRepo.top()->mRating << "  ";
		pRepo.pop();
	}


	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>


using namespace std;

//bool hasChildNode(char val)
//void addChildNode(char val)
//Node * getChildNode(char val)
class Node
{
	char mVal;
	map<char, Node *> mChildren;

public:
	Node()
	{

	}

	Node(char val)
	{
		mVal = val;
	}


	bool hasChildNode(char val)
	{
		if (mChildren.find(val) == mChildren.end())
			return false;

		return true;
	}

	void addChildNode(char val)
	{
		mChildren[val] = new Node(val);
	}

	Node * getChildNode(char val)
	{
		if (mChildren.find(val) == mChildren.end())
			return NULL;

		return mChildren[val];
	}

};

//void addString(string s)
//bool hasPattern(string pattern)
class Trie
{
private:
	Node * mRoot;

public:
	Trie()
	{
		mRoot = new Node();
	}

	void addString(string s)
	{
		Node * pCurr = mRoot;

		for (int i = 0; i < s.size(); ++i)
		{
			char val = s[i];

			if (pCurr->hasChildNode(val) == false)
				pCurr->addChildNode(val);

			pCurr = pCurr->getChildNode(val);
		}

	}


	bool hasPattern(string pattern)
	{
		Node * pCurr = mRoot;

		for (int i = 0; i < pattern.size(); ++i)
		{
			char val = pattern[i];

			if (pCurr->hasChildNode(val) == false)
				return false;

			pCurr = pCurr->getChildNode(val);
		}

		return true;
	}
};


string getNormalizedString(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	s.erase(remove_if(s.begin(), s.end(), isspace), s.end());

	return s;
}




int main()
{
	Trie searchTrie;

	string text = "To Kill a mocking bird";
	text = getNormalizedString(text);

	for (int i = text.size() - 1; i >= 0; --i)
	{
		searchTrie.addString(text.substr(i));
	}

	cout << searchTrie.hasPattern(getNormalizedString("kill a")) << endl;
	cout << searchTrie.hasPattern(getNormalizedString("a mock")) << endl;
	cout << searchTrie.hasPattern(getNormalizedString("parrot king")) << endl;

	system("pause");
	return 0;
}
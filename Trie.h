#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>
#include <cctype>
using namespace std;

class Trie
{
private:
	TrieNode* _root = nullptr;

protected:

public:
	Trie()
	{
		_root = new TrieNode{};
	}

	virtual ~Trie()
	{
		//TODO: clean up memory
	}

	//TODO: implement
	void addWord(const string& word)
	{
		TrieNode* iter = _root;

		for (auto character : word)
		{
			if (iter->hasChild(character) == false)
			{
				iter->setChild(character, new TrieNode(character));
			}
			iter = iter->getChild(character);
		}
		iter->setChild('$', new TrieNode('$'));
	}

	//TODO: implement
	vector<string> search(const string& word)
	{
		vector<string> matches;
		TrieNode* iter = _root;
		string tempWord = word;

		for (auto character : word)
		{
			for (auto child : iter->getChildren())
			{
				if (character == child.first)
				{
					iter = iter->getChildren()[character];
					break;
				}
			}
		}

		for (auto child : iter->getChildren())
		{
			if (child.first != '$')
			{
				tempWord = tempWord + child.first;
				searchHelper(matches, word + child.first);
			}
			else
			{
				matches.push_back(tempWord);
			}
		}
		return matches;
	}

	void searchHelper(vector<string>& matches, const string& word)
	{
		TrieNode* iter = _root;
		string tempWord = word;

		for (auto character : word)
		{
			for (auto child : iter->getChildren())
			{
				if (character == child.first)
				{
					iter = iter->getChildren()[character];
					break;
				}
			}
		}

		for (auto child : iter->getChildren())
		{
			if (child.first != '$')
			{
				tempWord = tempWord + child.first;
				searchHelper(matches, word + child.first);
			}
			else
			{
				matches.push_back(tempWord);
			}
		}
	}


};

#endif // !TRIE_H

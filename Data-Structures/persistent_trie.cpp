#include "bits/stdc++.h"
using namespace std;

const int sz = 26;

// Presistent Trie node structure
struct PersistentTrie{

	// stores all children nodes , where ith children denotes
	// ith alphabetical character
    vector < PersistentTrie* > children;

    // marks the ending of the key
    bool keyEnd = false;
    
    // constructor 1
    PersistentTrie(bool keyEnd = false) {
    	this->keyEnd = keyEnd;
    }

    // constructor 2åå
    PersistentTrie(vector < PersistentTrie* > &children,bool keyEnd = false) {
    	this->children = children;
    	this->keyEnd = keyEnd;
    }
	
	// detects existence of key in trie
	bool findKey(string &key, int len);

	// inserts key into trie
	// returns new node after insertion
	PersistentTrie* insert(string &key,int len);
};

// dummy PersistentTrie node
PersistentTrie* dummy;

// initialize dummy for easy implementation
void init() {
	dummy = new PersistentTrie(true);
	// all childredn of dummy as dummy
	vector < PersistentTrie* > children(sz,dummy);
	dummy->children = children;
}

PersistentTrie* PersistentTrie :: insert(string &key,int len) {
	if(len == key.length()) {
		return new PersistentTrie((*this).children,true);
	}
	vector < PersistentTrie* > new_version_PersistentTrie = (*this).children;
	PersistentTrie *tmpNode = new_version_PersistentTrie[key[len]-'a'];
	new_version_PersistentTrie[key[len]-'a'] = tmpNode->insert(key,len+1); 
	return new PersistentTrie(new_version_PersistentTrie);
}

bool PersistentTrie :: findKey(string &key,int len) {
	if(key.length() == len)
		return this->keyEnd;
	if(this->children[key[len]-'a'] == dummy)
		return false;
	return this->children[key[len]-'a']->findKey(key,len+1);
}

void printAllKeysInTrie(PersistentTrie *root, string &s) {
	int flag = 0;
	for(int i=0;i<sz;i++) {
		if(root->children[i] != dummy) {
			flag = 1;
			s.push_back('a'+i);
			printAllKeysInTrie(root->children[i],s);
			s.pop_back();
		}
	}
	if(flag == 0 and s.length() > 0)
		cout << s << endl;
}

int main(int argc, char const *argv[]) {

	init();
	vector < string > keys({"goku" , "gohan" , "goten" , "gogeta"});

	PersistentTrie* root[keys.size()];
	root[0] = dummy;

	for(int i=1;i<=keys.size();i++) {
		root[i] = root[i-1]->insert(keys[i-1],0);
		string s = "";
	}

	int idx = 3;
	cout << "All keys in trie after version - " << idx << endl;
	string key = "";
	printAllKeysInTrie(root[idx],key);

	string queryString = "goku";
	int l = 2,r = 3;
	cout << "range : " << "[" << l << "," << r << "]" << endl;
	if(root[r]->findKey(queryString,0) and !root[l-1]->findKey(queryString,0))
		cout << queryString << " - exists in above range" << endl;
	else
		cout << queryString << " - does not exists in above range" << endl;

	queryString = "goten";
	l = 2,r = 4;
	cout << "range : " << "[" << l << "," << r << "]" << endl;
	if(root[r]->findKey(queryString,0) and !root[l-1]->findKey(queryString,0))
		cout << queryString << " - exists in above range" << endl;
	else
		cout << queryString << " - does not exists in above range" << endl;


	return 0;
}

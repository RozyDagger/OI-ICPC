#include <vector>
#include <unordered_map>
#include <cstring>
#include <unordered_set>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>

struct node {
	struct node *v[26];
	int en;
	node() {
		for (int i = 0; i<26; ++i) v[i] = NULL;
		en = 0;
	}
};

class trie {
public:
	node * h;
	void dfs(node *nd, bool flag) {
		// if(!nd) return;
		if (nd->en) cnt += flag ? nd->en : 0;
		for (int i = 0; i<cvsz; ++i) if (nd->v[cv[i] - 'a']) dfs(nd->v[cv[i] - 'a'], ((cv[i] == x) || flag));
	}
	void vcst(string s) {
		cv.clear();
		//hashmap recorder may be needed
		for (int i = 0; i<s.length(); ++i) cv.push_back(s[i]);
		cvsz = cv.size();
	}
	int cnt, cvsz;
	vector<char> cv;
	char x;
	trie() {
		h = new node();
	}
	void add(string s) {
		node *cur = h;
		for (int i = 0; i<s.length(); ++i) {
			int ind = s[i] - 'a';
			if (!cur->v[ind]) cur->v[ind] = new node();
			cur = cur->v[ind];
		}
		++cur->en;
	}
	int get(string s) {
		cnt = 0;
		x = s[0];
		vcst(s);
		dfs(h, 0);
		return cnt;
	}
};

class trie2{
public:
	node * h;
	int cnt, cvsz;
	vector<char> cv;
	char x;
	void dfs(node *nd) {
		if (nd->en) cnt += nd->en;
		for (int i = 0; i < cvsz; ++i) if (nd->v[cv[i] - 'a']) dfs(nd->v[cv[i] - 'a']);
	}
	void vcst(string s) {
		cv.clear();
		for (int i = 0; i < s.length(); ++i) cv.push_back(s[i]);
		cvsz = cv.size();
	}
	trie2() {
		h = new node();
	}
	void add(string s) {
		node *cur = h;
		for (int i = 0; i < s.length(); ++i) {
			int ind = s[i] - 'a';
			if (!cur->v[ind]) cur->v[ind] = new node();
			cur = cur->v[ind];
		}
		++cur->en;
	}
	int get(string s) {
		cnt = 0;
		x = s[0];
		vcst(s);
		dfs(h);
		return cnt;
	}
};

string zsort(string &s) {
	int cnt = 0;
	bool bs[26] = { 0 };
	for (int i = 0; i<s.length(); ++i) {
		char c = s[i];
		if (!bs[c - 'a']) bs[c - 'a'] = 1, ++cnt;
	}
	string rst;
	rst.resize(cnt);
	cnt = 0;
	for (int i = 0; i<26; ++i) if (bs[i]) rst[cnt++] = i + 'a';
	return rst;
}

int main() {
	vector<string> wdlst;
	wdlst.push_back("apple");
	wdlst.push_back("pleass");
	wdlst.push_back("please");
	vector<string> dict;
	dict.push_back("aelwxyz");
	dict.push_back("aelpxyz");
	dict.push_back("aelpsxy");
	dict.push_back("saelpxy");
	dict.push_back("xaelpsy");
	vector<int> rst, rst2(dict.size());
	trie T;
	for (int i = 0; i<wdlst.size(); ++i) {
		string t = zsort(wdlst[i]);
		T.add(t);
	}
	for (int i = 0; i<dict.size(); ++i) cout << dict[i] << ": " << T.get(dict[i]) << endl;
	int done = 0;
	vector<vector<int>> vd(26, vector<int>());
	for (int i = 0; i < dict.size(); ++i) {
		char tc = dict[i][0];
		vd[tc - 'a'].push_back(i);
	}
	for (int i = 0; i<26; ++i) {
		if (vd[i].size()) {
			trie2 T2;
			char tx = i + 'a';
			for (string wd : wdlst)
				for (int j = 0; j<wd.size(); ++j)
					if (wd[j] == tx) {
						T2.add(zsort(wd));
						break;
					}
			for (int j = 0; j < vd[i].size(); ++j) {
				rst2[vd[i][j]] = T2.get(dict[vd[i][j]]);
				cout << dict[vd[i][j]] << ": " << rst2[vd[i][j]] << endl;
			}
		}
	}
	system("pause");
	// queue<node*> q;x
	// q.push(T.h);
	// while(!q.empty()){
	//     node *z=q.front(); q.pop();
	//     for(int i=0;i<26;++i) if(z->v[i]) printf("%c ", (i+'a')), q.push(z->v[i]);
	//     cout<<endl;
	// }
}

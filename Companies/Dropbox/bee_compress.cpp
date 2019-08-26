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

struct mode {
	unordered_map<char, mode*> mp;
	int en;
	mode() :en(0) {}
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

class ftrie {
public:
	mode * h;
	node *rt;
	ftrie() {
		h = new mode();
		rt = new node();
	}
	void add(string s) {
		node *cur = rt;
		for (int i = 0; i < s.length(); ++i) {
			int ind = s[i] - 'a';
			if (!cur->v[ind]) cur->v[ind] = new node();
			cur = cur->v[ind];
		}
		++cur->en;
	}
	void madd(string s) {
		mode *cur = h;
		for (int i = 0; i<s.size(); ++i) {
			char c = s[i];
			if (cur->mp.find(c) == cur->mp.end()) cur->mp[c] = new mode();
			cur = cur->mp[c];
		}
		++cur->en;
	}
	int get(string s) {
		int rst = 0;
		node *cur = rt;
		for (int i = 0; i < s.size(); ++i) {
			int c = s[i] - 'a';
			if (!cur->v[c]) return rst;
			cur = cur->v[c];
			rst += cur->en;
		}
		return rst;
	}
	int mget(string s) {
		int rst = 0;
		mode *cur = h;
		for (int i = 0; i<s.size(); ++i) {
			char c = s[i];
			if (!cur || cur->mp.find(c) == cur->mp.end() || cur->mp[c] == NULL) return rst;
			cur = cur->mp[c];
			if (cur) rst += cur->en;
			else break;
		}
		return rst;
	}
};

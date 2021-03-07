#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool palin_perm(string s) {

	map<char,int> mp;
	int len = 0;

	for (char c : s) {
		if (c != ' ') {
			mp[c] += 1;
			len++;
		}
	}

	bool ret = false;

	if (len%2 == 0) {
		int count = 0;

		for (auto &[k, v] : mp) {
			if (v%2 != 0) count++;
		}

		ret = count == 0;
	} else {
		int count = 0;

		for (auto &[k, v] : mp) {
			if (v%2 != 0) count++;
		}

		ret = count == 1;
	}

	return ret;
}

TEST(Perm, test) {

	EXPECT_EQ(palin_perm("tact coa"), true);

	EXPECT_EQ(palin_perm("aab"), true);
	EXPECT_EQ(palin_perm("aabb"), true);
	EXPECT_EQ(palin_perm("aabbcd"), false);
	EXPECT_EQ(palin_perm("aabcd"), false);
}

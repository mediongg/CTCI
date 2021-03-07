#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;


bool is_unique(string s) {
	set<char> visited;

	for (char c : s) {
		if (visited.find(c) != visited.end()) {
			return false;
		}

		visited.insert(c);
	}

	return true;
}

bool is_unique_v2(string s) {
	array<bool, 256> visited = { false };

	for (char c : s) {
		int idx = (int)c;

		if (visited[idx]) return false;
		visited[idx] = true;
	}

	return true;
}

TEST(is_unique_test, test) {
	EXPECT_EQ(is_unique("ABCDEZZZaa"), false);
	EXPECT_EQ(is_unique("Aabc"), true);
}

TEST(is_unique_test_v2, test) {
	EXPECT_EQ(is_unique_v2("ABCDEZZZaa"), false);
	EXPECT_EQ(is_unique_v2("Aabc"), true);
}

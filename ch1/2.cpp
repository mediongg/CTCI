#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;


bool is_perm(string a, string b) {
	array<int, 256> freq1 = { 0 };
	array<int, 256> freq2 = { 0 };

	for (char c : a) {
		int idx = (int)c;
		freq1[idx]++;
	}

	for (char c : b) {
		int idx = (int)c;
		freq2[idx]++;
	}

	for (int i = 0; i < 256; ++i) {
		if (freq1[i] != freq2[i]) return false;
	}

	return true;
}

TEST(is_perm, test) {
	EXPECT_EQ(is_perm("abc", "bca"), true);
	EXPECT_EQ(is_perm("ABC", "BBAC"), false);

	EXPECT_EQ(is_perm("google", "elgoog"), true);
}

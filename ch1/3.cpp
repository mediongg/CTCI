#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void adjust(string& s, int l, int r) {
	if (l > r) return;

	for (int i = r; i >= l; --i) {
		s[i+2] = s[i];
	}
}


string urlify(string s, int len) {
	for (int i = len-1; i >= 0; --i) {
		if (s[i] == ' ') {
			adjust(s, i+1, len-1);

			s[i] = '%';
			s[i+1] = '2';
			s[i+2] = '0';
			len += 2;
		}
	}

	return s;
}
TEST(URLify, test) {
	string s = "Mr John Smith";
	int len = s.size();
	s.resize(len+4, ' ');

	EXPECT_EQ(urlify(s, len), "Mr%20John%20Smith");

	s = "   ";
	len = s.size();
	s.resize(len+6, ' ');
	EXPECT_EQ(urlify(s, len), "%20%20%20");

	s = "abcdd";
	EXPECT_EQ(urlify(s, s.size()), "abcdd");
}

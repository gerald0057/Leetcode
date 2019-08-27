#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_subStr_len = 0;
		string sub_str;
		
		if (s.empty()) {
			return 0;
		}

		sub_str.append(s, 0, 1);
		for (int i = 1; i < s.length(); ++i) {
			if (sub_str.find_first_of(s[i]) != string::npos) {
				if (sub_str.length() > max_subStr_len) {
					max_subStr_len = sub_str.length();
				}
				i -= sub_str.length();

				cout << sub_str << endl;
				sub_str.clear();
			} else {
				sub_str.append(s, i, 1);
			}
		}

		return max_subStr_len > sub_str.length() ? max_subStr_len : sub_str.length();
	}
};

int main(void) {
	string str;
	getline(cin, str);
	
	Solution sol;
	int sub_len = sol.lengthOfLongestSubstring(str);

	cout << sub_len << endl;

	return 0;
}

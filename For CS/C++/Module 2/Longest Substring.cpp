
#include <iostream>
#include <string>
using namespace std;

int longestUniqueSubsttr(string str)
{
	if (str.length() == 0)
		return 0;

	if (str.length() == 1)
		return 1;

	int maxLength = 0;
	bool visited[256] = { false };

	int left = 0, right = 0;
	while (right < str.length()) {

		if (visited[str[right]] == true) {

			while (visited[str[right]] == true) {

				visited[str[left]] = false;
				left++;
			}
		}

		visited[str[right]] = true;

		maxLength = max(maxLength, (right - left + 1));
		right++;
	}
	return maxLength;
}

int main()
{
	string str ;
	cin>>str;
	int len = longestUniqueSubsttr(str);
	cout <<len;
	return 0;
}

                                                                                                                            

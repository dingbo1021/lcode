#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class solution{

public:
    int lengthOfLongestSubstring(string s) 
    {
    	unordered_map<int,int> hash;
    	if (s.length() == 0) return 0;

    	int result = 1;

    	for (int i = 0; i < s.length() - result; i++)
    	{
    		for (int j = i; j < s.length(); j++)
    			{
    				if (hash.find(s.at(j)) == hash.end())
    				{
						hash[s.at(j)] = j;
					}
					else
					{
						result = result < hash.size() ? hash.size() : result;
						hash.clear();
						break;
					}
    			}
    	}
    	result = result < hash.size() ? hash.size() : result;
    	return result;
    }
    int lengthOfLongestSubstring2(string s) 
    {
    	int last[256];
    	memset(last, -1, sizeof(last));
    	int left = 0, result = 0;
    	for ( int i = 0; i < s.length(); i++)
    	{
    		if (last[s.at(i)] >= left) 
    			left = last[s.at(i)] + 1;
    		last[s.at(i)] = i;
    		result = result > i - left + 1 ? result : i - left + 1;
    	}
    	return result;

    }
    string longestPalindrome(string s) 
    {
    	string output = "";
    	if (s.length() == 0) return output;
    	if (s.length() == 1) return s;

    	string temp1(""), temp2("");

    	for (int i = 0 ; i < s.length() - 1; i++)
    	{
    		temp1 = subfind(s, i, i);
    		if(s[i] == s[i + 1])
    		{
    			temp2 = subfind(s, i, i + 1);
    			temp1 = temp1.length() > temp2.length() ? temp1 : temp2;
    		}
			if(temp1.length() > output.length())
    			output = temp1;
    	}
    	return output;
    }

    string subfind(string s, int left, int right)
    {
    	string out;
    	while (left >= 0 && right < s.length() && s[left] == s[right])
		{
			left--;
			right++;
		}

    	out = s.substr(left + 1, right - left - 1);
    	return out;
    }

};

int main(int argc, const char * argv[]) 
{
	string test1("sssssss1ssss");
///	test1.substr(0,1);
//	cout<<test1.substr(5,6)<<endl;
	solution s;


//	cout<< s.lengthOfLongestSubstring(test1) <<endl;
//	cout<< s.lengthOfLongestSubstring2(test1) <<endl;
	cout<< s.longestPalindrome(test1) <<endl;

return 0;
}
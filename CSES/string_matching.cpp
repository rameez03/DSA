#include <cstring>
#include <iostream>
using namespace std;

void computeLPSArray(string pat, int M, int* lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) 
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
  
    int lps[M], count = 0;
  
    computeLPSArray(pat, M, lps);
  
    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            count++;
            j = lps[j - 1];
        }
  
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return count;
}

int main() {
    string s, s1;
    cin>>s>>s1;
    int res = KMPSearch(s1, s);
    cout<<res;
	return 0;
}
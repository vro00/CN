#include<bits/stdc++.h>
using namespace std;

string xor1(string a, string b)
{
    string result = "";
    int n = b.length();
    for(int i=1; i<n; i++){
        if(a[i] == b[i])
            result += "0";
        else
            result += "1";
    }return result;
}
string mod2div(string dividend, string divisor)
{
    int pick = divisor.length();
    string tmp = dividend.substr(0, pick);
    int n = dividend.length();
    while(pick<n){
        if(tmp[0] == '1')
            tmp = xor1(divisor, tmp) + dividend[pick];
        else
            tmp = xor1(std::string(pick, '0'), tmp) + dividend[pick];
        pick += 1;
    }
    if(tmp[0] == '1')
        tmp = xor1(divisor, tmp);
    else
        tmp = xor1(std::string(pick, '0'), tmp);
    return tmp;
}
void encodedData(string data, string key)
{
    int l_key = key.length();
    string appended_data = (data + std::string(l_key - 1, '0'));
    string remainder = mod2div(appended_data, key);
    string codeword = data + remainder;
    cout << "Remainder : " << remainder << "\n";
    cout << "Encoded Data : " << codeword << "\n";
}
int main()
{
    string data = "100100";
    string key = "1101";
    encodedData(data, key);
    return 0;
}
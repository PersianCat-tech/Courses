#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<cstring>
using namespace std;
unordered_map<string, int> key{
		{"int", 1}, {"void", 2}, {"break", 3}, {"float", 4},
        {"while", 5}, {"do", 6}, {"struct", 7}, {"const", 8},
    	{"case", 9}, {"for", 10}, {"return", 11}, {"if", 12},
        {"default", 13}, {"else", 14}
};
unordered_map<string, int> boundry{
	{"-", 1}, {"/", 2}, {"(", 3}, {")", 4},
	{"==", 5}, {"<=", 6}, {"<", 7}, {"+", 8},
	{"*", 9}, {">", 10}, {"=", 11}, {",", 12},
	{";", 13}, {"++", 14}, {"{", 15}, {"}", 16}	
};
unordered_map<string, int> identity;

string sentence;
int len;
int iden_count, key_count, num_count;
int check_iden(int pos);
int check_num(int pos);
int check_boundry(int pos);
bool isvalid(char s);
string itostr(int x);
int main()
{
	getline(cin, sentence); 
	string Token = "Token :";
	string I = "I :";
	string C = "C :";
	int i = 0; 
	len = sentence.length();
	while(i < len){
		while(sentence[i] == ' ') ++i;
		if(sentence[i] == '_' || (sentence[i] >= 'A' && sentence[i] <='Z') 
		|| (sentence[i] >= 'a' && sentence[i] <= 'z')){
			int res = check_iden(i);
			string iden = sentence.substr(i, res);
			if(key.find(iden) == key.end()){
				if(identity.find(iden) == identity.end()){
					++iden_count;
					if(iden_count != 1) I += ' ';
						I += iden;
					identity.insert({iden, iden_count});
				}
				Token += "(I " + itostr(identity[iden]) + ")";		
			}
			else{
				Token += "(K " + itostr(key[iden]) + ")";
			}
			i += res;	
		}
		else if(sentence[i] >= '0' && sentence[i] <= '9'){
			int res = check_num(i);
			string count = sentence.substr(i, res);
			if(identity.find(count) == identity.end()){
				++num_count;
				if(num_count != 1) C += " ";
		    	C += count;
				identity.insert({count, num_count});
			}
			Token += "(C " + itostr(identity[count]) + ")";
		    i += res;	
		}
		else {
			string uboundry;
			if((sentence[i] == '<' && sentence[i+1] == '=') 
			|| (sentence[i] == '+' && sentence[i+1] == '+')
			|| (sentence[i] == '=' && sentence[i+1] == '=')){
				uboundry += sentence[i];
				uboundry += sentence[i+1];
				i += 2;
			}
			else{
				uboundry = sentence[i];
				++i;
			} 
			Token += "(P " + itostr(boundry[uboundry]) + ")";
			
		}
		//cout << Token << endl << I << endl << C << endl;	
	}
	cout << Token << endl << I << endl << C;
	return 0;
}
bool isvalid(char s){
	if(s == '_' || (s >= 'A' && s <='Z') 
		|| (s >= 'a' && s <= 'z') ||
	   	(s >= '0' && s <= '9')) return false;
	if(s == ' ') return false;
	return true;
}
int check_iden(int pos){
	int res = 0;
	for(int i = pos; i < len; ++i){
		if(sentence[i] == '_' || (sentence[i] >= 'A' && sentence[i] <='Z') 
		|| (sentence[i] >= 'a' && sentence[i] <= 'z') ||
	   	(sentence[i] >= '0' && sentence[i] <= '9')){
			++res;
		}
		else break;
	}
	return res;
}
string itostr(int x){
	int sign = 0;
	if(x < 0){
		sign = 1;
		x = -x;
	}
	string res;
	while(x){
		res += '0' + x%10;
		x = x/10;
	}
	if(sign == 1) res += '-';
	reverse(res.begin(), res.end());
	return res;
}
int check_num(int pos){
	int res = 0;
	for(int i = pos; i < len; ++i){
		if(sentence[i] >= '0' && sentence[i] <= '9') res++;
		else break;
	}
	return res;
}
int check_boundry(int pos){
	int res = 0;
	for(int i = pos; i < len; ++i){
		if(isvalid(sentence[i])) res++;
		else break;
	}
	return res;
}		
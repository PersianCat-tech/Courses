#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<string, int> K{
		{"int", 1}, {"void", 2}, {"break", 3}, {"float", 4},
        {"while", 5}, {"do", 6}, {"struct", 7}, {"const", 8},
    	{"case", 9}, {"for", 10}, {"return", 11}, {"if", 12},
        {"default", 13}, {"else", 14}
};  //关键字表
unordered_map<string, int> P{
	{"-", 1}, {"/", 2}, {"(", 3}, {")", 4},
	{"==", 5}, {"<=", 6}, {"<", 7}, {"+", 8},
	{"*", 9}, {">", 10}, {"=", 11}, {",", 12},
	{";", 13}, {"++", 14}, {"{", 15}, {"}", 16}	
}; //界符表
unordered_map<string, int> I;   //标识符表
unordered_map<string, int> C1;  //常整数表
unordered_map<string, int> C2;  //常实数表
unordered_map<char, int> CT;    //字符常量表
unordered_map<string, int> ST;  //字符串常量表

string str;
string I;   //标识符的符号表
int i;
int I_Count;    //标识符在符号表中的位置

int getch_0(int *ch);   //状态转移方程

int main()
{
    getline(cin, str);
    int ch = 0;
    while(str[i] != '\n'){
        string Token;
        switch(ch){
            case 0:{
                ch = getch_0(&ch);
                Token += str[i++];
                break;
            }
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                if(P.find(Token+str[i]) != P.end()){
                    Token += str[i++];
                }
                ch = 5;
                break;
            }
            case 4:{
                ch = 0;
                break;
            }
            case 5:{
                
                break;
            }
            default:{
                cout << "ERROR" << endl;
                return  0;
            }
        }
    }
}
int getch_0(int *ch){
    if((str[i]>='A'&&str[i]<='Z') || (str[i]>='a'&&str[i]<='z') || str[i]=='_') return 1;
    else if(str[i]>='0'&&str[i]<='9') return 2;
    else return 3;
}
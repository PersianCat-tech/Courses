#include<iostream>
#include<cstring>
#include<algorithm>
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
   
string str; //接受输入的字符串
string Token;   //暂时存储分析str得到的记号
string res;
int i;

string I_res;   //标识符的符号表
string C1_res;  //常整数的符号表

int I_Count;    //标识符在符号表中的位置
int C1_Count;   //常整数在符号表中的位置


string itostr(int x);
void func0(const char &a, int *ch);   //状态0转移方程
void func1(const char &a, int *ch);   //状态1转移方程
void func2(const char &a, int *ch);   //状态2转移方程
void func3(const char &a, int *ch);   //状态3转移方程
void func4(const char &a, int *ch);   //状态4转移方程
void func5(const char &a, int *ch);   //状态5转移方程

int main()
{
    res = "Token :";
    I_res = "I: ";
    C1_res = "C1: ";

    getline(cin, str);
    int ch = 0;
    while(str[i] != '\n'){
        
        switch(ch){
            case 0: func0(str[i], &ch);break;
            case 1: func1(str[i], &ch);break;
            case 2: func2(str[i], &ch);break;
            case 3: func3(str[i], &ch);break;
            case 4: func4(str[i], &ch);break;
            default: Token = "";
        }
    }
    return 0;
}
void func0(const char &a, int *ch){
    if((a>='A'&&a<='Z') || (a>='z'&&a<='z') || a == '_'){
        *ch = 1; Token += str[i++]; return;
    }
    if(a>='1' && a<='9'){
        *ch = 2; Token += str[i++]; return;
    }

}
void func1(const char &a, int *ch){
    if((a>='A'&&a<='Z') || (a>='z'&&a<='z') || a == '_' || (a>='0'&&a<='9')){
        *ch = 1; Token += str[i++];
    }
    else {
        *ch = 0x3fffffff;  //case: default 本次识别已结束，开始判断Token的类型
        if(K.find(Token) != K.end()){   //识别出关键字
            res += "(K " + itostr(K[Token]) +")";
        }
        else{   //识别出标识符
            if(I.find(Token) != I.end()){   //标识符已出现过
                res += "(I " + itostr(I[Token]) +")";
            }
            else {      //标识符未出现过
                ++I_Count;
                if(I_Count != 1) I_res += ' ';
                I_res += Token;
                I.insert({Token, I_Count});
            }            
        }
    }
}
void func2(const char &a, int *ch){
    if(a>='0' && a<='9'){   //此处与状态1可接受的字符不一样，因为除首位外其他数字可为0
        *ch = 2; Token += str[i++]; return;
    }
    else if(a == '.'){
        *ch = 3; Token += str[i++]; return;
    }
    else if(a == 'e'){
        *ch = 4; Token += str[i++]; return;
    }
}
void func3(const char &a, int *ch){
    if(a>='0' && a<='9'){
         *ch = 3; Token += str[i++]; return;
    }
    else{
        *ch = 0x3fffffff;   //状态3识别成功的为常整数
        if(C1.find(Token) != C1.end()){ //该常整数已出现过一次
            res += "(C1 " + itostr(C1[Token]) +")";
        }
        else{   //该常整数第一次出现
            ++C1_Count;
            if(C1_Count != 1) C1_res += ' ';
            C1_res += Token;
            C1.insert({Token, C1_Count});
        }
    }
}
void func4(const char &a, int *ch){
    if(a == '-'){
        *ch = 5; Token += str[i++]; return;
    }
    else if(a >= '1' && a <= '9'){// 此时a的值域中不包括0,因为科学计数法e后的第一个数字不为0
        *ch = 6; Token += str[i++]; return;
    }  
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

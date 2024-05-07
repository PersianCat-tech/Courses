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
unordered_map<char, int> P{
	{'-', 1}, {'/', 2}, {'(', 3}, {')', 4},
	//{"==", 5}, {"<=", 6}, {"++", 14},   这三种界符将特判
    {'<', 7}, {'+', 8},
	{'*', 9}, {'>', 10}, {'=', 11}, {',', 12},
	{';', 13},  {'{', 15}, {'}', 16}	
}; //界符表
unordered_map<string, int> I;   //标识符表
unordered_map<string, int> C1;  //常整数表
unordered_map<string, int> C2;  //常实数表
unordered_map<string, int> CT;    //字符常量表
unordered_map<string, int> ST;  //字符串常量表
   
string str; //接受输入的字符串
string Token;   //暂时存储分析str得到的记号
string res;
int i;
int flag; 


string I_res;   //标识符的符号表
string C1_res;  //常整数的符号表
string C2_res;  //常实数的符号表
string CT_res;  //字符常量的符号表
string ST_res;  //字符串常量的符号表



int I_Count;    //标识符在符号表中的位置
int C1_Count;   //常整数在符号表中的位置
int C2_Count;   //常实数在符号表中的位置
int CT_Count;   //字符常量在符号表中的位置
int ST_Count;   //字符串常量在表中的位置


void display();
string itostr(int x);
int hextod(string s);
void func0(const char &a, int *ch);   //状态0转移方程
void func1(const char &a, int *ch);   //状态1转移方程
void func2(const char &a, int *ch);   //状态2转移方程
void func3(const char &a, int *ch);   //状态3转移方程
void func4(const char &a, int *ch);   //状态4转移方程
void func5(const char &a, int *ch);   //状态5转移方程
void func6(const char &a, int *ch);   //状态6转移方程
void func7(const char &a, int *ch);   //状态7转移方程
void func8(const char &a, int *ch);   //状态8转移方程
void func9(const char &a, int *ch);   //状态9转移方程
void func10(const char &a, int *ch);   //状态10转移方程
void func11(const char &a, int *ch);    //状态11转移方程
void func12(const char &a, int *ch);    //状态12转移方程
void func13(const char &a, int *ch);    //状态13转移方程



int main()
{
    res = "Token :";
    I_res = "I :";
    C1_res = "C1 :";
    C2_res = "C2 :";
    CT_res = "CT :";
    ST_res = "ST :";
    getline(cin, str);
    int ch = 0;
    while(str[i] != '\0' || flag == 0){
        if(str[i] == '\0') flag = 1;
        if(flag > 1) break;
        //while(ch != 11 && str[i] == ' ') ++i;   //ch=11代表正在识别字符串，除了读取字符串以外跳过空格
        //display();
        switch(ch){
            case 0: func0(str[i], &ch);break;
            case 1: func1(str[i], &ch);break;   //识别关键字和标识符
            case 2: func2(str[i], &ch);break;   //识别十进制常整数
            case 3: func3(str[i], &ch);break;   //3,4,5,6识别常实数
            case 4: func4(str[i], &ch);break;
            case 5: func5(str[i], &ch);break;
            case 6: func6(str[i], &ch);break;
            case 7: func7(str[i], &ch);break;   //7,8识别十六进制整数
            case 8: func8(str[i], &ch);break;
            case 9: func9(str[i], &ch);break;   //9,10识别字符常量
            case 10: func10(str[i], &ch);break;
            case 11: func11(str[i], &ch);break; //11,12识别字符串常量
            case 12: func12(str[i], &ch);break;
            case 13: func13(str[i], &ch);break;   //识别界符,i-1是为了传递界符的第一个符号
            default: Token = "";ch = 0; //本次识别结束，准备下一次识别
        }
    }
    //cout << "temp: " << Token <<endl;
    if(flag > 1) cout << "ERROR" << endl;
    else{
        cout << res << endl;
        cout << I_res << endl;
        cout << C1_res << endl;
        cout << C2_res << endl;
        cout << CT_res << endl;
        cout << ST_res << endl;;
    }
    return 0;
}



void func0(const char &a, int *ch){
    while(str[i] == ' ') ++i;
    if((a>='A'&&a<='Z') || (a>='a'&&a<='z') || a == '_'){
        *ch = 1; Token += str[i++]; return;
    }
    if(a>='1' && a<='9'){
        *ch = 2; Token += str[i++]; return;
    }
    if(a == '0'){
        *ch = 7; Token += str[i++]; return;
    }
    if(a == '\''){
        *ch = 9; str[i++]; return;
    }
    if(a == '"'){
        *ch = 11; str[i++]; return;
    }
    if(P.find(str[i]) != P.end()){
        *ch = 13; Token += str[i]; return;  
    }
    return;
}
void func1(const char &a, int *ch){
    if((a>='A'&&a<='Z') || (a>='a'&&a<='z') || a == '_' || (a>='0'&&a<='9')){
        *ch = 1; Token += str[i++]; return;
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
                res += "(I " + itostr(I[Token]) +")";
            }            
        }
    }
    return;
}
void func2(const char &a, int *ch){
    if(a>='0' && a<='9'){   //此处与状态1可接受的字符不一样，因为除首位外其他数字可为0
        *ch = 2; Token += str[i++]; return;
    }
    else if(a == '.'){
        *ch = 3; Token += str[i++];
        if(str[i] < '0' || str[i] > '9') flag = 2; 
        return;
    }
    else if(a == 'e'){
        *ch = 4; Token += str[i++];
        if(str[i] < '0' || str[i] > '9') flag = 2; 
        return;
    }
    else{
        *ch = 0x3fffffff;   //跳转到case default, 状态2识别成功的为常整数
        if(C1.find(Token) != C1.end()){ //该常整数已出现过一次
            res += "(C1 " + itostr(C1[Token]) +")";
        }
        else{   //该常整数第一次出现
            ++C1_Count;
            if(C1_Count != 1) C1_res += ' ';
            C1_res += Token;
            C1.insert({Token, C1_Count});
            res += "(C1 " + itostr(C1_Count) + ")";
        }
    }
    return;
}
void func3(const char &a, int *ch){
    if(a>='0' && a<='9'){
         *ch = 3; Token += str[i++]; return;
    }
    else if(a == 'e'){
        *ch = 4; Token += str[i++]; return;
    }
    else{
        *ch = 0x3fffffff;   //跳转到default case.状态3识别成功的为常实数
        if(C2.find(Token) != C2.end()){ //该常实数已出现过一次
            res += "(C2 " + itostr(C2[Token]) +")";
        }
        else{   //该常整数第一次出现
            ++C2_Count;
            if(C2_Count != 1) C2_res += ' ';
            C2_res += Token;
            C2.insert({Token, C2_Count});
            res += "(C2 " + itostr(C2_Count) + ")";
        }
    }
    return;
}
void func4(const char &a, int *ch){
    if(a == '-'){
        *ch = 5; Token += str[i++]; return;
    }
    else if(a >= '1' && a <= '9'){// 此时a的值域中不包括0,因为科学计数法e后的第一个数字不为0
        *ch = 6; Token += str[i++]; return;
    }  
    return;
}
void func5(const char &a, int *ch){
    if(a >= '1' && a <= '9'){// 此时a的值域中不包括0,因为-后的第一个数字不为0
        *ch = 6; Token += str[i++]; return;
    }
    return;  
}
void func6(const char &a, int *ch){
    if(a >= '0' && a <= '9'){// 此时a的值域中包括0
        *ch = 6; Token += str[i++]; return;
    }
    else{
        *ch = 0x3fffffff;   //跳转到case default.状态6识别成功的为常实数
        if(C2.find(Token) != C2.end()){ //该常实数已出现过一次
            res += "(C2 " + itostr(C2[Token]) +")";
        }
        else{   //该常整数第一次出现
            ++C2_Count;
            if(C2_Count != 1) C2_res += ' ';
            C2_res += Token;
            C2.insert({Token, C2_Count});
            res += "(C2 " + itostr(C2_Count) + ")";
        }
    }
    return;  
}
void func7(const char &a, int *ch){
    if(a == 'X' || a == 'x'){   //注意x的大小写
        *ch = 8; Token += str[i++]; return;
    }
    else{
        *ch = 0x3fffffff;
        if(C1.find(Token) != C1.end()){ //该常整数已出现过一次,此处特判0
            res += "(C1 " + itostr(C1[Token]) +")";
        }
        else{   //该常整数第一次出现
            ++C1_Count;
            if(C1_Count != 1) C1_res += ' ';
            C1_res += Token;
            C1.insert({Token, C1_Count});
        }
    }
    return;
}
void func8(const char &a, int *ch){
    if((a>='0'&&a<='9') || (a>='a'&&a<='f') || (a>='A'&&a<='F')){
       *ch = 8; Token += str[i++]; return; 
    }
    else{
        *ch = 0x3fffffff;
        Token = itostr(hextod(Token));  //将十六进制整数转为十进制
        if(C1.find(Token) != C1.end()){ //该常整数已出现过一次
            res += "(C1 " + itostr(C1[Token]) +")";
        }
        else{   //该常整数第一次出现
            ++C1_Count;
            if(C1_Count != 1) C1_res += ' ';
            C1_res += Token;
            C1.insert({Token, C1_Count});
            res += "(C1 " + itostr(C1[Token]) +")";
        }
    }
    return;
}
void func9(const char &a, int *ch){
    *ch = 10; Token += str[i++]; return;
}
void func10(const char &a, int *ch){
    if(a == '\''){
        *ch =0x3fffffff; str[i++];
        if(CT.find(Token) != CT.end()){   //字符常量已出现过
                res += "(CT " + itostr(CT[Token]) +")";
        }
        else {      //字符常量未出现过
            ++CT_Count;
            if(CT_Count != 1) CT_res += ' ';
            CT_res += Token;
            CT.insert({Token, CT_Count});
            res += "(CT " + itostr(CT[Token]) +")";
        }       
        return;
    }
    flag = 2;
    return;
}
void func11(const char &a, int *ch){
    if(a == '"'){
        *ch = 12; str[i++]; return;
    }
    else{
        *ch = 11; Token += str[i++]; return;
    }
    return;
}
void func12(const char &a, int *ch){
    *ch = 0x3fffffff;
    if(ST.find(Token) != ST.end()){   //字符串常量已出现过
        res += "(ST " + itostr(ST[Token]) +")";
    }
    else {      //字符常量未出现过
        ++ST_Count;
        if(ST_Count != 1) ST_res += ' ';
        ST_res += Token;
        ST.insert({Token, ST_Count});
        res += "(ST " + itostr(ST_Count) + ")";
    }       
    return;
}
void func13(const char &a, int *ch){
    int temp = P[a];
    ++i;
    switch(a){  //{"==", 5}, {"<=", 6}, {"++", 14},   这三种界符将特判
        case '=':{
            if(str[i] == '=') {
                Token += str[i++];
                temp = 5;
            }
            break;
        }
        case '<':{
            if(str[i] == '=') {
                Token += str[i++];
                temp = 6;
            }
            break;
        }
        case '+':{
            if(str[i] == '+') {
                Token += str[i++];
                temp = 14;
            }
            break;
        }
        default: break;
    }
    *ch =0x3fffffff;
    res += "(P " +  itostr(temp) + ")";
    return;
}

void display(){
    cout << "temp :" << Token <<endl;
    cout << res << endl;
    cout << I_res << endl;
    cout << C1_res << endl;
    cout << C2_res << endl;
    cout << CT_res << endl;
    cout << ST_res << endl;
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
int hextod(string s){
    int k = 0;
    while(s[k] != '0'){
        if(s[k] >= 'A' && s[k] <= 'Z') s[k] = s[k] + 32;
        k++;
    }
    k = 0;
    while(s[k] != 'x' && s[k] != 'X') ++k;
    ++k;
    int res = 0;
    while(s[k] != '\0'){
        res *= 16;
        if(s[k] >= '0' && s[k] <= '9') res += s[k] - '0';
        else res += s[k] - 'a' + 10;
        ++k;
    }
    return res;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
// 定义单词种类
typedef enum {
  KEYWORD,   // 关键字
  DELIMITER, // 界符
  IDENTIFIER,// 标识符
  INTEGER    // 常整型数
} TokenType;
 
// 关键字表
char *keywords[] = {
  "int", "void", "break", "float", "while", "do",
  "struct", "const", "case", "for", "return", "if",
  "default", "else"
};
 
// 界符表
char delimiters[] = {
  '-', '/', '(', ')', '--', '<=', '<', '+', '*', '>',
  '=', ',', ';', '++', '{', '}', '\'', '"'
};
 
// 标识符表
char *identifiers[100];
int identifier_count = 0;
 
// 常整数表
int integers[100];
int integer_count = 0;
 
// Token 序列
struct Token {
  TokenType type; // 单词种类
  char *lexeme;   // 单词内容
  int value;      // 单词值
} tokens[100];
int token_count = 0;
 
// 读入的源程序
char source[100];
int source_pos = 0;
 
// 读入下一个字符
char get_char() {
  return source[source_pos++];
}
 
// 跳过空白符
void skip_space() {
  while (isspace(source[source_pos])) source_pos++;
}
 
// 读入单词
void get_token() {
  skip_space();
 
  char ch = get_char();
 
  // 如果是字母，则读入单词
  if (isalpha(ch)) {
    int lexeme_pos = 0;
    char lexeme[100];
    while (isalpha(ch) || isdigit(ch)) {
      lexeme[lexeme_pos++] = ch;
      ch = get_char();
    }
    lexeme[lexeme_pos] = '\0';
    source_pos--; // 将最后读入的非字母或数字字符放回去
 
    // 判断是否为关键字
for (int i = 0; i < 14; i++) {
if (strcmp(keywords[i], lexeme) == 0) {
tokens[token_count].type = KEYWORD;
tokens[token_count].lexeme = lexeme;
token_count++;
return;
}
}
 
 
// 如果不是关键字，则加入标识符表
identifiers[identifier_count] = lexeme;
tokens[token_count].type = IDENTIFIER;
tokens[token_count].lexeme = lexeme;
tokens[token_count].value = identifier_count;
identifier_count++;
token_count++;
return;
}
 
// 如果是数字，则读入常整数
if (isdigit(ch)) {
int value = 0;
while (isdigit(ch)) {
value = value * 10 + (ch - '0');
ch = get_char();
}
source_pos--; // 将最后读入的非数字字符放回去
 
 
// 加入常整数表
integers[integer_count] = value;
tokens[token_count].type = INTEGER;
tokens[token_count].value = value;
integer_count++;
token_count++;
return;
}
 
// 如果是界符，则读入界符
for (int i = 0; i < 18; i++) {
if (delimiters[i] == ch) { 
// 加入 Token 序列
tokens[token_count].type = DELIMITER;
tokens[token_count].lexeme = ch;
token_count++;
return;
}
}
}
 
int main() {
// 读入源程序
scanf("%s", source);
 
// 读入 Token 序列
while (source_pos < strlen(source)) {
get_token();
}
 
// 输出 Token 序列
for (int i = 0; i < token_count; i++) {
if (tokens[i].type == KEYWORD) {
printf("(KEYWORD, %s)\n", tokens[i].lexeme);
} else if (tokens[i].type == IDENTIFIER) {
printf("(IDENTIFIER, %s)\n", tokens[i].lexeme);
} else if (tokens[i].type == INTEGER) {
printf("(INTEGER, %d)\n", tokens[i].value);
} else if (tokens[i].type == DELIMITER) {
printf("(DELIMITER, %c)\n", tokens[i].lexeme);
}
}
 
// 输出标识符表
printf("\nIdentifier Table:\n");
for (int i = 0; i < identifier_count; i++) {
printf("%s\n", identifiers[i]);
}
 
// 输出常整数表
printf("\nInteger Table:\n");
for (int i = 0; i < integer_count; i++) {
printf("%d\n", integers[i]);
}
 
return 0;
}

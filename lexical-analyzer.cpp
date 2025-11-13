#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <regex>

using namespace std;

vector <pair<string, string>> lexicalAnalyzer(ifstream & file) 
{
    regex numberDecimalRegex("^\\d+$");
    regex numberFloatRegex("^\\d*\\.\\d+$");
    regex numberHexadecimalRegex("^0[xX][0-9a-fA-F]+$");
    regex stringConstantRegex("\"[^\"]*\"");
    regex charConstantRegex("'.'");
    regex preprocessorDirectiveRegex("^#[a-zA-Z_]\\w*$");
    regex commentRegex("^;.*$");
    regex reservedWordRegex("^(MOV|ADD|SUB|DIV|MUL|PUSH|POP|JMP|JE|JNE|CALL|RET|NOP|CMP|LEA|INT)$");
    regex operatorRegex("^(AND|OR|XOR|NOT|SHL|SHR|INC|DEC)$");
    regex punctuationMarkRegex("^[\\.,;:\\[\\]{}()]$");
    regex identifierRegex("^[a-zA-Z_][a-zA-Z0-9_]*$");
    regex assemblerDirectiveRegex("^\\.[a-zA-Z_][a-zA-Z0-9_]*$");

    string code((istreambuf_iterator <char>(file)), istreambuf_iterator <char>());

    vector<pair<regex, string>> patterns = 
    {
        {numberDecimalRegex, "Decimal number"},
        {numberFloatRegex, "Float number"},
        {numberHexadecimalRegex, "Hexadecimal number"},
        {stringConstantRegex, "String constant"},
        {charConstantRegex, "Char constant"},
        {preprocessorDirectiveRegex, "Preprocessor directive"},
        {commentRegex, "Comment"},
        {reservedWordRegex, "Reserved word"},
        {operatorRegex, "Operator"},
        {punctuationMarkRegex, "Punctuation mark"},
        {identifierRegex, "Identifier"},
        {assemblerDirectiveRegex, "Assembler directive"}
    };

    vector <pair<string, string>> lexemes;
    regex wordsRegex(";.*|\\d*\\.\\d+|\\.[a-zA-Z_][a-zA-Z0-9_]*|\\w+|[\\.,;:\\[\\]{}()]|\"[^\"]*\"|'.'|#[a-zA-Z_][a-zA-Z0-9_]*\\b");
    smatch match;

    string::const_iterator start(code.cbegin());

    while (regex_search(start, code.cend(), match, wordsRegex)) 
    {
        string lexeme = match[0];
        string lexemeType = "Error";

        for (const auto & pattern: patterns) 
        {
            if (regex_match(lexeme, pattern.first)) 
            {
                lexemeType = pattern.second;
                break;
            }
        }
        
        lexemes.emplace_back(lexeme, lexemeType);
        start = match.suffix().first;
    }
    return lexemes;
}

int main() 
{
    string filename;
    ifstream file;

    cout << "Enter file's name: ";
    cin >> filename;

    do 
    {
        file.open(filename);

        if (file.is_open()) 
        {
            break;
        }

        cout << "Unable to read the file. Enter file's name again or type 'exit' to stop the program: ";
        cin >> filename;

        if (filename == "exit")
        {
            return 1;
        }

    } while(true);

    vector <pair<string, string>> lexemes = lexicalAnalyzer(file);

    for (const auto & lexeme : lexemes) 
    {
        cout << "< " << lexeme.first << " - " << lexeme.second << " >" << endl;
    }

    file.close();

    return 0;
} 

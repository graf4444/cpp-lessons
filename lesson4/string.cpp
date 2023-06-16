#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string empty = "";
    string str1 = "abcdef";

    cout << str1 << endl;
    cout << "size: " << str1.size() << endl;
    cout << "length: " << str1.length() << endl;

    cout << "\"abcdef\".empty(): " << str1.empty() << endl;
    cout << "\"\".empty(): " << empty.empty() << endl;

    cout << "before: " << str1 << endl;
    str1.clear();
    cout << "after:  " << str1 << endl;
    str1 = "abcdef";

    cout << "str1[2]: " << str1[2] << endl;

    cout << "str1.substr(1, 4): " << str1.substr(1, 4) << endl;
    cout << "str1: " << str1 << endl;

    str1 += "gh";
    cout << "str1 += \"gh\": " << str1 << endl;

    cout << str1 << endl;
    str1.append("ij");
    cout << "str1.append(\"ij\"): " << str1 << endl;

    str1 = "abcdef";
    cout << str1 << endl;
    str1.insert(2, "jkl");
    cout << "str1.insert(2, \"jkl\"): " << str1 << endl;
    
    str1 = "abcdef";
    cout << str1 << endl;
    str1.erase(1, 4);
    cout << "str1.erase(1, 4): " << str1 << endl;

    str1 = "bababab";
    cout << str1 << endl;
    cout << "str1.find(\"ab\"): " << str1.find("ab") << endl;

    str1 = "bababab";
    cout << str1 << endl;
    cout << "str1.rfind(\"ab\"): " << str1.rfind("ab") << endl;

    str1 = "bababab";
    cout << str1 << endl;
    cout << "str1.find(\"ab\", 2): " << str1.find("ab", 2) << endl;
    
    str1 = "abcdef";
    cout << str1 << endl;
    cout << "str1.replace(2, 2, \"abc\"): " << str1.replace(2, 2, "abc") << endl;

    // 0 -- == , - -- <, + -- >
    str1 = "abca";
    string str2 = "abc";
    cout << "str1.compare(str2): " << str1.compare(str2) << endl;

    str1 = "abcdef";
    cout << str1 << endl;
    str1.push_back('h');
    cout << "str1.push_back(\"abc\"): " << str1 << endl;

    str1 = "abcdef";
    cout << str1 << endl;
    str1.pop_back();
    cout << "str1.pop_back(): " << str1 << endl;

    str1 = "abcdef";
    cout << str1 << endl;
    str1.pop_back();
    cout << "str1.pop_back(): " << str1 << endl;

    cout << "(char)toupper('a'): " << (char)toupper('a') << endl;
    cout << "(char)tolower('A'): " << (char)tolower('A') << endl;

    str1 = "abc";
    str2 = "def";
    cout << "str1 " << str1 << " | str2 " << str2 << endl;
    str1.swap(str2);
    cout << "str1 " << str1 << " | str2 " << str2 << endl;

    return 0;
}
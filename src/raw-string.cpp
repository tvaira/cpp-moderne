#include <iostream>

using namespace std;

int main()
{
    string str1 = "<a href=\"file\">C:\\Program Files\\</a>";
    string str2 = R"(<a href="file">C:\Program Files\</a>)";
    
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    
    string rev = str;
    reverse(rev.begin(), rev.end());
    
    if(str == rev)
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";
    
    return 0;
}

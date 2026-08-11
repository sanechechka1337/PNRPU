#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void Validate(const string& str, const string& substr)
{
    if (str.empty() || substr.empty())
    {

        throw invalid_argument("Error: string or substring cannot be empty");
    }
    if (substr.length() > str.length())
    {
        throw invalid_argument("Error: substring cannot be longer than string");
    }
}

int Direct_search(const string& str, const string& substr)
{
    Validate(str, substr);

    bool is_equal;
    for (int i = 0; i < str.length() - substr.length() + 1; i++)
    {
        is_equal = true;

        for (int j = 0; j < substr.length(); j++)
        {
            if (str[i + j] != substr[j])
            {
                is_equal = false;
                break;
            }
        }

        if (is_equal) 
        { 
            return i; 
        } 
    }
    return -1;
}

int main()
{
    string str = "gekwldlkaworkodwllfkw";
    string substr = "work";

    int result = Direct_search(str, substr);
    if (result != -1)
    {
        cout << "The substring was found.";
    }
    else
    {
        cout << "The substring was not found.";
    }
}

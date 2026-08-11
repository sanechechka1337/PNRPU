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

int Boyer_Moore(string str, string substr)
{
    Validate(str, substr);

    const int char_size = 256;
    unsigned int shift[char_size];

    for (int i = 0; i < char_size; i++)
    {
        shift[i] = substr.length();
    }

    for (int i = 0; i < substr.length() - 1; i++)
    {
        shift[(unsigned char)substr[i]] = substr.length() - i - 1;
    }

    int end_substr = substr.length() - 1;
    int mismatch_pos;
    bool is_equal;

    while (end_substr < str.length())
    {
        is_equal = true;

        for (int i = 0; i < substr.length(); i++)
        {
            if (substr[substr.length() - i - 1] != str[end_substr - i])
            {
                mismatch_pos = end_substr - i;
                is_equal = false;
                break;
            }
        }

        if (is_equal) 
        {
            return end_substr - substr.length() + 1; 
        }

        end_substr = mismatch_pos + shift[(unsigned char)str[mismatch_pos]];
    }

    return -1;
}

int main()
{
    string str = "АБРАКАДКАДАБРА";
    string substr = "КАДАБРА";

    int result = Boyer_Moore(str, substr);
    if (result != -1)
    {
        cout << "The substring was found.";
    }
    else
    {
        cout << "The substring was not found.";
    }
}
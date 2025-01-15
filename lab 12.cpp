#include <iostream>
#include <string>

using namespace std;

string findLongestCommonSubstring(string a, string b)
{
    string result;
    int length_a = a.length();
    int length_b = b.length();
    int** table = new int* [length_a + 1];

    for (int i = 0; i <= length_a; i++)
    {
        table[i] = new int[length_b + 1];
        for (int j = 0; j <= length_b; j++)
            table[i][j] = 0;
    }

    int maximum = 0;
    int lastSubstringBegin = 0;

    for (int i = 1; i <= length_a; i++)
    {
        for (int j = 1; j <= length_b; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                if (table[i][j] > maximum)
                {
                    maximum = table[i][j];
                    lastSubstringBegin = i - maximum;
                }
            }
            else table[i][j] = 0;
        }
    }

    if (maximum > 0)
    {
        for (int i = lastSubstringBegin; i < lastSubstringBegin + maximum; i++)
        {
            result += a[i];
        }
    }

    for (int i = 0; i <= length_a; i++)
    {
        delete[] table[i];
    }
    delete[] table;

    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    string result = findLongestCommonSubstring(a, b);
    cout << "Odpowiedz" << endl;
    cout << result << endl << result.length() << endl;
    return 0;
}
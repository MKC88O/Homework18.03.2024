// Homework18.03.2024.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <windows.h>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;




int main() {
    srand(time(0));
    ////////////////////////////////////////////////////////////////////////////               1               //////////////////////////////////////////////////////////////////////////////
    const int Size = 1000;
    char str[Size];
    char symbol;
    int count = 0;

    cout << "Enter text: ";
    gets_s(str, Size);

    cout << "Enter symbol: ";
    cin >> symbol;
    cout << "\n";
    cout << "Symbol: " << symbol << "\n";

    cout << "Indexes of coincidences symbol: ";
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == symbol) {
            cout << i << " ";
            count++;
        }
    }
    cout << "\n";
    cout << "Quantity of coincidences " << count << "\n\n\n";

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     ////////////////////////////////////////////////////////////////////////////               2               /////////////////////////////////////////////////////////////////////////////

        
    char STR[Size];
    cout << "Enter text in engleash: ";
    cin.ignore();
    gets_s(STR, Size);

    int totalSymbols = 0;
    int totalWords = 0;
    int totalGlasn = 0;
    int totalSoglasn = 0;
    int totalPunct = 0;
    int totalNum = 0;
    int totalOthers = 0;

    bool Word = false;

    for (int i = 0; STR[i] != '\0'; i++)
    {
        char x = STR[i];
        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'))
        {
            totalSymbols++;

            if (isalpha(x)) {
                if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
                {
                    totalGlasn++;
                }
                else
                {
                    totalSoglasn++;
                }
            }
            else if (isdigit(x))
            {
                totalNum++;
            }
        }
        else if (isspace(x))
        {
            if (Word && !isdigit(x))
            {
                totalWords++;
                Word = false;
            }
        }
        else
        {
            totalSymbols++;

            if (x == '.' || x == ',' || x == '!' || x == '?' || x == ';')
            {
                totalPunct++;
            }
            else
            {
                totalOthers++;
            }
        }

        if (!isspace(x) && !Word)
        {
            Word = true;
        }
    }

    if (Word)
    {
        totalWords++;
    }

    cout << "Total symbols: " << totalSymbols << "\n";
    cout << "Total words: " << totalWords << "\n";
    cout << "Total Glasnyh: " << totalGlasn << "\n";
    cout << "Total Soglasnyh: " << totalSoglasn << "\n";
    cout << "Total puncts: " << totalPunct << "\n";
    cout << "Total numbers: " << totalNum << "\n";
    cout << "Total others " << totalOthers << "\n\n\n";

 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////               3               /////////////////////////////////////////////////////////////////////////////

    char Str[Size];
    cout << "Enter text: ";
    cin.ignore();
    gets_s(Str, Size);

    double wordsCount = 0;
    double wordLen = 0;
    bool Words = false;

    for (int i = 0; Str[i] != '\0'; i++)
    {
        char c = Str[i];
        if (!isspace(c))
        {
            if (!Words)
            {
                Words = true;
            }
            wordLen++;
        }
        else
        {
            if (Words)
            {
                wordsCount++;
                Words = false;
            }
        }
    }

    if (Words)
    {
        wordsCount++;
    }

    double AvgLen = wordLen / wordsCount;
    cout << "Total quantity of words: " << wordsCount << "\n";
    cout << "Total lenght of all words: " << wordLen << "\n";
    cout << "Average lenght of word: " << AvgLen << "\n\n\n";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////               4               //////////////////////////////////////////////////////////////////////////////

    int lenPass;
    cout << "Enter lenght of password: ";
    cin >> lenPass;

    string password;
    string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=\\|/';:`~,.";

    for (int i = 0; i < lenPass; i++) 
    {
        int random = rand() % symbols.length();
        password += symbols[random];
    }
    cout << "\n";
    cout << "Ready!\n";
    cout << "Here's your password: " << password << "\n\n\n";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////               5               //////////////////////////////////////////////////////////////////////////////

    string text;
    string reversText;
    string newText;

    cout << "Enter text: ";
    //cin >> text;
    cin.ignore();
    getline(cin, text);

    for (int i = 0; i < text.length(); i++) 
    {
        if (text[i] != ' ' && text[i] != '.' && text[i] != ',' && text[i] != '!' && text[i] != '?' &&
            text[i] != ';')
        {
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                text[i] = text[i] - 'A' + 'a';
            }
            newText += text[i];
        }
    }

    for (int i = newText.length() - 1; i >= 0; i--)
    {
        reversText += newText[i];
    }

    if (newText == reversText)
    {
        cout << "Yes, its palindrom!\n\n";
        cout << reversText;
        cout << newText;
    }
    else 
    {
        cout << "No, its not palindrom!\n\n";
        cout << reversText;
        cout << newText;
    }   
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

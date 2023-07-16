#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{

    string charStream{"India is my country and all Indians are my brothers and sisters. I love my country and I am proud of its rich and varied heritage. I shall always strive to be worthy of it. I shall give my parents, teachers and all elders respect and treat everyone with courtesy. To my country and my people, I pledge my devotion. In their well-being and pro!@&54332*(sperity alone lies my happiness. india255 is my country and all indians are my brothers and sisters. I love my country and I am proud of its rich and varied heritage. I shall always strive to be worthy of it. I shall give my3434 parents, teachers and9973 all elders res4343pect and treat eve98957867ryone with courtesy. To my country and my people, I pledge my devotion. In their well-being and prosperity alone lies my happiness. "};

    string regexStream{};

    while (true)
    {
        cout << "Enter the regex stream: ";
        getline(cin, regexStream);
        regex regExpr{regexStream};

        if (regex_match(charStream, regExpr))
        {
            cout << "Matched!" << endl;
        }
        else
        {
            cout << "NOT Matched!" << endl;
        }

        cout << "=== cm ===" << endl;
        cmatch cm;
        char *charArray = charStream.data();
        regex_match(charArray, cm, regExpr);

        regex_match(charArray, cm, regExpr, regex_constants::match_default);

        cout << "=== sm ===" << endl;

        smatch sm;
        regex_match(charStream, sm, regExpr);

        regex_match(charStream.cbegin(), charStream.cend(), sm, regExpr);
        cout << "String:range, size:" << sm.size() << " matches\n";

        cout << "the matches are: ";
        for (unsigned i = 0; i < sm.size(); ++i)
        {
            cout << "[" << sm[i] << "] ";
        }

        cout << endl;
    }

    return EXIT_SUCCESS;
}

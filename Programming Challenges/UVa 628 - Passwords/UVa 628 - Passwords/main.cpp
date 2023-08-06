#include <iostream>

using namespace std;

const int num_digits = 10;

string numbers[num_digits] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

void generate_password(string dictionary[], int num_words, string rule, string result[], int k)
{
    if(k == rule.size()){
        for(int i=0; i<k; i++)
            cout << result[i];
        cout << endl;
        return;
    }

    if(rule[k] == '#'){
        for(int i=0; i<num_words; i++){
            result[k] = dictionary[i];
            generate_password(dictionary, num_words, rule, result, k+1);
        }
    }else{
        if(rule[k] == '0'){
            for(int i=0; i<num_digits; i++){
                result[k] = numbers[i];
                generate_password(dictionary, num_words, rule, result, k+1);
            }

        }
    }

    return;
}

int main() {

    int num_words = 0;
    int num_rules = 0;
    int num_test_cases = 2;

    string result[100];

    while(num_test_cases--){
        cin >> num_words;
        string dictionary[num_words];

        for(int i=0; i<num_words; i++)
            cin >> dictionary[i];

        cin >> num_rules;

        string rules[num_rules];

        for(int i=0; i<num_rules; i++)
            cin >> rules[i];

        for(int i=0; i<num_rules; i++)
            generate_password(dictionary, num_words, rules[i], result, 0);

        cout << "--"<< endl;

        return 0;
    }



    return 0;
}

/*

#include <iostream>
#include <string>

using namespace std;

string rule;

int NumWords;
string words[105];
string numbers[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

// Interestingly, having this be a ptr or a pure copy yields the same result
string outputs[300];

void PrintOut(int pos)
{
    if (pos == rule.size())
    {
        for (int i = 0; i < pos; ++i)
            cout << outputs[i];
        cout << '\n';
    } else {
        if (rule[pos] == '#')
        {
            for (int i = 0; i < NumWords; ++i)
            {
                outputs[pos] = words[i];
                PrintOut(pos + 1);
            }
        } else {
            for (int i = 0; i < 10; ++i)
            {
                outputs[pos] = numbers[i];
                PrintOut(pos + 1);
            }
        }
    }

    return;
}


int main()
{
    while (cin >> NumWords)
    {
        for (int i = 0; i < NumWords; ++i)
            cin >> words[i];
        cout << "--\n";
        int numRule;
        cin >> numRule;

        while (numRule--)
        {
            cin >> rule;
            PrintOut(0);
        }
    }
}
*/

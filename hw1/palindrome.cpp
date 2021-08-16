#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;

bool non_alphanum(char c)
{
    return isalnum(c) == 0;
}

int main(int argv, char* argc[])
{
    string input(argc[1]);

    //tolower
    transform(input.begin(), input.end(),input.begin(), ::tolower);

    //remove nonalphanum
    input.erase(remove_if(input.begin(), input.end(), non_alphanum), input.end());

    //output
    if (input == string(input.rbegin(), input.rend()))
        cout<< "Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}

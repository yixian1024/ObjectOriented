#include<bits/stdc++.h>
#include<fstream>
#include<cctype>
#include<string>

using namespace std;

int main(void)
{
    string load("load"),locate("locate"),ending("end"),newd("new");
    string word,option,str,num,filename;
    fstream file;
    char temp[20];
    int n;

    while(1)
    {
        cout<<">";
        cin>>temp;
        string option=temp;
        //load
        if(option==load)
        {
            cin>>temp;
            filename=temp;
            file.open(filename.c_str());
            //file.open(temp,fstream::in);
            if(!file)
                cerr<<"Error reading from file"<<endl;
        }
        //locate
        else if(option==locate)
        {
            cin>>temp>>str;
            int mark=0;
            for(int i=0; i<str.length(); i++)
                if(!isdigit(str[i]))
                {
                    cerr<<"Invalid command"<<endl;
                    mark=99;
                    break;
                }
            if(mark==99)continue;
            n=atoi(str.c_str());
            //cout<<n<<endl;
            word=temp;
            int nsame=0;
            while(1)
            {
            	if(file>>str==NULL)
                    break;
                //cout<<str<<endl;
                //remove nonalphanum
                for(int i=0; i<str.length(); i++)
                {
                    if(!isalnum(str[i])&&str[i]!=39)
                        str.erase(i);
                }
                if(str.compare(word)==0)
                    nsame++;
                mark++;
                if(nsame==n)
                    break;
            }
            if(nsame==n)
                cout<<mark<<endl;
            else
            {
                cout<<"No matching entry"<<endl;
                file.close();
                file.open(filename.c_str());
            }
            //start from beginning again
            file.seekp(0,ios::beg);
        }
        //new
        else if(option==newd)
        {
            file.close();
            filename='.';
        }
        //end
        else if(option==ending)
        {
            file.close();
            break;
        }
		else
				cerr<<"Incalid command"<<endl;
    }
}

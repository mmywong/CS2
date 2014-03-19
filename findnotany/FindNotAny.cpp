#include <iostream>

using namespace std;

int strLen(char s[]);
int findNotAny(char charSet[], char s[], int startPos);
int Find(char key, char s[], int startPos);


int main()
{
    char set[10], mainarray[50];
    int positionfound;
    int start;

    cout<<"Main Array: "<<endl;
    cin.getline(mainarray, 50);

    cout<<"Character set: "<<endl;
    cin.getline(set, 10);

    cout<<"Starting Position: "<<endl;
    cin>>start;

    positionfound = findNotAny(set, mainarray, start);

    cout<<"position of non-matching character: "<<endl;
    cout<<positionfound<<endl;
    return 0;
}

int findNotAny(char charSet[], char s[], int startPos)
{
    int i = startPos-1;
    int findValue;

    while(s[i] != '\0' )
    {
        findValue = Find(s[i], charSet, 1);

        if(findValue>0)
        {
            i++;
        }
        else
        {
            return i+1;
        }

    }

}


int strLen(char s[])
{
     int i = 0;
     int count = 0;
     while((s[i]!='\0'))
    {
        i++;
        count = i;
    }
     return count;
}

int Find(char key, char s[], int startPos)
{
    int i=startPos-1;
    int n;
    n = strLen(s);
    while(s[i] != '\0')
    {
        if(key != s[i])
            {
                i++;
            }
        else if(key==s[i])
            {
                return i+1;
            }
        else if(s[i]==s[n])
            {
                return -1;
            }
    }
}

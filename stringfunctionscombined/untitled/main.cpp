#include <iostream>

using namespace std;
int findNotAny(char charSet[], char s[], int startPos);

int main()
{
    char charSet[50];
    int positionfound=0;
    int findAnyStart;

    cout<<"==Find Not Any=="<<endl<<endl;

    cout<<"Main Array: "<<endl;
    cin.ignore();
    cin.getline(word, 100);

    cout<<"Character set: "<<endl;
    cin.ignore();
    cin.getline(charSet, 50);

    cout<<"Starting Position: "<<endl;
    cin>>findAnyStart;

    positionfound = findNotAny(charSet, word, findAnyStart);

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
        findValue = find(s[i], charSet, 1);

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

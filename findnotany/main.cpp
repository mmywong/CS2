#include <iostream>

using namespace std;

int strLen(char s[]);
int findNotAny(char charSet[], char s[], int startPos);
bool checkChar(char letter, char charSet[]);

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

    while(s[i] != '\0' )
    {
        bool answer;

        answer = checkChar(s[i], charSet);
        while(answer == true)
        {
            i++;
            return i;
        }



    }

}

bool checkChar(char letter, char charSet[])
{
    int i=0;
    while(charSet[i] != '\0')
    {


        for (int i = 0; i < strLen(charSet); i++)

            if (letter == charSet[i])
            {
                return true;
            }



}

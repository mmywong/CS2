#include <iostream>

using namespace std;

//Lower Level Functions
int strLen(char s[]);
int find(char key, char s[], int startPos);
void subStr(char s[],char sub[],int start,int length);
int findAny(char charSet[], char s[], int startPos);
int findNotAny(char charSet[], char s[], int startPos);

//Higher Order Functions
void Zorg(char MyString[], char CharSet[], char Substring[], int& pos);

int main()
{
    char mainarray[100], setarray[100], subarray[100];
    int startPos;


    cout<<"Main array: "<<endl;
    cin.getline(mainarray, 100);

    cout<<"Character set: "<<endl;
    cin.getline(setarray, 100);

    cout<<"Starting Position: "<<endl;
    cin>>startPos;

    Zorg(mainarray, setarray, subarray, startPos);

    // cout << "Pos: " << startPos;

    return 0;
}

void Zorg(char MyString[], char CharSet[], char Substring[], int& pos)
{
    int length;
    int newpos;

    pos = findAny(CharSet, MyString, pos);
    length = findNotAny(CharSet, MyString, pos) - pos;
    cout<<"Token starts at position: "<< pos <<endl;

    newpos = pos+length; //"moving index"
    cout<<"Token ends at position: "<< newpos <<endl;



    subStr(MyString, Substring, pos, length);

    cout << "Token length : " << length <<endl;
    cout<<"Token word: "<< Substring <<endl <<endl;

}

//Sub String
/*Creates a substring array. The function takes a section of the main array and
copies the section starting from the starting position and of the given length
and copies this section into the substring array.
Places null character at the end of substring.*/
void subStr(char s[],char sub[],int start,int length)
{
    int i=start, j=0;
    while(s[i] != s[start+length])
    {
        sub[j]=s[i];
        i++;
        j++;
    }
    sub[j]='\0';

}

//Find
//Finds a character in the string starting from the starting position.
//Returns an integer which denotes the position where the character is found.
int find(char key, char s[], int startPos)
{
    int i=startPos;

//    cout << s << endl;
//  cout << "len: " << strLen(s) << endl;

    for(i=startPos; i < strLen(s); i++)
        if(s[i] == key)
            return i;
    return -1;

}

//FindAny
//Finds any of the characters from the string charset in the main string, starting from the starting position.
//Returns an integer which denotes the position where the first matching character is found.
int findAny(char charSet[], char s[], int startPos)
{
    int i= startPos;
//    cout << strLen(s)<<endl;

    while(s[i] != '\0')
    {
        if(find(s[i], charSet, 0) != -1)
        {
//          cout << "i: " << i << endl;
            return i;
        }
        else
            i++;
    }
    return -1;
}

//Find Not Any
/*Finds any of the characters which are not from the string
charset in the main string, starting from the starting position.
Returns an integer which denotes the position where the first non-matching character is found. */
int findNotAny(char charSet[], char s[], int startPos)
{
    int i = startPos;

    while(s[i] != '\0')
    {
        if(find(s[i], charSet, 0) == -1)
            return i;
        else
            i++;
    }
    return -1;
}

//Length
//Finds the length of the string and returns an integer.
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

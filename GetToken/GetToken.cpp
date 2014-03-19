#include <iostream>

using namespace std;

//Lower-Level Functions
int strLen(char s[]);
void subStr(char s[],char sub[],int start,int length);
int findAny(char charSet[], char s[], int startPos);
int findNotAny(char charSet[], char s[], int startPos);
int find(char key, char s[], int startPos);

//Higher-Order Functions
void Zorg(char MyString[], char CharSet[], char Substring[], int& pos);
bool GetToken(char Block[], char Token[], char &tokenType, int &pos);

int main()
{
    char word[100];
    int i;
    char key;

    cin>>key;
    //need to change key into a char set.

    while (word[i] != '\0')
    {
        if(find(s[i], Alpha, startPos) )
        GetToken(word, ______)
    }
    return 0;
}

bool GetToken(char Block[], char Token[], char &tokenType, int &pos)
{
    char Alpha[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char Num[10] = "0123456789";
    char Punc[32] = " !#$%&'()*+,-./:;<=>?@[\]^_`{|}~";

    if(find(character, Alpha, pos) != -1)
    {
        Zorg(Block, Alpha, Token, pos);
        if(pos == strLen(Block[]))
            return true;
        else
            return false;
    }
    if(find(character, Num, pos) != -1)
    {
        Zorg(Block, Num, Token, pos);
        if(pos == strLen(Block[]))
            return true;
        else
            return false;
    }
    if(find(character, Punc, pos) != -1)
    {
        Zorg(Block, Punc, Token, pos);
        if(pos == strLen(Block[]))
            return true;
        else
            return false;
    }


}

int Zorg(char MyString[], char CharSet[], char Substring[], int& pos)
{
    int length;

    pos = findAny(CharSet, MyString, pos);
    length = findNotAny(CharSet, MyString, pos) - pos;

    subStr(MyString, Substring, pos, length);

    /*
    cout << "pos : " << pos << endl;
    cout << "length : " << length << endl;
    */
    cout<<Substring<<endl<<endl;
}


int find(char key, char s[], int startPos)
{
    int i=startPos-1  ;
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


void subStr(char s[],char sub[],int start,int length)
{
    int i=start-1, j=0;
    while(s[i] != s[start+length-1])
    {
        sub[j]=s[i];
        i++;
        j++;
    }
    sub[j]='\0';

}

int findAny(char charSet[], char s[], int startPos)
{
    int i= startPos-1;
    int j=0;
    int n;
    n = strLen(s);
    while(s[i] != '\0')
    {
        while(charSet[j] != '\0')
        {
            if (s[i] != charSet[j])
                j++;
            else if(s[i] == charSet[j])
                return i+1;
        }
        if(s[i] == s[n])
            return -1;
        else
        {
            i++;
            j=0;
        }
    }
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

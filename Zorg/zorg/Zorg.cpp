#include <iostream>

using namespace std;

int strLen(char s[]);
int find(char key, char s[], int startPos);
void subStr(char s[],char sub[],int start,int length);
int findAny(char charSet[], char s[], int startPos);
int findNotAny(char charSet[], char s[], int startPos);
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

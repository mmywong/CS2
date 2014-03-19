#include <iostream>

//Lower Level Functions
int strLen(char s[]);
int find(char key, char s[], int startPos);
void subStr(char s[],char sub[],int start,int length);
int findAny(char charSet[], char s[], int startPos);
int findNotAny(char charSet[], char s[], int startPos);

//Higher Order Functions
void Zorg(char Block[], char CharSet[], char Substring[], int& pos);
bool GetToken(char Block[], char Sub[][100], int& tokenType, int& pos, int& i);
void TokenizeBlock(char Block[], char Sub[][100], int& pos, int&i);
int GetBlock(instream &ins, char block[], int size);
void TokenizeFile(ifstream &inRead, char token2D[][100], int size_block);


using namespace std;

int main()
{
    int i=0;
    int position=0;
    char block[100], sub[i][100];
    char 2D[][100];

    ifstream infile;
    infile.open("file.txt");
    infile>>str;
    infile.close();

    TokenizeFile(file, 2D, i);

    ofstream outfile;
    outfile.open("file.txt");
    outfile<<"file";
    outfile.close();





    return 0;
}

void TokenizeFile(ifstream &inRead, char token2D[][100], int size_block)
{
    char block[size_block]={};
    int rows_used = 0;
    while(GetBlock(in.read, block, size_block))
    {
        TokenizeBlock(block, token2D, rows_used);
    }
}


int GetBlock(instream &ins, char block[], int size)
{
    ins.read(block, size);
    block[ins.gcount]='\0';
    return ins.gcount;
}

void TokenizeBlock(char Block[], char Sub[][100], int &pos, int &i)
{
    bool done = GetToken(Block, Sub, pos, i);
    while (!done)
    {
        GetToken(Block, Sub, tokenType, pos, i);
        i++;
    }
}

bool GetToken(char Block[], char Token[], int &tokenType, int &pos, int &i)
    {
        char Alpha[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char Num[11] = "0123456789";
        char Punc[33] = " !#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

        if(find(Block[pos], Alpha, pos) != -1)
        {
            Zorg(Block, Alpha, Token, pos);
            tokenType = 1;
            cout<<"Type:"<<tokenType<<endl;
            cout<<"Token: "<<Token<<endl;

            if(pos == strLen(Block[i]))
                return true;
            else
                return false;
        }
        if(find(Block[pos], Num, pos) != -1)
        {
            Zorg(Block, Num, Token, pos);
            tokenType = 2;
            cout<<"Type:"<<tokenType<<endl;
            cout<<"Token: "<<Token<<endl;
            if(pos == strLen(Block[i]))
                return true;
            else
                return false;
        }
        if(find(Block[pos], Punc, pos) != -1)
        {
            Zorg(Block, Punc, Token, pos);
            tokenType = 3;
            cout<<"Type: "<<tokenType<<endl;
            cout<<"Token: "<<Token<<endl;
            if(pos == strLen(Block[i]))
                return true;
            else
                return false;
        }


    }


//Zorg
//
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
int find(char key[], char s[], int startPos)
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

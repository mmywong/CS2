#include <iostream>

using namespace std;

bool scanChar(char key, char charSet[]);
int strLen(char s[]);
void strCat(char s[], char t[]);
int strCmp(char s[], char t[]);
void strCpy(char s[], char t[]);
void subStr(char s[],char sub[],int start,int length);
int find(char key, char s[], int startPos);
int findAny(char charSet[], char s[], int startPos);
int findNotAny(char charSet[], char s[], int startPos);
void toUpper(char s[]);
void toLower(char s[]);

int main()
{
    //for 1:Length
    int length;
    char word[100];

    //for 2,3,4:Concatenate, Compare, Copy
    char word1[100], word2[100];

    //for 3: Compare
    int result;

    //for 5: Substring
    char mainarray[100], subarray[50];
    int startPos, howlong;

    //for 6: Find
    char letter;
    int findStart, findResult;

    //for 7, 8: Find Any, Find Not Any
    char charSet[50];
    int positionfound=0;
    int findAnyStart;

    //for 9, 10: To Upper, To Lower
    //using word[100] from "1:Length"

    int choice;
    cout<<"Main Menu"<<endl;
    cout<<"1: String Length"<<endl;
    cout<<"2: String Concatenate"<<endl;
    cout<<"3: String Compare"<<endl;
    cout<<"4: String Copy"<<endl;
    cout<<"5: Sub String"<<endl;
    cout<<"6: Find"<<endl;
    cout<<"7: Find Any"<<endl;
    cout<<"8: Find Not Any"<<endl;
    cout<<"9: To Upper"<<endl;
    cout<<"10: To Lower"<<endl;
    cout<<"x: Exit"<<endl<<endl;

    cout<<":";
    cin>>choice;

    cout<<endl;

    switch(choice)
    {
          case 1:
                cout<<"==String Length=="<<endl<<endl;

                cout<<"Word: ";

                cin.ignore();
                cin.getline(word,100);
                length = strLen(word);

//              cout<<"String length: "<<length<<endl<<endl;
                break;
          case 2:
                cout<<"==String Concatenate=="<<endl<<endl;

                cout<<"Word 1: "<<endl;
                cin>>word1;
                cout<<"Word 2:"<<endl;
                cin>>word2;
                strCat(word1, word2);
                cout<<word1<<endl<<endl;
                break;
          case 3:
                cout<<"==String Compare=="<<endl<<endl;

                cout<<"0: The words are the same"<<endl;
                cout<<"1: First word is greater than second word"<<endl;
                cout<<"-1: First word is smaller than second word"<<endl<<endl;

                cin>>word1;
                cin>>word2;

                result = strCmp(word1, word2);

                cout<<result<<endl<<endl;
                break;
           case 4:
                cout<<"==String Copy=="<<endl<<endl;

                cout<<"Word 1: "<<endl;
                cin>>word1;
                cout<<"Word 2: "<<endl;
                cin>>word2;
                strCpy(word1, word2);
                cout<<word1<<endl<<endl;
                break;
           case 5:
                cout<<"==Sub String=="<<endl<<endl;

                cout<<"Main Array: "<<endl;
                cin.ignore();
                cin.getline(mainarray, 100);

                cout<<"Starting Position: "<<endl;
                cin>>startPos;

                cout<<"Length of SubString: "<<endl;
                cin>>howlong;

                subStr(mainarray, subarray, startPos, howlong);

                cout<<subarray<<endl;
                break;
           case 6:
                cout<<"==Find=="<<endl<<endl;

                cout<<"Word: "<<endl;
                cin.ignore();
                cin.getline(word, 100);


                cout<<"Letter: "<<endl;
                cin>>letter;

                cout<<"Starting from position: "<<endl;
                cin>>findStart;

                findResult = find(letter, word, findStart);

                cout<<"Character is found in position: "<<endl;
                cout<<findResult<<endl;
                break;
            case 7:
                cout<<"==Find Any=="<<endl<<endl;

                cout<<"Main Array: "<<endl;
                cin.ignore();
                cin.getline(word, 100);

                cout<<"Character set: "<<endl;
                cin.getline(charSet, 50);

                cout<<"Starting Position: "<<endl;
                cin>>findAnyStart;

//              cout << "character set: " << charSet[0] << endl << endl;

                //cout<<endl<<"s: "<<word<<", charset: "<<charSet<<", findAnyStart: "<<findAnyStart<<endl;
                //cout<<"  "<<word[positionfound]<<endl;

                positionfound = findAny(charSet, word, findAnyStart);

                cout<<positionfound<<endl;
                break;
            case 8:
                cout<<"==Find Not Any=="<<endl<<endl;

                cout<<"Main Array: "<<endl;
                cin.ignore();
                cin.getline(word, 100);

                cout<<"Character set: "<<endl;
                cin.getline(charSet, 50);

                cout<<"Starting Position: "<<endl;
                cin>>findAnyStart;

                positionfound = findNotAny(charSet, word, findAnyStart);

                cout<<"position of non-matching character: "<<positionfound<<endl;
                break;
            case 9:
                cin.ignore();
                cin.getline(word, 100);
                toUpper(word);
                cout<<word<<endl;
                break;
            case 10:
                cin.ignore();
                cin.getline(word, 100);
                toLower(word);
                cout<<word<<endl;
                break;
            case 'x':

                break;





     }



    return 0;
}

//1:Length
//Finds the length of the string and returns an integer.
int strLen(char s[])
//here, the i is the index pos of null character
{

     int i = 0;
     while((s[i]!='\0'))
        i++;
     return i;
}

//2:Concatenate
//Concatenates two strings together.
//The function will copy string 2 and place it at the end of string 1.
//Places null character at the end of string.
void strCat(char s[], char t[])
{
    int n;
    int m=0;
    n = strLen(s);
    while(t[m] != '\0')
    {
        s[n]=t[m];
        n++;
        m++;
    }
    s[n]='\0';
}

//3:Compare
/*Compares two strings. The function will compare each character from the beginning
to the end of the array. If the two strings are the same,
the function will return a value of 1.
If the two strings are different, the function will return a value of -1.*/
int strCmp(char s[], char t[])
{
    int i=0;

    do
    {
        if(s[i]==t[i])
            i++;
        else if(s[i]>t[i])
            return 1;
        else
            return -1;
    }while((s[i] != '\0')||(t[i]) != '\0');
}

//4: Copy
//Copies characters from source to destination.
//Array overwrites destination. Places null character at the end of string.
void strCpy(char s[], char t[])
{
    int i=0;
    while(t[i] != '\0')
    {
        s[i]=t[i];
        i++;
    }
    s[i]='\0';
}

//5: Sub String
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

//6: Find
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

//7: FindAny
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


    /*
    while(s[i] != '\0')
    {
        while(charSet[j] != '\0')
        {
            if (s[i] != charSet[j])
                j++;
            else if(s[i] == charSet[j])
                return i;
        }
        if(s[i] != s[n])
        {
            i++;
            j=0;
        }
    }
    return -1;
    */
}

//8: Find Not Any
/*Finds any of the characters which are not from the string
charset in the main string, starting from the starting position.
Returns an integer which denotes the position where the first non-matching character is found. */
int findNotAny(char charSet[], char s[], int startPos)
{
    int i = startPos;

    while(s[i] != '\0')
    {
        if(find(s[i], charSet, 0) == -1)
        {
            return i;
        }
        else
            i++;
    }
    return -1;




    //    int isItFound;

//    while (s[i] != '\0')
//    {
//        isItFound = find(s[i], charSet, 0);
//        if(isItFound > 0) //found matching
//            i++;
//        else //not matching
//            return i;
//    }
}



//9: To Upper
//Converts the character from lower case to upper case by deducting 32 from its ASCII value.
//Leaves the characters which are already upper case alone.
void toUpper(char s[])
{
    int i=0;

    while(s[i] != '\0')
    {
        switch(s[i])
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':

                s[i]=s[i]-32;
                i++;
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            case ' ':
                s[i]=s[i];
                i++;
                break;
            }




        }
}

//10: To Lower
//Converts the character from upper case to lower case by adding 32 to its ASCII value.
//Leaves the characters which are already lower case alone.
void toLower(char s[])
{
    int i=0;

    while(s[i] != '\0')
    {
        switch(s[i])
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            case ' ':
                s[i]=s[i];
                i++;
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                s[i]=s[i]+32;
                i++;
                break;
            }

    }
}

//finds whether a character key is within charSet. If found, function will return true.
bool scanChar(char key, char charSet[])
{
    for(int i=0; i<strLen(charSet); i++)
        if (key == charSet[i])
            return true;
    return false;
}

#include <iostream>

using namespace std;

void subStr(s[], sub[], start, length);

int main()
{
    char mainarray[100], subarray[20];
    int startPos, howlong;
    
    cout<<"Main Array: "<<endl;
    cin.getline(mainarray, 100);
    
    cout<<"Starting Position: "<<endl;
    cin>>startPos;
    
    cout<<"Length of SubString: "<<endl;
    cin>>howlong;
    
    subStr(mainarray, subarray, startPos, howlong);
    
    cout<<subarray<<endl;
    
    return 0;
}

void subStr(s[], sub[], start, length)
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


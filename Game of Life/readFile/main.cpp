#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <ctime>

using namespace std;

#define MAX 10

void createRandomWorld();
void getFile(ifstream &in);
void readFile(ifstream &in, int world[MAX][MAX]);
void display(int world[MAX][MAX]);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int world[MAX][MAX];
    ifstream in;
    srand(time(NULL));
    createRandomWorld();//ONLY FOR CREATING A FILE SO THAT TESTING OF READING CAN BE DONE
    getFile(in);
    readFile(in, world);
    display(world);
    return a.exec();
}

void createRandomWorld()
{
    char filename[80];
    ifstream in;
    ofstream out;
    bool again;
    do
    {
        again = false;
        cout<<"What is the name of the file to create: ";
        cin>>filename;
        in.open(filename);
        if(!in.fail())
        {
            in.close();
            cout<<"That file exists. You need to try again"<<endl;
            again = true;
        }
    }while(again);
    in.close();
    out.open(filename);
    for(int i = 1; i < MAX-2; i++)
    {
        for(int j = 1; j < MAX-2 ; j++)
        {
            int temp = rand()%2;
            out<<setw(2)<<temp;
            cout<<setw(2)<<temp;
        }
        out<<endl;
        cout<<endl;
    }
}

void getFile(ifstream &in)
{
    char filename[80];
    bool again;
    do
    {
        again = false;
        cout<<"What is the name of the file: ";
        cin>>filename;
        in.open(filename);
        if(in.fail())
        {
            in.close();
            cout<<"That file does not exist. You need to try again"<<endl;
            again = true;
        }
    }while(again);
}

void readFile(ifstream &in, int world[MAX][MAX])
{
    for(int i = 1; i < MAX-2; i++)
        for(int j = 1; j < MAX-2; j++)
            in>>world[i][j];
}

void display(int world[MAX][MAX])
{
    for(int i = 1; i < MAX-2; i++)
    {
        for(int j = 1; j < MAX-2; j++)
            cout<<setw(3)<<world[i][j];
        cout<<endl;
     }
}

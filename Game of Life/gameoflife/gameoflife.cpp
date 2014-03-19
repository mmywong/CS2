#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#define max_col  7
#define max_row  7

void init(int world[max_row][max_col]);
void runSimulation(ofstream& out, int world[max_row][max_col]);
void infinite(int world[max_row][max_col]);
void read(ifstream &in, int world[max_row][max_col]);
void display(int world[max_row][max_col], ofstream& out);
int CountNeighbors(int world[max_row][max_col], int row, int col);
void GetNextGen(int world[max_row][max_col], int world2[max_row][max_col]);
void Random(int world[max_row][max_col]);

int main()
{

    int world[max_row][max_col];
    int world2[max_row][max_col];

    init(world);
    init(world2);

    ifstream in_stream;
    ofstream out_stream;

    //read config file
    in_stream.open("configfile.txt");
    out_stream.open("nextgen.txt");

    //load pattern file into array
    read(in_stream, world);

    runSimulation(out_stream, world);

    //close file
    in_stream.close();
    out_stream.close();

    return 0;
}

void runSimulation(ofstream& out, int world[max_row][max_col])
{
    int world2[max_row][max_col];
    init(world2);
    char choice;

    //Main Menu
    cout<<"N: Next generation"<<endl;
    cout<<"G: Go and loop consecutive generations"<<endl;
    cout<<"P: Pause at a specific generation"<<endl;
    cout<<"S: Save Pattern"<<endl;
    cout<<"L: Load Pattern"<<endl;
    cout<<"R: Randomly bring 50 cells to life"<<endl;
    cout<<"K: Kill all"<<endl;

    cin>>choice;

    switch(choice)
    {
        case 'N':
            GetNextGen(world, world2);
            display(world2, out);
            break;
        //case 'G':
          //case 'P':


    }


    do
    {
        //process
        GetNextGen(world, world2);
        display(world2, out);
        cout<<endl<<"Do you want to see another generation? ";
        cin>>answer;
    }while(toupper(answer[0]) == 'Y');
}

void init(int world[max_row][max_col])
{
    for(int i = 0; i < max_row; i++)
        for(int j = 0; j < max_col; j++)
            world[i][j] = 0;
}

void read(ifstream &in, int world[max_row][max_col])
{
    //sets up gutter:
 /*   for(int i=0; i<max_row; i++)
        world[i][0] = 0;
    for(int j=0; j<max_col; j++)
        world[0][j] = 0;
*/
    //fills in array starting from world[1][1] to world[max_row-1][max_col-1]:
    for(int i=1; i<max_row-1; i++)
    {
        for(int j=1; j<max_col-1; j++)
        {
            in>>world[i][j];
            cout<<setw(3)<<world[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void display(int world[max_row][max_col], ofstream& out)
{
    for(int i=1; i<max_row-1; i++)
    {
        for(int j=1; j<max_col-1; j++)
        {
            cout<<setw(3)<<world[i][j];
            out<<setw(3)<<world[i][j];
        }
        cout<<endl;
        out<<endl;
    }
}

int CountNeighbors(int world[max_row][max_col], int row, int col)
{
    int neighbors = 0;
    for(int i = (row-1); i < (row+2); i++)
    {
        for(int j = (col-1); j < (col+2); j++)
            neighbors += world[i][j];
    }
    if(world[row][col] == 1)
        neighbors -= 1;
    return neighbors;
}

void GetNextGen(int world[max_row][max_col], int world2[max_row][max_col])
{
    infinite(world);
    for(int j=0; j<max_col; j++)
    {
        for (int i=0; i<max_row; i++)
        {
            /* Alternative Method
            switch(CountNeighbors(world, i, j))
            {

                case 0:
                case 1:
                    world2[i][j] = 0;
                    break;
                case 2:
                    world2[i][j] = world[i][j];
                    break;
                case 3:
                    world2[i][j] = world[i][j];
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                    world2[i][j] = 0;
                    break;
             */
            int totalNeighbors = CountNeighbors(world,i,j);
            switch(totalNeighbors)
            {
                case 2: if(world[i][j] == 1)
                            world2[i][j] = 1;
                        else
                            world2[i][j] = 0;
                        break;

                case 3: world2[i][j] = 1;
                        break;

                default: world2[i][j] = 0;
            }
/*
            if(CountNeighbors(world, i, j) < 2 || CountNeighbors(world, i, j) > 3)
                world2[i][j] = 0;
            else if (CountNeighbors(world, i, j) == 2)
                world2[i][j] = world[i][j];
            else if (CountNeighbors(world, i, j) == 3)
                world2[i][j] = 1;

*/

          }
    }
    for(int i=0; i<max_row; i++)
        for(int j=0; j<max_col; j++)
            world[i][j]=world2[i][j];

}

//creates infinite loop by copying the borders
void infinite(int world[max_row][max_col])
{
    world[0][0]=world[max_row-2][max_col-2]; //set top left corner of gutter
    world[max_row-1][max_col-1]=world[1][1]; //set bottom right corner of gutter
    world[max_row-1][0]=world[1][max_col-2]; //set bottom left corner of gutter
    world[0][max_col-1]=world[max_row-2][1]; //set top right corner of gutter
    for(int i=1; i<max_row-1; i++)
    {
        world[i][0] = world[i][max_col-2];
        world[i][max_col-1] = world[i][1];
    }
    for(int j=1; j<max_col-1; j++)
    {
        world[0][j] = world[max_row-2][j];
        world[max_row-1][j] = world[1][j];
    }
}


//Functions still under construction
/*

//continues to get the next generation
void Go()
{
    bool PauseAction;

     if ( PauseAction == false )
    {
         PauseAction = true;
         i = 1;
    }
     if ( PauseAction == true && i == 0)
    {
         PauseAction = false;
    }

    //alternative
    do
    {
        again = false;
        cin>>
        if(!in.fail())
        {
            in.close();
            cout<<"That file exists. You need to try again"<<endl;
            again = true;
        }
    }while(again);
}

//creates a random world
void Random(int world[max_row][max_col])
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
*/

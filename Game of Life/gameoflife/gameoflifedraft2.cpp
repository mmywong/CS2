#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#define max_col  7
#define max_row  7

void init(int world[max_row][max_col]);
void read(ifstream &in, int world[max_row][max_col]);
void display(int world[max_row][max_col]);
int CountNeighbors(int world[max_row][max_col], int row, int col);
void GetNextGen(int world[max_row][max_col], int world2[max_row][max_col]);

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

    //process
    GetNextGen(world, world2);
    display(world2);

    //close file
    in_stream.close();
    out_stream.close();

    return 0;
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

void display(int world[max_row][max_col])
{
    for(int i=1; i<max_row-1; i++)
    {
        for(int j=1; j<max_col-1; j++)
            cout<<setw(3)<<world[i][j]<<"("<<CountNeighbors(world,i,j)<<")";
        cout<<endl;
    }
}

int CountNeighbors(int world[][], int col, int row)
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
    for(int j=0; j<max_col; j++)
    {
        for (int i=0; i<max_row; i++)
        {
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

                    /*
            if(CountNeighbors(world, i, j) < 2 || CountNeighbors(world, i, j) > 3)
                world2[i][j] = 0;
            else if (CountNeighbors(world, i, j) == 2)
                world2[i][j] = world[i][j];
            else // (CountNeighbors(world, i, j) == 3)
                world2[i][j] = 1;
                */
             }
          }
    }

    //creates infinite loop by copying the borders
/*
    for(int i=1; i<max_col-1; i++)
    {
        world2[i][0] = world[i][max_col-2];
        world2[i][max_col-1] = world[i][1];
    }
    for(int j=1; j<max_col-1; j++)
    {
        world2[0][j] = world[max_row-2][j];
        world2[max_row-1][j] = world[1][j];
    }



*/


}



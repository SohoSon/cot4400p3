#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

struct Node {
    string direction;
    pair <int, int> curr;
    //xy for three
    //xy for four
    pair <int, int> three = make_pair(-1, -1);//location 4 steps away first = x, sec=y
    pair <int, int> four = make_pair(-1, -1); //location 3 steps away first = x, sec=y
    bool flag3 = false;
    //bool flag4 = false;
};
//g

int column, rows;
stack<pair<string, string> > path;
stack<pair<string, string> > result;

void printresult(stack<pair<string, string> >& result)
{
    ofstream outputFile;
    outputFile.open("output.txt");

    //pair<string, string> temp1;
    vector<pair<string, string> > temp;

    while (!result.empty())
    {
        temp.push_back(result.top());
        result.pop();
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        //cout << temp.at(i).first << temp.at(i).second << " ";
        outputFile << temp.at(i).first << temp.at(i).second << " ";
    }


    outputFile.close();
}

void DFS(Node** adjlist, int x, int y)
{
    pair<string, string> temp;
    //Add stack to record this point, if the following succeeds. Then there is no need to move.

    if (adjlist[x][y].direction == "J")  //found it
    {
        cout << "found it" <<endl;
        // cout << adjlist[x][y].three.first << ", " << adjlist[x][y].three.second << endl;
        // temp = make_pair(adjlist[adjlist[x][y].three.first][adjlist[x][y].three.second].direction, "-3");
        // cout << temp.first << temp.second << endl;

        // path.push(temp);

        result = path;
        printresult(result);
        //printresult(result);
        exit(0);
        return;
    }

    //Check whether the points of 3 and 4 are negative numbers, negative numbers are all borders, if three and four are all negative numbers, it means that the road is dead.
    if (adjlist[x][y].three.first >= 0 && adjlist[x][y].three.first < column && adjlist[x][y].three.second >= 0 && adjlist[x][y].three.second < rows) //for 3
    {   
        //if(adjlist[x][y].flag3 == false) //if not visited
        //{
            adjlist[x][y].flag3 = true;  //Visited 3 nodes
            //cout << "starting go 3: " ;
            //temp = make_pair(adjlist[adjlist[x][y].three.first][adjlist[x][y].three.second].direction, "-3");
            temp = make_pair(adjlist[x][y].direction, "-3");
            //cout << temp.first << temp.second << " ";
            path.push(temp); //Record this step and record the current name on the left + 3 to go.
          //  int a =  adjlist[x][y].three.first; //Next 3
          //  int b =  adjlist[x][y].three.second;
        //if (adjlist[a][b].three.first >= 0 && adjlist[a][b].three.first < column && adjlist[a][b].three.second >= 0 && adjlist[a][b].three.second < rows)
       // {
            // if(adjlist[a][b].flag3 == true)
            // {
            //     path.pop();
            // } //if not visited
            if(adjlist[adjlist[x][y].three.first][adjlist[x][y].three.second].flag3 == false /*|| adjlist[adjlist[x][y].three.first][adjlist[x][y].three.second].flag4 == false*/ ) //if not visited
                DFS(adjlist, adjlist[x][y].three.first, adjlist[x][y].three.second);
            else
                path.pop();
       // }
            
       // } 
    }
 
    pair<string, string> temp2;
    if (adjlist[x][y].four.first >= 0 && adjlist[x][y].four.first < column && adjlist[x][y].four.second >= 0 && adjlist[x][y].three.second < rows) //for 4
    {
        //if(adjlist[x][y].flag4 == false) //if not visited
        //{
            adjlist[x][y].flag3 = true;
            //cout << "starting go 4: " ;
            //temp2 = make_pair(adjlist[adjlist[x][y].four.first][adjlist[x][y].four.second].direction, "-4");
            temp2 = make_pair(adjlist[x][y].direction, "-4");
            //cout << temp2.first << temp2.second << " ";
            path.push(temp2); //Record this step and record the current left name + 4 to go.

           // int a =  adjlist[x][y].four.first;  //Next 4
           // int b =  adjlist[x][y].four.second;
       // if (adjlist[a][b].four.first >= 0 && adjlist[a][b].four.first < column && adjlist[a][b].four.second >= 0 && adjlist[a][b].four.second < rows)
        //{
            // if(adjlist[a][b].flag4 == true)
            // {
            //     path.pop();
            //     path.pop();
            // } //if not visited
            if(adjlist[adjlist[x][y].four.first][adjlist[x][y].four.second].flag3 == false /*|| adjlist[adjlist[x][y].four.first][adjlist[x][y].four.second].flag4 == false*/) //if not visited
                DFS(adjlist, adjlist[x][y].four.first, adjlist[x][y].four.second);
            else
                path.pop();
        //}
        //}
    }

    path.pop();
    //The current stack is probably removed here

}


int main() {
    
    int t_x = 0, t_y = 0; //tarzan's position
    Node** adjlist;

    ifstream file("input.txt"); //Open input file
    if (file.is_open())
    {
        string x, y;
        file >> y >> x; //sizes of gragh
        column = stoi(x);
        rows = stoi(y);

        cout << "column = x = " << column << endl;
        cout << "rows = y = " << rows << endl;

        string a, b;
        file >> a >> b; //tarzan's position
        t_x = stoi(b);
        t_y = stoi(a);

        cout << "starting x = " << t_x << endl;
        cout << "starting y = " << t_y << endl;

        adjlist = new Node * [column];
        for (int q = 0; q < column; q++)
        {
            adjlist[q] = new Node[rows];
        }

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < column; i++)
            {
                string dir;
                file >> dir;
                adjlist[i][j].direction = dir;
                adjlist[i][j].curr = make_pair(i, j); //(x, y) = (c, r)
                if (adjlist[i][j].direction == "S") //
                {
                    adjlist[i][j].three = make_pair(i, j + 3);
                    adjlist[i][j].four = make_pair(i, j + 4);
                }
                else if (adjlist[i][j].direction == "N")
                {
                    adjlist[i][j].three = make_pair(i, j - 3);
                    adjlist[i][j].four = make_pair(i, j - 4);
                }
                else if (adjlist[i][j].direction == "W")
                {
                    adjlist[i][j].three = make_pair(i - 3, j);
                    adjlist[i][j].four = make_pair(i - 4, j);
                }
                else if (adjlist[i][j].direction == "E")
                {
                    adjlist[i][j].three = make_pair(i + 3, j);
                    adjlist[i][j].four = make_pair(i + 4, j);
                }
                else if (adjlist[i][j].direction == "NE")
                {
                    adjlist[i][j].three = make_pair(i + 3, j - 3);
                    adjlist[i][j].four = make_pair(i + 4, j - 4);
                }
                else if (adjlist[i][j].direction == "NW")
                {
                    adjlist[i][j].three = make_pair(i - 3, j - 3);
                    adjlist[i][j].four = make_pair(i - 4, j - 4);
                }
                else if (adjlist[i][j].direction == "SE")
                {
                    adjlist[i][j].three = make_pair(i + 3, j + 3);
                    adjlist[i][j].four = make_pair(i + 4, j + 4);
                }
                else if (adjlist[i][j].direction == "SW")
                {
                    adjlist[i][j].three = make_pair(i - 3, j + 3);
                    adjlist[i][j].four = make_pair(i - 4, j + 4);
                }

            }
        }

        //  for(int j = 0; j < rows; j++)
        //  {
        //      for(int i = 0; i < column; i++)
        //      {
        //          cout << adjlist[i][j].direction << endl;
        //          cout << "curr: " << adjlist[i][j].curr.first << "," << adjlist[i][j].curr.second << endl;
        //          cout << adjlist[i][j].three.first << "," << adjlist[i][j].three.second << endl;

        //      }
        //  }


        //DFS(adjlist, t_x, t_y);
        //printresult(result);
    }

    

    file.close();


    //DFS(adjlist, column, rows);
    //printresult(result);


    // pair<string, string> temp1 = make_pair("E", "-3");
    // stack<pair<string, string>> ok;
    // ok.push(temp1);
    // cout << ok.top().first << ok.top().second;

    //printresult(ok);


    DFS(adjlist, t_x-1, t_y-1);
    //printresult(result);
    
    //cout << rows << " " << column << " " << t_x << " " << t_y << endl; 
       // cout << adjlist[0][0].curr.first << "," << adjlist[0][0].curr.second << endl;
       // cout << adjlist[1][0].curr.first << "," << adjlist[1][0].curr.second << endl;
       // cout << adjlist[0][1].curr.first << "," << adjlist[0][1].curr.second << endl;
       // cout << adjlist[1][1].curr.first << "," << adjlist[1][1].curr.second << endl;

       // cout << adjlist[0][0].direction << "," << adjlist[0][0].direction << endl;
       // cout << adjlist[1][0].direction << "," << adjlist[1][0].direction << endl;
       // cout << adjlist[0][1].direction << "," << adjlist[0][1].direction << endl;
       // cout << adjlist[1][1].direction << "," << adjlist[1][1].direction << endl;

    return 0;
}

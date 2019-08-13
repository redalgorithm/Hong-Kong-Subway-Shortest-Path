//
//  main.cpp
//  Graph
//
//  Created by 8 on 3/12/19.
//  Copyright © 2019 Shaanan. All rights reserved.
//

#include <iostream>
#include <queue>
#include <array>
#include <string>
using namespace std;

const int MAXSIZE = 90;
int G[MAXSIZE][4] =
{
    {1,2,51,-1},
    {0,2,42,51},
    {1,3,52,66},
    {2,4,70,-1},
    {3,5,-1,-1},
    {4,6,18,-1},
    {5,7,-1,-1},
    {6,8,19,-1},
    {7,9,-1,-1},
    {8,10,-1,-1},
    {9,11,-1,-1},
    {10,12,44,72},
    {11,13,44,45},
    {12,14,-1,-1},
    {13,15,-1,-1},
    {14,16,-1,-1},
    {15,-1,-1,-1},
    {18,-1,-1,-1},
    {17,5,-1,-1},
    {7,20,-1,-1},
    {19,21,32,33},
    {20,22,-1,-1},
    {21,23,-1,-1},
    {22,24,-1,-1},
    {23,25,-1,-1},
    {24,26,-1,-1},
    {25,27,-1,-1},
    {26,28,-1,-1},
    {27,29,-1,-1},
    {28,30,57,-1},
    {29,63,-1,-1},
    {32,70,-1,-1},
    {20,31,-1,-1},
    {20,34,82,-1},
    {33,35,-1,-1},
    {34,36,-1,-1},
    {35,37,-1,-1},
    {36,38,-1,-1},
    {37,39,-1,-1},
    {38,40,-1,-1},
    {39,41,-1,-1},
    {40,-1,-1,-1},
    {1,43,71,-1},
    {42,44,-1,-1},
    {11,12,43,71},
    {12,46,-1,-1},
    {45,80,79,-1},
    {46,-1,-1,-1},
    {49,-1,-1,-1},
    {48,50,-1,-1},
    {49,51,-1,-1},
    {50,0,-1,-1},
    {2,53,-1,-1},
    {52,54,-1,-1},
    {53,55,-1,-1},
    {54,56,-1,-1},
    {55,57,-1,-1},
    {56,58,29,-1},
    {57,59,-1,-1},
    {58,60,-1,-1},
    {59,61,-1,-1},
    {60,62,-1,-1},
    {61,-1,-1,-1},
    {30,64,-1,-1},
    {63,65,-1,-1},
    {64,-1,-1,-1},
    {2,67,-1,-1},
    {66,68,-1,-1},
    {67,69,-1,-1},
    {68,-1,-1,-1},
    {3,31,71,-1},
    {42,44,70,-1},
    {11,73,-1,-1},
    {72,74,-1,-1},
    {73,75,-1,-1},
    {74,76,-1,-1},
    {75,77,-1,-1},
    {76,78,-1,-1},
    {77,-1,-1,-1},
    {46,-1,-1,-1},
    {46,81,-1,-1},
    {80,-1,-1,-1},
    {33,83,-1,-1},
    {82,84,-1,-1},
    {83,85,-1,-1},
    {84,86,-1,-1},
    {85,87,-1,-1},
    {86,88,-1,-1},
    {87,89,-1,-1},
    {88,-1,-1,-1}
};

array<string, MAXSIZE> Stations =
{
    "Central",
    "Hong Kong",
    "Admiralty",
    "Tsim Sha Tsui",
    "Jordan",
    "Yau Ma Tei",
    "Mong Kok",
    "Prince Edward",
    "Sham Shui Po",
    "Cheung Sha Wan",
    "Lai Chi Kok",
    "Mei Foo",
    "Lai King",
    "Kwai Fong",
    "Kwai Hing",
    "Tai Wo Hau",
    "Tsuen Wan",
    "Whampoa",
    "Ho Man Tin",
    "Shek Kip Mei",
    "Kowloon Tong",
    "Lok Fu",
    "Wong Tai Sin",
    "Diamond Hill",
    "Choi Hung",
    "Kowloon Bay",
    "Ngau Tau Kok",
    "Kwun Tong",
    "Lam Tin",
    "Yau Tong",
    "Tiu Keng Leng",
    "Hung Hom",
    "Mong Kok East",
    "Tai Wai",
    "Sha Tin",
    "Fo Tan",
    "University",
    "Tai Po Market",
    "Tai Wo",
    "Fanling",
    "Sheung Shui",
    "Lo Wu",
    "Kowloon",
    "Olympic",
    "Nam Cheong",
    "Tsing Yi",
    "Sunny Bay",
    "Tung Chung",
    "Kennedy Town",
    "HKU",
    "Sai Ying Pun",
    "Sheung Wan",
    "Wan Chai",
    "Causeway Bay",
    "Tin Hau",
    "Fortress Hill",
    "North Point",
    "Quarry Bay",
    "Tai Koo",
    "Sai Wan Ho",
    "Shau Kei Wan",
    "Heng Fa Chuen",
    "Chai Wan",
    "Tseung Kwan O",
    "Hang Hau",
    "Po Lam",
    "Ocean Park",
    "Wong Chuk Hang",
    "Lei Tung",
    "South Horizons",
    "East Tsim Sha Tsui",
    "Austin",
    "Tsuen Wan West",
    "Kam Sheung Road",
    "Yuen Long",
    "Long Ping",
    "Tin Shui Wai",
    "Siu Hong",
    "Tuen Mun",
    "Disneyland Resort",
    "Airport",
    "AsiaWorld-Expo",
    "Che Kung Temple",
    "Sha Tin Wai",
    "City One",
    "Shek Mun",
    "Tai Shui Hang",
    "Heng On",
    "Ma On Shan",
    "Wu Kai Sha"
};

// -------------------------------------------------
// Breadth First Search
/*
   Utilizes Graph (G) to search
   for shortest path from source (s)
   to destination (e).
*/
// -----------------pre-init------------------------

int p[MAXSIZE];     // predecessor (parent) of u
int d[MAXSIZE];     // distance from s to e
queue<int> Q;       // contains GREY vertices only

// -------------------------------------------------
void BFS(int G[MAXSIZE][4], int s, int e)
{
    // INITIALIZATIONS
    int u,v;                // u is the vertex, v is the vertex adjacent to u
    int color[MAXSIZE];     // array that keeps track of colors
    const int WHITE = 0;    // vertex has not yet been discovered
    const int GREY = 1;     // discovered vertex that has not yet had neighbors (v) fully examined
    const int BLACK = 2;    // discovered vertex that had all neighbors (v) fully examined
    
    // ASSIGN DEFAULTS TO ARRAYS
    for(int i=0; i<MAXSIZE; i++)
    {
        color[i] = WHITE;
        d[i] = 10000;       // 10000 represents infinity
        p[i] = -1;
    }
    
    // ASSIGN SOURCE VALUES
    color[s] = GREY;
    d[s] = 0;
    p[s] = -1;
    Q.push(s);
    
    // GET ROUTE
    while(!Q.empty())
    {
        u = Q.front();
        for(int i=0; i<4; i++)
        {
            v = G[u][i];
            
            if(v != -1 && color[v] == WHITE)
            {
                color[v] = GREY;
                d[v] = d[u] + 1;
                p[v] = u;
                Q.push(v);
            }
        }
        Q.pop();
        color[u] = BLACK;
    }
}

/*
 -------------------------
 Converts string to
 all uppercase.
 
 Returns modified string
 -------------------------
*/
string toUpper(string str)
{
    int i=0;
    while(i < str.length())
    {
        str[i] = toupper(str[i]);
        i++;
    }
    
    return str;
}
/////////////////////////////////////////////////////////////
int main()
{
    //----------initialize vars----------//

    //INITIALIZE USER VARS
    string start, end;
    
    // INITIALIZE START AND END NODES (default: -1)
    int s = -1, e = -1;
    
    int it = 0;
    do
    {
        //------------get address------------//
        
        // [workaround for getline issues]
        cout << "Press ENTER" << endl;
        cin.ignore();
        cout << endl;
        // GET SOURCE
        cout << "My Location: ";
        getline(cin, start);
        
        // GET DESTINATION
        cout << "Destination: ";
        getline(cin, end);
        
        //--------translate stations---------//
        it = 0;
        while(it < Stations.size())
        {
            if(toUpper(Stations[it]) == toUpper(start))
            {
                s = it;
            }
            if(toUpper(Stations[it]) == toUpper(end))
            {
                e = it;
            }
            it++;
        }
        
        if(s<0 || e<0)
        {
            cout << "______________________________________________________" << endl;
            cout << endl << "* Station not found *\n Please refer to the Hong Kong subway system." << endl;
            cout << "______________________________________________________" << endl;
        }
    }while(s<0 || e<0);
    
    //-------get shortest route--------//
    
    BFS(G, s, e);
    
    //---------output result----------//
    
    cout << endl;
    if(Q.empty())
    {
        //cout << "Start: " << s << endl;
        //cout << "End: " << e << endl;
        int places = d[e]+1;
        int route[places];
        int temp;
        it = 0;
        
        cout << places-1 << " stops from " << Stations[s] << "[" << s << "] to "
        << Stations[e] << "[" << e << "]" << endl;
        
        route[it] = e;
        it++;
        temp = p[e];
        
        while(temp != -1)
        {
            route[it] = temp;
            it++;
            temp = p[temp];
        }
        
        it = places-1;
        while(it > -1)
        {
            cout << route[it--] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "ERROR" << endl;
    }
    
    return 0;
}

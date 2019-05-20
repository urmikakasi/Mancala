//
//  main.cpp
//  mancala
//
//  Created by Urmika Kasi on 09/05/19.
//  Copyright © 2019 Urmika Kasi. All rights reserved.
//

#include <iostream>
using namespace std;
int board[2][6];
int store[2]={0};
void init()
{
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<6;j++)
            board[i][j]=4;
    }
}
void displayboard()
{
    int i=0,j;
    cout<<"\t ";
        for(j=0;j<6;j++)
        {
            cout<<board[i][j]<<" ";
        }
    cout<<"\n";
    cout<<store[0];
    cout<<"\t\t\t\t\t"<<store[1];
    cout<<"\n\t ";
    i=1;
    for(j=0;j<6;j++)
    {
        cout<<board[i][j]<<" ";
    }
    cout<<"\n\n\t ";
    for(j=0;j<6;j++)
        cout<<j+1<<" ";
    
}
int p=1;
int play(int p)//p is the player, returns whose turn next
{
    cout<<"\nPlayer: "<<p;
    cout<<"\nEnter column no. to pick seeds out of: ";
    int col;
pick:
    cin>>col;
    int end=0, seeds;
    int i,j;
    i=p-1;
    j=col-1;
    seeds= board[i][j];
    int k=0;
    if(seeds==0)
    {
        cout<<"There are no seeds here. Enter another column no. :";
        goto pick;
    }
    if(col>6||col<1)
    {
        cout<<"\nInvalid column. Enter another column no. :\n";
    }
    board[i][j]=0;
    while(k<seeds)
    {
        
        if(i==1)
        {
            if(p-1!=i)
            {
                if(j==5)
                {
                    //k++;
                    i=0;
                    //store[1]--;
                    j=6;
                    goto inc;
                }
            }
            if(j==5)
            {
                i=0;
                store[i+1]++;
                k++;
                if(k==seeds)
                {
                    end=1;
                    break;
                }
                
                k++;
                j=5;
                board[i][j]++;
                

                
            }
            else
            {
                if(k==seeds-1 && board[i][j+1]==0 && i==p-1)
                {
                    if(i==0)
                    {
                        store[i]+=board[i+1][j-1]+seeds-k;
                        board[i+1][j-1]=0;
                        //board[i+1][j-2]=0;
                    }
                    else
                    {
                        store[i]+=board[i-1][j+1]+seeds-k;
                        board[i-1][j+1]=0;
                        //board[i-1][j+2]=0;
                    }
                    //board[i][j+1]=1;
                    break;
                }
                /*if(k==seeds-1 && board[i][j+2]==0)
                {
                    if(i==1)
                    {
                        //board[i][j+1]=1;
                        if(j+3<6)
                        {
                            store[p-1]+=board[i][j+3]+board[i-1][j+3];
                            board[i][j+3]=board[i-1][j+3]=0;
                            
                        }
                        
                    }
                    if(i==0)
                    {
                        //board[i][j-1]=1;
                        if(j-3>=0)
                        {
                            store[p-1]+=board[i][j-3]+board[i+1][j-3];
                            board[i][j-3]=board[i+1][j-3]=0;
                        }
                    }
                }*/
                
            inc2:
                j++;
                board[i][j]+=1;
                
                k++;
                
            }
            
            
        }
        else if(i==0)
        {
            if(p-1!=i)
            {
                if(j==0)
                {
                    //k++;
                    i=1;
                    //store[0]--;
                    //continue;
                    j=-1;
                    goto inc2;
                    
                    
                }
            }
            if(j==0)
            {
                
                i=1;
                store[0]++;
                k++;
                if(k==seeds)
                {
                    end=1;
                    break;
                }
                
                k++;
                j=0;
                board[i][j]++;

            }
            else
            {
                if(k==seeds-1 && board[i][j-1]==0 && i==p-1)
                {
                    if(i==0)
                    {
                        store[i]+=board[i+1][j-1]+seeds-k;
                        board[i+1][j-1]=0;
                        //board[i+1][j-2]=0;
                    }
                    else
                    {
                        store[i]+=board[i-1][j+1]+seeds-k;
                        board[i-1][j+1]=0;
                        //board[i-1][j+2]=0;
                    }
                    //board[i][j-1]=1;
                    break;
                }
                /*if(k==seeds-1 && board[i][j-2]==0 )
                {
                    if(i==0)
                    {
                        //board[i][j-1]=1;
                        if(j-3>=0)
                        {
                            store[p-1]+=board[i][j-3]+board[i+1][j-3];
                            board[i][j-3]=board[i+1][j-3]=0;
                        }
                    }
                    if(i==1)
                    {
                        //board[i][j+1]=1;
                        if(j+3<6)
                        {
                            store[p-1]+=board[i][j+3]+board[i-1][j+3];
                            board[i][j+3]=board[i-1][j+3]=0;
                            
                        }
                        
                    }
                }*/
                
            inc:
                j--;
                
                board[i][j]++;
                k++;
            }
        }
    }
    /*if(i==p-1&&board[i][j]==0)
    {
        
    }*/
    if(end==1)
        return p;
    else
    {
        if(p==1)
            return 2;
        else
            return 1;
    }
    
    
}

int main()
{
    int i,j;
    init();
    displayboard();
    int flag;
    flag=1;
    
    
    while(flag==1)
    {
        p=play(p);
        displayboard();
        flag=0;
        i=0;
        for(j=0;j<6;j++)
        {
            if(board[i][j]!=0)
                flag=1;
        }
        flag=0;
        i=1;
        for(j=0;j<6;j++)
        {
            if(board[i][j]!=0)
                flag=1;
        }
        if(flag==0)
            break;
        
    }
    if(flag==0)
    {
        i=0;
        for(j=0;j<6;j++)
        {
            store[i]+=board[i][j];
        }
        i=1;
        for(j=0;j<6;j++)
        {
            store[i]+=board[i][j];
        }
        
    }
    if(store[0]>store[1])
    {
        cout<<"\nThe winner is player 1!!";
    }
    else
        cout<<"The winner is player 2!!";
    
}

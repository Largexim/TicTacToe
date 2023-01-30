//created by Sina hasanzadeh 4012023006
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
void write_end(std::string scoreboard[]);
int Play(std::string,std::string,double * );
void Scoreboard();
void Check(double[2][3] , int );
int nc1(std::string[],std::string,int,int,int);
int nc2(std::string[],std::string,int,int,int);
void write1(std::string,int,int,int);
void write2(std::string,int,int,int);
void file(std::string,std::string,int,int,int,int,int,int);
using namespace std;
struct Player{
    string name;
    int wins;
    int lose;
    int draw;
};
int main()
{
    const int i = 30;
    double sumone,sumtwo;
    string p1name;
    char p2name[i];
    Player one;
    Player two;
    //starting 
    string sina;
    cout<<"Press Enter to start :";
    getline(cin , sina);

    // entering names
    cout << "\nHI, WELLCOME TO THE GAME.\n";
    cout << "\nEnter the name of the first player : ";
    cin>>p1name;
    cout << "\nEnter the name of the second player : ";
    cin>>p2name;
    cout <<"\nThanks, now let's go to the game ->\n";
one.name = p1name;
two.name = p2name;
    double *pR;
    double R = 0;
    pR = &R;
    double scores[2][3]={{0,0,0},{0,0,0}};
    one.wins = scores[0][0];
    one.lose = scores[0][1];
    two.wins = scores[0][2];
    two.lose = scores[1][0];
    one.draw = scores[1][1];
    two.draw = scores[1][2];
    file(one.name,two.name,one.wins,one.lose,one.draw,two.wins,two.lose,two.draw);
    int draw=0;
    //double *pS;
    //pS = &scores[0][0];
    int Menu;

    //game menu
    while(true)
    {
        cout<<"\n1) Play.\n2) Scoreboard.\n3) Save and Exit.\n";
        cin >> Menu;
        switch (Menu)
            {
                case 1 :{
                 Play(one.name,two.name,pR);
                 Check(scores,R);
                one.wins = scores[0][0];
                one.lose = scores[0][1];
                two.wins = scores[1][0];
                two.lose = scores[1][1];
                one.draw = scores[0][2];
                two.draw = scores[1][2];
                scores[0][0]=0;
                scores[0][1]=0;
                scores[1][0]=0;
                scores[1][1]=0;
                scores[0][2]=0;
                scores[1][2]=0;
                file(one.name,two.name,one.wins,one.lose,one.draw,two.wins,two.lose,two.draw);
                 break;
                }
                case 2 : Scoreboard(); break;
                case 3 : exit(0);
                default : break;
            }
    }
    return(0);
}
//---------------------------------------------------------------------------------

//playing
int Play(string p1,string p2,double *result)
{
    //first print
    *result =-1;
    char Dooz[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    cout <<endl;
    for( int i=0 , h =0 ; i<3 ; i++ , h ++)
    {
        for( int j=0 , g=0 ; j<3 ; j++ , g++)
            {
                cout <<"  "<< Dooz[i][j]<<"  ";
                if (g==2)
                break;
                cout<<"|";
            }

        cout<<endl;

        if(h==2)
        break;

        cout<<" ---------------"<<endl;
    }

    //starting game

    for(int i=1; i<10 ; i++ )
    {
        string player;
        char x,y;
        if(i%2==0)
            {
                player=p2;
                y = 'X';
            }
        else
            {
                player=p1;
                y = 'O';
            }

                cout<<"\n"<<player<<" : "<<endl;
                cin >> x;

        switch(x)
        {
            case '1' :{if(Dooz[0][0]=='X'||Dooz[0][0]=='O'){cout<<"\nchoose another place!!\n\n";i--;} else Dooz[0][0]=y;break;}
            case '2' :{if(Dooz[0][1]=='X'||Dooz[0][1]=='O'){cout<<"\nchoose another place!!\n\n";i--;} else Dooz[0][1]=y;break;}
            case '3' :{if(Dooz[0][2]=='X'||Dooz[0][2]=='O'){cout<<"\nchoose another place!!\n\n";i--;} else Dooz[0][2]=y;break;}
            case '4' :{if(Dooz[1][0]=='X'||Dooz[1][0]=='O'){cout<<"\nchoose another place!!\n\n";i--;} else Dooz[1][0]=y;break;}
            case '5' :{if(Dooz[1][1]=='X'||Dooz[1][1]=='O'){cout<<"\nchoose another place!!\n\n";i--;} else Dooz[1][1]=y;break;}
            case '6' :{if(Dooz[1][2]=='X'||Dooz[1][2]=='O'){cout<<"\nchoose another place!!\n\n";i--;} else Dooz[1][2]=y;break;}
            case '7' :{if(Dooz[2][0]=='X'||Dooz[2][0]=='O'){cout<<"\nchoose another place!!\n\n";i--;} else Dooz[2][0]=y;break;}
            case '8' :{if(Dooz[2][1]=='X'||Dooz[2][1]=='O'){cout<<"\nchoose another place!!\n\n";i--;} else Dooz[2][1]=y;break;}
            case '9' :{if(Dooz[2][2]=='X'||Dooz[2][2]=='O'){cout<<"\nchoose another place!!\n\n";i--;} else Dooz[2][2]=y;break;}
        }
        if (i==9)
        {
        *result=0;
        }
        //cheking
        //----------------------------------------------------------'O'
        for(int i=0 ; i<3 ;i++)
            {
                int sho1=0;
                for(int j=0;j<3;j++)
                {
                    if(Dooz[i][j]=='O')
                    sho1++;
                }
                if (sho1==3)
                {
                    *result = 1;
                    break;
                }
            }
            for(int i=0 ; i<3 ;i++)
            {
                int sho1=0;
                for(int j=0;j<3;j++)
                {
                    if(Dooz[j][i]=='O')
                    sho1++;
                }
                if (sho1==3)
                {
                    *result = 1;
                    break;
                }
            }
            int sho1=0;
            for(int i=0;i<3;i++)
            {
                if(Dooz[i][i]=='O')
                sho1++;
                if(sho1==3)
                {
                    *result=1;
                }
            }
            if(Dooz[0][2]=='O'&&Dooz[1][1]=='O'&&Dooz[2][0]=='O')
            {
                *result=1;
            }
            
            //----------------------------------------------------------'O'
            //----------------------------------------------------------'#'
              for(int i=0 ; i<3 ;i++)
            {
                int sho2=0;
                for(int j=0;j<3;j++)
                {
                    if(Dooz[i][j]=='X')
                    sho2++;
                }
                if (sho2==3)
                {
                    *result = 2;
                    break;
                }
            }
            for(int i=0 ; i<3 ;i++)
            {
                int sho2=0;
                for(int j=0;j<3;j++)
                {
                    if(Dooz[j][i]=='X')
                    sho2++;
                }
                if (sho2==3)
                {
                    *result = 2;
                    break;
                }
            }
            int sho2=0;
            for(int i=0;i<3;i++)
            {
                if(Dooz[i][i]=='X')
                sho2++;
                if(sho2==3)
                {
                    *result=2;
                    break;
                }
            }
            if(Dooz[0][2]=='X'&&Dooz[1][1]=='X'&&Dooz[2][0]=='X')
            {
                *result=2;
            }
            //----------------------------------------------------------'#'

            //second print
    
    for( int i=0 , kir =0 ; i<3 ; i++ , kir ++)
        {
            for( int j=0 , cos=0 ; j<3 ; j++ , cos++)
            {
                cout <<"  "<< Dooz[i][j]<<"  ";
                if (cos==2)
                break;
                cout<<"|";
            }
            cout<<endl;
            if(kir==2)
            break;
            cout<<" ---------------"<<endl;
        }

        //who is the winer
        if(*result==1||*result==2||*result==0)
        {
            if(*result==1)
            {
            cout<<endl<<p1<<" wins!!\n";
            }
            else if (*result==2)
            {
            cout<<endl<<p2<<" wins!!\n";
            }
            else
            {
                cout<<"Tie";
            }
        break;
        }
    }
return(*result);
}
//------------------------------------------------------------------------------------

//megdardehi scoreboard
void Check(double a[2][3],int x)
{
if (x==1)
{

cout<<x;
a[0][0] =1;
a[1][1] =1;
}
else if (x==2)
{
a[0][1] =1;
a[1][0] =1;
}
else if (x==0)
{
a[0][2] =1;
a[1][2] =1;
}
else
{}
}
//-----------------------------------------------------------------------------------

//scoreboard

void Scoreboard()
{
        string score;
    string Ascore[30];
    ifstream read;
    read.open("scoreboard.txt");
    for(int i=0;(!read.eof());i++)
    {
        getline (read , score);
        Ascore[i]=score;
    }
    read.close();
    int count = 0;
    for(int k=0 ; Ascore[k][0];k++)
    {
        int count = 0;
        string temp;
        for(int j=0 ; Ascore[k][j] ; j++)
        {
        count+=1;
        }
        char a=0,b=0;
        for(int i=0 ; Ascore[i][0] && Ascore[i+1][0];i++)
    {
        a = (((Ascore[i][count-5])*3) + (Ascore[i][count-1]));
        b = (((Ascore[i+1][count-5])*3)+ (Ascore[i+1][count-1]));
            if(a<b)
            {
            temp = Ascore[i];
            Ascore[i] = Ascore[i+1];
            Ascore[i+1] = temp;
            }
    }    
    }
    cout <<".NAME |W|L|D "<<endl;
    for(int i =0 ; Ascore[i][0];i++)
    {
         cout<<(i+1)<<"."<<Ascore[i]<<endl;
    }

}

void file(string p1,string p2,int x , int y ,int z , int w ,int l , int d)
{
    string score;
    string Ascore[30];
    ifstream read;
    read.open("scoreboard.txt");
    for(int i=0;(!read.eof());i++)
    {
        getline(read , Ascore[i]);
    }
    int a1=nc1(Ascore,p1,x,y,z);
    int a2=nc2(Ascore,p2,w,l,d);
    if(a1==0)
    {
        write1(p1,x,y,z);
    }
    if(a2==0)
    {
        write2(p2,w,l,d);
    }
    if(a1==1||a2==1)
    write_end(Ascore);
}

int nc1(string a[30],string p1,int x1,int y1,int z1)
{
    int temp=0;
        for(int j=0; p1[j] ;j++ )
        {
            temp++;
        }
        cout<<temp;
    int x=0;
        for(int i=0 ; a[i][0];i++)
        {
            int temp1=0;
            for(int j=0 ; j<=temp;j++)
            {
                if(a[i][j]==p1[j])
                {
                temp1++;
                if(temp1==temp)
                {
                    a[i][temp+5]+=z1;
                    a[i][temp+3]+=y1;
                    a[i][temp+1]+=x1;
                    x=1;
                    break;
                }
                }
            }
        }
    cout<<endl;
    return(x);
}
int nc2(string a[30],string p2,int x2,int y2,int z2)
{
            int temp=0;
        for(int j=0;p2[j];j++ )
        {
            temp++;
        }
        cout<<temp;
    int x=0,j=0;
        for(int i=0 ; a[i][0];i++)
        {
            int temp2=0;
            for(int j=0 ; j<=temp ;j++)
            {
                if (a[i][j]==p2[j])
                {
                    temp2++;
                    if(temp2==temp)
                    {
                    a[i][temp+5]+=z2;
                    a[i][temp+3]+=y2;
                    a[i][temp+1]+=x2;
                    x=1;
                    break;
                    }
                }
            }   
        }
        cout<<endl;
    return(x);
}

void write1(string p1,int x , int y ,int z )
{
    ofstream write1;
        write1.open("scoreboard.txt",ios::app);
        write1 << p1 << " " << x << " " << y << " " << z << endl;
        write1.close();
}
void write2(string p2, int w ,int l , int d)
{
    ofstream write1;
        write1.open("scoreboard.txt",ios::app);
        write1 << p2 << " " << w << " " << l << " " << d << endl;
        write1.close();
}
void write_end(string scoreboard[30])
{
    ofstream write("scoreboard.txt");
     for(int i=0 ; scoreboard[i][0] ; i++)
    {
        write << scoreboard[i]<<endl;
    }
    write.close();
} 
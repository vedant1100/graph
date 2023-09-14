#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class graph_matrix{
    public:
    int dist[20][20],num,x,conn_name,weight;
    char a[7][50],ch;
    
    graph_matrix(){
        for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                a[i][j]=0;
            }
        }
    }


    void add(){
        cout<<"\n \t enter number of cities : ";
        cin>>num;

        for(int i=1;i<=num;i++){
            cout<<"\n\t enter name of city "<<i<<" : ";
            cin>>a[i];
        }
    }


    void route(){
        for(int i=0;i<=num;i++){
            for(int j=i;j<=num;j++){
                if(i==j){
                    dist[i][j]=0;
                }
                else{
                    cout<<"\n is there a flight between cities "<<i<<" and "<<j<<" ? (y/n)";
                    cin>>ch;

                    if(ch=='y' || ch=='Y'){
                        cout<<"enter the distance between the city airports(kms) : ";
                        cin>>dist[i][j];
                        dist[i][j]=dist[j][i];
                    }

                    else{
                         dist[i][j]=dist[j][i]=-1;
                    }
                }
            }
        }
    }

    void display(){
        cout<<"\n distance matrix : ";
        for(int i=0;i<=num;i++){
            cout<<"\t";
            cout<<a[i];
        }
        cout<<endl;

        for(int i=0;i<=num;i++){
            cout<<a[i];
            for(int j=1;j<=num;j++){
                cout<<"\t"<<dist[i][j];
            }
            cout<<endl;
        }
    }

}m;

int main(){

    int n;

    while(true){
        cout<<"choose option : ";
        cout<<"1. enter data \n 2. display routes \n 3. exit \n option : ";
        cin>>n;

        switch(n){
            case 1:
            m.add();
            m.route();
            break;

            case 2:
            m.display();
            break;

            case 3:
            exit(0);

            default:
            cout<<"invalid choice";
        }
    }
    return 0;
}
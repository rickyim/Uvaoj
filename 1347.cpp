#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main(){
while(1){
    int numpoints=0;
    cin>>numpoints;
    if(cin.eof())
        return 0;
    int **dataset= new int*[numpoints+1];
    for(int i = 0;i<=numpoints; i++)
        dataset[i]= new int[2];

    for(int i = 1; i<=numpoints; i++) {
        cin >>dataset[i][0];
        cin >>dataset[i][1];
    }
    float **path = new float*[numpoints+1];
    for(int i = 0;i<=numpoints; i++)
        path[i]=new float[numpoints+1];
    for(int i = 1; i<=numpoints;i++)
        for(int j=1; j<=numpoints;j++)
        path[i][j]=0;
    if (numpoints == 2)
        printf("%.2f\n",2*sqrt((dataset[1][0]-dataset[2][0])*(dataset[1][0]-dataset[2][0])+(dataset[1][1]-dataset[2][1])*(dataset[1][1]-dataset[2][1])));
    else{
        path[2][1]=sqrt((float)(dataset[1][0]-dataset[2][0])*(dataset[1][0]-dataset[2][0])+
                        (dataset[1][1]-dataset[2][1])*(dataset[1][1]-dataset[2][1]));
        for(int i = 3; i<=numpoints; i++){
            for(int j=1; j<i;j++){//update path[i][j]
                if(i==(j+1)){
                    float mini = path[i-1][1]+sqrt(pow(dataset[i][0]-dataset[1][0],2)+pow(dataset[i][1]-dataset[1][1],2));
                    float mini2 = 0;
                    //for(int k = 2;k<=j-1;k++)
                    int k=2;
                    while(k<=j-1){
                        mini2 = path[i-1][k]+sqrt(pow(dataset[i][0]-dataset[k][0],2)+pow(dataset[i][1]-dataset[k][1],2));
                        if(mini2<mini){
                            mini = mini2;
                        }
                        k++;
                    }
                    path[i][j] = mini;
                }
                else
                    path[i][j]=path[i-1][j]+sqrt(pow(dataset[i][0]-dataset[i-1][0],2)+pow(dataset[i][1]-dataset[i-1][1],2));
            }
        }
        float mini = path[numpoints][1]+sqrt(pow(dataset[numpoints][0]-dataset[1][0],2)+pow(dataset[numpoints][1]-dataset[1][1],2));
        float mini2 =0;
        for(int i=2; i<numpoints; i++){
           mini2 = path[numpoints][i]+sqrt(pow(dataset[numpoints][0]-dataset[i][0],2)+pow(dataset[numpoints][1]-dataset[i][1],2));
           if(mini2<mini)
            mini = mini2;
        }
        printf("%.2f\n",mini);
    }
    for(int i = 0;i<=numpoints;i++)
        delete(dataset[i]);
    delete dataset;
    for(int i = 0;i<=numpoints;i++)
        delete(path[i]);
    delete path;

}
return 0;
}

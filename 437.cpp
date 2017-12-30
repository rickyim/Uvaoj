#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int findLength(int **a, int i, int NumNode){
if(a[i][3]>=0)
    return a[i][3];
int maxlength = 0;
for(int j=0; j<NumNode; j++){
    if(a[i][1]>a[j][1] && a[i][2]>a[j][2]){
        if(findLength(a, j, NumNode)>maxlength)
            maxlength = a[j][3];
    }
}
    a[i][3]=maxlength+a[i][0];
return a[i][3];
}
int main(){
    int kase = 0;
    while(1)
    {
    int n=0;
    cin>>n;
    if(n==0)
        break;
    int numNode = n*3;
    int **statMat;
    statMat = new int*[numNode];
    for(int i=0;i<n;i++)//STORE THE NODE
    {
        int tmpNode[3];
        cin>>tmpNode[0]>>tmpNode[1]>>tmpNode[2];
        for(int j=0;j<3;j++)
        {

            statMat[i*3+j] = new int[4];
            statMat[i*3+j][0] = tmpNode[j];
            statMat[i*3+j][3] = -1;//initialize to zero
            int x1 = (j+1)%3;
            int x2 = (j+2)%3;
            if(tmpNode[x1]>tmpNode[x2])
            {
                statMat[i*3+j][1]=tmpNode[x2];
                statMat[i*3+j][2]=tmpNode[x1];
            }
            else{
                statMat[i*3+j][1]=tmpNode[x1];
                statMat[i*3+j][2]=tmpNode[x2];
            }
        }
    }
    int maxLength = -1;
    for(int i =0;i<numNode;i++){
        statMat[i][3]=findLength(statMat, i, numNode);
        if(statMat[i][3]>maxLength)
        {
            maxLength = statMat[i][3];
        }
    }

    cout << "Case "<< ++kase << ": maximum height = "<<maxLength<<endl;
    delete[] statMat;
    }
    return 0;
}


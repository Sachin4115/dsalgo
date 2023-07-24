#include <iostream>
#include <string>
using namespace std;
void binseq(int n,string left,string right, int diff){
    if(n>9)
        return;
    if(n && abs(diff)<=n/2){
        if(n==1){
            binseq(n-1,left,"0"+right,diff);
            binseq(n-1,left,"1"+right,diff);
            return;
        }
        if(left!=""){
            binseq(n-2,left+"0",right+"0",diff);
            binseq(n-2,left+"0",right+"1",diff-1);
        }
        binseq(n-2,left+"1",right+"0",diff+1);
        binseq(n-2,left+"1",right+"1",diff);
    }
    else if(n==0&&diff==0)
        cout<<left+right<<" ";

}
int main()
{
    int n=6;
    binseq(n,"","",0);
    return 0;
}
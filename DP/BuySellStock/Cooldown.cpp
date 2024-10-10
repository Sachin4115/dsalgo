#include <iostream>
using namespace std;

int main()
{
    int n = 12;
    int arr[n] = {10,15,17,20,16,18,22,20,22,20,23,25};
    int lastBought=arr[0]*-1,lastSold=0,coolDown=0;
    for(int i=0;i<n;i++){
        int todayBought=0,todaySold=0,todayCool=0;
        todayBought=max(lastBought,coolDown-arr[i]);
        todaySold=max(lastSold,arr[i]+lastBought);
        coolDown=max(lastSold,coolDown);
        lastSold=todaySold;
        lastBought=todayBought;
    }
    cout<<lastSold;
    return 0;
}

// Price       last Bought          last sold           cooldown
// 10                  -10                 00               0
// 15                  -10                 05               0
// 17                  -10                 07               2
// 20                  -10                 10               7
// 16                  -09                 10               10
// 18                  -08                 10               10
// 22                  -08                 14               10
// 20                  -08                 14               14
// 22                  -08                 14               14
// 20                  -06                 14               14
// 23                  -06                 17               14
// 25                  -06                 19               17
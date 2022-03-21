#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int cnt = 0;
    for(int i=0; i< flowerbed.size(); i++){
        // 如果当前位置没有花 而且符合种花条件 就种花
        if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0)){
            flowerbed[i] = 1;
            cnt++;
        }
    }
    if(n<=cnt) return true;
    return false;
}

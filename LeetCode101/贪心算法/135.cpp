#include <vector>
using namespace std;

int candy(vector<int>& ratings) {
    vector<int> candy(ratings.size(),1);
    for(int i=0; i<ratings.size()-1; i++){
        if(ratings[i+1]>ratings[i]){
            candy[i+1] = candy[i] + 1;
        }
    }
    for(int i=ratings.size()-1; i>0; i--){
        if(ratings[i-1]>ratings[i] && candy[i-1]<=candy[i]){
            candy[i-1] = candy[i] + 1;
        }
    }
    int sum=0;
    for(int i=0; i<candy.size(); i++){
        sum += candy[i];
    }
    return sum;
}
#include <iostream>
using namespace std;

int main(){
    int T;
    int N, Q;
    int *dish_score;
    int *dish_chef;
    int query, x, y;
    int chefx, chefy;
    cin >> T;
    for(int i=0; i< T; i++){
        cin >> N;
        dish_score = new int[N+1];
        dish_chef = new int[N+1];
        for(int i=1; i<N+1; i++){
            cin >> dish_score[i]; //dish i has this score
            dish_chef[i] = i; //dish i has this chef as owner
        }
        //Take input no of test cases
        cin >> Q;
        for(int i=0; i<Q ; i++){
            cin >>  query;
            if(query == 0){
                cin >> x >> y;
                chefx = dish_chef[x];
                chefy = dish_chef[y];
                if(chefx == chefy){
                    cout << "Invalid query!" << endl;
                }
                else if(dish_score[x] == dish_score[y]){
                    continue;
                }
                else if(dish_score[x] > dish_score[y]){
                    dish_chef[y] = chefx; //chefx now wins dish y
                }
                else{
                    dish_chef[x] = chefy; 
                }
            }
            else { //query is 1
                cin >> x;
                cout << dish_chef[x] <<endl;
            }
        }

        delete(dish_score);
        delete(dish_chef);
    }
}

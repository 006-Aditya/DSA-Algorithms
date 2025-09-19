// problem link --

// https://leetcode.com/problems/design-a-food-rating-system/?envType=daily-question&envId=2025-09-17

// Map and Set Use 

// code -- 


class FoodRatings {
public:
    struct CustomCompare{
        bool operator()(const pair<int,string>&a, const pair<int,string>&b )const{
            if(a.first!=b.first){
                return a.first<b.first;
            }
            return a.second>b.second;
        }
    };
    unordered_map<string,pair<string,int> >foodCuisine;
    unordered_map<string, set<pair<int,string>,CustomCompare> >cuisineFood;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        foodCuisine.clear();
        cuisineFood.clear();
        for(int i=0;i<foods.size();i++){
            foodCuisine[foods[i]]={cuisines[i],ratings[i]};
            cuisineFood[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisineOfFood=foodCuisine[food].first;
        int oldRating=foodCuisine[food].second;
        foodCuisine[food]={cuisineOfFood,newRating};
        auto& st = cuisineFood[cuisineOfFood];         
        st.erase({oldRating,food});
        st.insert({newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto& st = cuisineFood[cuisine];         
        auto it=st.rbegin();
        return it->second;
    }
};

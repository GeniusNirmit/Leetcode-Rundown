class FoodRatings
{
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, int> foodRatingMap;
    unordered_map<string, set<pair<int, string>>> cuisineRatingMap;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();

        for (int i = 0; i < n; i++)
        {
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            cuisineRatingMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        string cuisine = foodCuisineMap[food];

        auto oldRatingItr = cuisineRatingMap[cuisine].find({-foodRatingMap[food], food});

        cuisineRatingMap[cuisine].erase(oldRatingItr);
        cuisineRatingMap[cuisine].insert({-newRating, food});
        foodRatingMap[food] = newRating;
    }

    string highestRated(string cuisine)
    {
        auto highRatedFood = *cuisineRatingMap[cuisine].begin();
        return highRatedFood.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
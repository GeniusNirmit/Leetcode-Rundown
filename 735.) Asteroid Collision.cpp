class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroidStack;
        vector<int> finalAsteroids;
        int counter = 0;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]>0)
                asteroidStack.push(asteroids[i]);
            else
            {
                while(!asteroidStack.empty() && abs(asteroids[i]) > asteroidStack.top())
                    asteroidStack.pop();
                if(!asteroidStack.empty() && asteroidStack.top() == abs(asteroids[i]))
                    asteroidStack.pop();
                else if(asteroidStack.empty())
                {
                    counter++;
                    finalAsteroids.push_back(asteroids[i]);
                }
            }
        }
        while(!asteroidStack.empty())
        {
            finalAsteroids.push_back(asteroidStack.top());
            asteroidStack.pop();
        }
        reverse(finalAsteroids.begin()+counter,finalAsteroids.end());
        return finalAsteroids;
    }
};
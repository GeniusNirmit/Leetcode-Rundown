class UndergroundSystem {
public:
    unordered_map<int, pair<int, string>> checkInTime;
    unordered_map<string, vector<double>> underGroundTime;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInTime[id] = {t, stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto startStation = checkInTime[id];
        underGroundTime[startStation.second+ "-" + stationName].push_back(t - startStation.first);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avgTime;
        vector<double> timeDiff = underGroundTime[startStation + "-" + endStation];

        for(int i=0; i<timeDiff.size(); i++)
            avgTime += timeDiff[i];
        
        return avgTime / timeDiff.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
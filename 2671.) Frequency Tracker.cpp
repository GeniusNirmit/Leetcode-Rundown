class FrequencyTracker {
public:
    unordered_map<int, int> counter, frequencyCounter;

    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(frequencyCounter[counter[number]])
            frequencyCounter[counter[number]]--;
        counter[number]++;
        frequencyCounter[counter[number]]++;
    }
    
    void deleteOne(int number) {
        if(counter[number])
        {
            frequencyCounter[counter[number]]--;
            counter[number]--;
            frequencyCounter[counter[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        if(frequencyCounter[frequency])
            return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
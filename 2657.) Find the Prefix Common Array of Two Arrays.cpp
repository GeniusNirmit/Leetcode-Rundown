// Approach - 1

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mpA, mpB;
        vector<int> prefixArray;
        prefixArray.push_back(0);

        for(int i=0; i<A.size(); i++)
        {
            int counter = 0;
            mpA[A[i]]++;
            mpB[B[i]]++;

            if(mpA[A[i]] == mpB[A[i]])
                counter++;
            
            if(A[i] != B[i] && mpB[B[i]] == mpA[B[i]])
                counter++;
            
            prefixArray.push_back(prefixArray[i] + counter);
        } 

        prefixArray.erase(prefixArray.begin());
        return prefixArray;
    }
};

// Approach - 2

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> count;
        vector<int> prefixArray;
        int counter = 0;

        for(int i=0; i<A.size(); i++)
        {
            int sizeA = count.size();
            count.insert(A[i]);

            if(sizeA == count.size())
                counter++;
            
            int sizeB = count.size();
            count.insert(B[i]);

            if(sizeB == count.size())
                counter++;

            prefixArray.push_back(counter);
        } 

        return prefixArray;
    }
};
class Solution {
public:
    bool hasMatch(string s, string p) {
        int starInd = p.find('*');

        string prefix = p.substr(0, starInd);
        string suffix = p.substr(starInd + 1);

        int prefixMatchInd = s.find(prefix);

        if (prefixMatchInd == string::npos) {
            return false;
        }

        int suffixMatchInd = s.find(
            suffix,
            prefixMatchInd + prefix.length()
        );

        return suffixMatchInd != string::npos;
    }
};
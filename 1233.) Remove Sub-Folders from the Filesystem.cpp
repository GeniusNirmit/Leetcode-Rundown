class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        int n = folder.size();
        sort(folder.begin(), folder.end());

        vector<string> updatedFolders;
        updatedFolders.push_back(folder[0]);

        for (int i = 1; i < n; i++)
        {
            string prevFolder = updatedFolders.back();
            prevFolder += '/';

            if (folder[i].compare(0, prevFolder.size(), prevFolder) != 0)
                updatedFolders.push_back(folder[i]);
        }

        return updatedFolders;
    }
};
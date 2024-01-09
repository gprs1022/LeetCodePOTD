class Solution
{
    // Knuth Morrison Pratt Prefix Length Function.
    // Returns The Length Of Longest Sub-String Ending At Index Which Is Also Prefix Of String.
    
    private:
        vector <int> prefix_function (string s) {
            
            int N = s.size();
            
            vector <int> KMP (N, 0);
            
            for (int i=1; i < N; ++i) {
                
                int j = KMP[i-1];
                
                while (j > 0 && s[j] != s[i]) 
                    j = KMP[j-1];
                    
                if (s[i] == s[j])
                    j++;
                
                KMP[i] = j;
            }
            
            return KMP;
        }
        
    public:
        vector <int> search(string pattern, string text) {
            
            // Merge The 2 Strings With A Wildcard Character In Between.
            string look = pattern + '?' + text;
            
            // Obtain The Prefix Function For Combined String.
            vector <int> KMP = prefix_function(look);
            
            vector <int> ans;
            
            // Initialise Start Pointer From 2*(Size Of Pattern).
            // This Is Because Even If String Matches From Beginning; It Would End At Chosen Index.
            
            int start = 2 * (pattern.size());
            
            for (int i = start; i < look.size(); ++i) {
                
                // Sub-Text Matches Pattern.
                if (KMP[i] == pattern.size())
                    
                    // 1 Is Added For 1-Based Indexing.
                    // Index = Current Index - Start + 1.
                    
                    ans.push_back(i - start + 1); 
            }
            
            return ans;
        }
};


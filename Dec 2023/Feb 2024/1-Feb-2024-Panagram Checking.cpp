bool checkPangram (string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        vector<bool> v(26,false);

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i]>='a' and s[i]<='z')
                v[s[i]-'a'] = true;
        }
        
        for(int i = 0 ; i < 26 ; i++)
        {
            if(v[i]==false)
                return false;
        }
        
        return true;
        // your code here
    }
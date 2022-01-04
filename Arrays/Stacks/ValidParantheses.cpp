class Solution {
public:
    bool isValid(string s) {
        
        stack <char> st;
        int i;
        
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' or s[i] == '[' or s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                    return false;
                
                char t = st.top();
                st.pop();
                
                if(t == '(')
                {
                    if(s[i] != ')')
                        return false;
                }
                else
                if(t == '{')
                {
                    if(s[i] != '}')
                        return false;
                }
                else
                if(t == '[')
                {
                    if(s[i] != ']')
                        return false;
                }
            }
        }
        
        if(st.empty())
            return true;
        
        return false;
    }
};
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false

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
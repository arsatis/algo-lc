class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int evalRPN(vector<string>& tokens) {
        long a;
        long b;
        vector<long> st;
        for(string c: tokens){
            if(c=="+" || c=="-" || c=="*" || c=="/"){
                b=st.back();
                st.pop_back();
                a=st.back();
                st.pop_back();
                if(c=="+"){
                    st.push_back(a+b);
                }else if (c=="-"){
                     st.push_back(a-b);
                }else if (c=="*"){
                    st.push_back(a*b);
                }else{
                    st.push_back(a/b);
                }
            }else{
                st.push_back(stoi(c));
            }
        }
        return (int)st.front();
    }
};
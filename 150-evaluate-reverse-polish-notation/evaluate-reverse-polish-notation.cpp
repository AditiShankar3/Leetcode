class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result=0;
        stack<int> st;
        for(string c:tokens){
            if(c=="+"||c=="-"||c=="*"||c=="/"){
                if(c=="+")
                {
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int sum=a+b;
                    st.push(sum);
                }
                else if(c=="-"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int diff=b-a;
                    st.push(diff);
                }
                else if(c=="*"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int prod=a*b;
                    st.push(prod);
                }
                else if(c=="/"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int div=b/a;
                    st.push(div);
                }
            }
            else{
                int num = stoi(c);
                st.push(num);
            }
        }
        return st.top();
    }
};
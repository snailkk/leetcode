class Solution {
public:
    string decodeString(string s) {
        stack<char> sp;
        string ret;
        for(const char &ch:s){
            if(ch != ']'){
                sp.push(ch);
            }
            else{
                char top = sp.top();
                string tmp;
                while(top != '['){
                    tmp = top + tmp;
                    sp.pop();
                    top = sp.top();
                }
                sp.pop();
                string m;
                char ppp = sp.top();
                while(ppp >= '0'&&ppp <= '9'){
                    m = ppp + m;
                    sp.pop();
                    if(!sp.empty())
                    ppp = sp.top();
                    else{
                        break;
                    }
                }
                int n = 0;
                for(const char& mm:m){
                    n = n*10 + (int)(mm - '0');
                }
                for(int i = n;i > 0;i--){
                    for(const char & t:tmp){
                        sp.push(t);
                    }
                }
            }
        }
        string tmp;
        while(!sp.empty()){
            char top = sp.top();
            tmp = top + tmp;
            sp.pop();
        }
        return tmp;
    }
};

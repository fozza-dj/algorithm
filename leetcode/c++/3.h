class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        if(length <= 0){
            return 0;
        }
        int alphabet[128] = {0};
        queue<char> q;
        int len = 1;//length Of Longest Substring
        int size = 0;

        for(int i=0; i<length; i++){
            char c = s[i];

            //no repeatation
            if(alphabet[c] == 0){
                alphabet[c] = 1;
                size++;
                q.push(c);
            }
            else{
                while(true){
                    char tmp = q.front();
                    size--;
                    alphabet[tmp] = 0;
                    q.pop();
                    if(tmp == c){
                        q.push(tmp);
                        size++;
                        alphabet[tmp] = 1;
                        break;
                    }
                }
            }
            if(size > len){
                len = size;
            }
        }
        return len;
    }
};
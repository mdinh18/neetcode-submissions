class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string& s : strs){
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0; 
        while(i < s.size()){
            int j = s.find('#', i);
            
            int length = std::stoi(s.substr(i, j - i));

            std::string str = s.substr(j + 1, length);
            decoded.push_back(str);
            
            // Move pointer `i` to the start of the next length prefix
            i = j + 1 + length;
        }
        return decoded;
    }
};
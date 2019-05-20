int compress(vector<char>& chars) {
    int left = 0;
    int cursor = 0;
        
    int N = chars.size();
    for (int i = 0; i < N; ++i) {
        if (i + 1 == N || chars[i] != chars[i + 1]) {
            chars[cursor++] = chars[i];
            int cnt = i - left + 1;
            if (cnt > 1) {
                std::string s = std::to_string(cnt);
                for (auto c : s) chars[cursor++] = c;
            }
            left = i + 1;
        }
    }
        
    return cursor;
}

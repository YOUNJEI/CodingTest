string timeConversion(string s) {
    string answer = "";
    
    int hour = stoi(s.substr(0, 2));
    
    if (s[8] == 'P') {
        if (hour < 12) {
            answer += to_string(hour + 12);
        }
        else if (hour == 12) {
            answer += "12";
        }
    }
    else if (s[8] == 'A') {
        if (hour < 12) {
            if (hour < 10) {
                answer += "0";
            }
            answer += to_string(hour);
        }
        else if (hour == 12) {
            answer += "00";
        }
    }
    answer += s.substr(2, 6);
    return answer;
}

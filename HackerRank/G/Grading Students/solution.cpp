vector<int> gradingStudents(vector<int> grades) {
    vector<int> answer;
    
    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] < 38) {
            answer.push_back(grades[i]);
        }
        else {
            if (grades[i] % 5 == 0) {
                answer.push_back(grades[i]);
            }
            else {
                int nextCurve = (grades[i] / 5) + 1;
                nextCurve *= 5;
                
                if (nextCurve - grades[i] < 3) {
                    answer.push_back(nextCurve);
                }
                else {
                    answer.push_back(grades[i]);
                }
            }
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int ID;
    string IN_TIME;
    string OUT_TIME;
    Node(int id, string in_time) : ID(id), IN_TIME(in_time)
    {
        OUT_TIME = "";
    }
    void setOUT_TIME(string out_time)
    {
        OUT_TIME = out_time;
    }
};

int findIdxUsingID(vector<Node*> &lst, int id)
{
    int i;
    
    i = 0;
    while (i < lst.size())
    {
        if (lst[i]->ID == id && lst[i]->OUT_TIME == "")
            return (i);
        i++;
    }
    return (-1);
}

bool compare(const Node* n1, const Node* n2)
{
    if (n1->ID < n2->ID)
        return (true);
    else
        return (false);
}

int calTime(string in, string out)
{
    string s1, s2;
    int h, m;
    
    s1 = out.substr(0, 2);
    s2 = in.substr(0, 2);
    h = stoi(s1) - stoi(s2);
    
    s1 = out.substr(3, 2);
    s2 = in.substr(3, 2);
    m = stoi(s1) - stoi(s2);
    if (m < 0)
    {
        h--;
        m += 60;
    }
    else if (m >= 60)
    {
        h++;
        m -= 60;
    }
    return (h * 60 + m);
}

int calFee(vector<int> fees, int chargeTime)
{
    int fee = 0;
    
    if (chargeTime < fees[0])
        return (fees[1]);
    fee += fees[1];
    chargeTime -= fees[0];
    
    fee += fees[3] * (chargeTime / fees[2]);
    if (chargeTime % fees[2] > 0)
        fee += fees[3];
    return (fee);
}

vector<int> makeAnswer(vector<int> fees, vector<Node*> lst)
{
    vector<int> vi;
    vector<int> t;
    vector<int> uni;
    int i;
    
    i = 0;
    while (i < lst.size())
    {
        if (lst[i]->OUT_TIME == "")
            lst[i]->OUT_TIME = "23:59";
        //t = calTime(lst[i]->IN_TIME, lst[i]->OUT_TIME);
        //cout<<t[0]<<"h "<<t[1]<<"m"<<endl;
        if (i != 0 && lst[i]->ID == lst[i - 1]->ID)
            uni[uni.size() - 1] += calTime(lst[i]->IN_TIME, lst[i]->OUT_TIME);
        else
            uni.push_back(calTime(lst[i]->IN_TIME, lst[i]->OUT_TIME));
        i++;
    }
    i = 0;
    while (i < uni.size())
    {
        vi.push_back(calFee(fees, uni[i]));
        i++;
    }
    return (vi);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<Node*> lst;
    string cmd[3];
    int i;
    
    i = 0;
    while (i < records.size())
    {
        cmd[0] = records[i].substr(0, 5);  // 05:34
        cmd[1] = records[i].substr(6, 4);
        cmd[2] = records[i].substr(11);
        switch (cmd[2][0])
        {
            case 'I':
                lst.push_back(new Node(stoi(cmd[1]), cmd[0]));
                break;
                
            case 'O':
                lst[findIdxUsingID(lst, stoi(cmd[1]))]->OUT_TIME = cmd[0];
                break;
        }
        i++;
    }
    sort(lst.begin(), lst.end(), compare);
    answer = makeAnswer(fees, lst);
    return answer;
}

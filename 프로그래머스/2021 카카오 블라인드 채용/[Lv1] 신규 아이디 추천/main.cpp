#include <string>

using namespace std;

string step1(string new_id)
{
    int i;
    
    i = 0;
    while (i < new_id.length())
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] += 'a' - 'A';
        i++;
    }
    return (new_id);
}

string step2(string new_id)
{
    string temp = "";
    int i;
    
    i = 0;
    while (i < new_id.length())
    {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            temp += new_id[i];
        i++;
    }
    return (temp);
}

string step3(string new_id)
{
    string temp = "";
    int i, j;
    
    i = 0;
    while (i < new_id.length())
    {
        if (new_id[i] == '.')
        {
            j = i;
            while (j < new_id.length())
            {
                if (new_id[j] != '.')
                    break ;
                j++;
            }
            temp += new_id[i];
            i = j - 1;
        }
        else
            temp += new_id[i];
        i++;
    }
    return (temp);
}

string step4(string new_id)
{
    if (new_id[0] == '.')
        new_id = new_id.substr(1, new_id.length() - 1);
    if (new_id[new_id.length() - 1] == '.')
        new_id = new_id.substr(0, new_id.length() - 1);
    return (new_id);
}

string step5(string new_id)
{
    if (new_id == "")
    {
        string temp = "a";
        return (temp);
    }
    return (new_id);
}

string step6(string new_id)
{
    string temp;
    
    if (new_id.length() >= 16)
    {
        temp = new_id.substr(0, 15);
        temp = step4(temp);
        return (temp);
    }
    else
        return (new_id);
}

string step7(string new_id)
{
    if (new_id.length() > 2)
        return (new_id);
    while (new_id.length() <= 2)
    {
        new_id += new_id[new_id.length() - 1];
    }
    return (new_id);
}

string solution(string new_id) {
    string answer = "";
    answer = step1(new_id);
    answer = step2(answer);
    answer = step3(answer);
    answer = step4(answer);
    answer = step5(answer);
    answer = step6(answer);
    answer = step7(answer);
    return answer;
}

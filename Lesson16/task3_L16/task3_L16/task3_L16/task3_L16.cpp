// task3_L16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>


int real_string_hash(std::string s, int p_size)
{
    int sum = 0;
    for (int i = 0; i < p_size; i++) {
        sum += s[i];
    }
    return sum;
}


int find_substring_light_rabin_karp(std::string s, std::string p)
{
    int count = 0;
    int h;
    int hash_p = real_string_hash(p, p.size());
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0)
        {
            h = real_string_hash(s, p.size());
        }
        else 
        {
            h -= s[i - 1];
            h += s[i + p.size() - 1];
        }
        if (h != hash_p)
        {
            if (i == (s.size() - 1))
            {
                return -1;
            }
        }
        else
        {
            for (int j = 0; j < p.size(); j++)
            {
                if (s[i + j] == p[j])
                {
                    count++;
                }
               
            }
            if (count == p.size())
            {
                return i;
            }
            else {

                if (i == (s.size() - 1))
                {
                    return -1;
                }
            }
               
        }

    }
}

int main() {
    setlocale(LC_ALL, "rus");
    std::string s;
    std::string p;
    while (p != "exit" && s != "exit")
    {
        std::cout << "Введите строку, в которой будет осуществляться поиск: ";
        std::cin >> s;
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> p;
        if (p.size() > s.size())
        {
            std::cout << "Подстрока не может быть больше строки!\n ";
        }
        else
        {
            if (find_substring_light_rabin_karp(s, p) == -1)
            {
                std::cout << "Подстрока не найдена.\n";
            }
            else
            {
                std::cout << "Подстрока " << p << " найдена по индексу " << find_substring_light_rabin_karp(s, p) << "\n";
            }
        }
        
    }
   
    

    return 0;

}
/*
#include <iostream>
#define ll long long int
#define prime 119
using namespace std;


ll createhash(string str, int n) {
    ll result = 0;
    for (int i = 0; i < n; i++) {
        result += (ll)(str[i] * (ll)pow(prime, i));
    }

    return result;
}

ll recalculate_hash(string str, int oldindex, int newindex, ll oldhash, int pathlength) {
    ll newhash = oldhash - str[oldindex];
    newhash = newhash / prime;
    newhash += (ll)(str[newindex] * (ll)(pow(prime, pathlength - 1)));
    return newhash;
}

bool checkequal(string str1, string str2, int start1, int end1, int start2, int end2) {
    if (end1 - start1 != end2 - start2) return false;
    while (start1 <= end1 and start2 <= end2) {
        if (str1[start1] != str2[start2]) return false;
        start1++;
        start2++;
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "rus");
    string str;
    cout << "Введите строку, в которой будет осуществляться поиск: ";
    cin >> str;
    string pat;
    cout << "Введите подстроку, которую нужно найти: ";
    cin >> pat;
    ll pathash = createhash(pat, pat.length());
    ll strhash = createhash(str, pat.length());
    for (int i = 0; i <= str.length() - pat.length() - 1; i++) {
        if (pathash == strhash and
            checkequal(str, pat, i, i + pat.length() - 1, 0, pat.length() - 1)) {
            cout << i << endl;
        }
        if (i < str.length() - pat.length()) {
            strhash = recalculate_hash(str, i, i + pat.length(), strhash, pat.length());
        }
    }

    return 0;

}
*/
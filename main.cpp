#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
namespace fs=std::filesystem;

void displaySet(set<pair<string, string>> s)
{
    for(auto it=s.begin(); it!=s.end(); it++)
    {
        cout<<it->first<<endl;
        cout<<it->second.substr(it->second.find_last_of('\\')+1)<<endl;
    }
}

void displayVector(vector<string> vec)
{
    int n=vec.size();
    for(int i=0; i<n; i++)
    {
        cout<<vec[i]<<endl;
    }
}

class searchEff{
public:
    map<string, map<int, string>> unimap;
    set <pair<string,string>> todos;
    set <pair<string,string>> ideas;
    set <pair<string,string>> torevise;
    vector <string> allUniqueWords;

    void readFile(string filename)
    {
        ifstream file(filename);
        if(!file.is_open())
            cout<<"Error! Could not open file."<<endl;
        map<string, int> uniqWrds;
        string line="";
        while(getline(file, line))
        {
            transform(line.begin(), line.end(), line.begin(), ::tolower);
           // cout<<line<<endl;
            int l=line.size(), i=0;
            while(line[i]==' '&&i<l)
                i+=1;
            if(i==l)
                continue;
            if(line.find("@to-do")!=string::npos)
            {
                todos.insert({line.substr(i+6), filename});
                continue;
            }
            if(line.find("::idea")!=string::npos)
            {
                ideas.insert({line.substr(i+6), filename});
                continue;
            }
            if(line.find("@to-revise")!=string::npos)
            {
                torevise.insert({line.substr(i+10), filename});
                continue;
            }
            line.push_back(' ');
            int j=i,len=line.size();
            string word="";
                while(j<len)
                {
                    if(line[j]==' ')
                    {
                        if(uniqWrds.find(word)!=uniqWrds.end())
                            uniqWrds[word]+=1;
                        else
                            uniqWrds[word]=1;
                        word="";
                    }
                    else if(isalnum(line[j]))
                        word+=line[j];
                    j+=1;
                }
            }
        for(auto it=uniqWrds.begin(); it!=uniqWrds.end(); it++)
        {
            unimap[it->first].insert({it->second, filename});
        }
    }
    void readAllFiles(string foldername)
    {
        for (auto entry : fs::directory_iterator(foldername)) {
            if (fs::is_regular_file(entry) && entry.path().extension() == ".txt") {
                string str=entry.path().string();
               // cout << "Found file: " << str<< "\n";
                readFile(str);
            }
        }
    }
    void displayUniMap()
    {
        cout<<"Displaying UniMap: ";
        for(auto it=unimap.begin(); it!=unimap.end(); it++)
        {
            cout<<it->first<<endl;
            for(auto itr=it->second.begin(); itr!=it->second.end(); itr++)
            {
                cout<<itr->first<<"  ";
                cout<<itr->second.substr(itr->second.find_last_of('\\')+1)<<endl;
            }
            cout<<endl;
        }
    }
    void storeAllUniqueWords()
    {
        for(auto it=unimap.begin(); it!=unimap.end(); it++)
        {
            allUniqueWords.push_back(it->first);
        }
    }
    void displayWordPres(string wrd)
    {
        int num, i=0;
        cout<<"Enter how many files you want to see: ";
        cin>>num;
        for(auto it=unimap[wrd].rbegin(); it!=unimap[wrd].rend()&&i<num; it++)
        {
            cout<<it->second.substr(it->second.find_last_of('\\')+1);
            cout<<"\t: "<<it->first<<"  times"<<endl;
            i++;
        }
    }
    int findLevestein(string s, string t)
    {
        int n=s.size(), num=t.size();
        vector<vector<int>> dp(num+1, vector<int>(n+1, 0));
        for(int i=0; i<=num; i++)
            dp[i][0]=i;
        for(int j=0; j<=n; j++)
            dp[0][j]=j;
        for(int i=1; i<=num; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(t[i-1]==s[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
        return dp[num][n];
    }
    void searchForWord()
    {
        string wrd;
        cout<<"Enter word whose detailed frequency analysis you want to know: ";
        cin>>wrd;
        transform(wrd.begin(), wrd.end(), wrd.begin(), ::tolower);
        if(binarySearch(0, wrd, allUniqueWords.size()-1)!=-1)
        {
            displayWordPres(wrd);
        }
        else
        {
            vector<pair<int, string>> allMatching;
            cout<<"Oops! You don't have the exact word you mentioned in your notes!"<<endl;
            cout<<"But, don't you worry, we'll find just the right suggestions for you!"<<endl;
            int n=allUniqueWords.size(), j=0, f=0;
            for(int i=0; i<n; i++)
            {
                allMatching.push_back({findLevestein(wrd, allUniqueWords[i]), allUniqueWords[i]});
            }
            sort(allMatching.begin(), allMatching.end());
            cout<<"Enter y/n: ";
            char ch;
            for(int i=0; i<n&&j<5; i++, j++)
            {
                cout<<"Did you mean: "<<allMatching[i].second<<" "<<allMatching[i].first<<endl;
                cin>>ch;
                if(ch=='y')
                {
                    displayWordPres(allMatching[i].second);
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                cout<<"Looks like there are no valid options for your input :(( Try entering a different word."<<endl;
            }
        }
    }
    int binarySearch(int l, string str, int r)
    {
        if(l>r)
            return -1;
        int mid=(l+r)/2;
        if(allUniqueWords[mid]==str)
            return mid;
        else if(allUniqueWords[mid]<str)
            return binarySearch(mid+1, str, r);
        else
            return binarySearch(l, str, mid-1);
    }
    void searchPref()
    {
        string pref;
        int num_of_matches;
        cout<<"Enter a prefix as per which you want to look up words: "<<endl;
        cin>>pref;
        transform(pref.begin(), pref.end(), pref.begin(), ::tolower);
        vector<pair<int, string>> allIncPref;
        for(int i=0; i<allUniqueWords.size(); i++)
        {
            if(pref[0]==allUniqueWords[i][0])
            {
                int k=0;
                for(int j=0; j<allUniqueWords[i].size(), k<pref.size(); j++, k++)
                {
                    if(pref[k]!=allUniqueWords[i][j])
                    {
                        allIncPref.push_back({pref.size()-k, allUniqueWords[i]});
                        break;
                    }
                }
                if(k==pref.size())
                {
                    allIncPref.push_back({0, allUniqueWords[i]});
                }
            }
        }
        sort(allIncPref.begin(), allIncPref.end());
        cout<<"Enter number of matches you want to see, or -1 if you want to see all: ";
        cin>>num_of_matches;
        char ch;
        for(int i=0, j=0; i<allIncPref.size(), (num_of_matches==-1||j<num_of_matches); i++)
        {
            cout<<"Do you want to see file matches for "<<allIncPref[i].second<<" ?"<<endl;
            cout<<"Enter y/n: ";
            cin>>ch;
            if(ch=='y')
            {
                displayWordPres(allIncPref[i].second);
            }
            if(num_of_matches!=-1)
                j++;
        }
    }
   /* void previewWordInFile(string filename)
    {
        ifstream(file)
    } */
    };
int main()
{
    searchEff obj;
    obj.readAllFiles("C:/Users/Sia Srivastava/OneDrive/Desktop/Git folder/SearchEff/pqrs");
    cout<<"TO-DOS"<<endl;
    displaySet(obj.todos);
    cout<<"IDEAS"<<endl;
    displaySet(obj.ideas);
    cout<<"TO REVISE"<<endl;
    displaySet(obj.torevise);
    obj.displayUniMap();
    obj.storeAllUniqueWords();
    displayVector(obj.allUniqueWords);
    obj.searchForWord();
    obj.searchPref();
    return 0;
}





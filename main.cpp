#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
namespace fs=std::filesystem;

void displaySet(set<pair<string, string>> s)
{
    for(auto it=s.begin(); it!=s.end(); it++)
    {
        cout<<it->first<<endl;
        cout<<it->second<<endl;
    }
}
void displayVector(vector<string> vec)
{
    for(int i=0; i<vec.size(); i++)
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
                cout<<itr->first<<"  "<<itr->second<<endl;
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
    return 0;
}





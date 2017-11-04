#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;
vector<vector<string>> ret;
unordered_map<string, set<string>> oneDiffMap;

static int index = 1;


bool oneDiff(string a, string b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return false;
    }
    return diff == 1;
}
void help(string beginWord, string endWord, set<string>& wordSet, vector<string> cur) {
    if (beginWord == "bad" && endWord == "ism" && wordSet.size() == 555) {
        cout << index++ << endl;
    }
    if (ret.size() && cur.size() >= ret[0].size()) return;


    set<string> curOneDiffSet;

    if (oneDiffMap.find(beginWord) != oneDiffMap.end()) {

        for (string s : oneDiffMap[beginWord]) {
            curOneDiffSet.insert(s);
        }

    }

    if (curOneDiffSet.find(endWord) != curOneDiffSet.end() ) {
        cur.push_back(endWord);

        if (ret.size() && cur.size() < ret[0].size()) {
            ret.clear();
        }
        ret.push_back(cur);
        return;
    }


    for (string word : curOneDiffSet) wordSet.erase(word);

    for (string word : curOneDiffSet) {
        cur.push_back(word);
        help(word, endWord, wordSet, cur);
        cur.pop_back();
    }

    for (string word : curOneDiffSet) wordSet.insert(word);
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    set<string> wordSet(wordList.begin(), wordList.end());
    vector<string> cur{beginWord};

    if (wordSet.count(endWord) == 0) return ret;

    int n = wordList.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (!oneDiff(wordList[i], wordList[j])) continue;
            oneDiffMap[wordList[i]].insert(wordList[j]);
            oneDiffMap[wordList[j]].insert(wordList[i]);
        }
    }

    wordSet.erase(beginWord);
    wordSet.erase(endWord);
    help(beginWord, endWord, wordSet, cur);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return ret;
}


int main(){
    vector<string> list = {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};


    findLadders("cet", "ism", list);

    return 0;
}

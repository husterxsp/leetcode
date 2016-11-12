#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0){
        return NULL;
    }
    vector<int> tmp;
    int i;
    for(i = 0; i < lists.size(); i++){
        while (lists[i] != NULL) {
            tmp.push_back(lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }
    for(i = 0; i < tmp.size(); i++){
        for(int j = i+1; j < tmp.size();j++){
            if(tmp[j] < tmp[i]){
                int tmpVal = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = tmpVal;
            }
        }
    }
    ListNode *result, *pointer;
    result = new ListNode(tmp[0]);
    pointer = result;
    for(i = 1; i < tmp.size(); i++){
        pointer->next = new ListNode(tmp[i]);
        pointer = pointer->next;
    }
    return result;
}

int main(){
    ListNode *input;
    input = new ListNode(1);
    vector<ListNode *> lists;
    lists.push_back(input);
    input = new ListNode(2);
    lists.push_back(input);
    cout << mergeKLists(lists);
    return 0;
}
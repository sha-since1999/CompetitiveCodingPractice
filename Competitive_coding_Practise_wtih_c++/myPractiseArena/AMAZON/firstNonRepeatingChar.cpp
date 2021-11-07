#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    char ch;
    node * prev,*next;
    node(char _ch){
        ch=_ch;
        prev=next=NULL;
    }
};
class List{
    public:
    node* head = new node('#');
    node* tail = new node('#');
    List(){
        head->next = tail;
        tail->prev = head;
    }
    void addNode(node* newnode){
        node* last =tail->prev;
        last->next = newnode;
        tail->prev= newnode;
        newnode->next= tail;
        newnode->prev= last;
    }
    void removeNode( node* delnode){
        node* delprev= delnode->prev;
        node* delnext= delnode->next;
        delnext->prev= delprev;
        delprev->next= delnext;
    }
};
string solve( string A) {
    if(A[0]=='\0') return "";
    List *dll =new List;
    vector<bool>repeated(CHAR_MAX+1,false);
    unordered_map<char,node*> findnode;
    string B="";
    for( int  i=0;A[i];i++){

        if(findnode.find(A[i])!=findnode.end()){
            if(!repeated[A[i]]){
            dll->removeNode(findnode[A[i]]);
            repeated[A[i]]=true;
            }
        }
        else{
            node* newnode= new node(A[i]);
            findnode[A[i]]=newnode;
            dll->addNode(newnode);
        }
        char firstunique = dll->head->next->ch;
        B.push_back(firstunique);
    }
 return B;
}

string solution(string A){
    if(A.size()==0) return "";
    unordered_map<char,int> m;
    string ans="";
    int j=0;
    m[A[j]]++;
    ans+=A[j];
    for( int i=1;A[i];i++){
        m[A[i]]++;

        if (A[j] != A[i])
            ans += A[j];
        else
        {

            while (m[A[j]] != 1 && j < i)
                j++;

            if (j == i && m[A[j]] > 1)
            {
                ans += '#';
                j++;
            }
            else
                ans += A[j];
        }
    }
    return ans;
}
int main(){
    string s = "asdfaassdfewq";
    cout<<s<<endl;
    cout << solve(s) << endl;
    cout << solution(s) << endl;

    return 0;
}

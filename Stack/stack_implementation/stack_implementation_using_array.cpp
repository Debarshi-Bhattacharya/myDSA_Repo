#include<bits/stdc++.h>
using namespace std;
template <typename T>// stack should made of any datatype so we are using template here
class Stack
{
    private:
        vector<T>v;
    public:
        bool empty()
        {
            return v.size()==0;
        }
        void push(T data)
        {
            v.push_back(data);
        }
        void pop()
        {
            if(!empty())
            {
                v.pop_back();
            }
        }
        T top()
        {
            return v[v.size()-1];
        }
};
int main()
{
    Stack <int> s;
    s.push(4);
    s.push(7);
    s.push(2);
    s.pop();
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    Stack<char>schar;
    schar.push('a');
    schar.push('b');
    schar.push('d');
    while(!schar.empty())
    {
        cout<<schar.top()<<" ";
        schar.pop();
    }
}
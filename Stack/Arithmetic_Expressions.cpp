// application of stack to convert infix to postfix, prefix, infix to postfix, prefix to infix and vice versa 

using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()


string infix_to_postfix(string s){
    string ans; // the answer
    stack < char > st; // stack of char
    // priority function to get the priority of the operator
    auto priority = [](char c){
      if (c == '+' || c == '-') return 1;
      if (c == '*' || c == '/') return 2;
      return 0;
    };
    for (int i = 0; i < s.size(); i++){
    if (s[i] == '(') st.push(s[i]); // push the opening bracket
    else if (s[i] == ')'){ // if the current char is closing bracket
        while (st.top() != '('){ // pop all the operators until the opening bracket
        ans += st.top(); // add the operator to the answer
        st.pop(); // pop the operator from the stack
        }
        st.pop(); // pop the opening bracket
    }
    // if the current char is an operator
    else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
        // pop all the operators from the stack which has higher or equal priority
        while (!st.empty() && st.top() != '(' && priority(st.top()) >= priority(s[i])){
          ans += st.top(); // add the operator to the answer
          st.pop(); // pop the operator from the stack
        }
        st.push(s[i]); // push the current operator to the stack
    }
      else ans += s[i]; // if the current char is an operand, add it to the answer
    }
    // pop all the remaining operators from the stack
    while (!st.empty()){
      ans += st.top(); // add the operator to the answer
      st.pop(); // pop the operator from the stack
    }
    return ans; // return the answer
}  


string infix_to_prefix(string s){
    reverse(all(s)); // reverse the string
    // replace the opening bracket with closing bracket and vice versa
    for (int i = 0; i < s.size(); i++){
      if (s[i] == '(') s[i] = ')';
      else if (s[i] == ')') s[i] = '(';
    }
    string ans = infix_to_postfix(s); // get the postfix of the reversed string
    reverse(all(ans)); // reverse the postfix
    return ans; // return the answer
}


string postfix_to_infix(string s){
    stack < string > st; // stack of string
    for (int i = 0; i < s.size(); i++){
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){ // if the current char is an operator
        string op1 = st.top(); // get the first operand
        st.pop(); // pop the first operand from the stack
        string op2 = st.top(); // get the second operand
        st.pop(); // pop the second operand from the stack
        string temp = "(" + op1 + s[i] + op2 + ")"; // add the operator between the two operands
        st.push(temp); // push the temp string to the stack
    }
      else st.push(string(1, s[i])); // if the current char is an operand, push it to the stack
    }
    return st.top(); // return the answer
}

string prefix_to_infix(string s){
    reverse(all(s)); // reverse the string
    string ans = postfix_to_infix(s); // get the infix of the reversed string
    reverse(all(ans)); // reverse the infix
    return ans; // return the answer
}


int main(){

    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
   
    string s = "a+b*(c^d-e)^(f+g*h)-i"; // the expression to be converted
    cout << infix_to_postfix(s) << endl; // print the postfix of the expression
    cout << infix_to_prefix(s) << endl; // print the prefix of the expression
    cout << postfix_to_infix(infix_to_postfix(s)) << endl; // print the infix of the expression
    cout << prefix_to_infix(infix_to_prefix(s)) << endl; // print the infix of the expression


  return 0;
}

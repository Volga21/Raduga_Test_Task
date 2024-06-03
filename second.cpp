//2. Ниже представлен код рекурсивной функции, вычисляющей длину наиболее длинной (наиболее вложенной) ветви некоторой древовидной структуры.
//	a) устраните ошибки в данном коде;
//	б) перепишите функцию без использования рекурсии.

#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>

struct TreeNode
{
	std::vector<TreeNode*> childNodes;
    int value;
};

int longestBrunch(TreeNode* node)
{
    size_t max_elemnt=0;
    if(node->childNodes.size()==0){
        return 1;
    }
    size_t temp;
	for(size_t i=0;i<node->childNodes.size();i++){
        temp=longestBrunch(node->childNodes[i])+1;
        if(temp>max_elemnt){
            max_elemnt=temp;
        }
    }   
    return max_elemnt;
}

//без рекурсии обходим все дерево, используя стек
int longestBrunchNoRecursion(TreeNode* node){
    int max_count=0;
    std::queue<TreeNode*> st;
    TreeNode * temp_node;
    st.push(node);
    while(!st.empty()){
        int len=st.size();
        for(size_t i=0;i<len;i++){
            temp_node=st.front();
            st.pop();
            for(int j=0;j<temp_node->childNodes.size();j++){
                st.push(temp_node->childNodes[j]);
            }
        }
        max_count++;
    }
    return max_count;
}
int main(){
    TreeNode n2;
    n2.value=2;
    TreeNode n3;
    n3.value=3;
    TreeNode n4;
    n4.value=4;
    TreeNode n5;
    n5.value=5;
    TreeNode n6;
    n6.value=6;
    TreeNode n7;
    n7.value=7;
    TreeNode n10;
    n10.value=10;
    TreeNode n9;
    n9.value=9;
    TreeNode n8;
    n8.value=8;
    TreeNode n11;
    n11.value=11;
    std::vector<TreeNode*> v1{&n2,&n3};
    std::vector<TreeNode*> v2{&n4,&n5,&n6};
    std::vector<TreeNode*> v3{&n7};
    std::vector<TreeNode*> v4{&n8,&n9};
    std::vector<TreeNode*> v5{&n10};
    std::vector<TreeNode*> v6{&n11};
    TreeNode n1;
    n1.value=1;
    n1.childNodes=v1;
    n2.childNodes=v2;
    n4.childNodes=v3;
    n3.childNodes=v4;
    n8.childNodes=v5;
    n10.childNodes=v6;
    std::cout<<longestBrunchNoRecursion(&n1)<<std::endl;
    std::cout<<longestBrunch(&n1);
}

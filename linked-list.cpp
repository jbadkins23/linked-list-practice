#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode (int x): val(x) {}
};

/*  Finds the middle of the linked list with brute force
*   Counts the number of links then loops over it again
*   to return the link
*/

ListNode *middle_of_list (ListNode* s1){
    int count = 1;
    ListNode *save_start;
    save_start = s1;

    while (s1->next != NULL) {
        cout << "At #" << count << " in linked list with val " << s1->val << "\n";
        s1 = s1->next;
        count++;
    }
    cout << "At #" << count << ", the end of linked list with val " << s1->val << "\n";

    count = count/2 + 1;
    cout << "The middle is " << count << "\n";
    s1 = save_start;
    for (int i=1; i<count; i++) {
        s1 = s1->next;
    }

    return s1;
}

/*  Generates a linked list with values representing their count in the list
*   the index is the starting size, i.e. if the first node index = 1
*   TODO: Convert into a class instead(?)
*/
void create_linked_list (int index, int end_num, ListNode* prev_node) {
    index++;
    if(index == end_num) {
        ListNode* newNode = new ListNode(index);
        prev_node->next = newNode;
        newNode->next = NULL;
        cout << "Created last link #" << index << " out of " << end_num << "\n";
        return;
    }
    else {
        ListNode* newNode = new ListNode(index);
        prev_node->next = newNode;
        cout << "Created link #" << index << " out of " << end_num << "\n";
        create_linked_list(index, end_num, newNode);
    }
}

int main () {
    int link_size;
    cout << "Enter number of links for the list\n";
    cin >> link_size;
    if(link_size <= 1) {
        cerr << "Error: the requested links must be greater than 1\n";
        return -1;
    }
    ListNode *head, *middle;
    head = new ListNode(1);
    cout << "Created default link #1\n";
    
    create_linked_list(1, link_size, head);
    middle = middle_of_list(head);

    cout << "Middle val is " << middle->val << "\n";
    
    return 0;
}
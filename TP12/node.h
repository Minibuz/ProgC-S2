typedef struct node{
    char* word;
    struct node* node;
}Node, *List;

Node *create_node(char* word);
void free_node(Node *n);
void free_nodes(Node *n);

Node* insert_front(Node *n, char* word);
int find_word(Node *n,char* word);
int equal(char* word1, char* word2);

int size_node(Node *n);
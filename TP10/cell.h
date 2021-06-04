typedef struct cell
{
    char* first_name;
    char* last_name;
    int age;
    struct cell* next;
}Cell, *List;

Cell* allocate_cell(char* first, char* last, int age);
void free_list(List l);

void print_list(List l);

int age_order(Cell* p1, Cell* p2);
int name_order(Cell* p1, Cell* p2);
List ordered_insertion(List l, Cell* newCell, int order_func(Cell*, Cell*));
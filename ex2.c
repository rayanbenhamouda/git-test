int main(void) {
  struct list *l = NULL;
  // struct list *l = list_init(1);
  // list_print(l);
  list_append(l, 2);
  list_print(l);
  // l = list_prepend(l,42);
  // list_print(l);
  // printf("list length is %zu\n", list_length(l));

  // struct list *l2 = list_init(32);
  // list_append(l2, 22);
  // list_append(l2, 53);
  // list_append(l2, 0);
  // list_print(l2);
  // l = list_concat(l, l2);
  // list_print(l);
  // printf("concatened list length is %zu\n", list_length(l));
  list_destroy(l);
  return 0;
}
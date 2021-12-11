#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct list
{
  int value;
  struct list *next;
};

//----------init
struct list *list_init(int value){
  struct list *Liste = (struct list *)malloc(sizeof(struct list));
  Liste->value = value;
  Liste->next = NULL ; 
  return Liste;
}
//----------print
void list_print(struct list *list){
  while(list != NULL){
    printf("%d", list->value);
    list = list->next;
    if(list==NULL){
      printf("\n");
    }
    else{
      printf(" ");
    }
  }
}

//----------append
struct list *list_append(struct list *list, int value){
  if(list==NULL){
    list = list_init(value);
    list_print(list);
    return list ;
  }
  //---------------------------
  else{
    struct list *new_list=(struct list *)malloc(sizeof(list));
    new_list->value= value;
    new_list->next=NULL ;
    struct list *skip = list ;
    while(skip->next != NULL){
      skip = skip->next;
    }
    skip->next=new_list;
    return list ;
  }
}

//----------prepend
struct list *list_prepend(struct list *list, int value){
  if(list==NULL){
    struct list *l = list_init(value);
    return l;
  }
  struct list *test = (struct list *)malloc(sizeof(list));
  test->value = value ;
  test->next = list ;
  return test;
}

//----------length
size_t list_length(struct list *list){
  size_t taille=0;
  while(list != NULL){
    taille+=1;
    list = list->next;
  }
  return taille ; 
}

// struct list *list_concat(struct list *list1, struct list *list2){
//   if(list1==NULL || list2==NULL){
//     return NULL ;
//   }
//   // struct list *new_list=(struct list *)malloc(sizeof(list1)); //+sizeof(list2)
//   // new_list=list1;
//   // new_list->next= list2 ;
//   struct list *skip = list1 ;
//   while(skip->next != NULL){
//     skip = skip->next;
//   }
//   skip->next=list2;
//   return list1 ;
// }
//----------concat
struct list *list_concat(struct list *list1, struct list *list2){
  if(list1==NULL || list2==NULL){
    return NULL ;
  }
  struct list *new_list = list_init(list1->value);
  struct list *skip = list1 ;
  while(skip->next != NULL){
    skip = skip->next;
    list_append(new_list, skip->value);
  }
  struct list *skip2 = list2 ;
  list_append(new_list, skip2->value);
  while(skip2->next != NULL){
    skip2 = skip2->next;
    list_append(new_list, skip2->value);
  }
  return new_list ;
}
//-----------destroy
void list_destroy(struct list *list){
  struct list *current = list ;
  struct list *next = list ;
  while(current!=NULL)
  {
    next = current->next;
    free(current);
    current=next;
  }
  list = NULL ;
}


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
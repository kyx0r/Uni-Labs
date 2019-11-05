// Example program
#include "header.h"

size_t fstrlen (const char* s) 
{
	register const char* i;
	for(i=s; *i; ++i);
	return (i-s);
}

size_t sstrlen (const char* s) 
{
	register const char* i;
	for(i=s; *i != ' '; ++i);
	return (i-s);
}

#define DEBUG
#ifdef DEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) \
		{ \
			printf("%s \n", message);\
			printf("Assertion %s failed in, %s line: %d \n", #condition, __FILE__, __LINE__);\
			char buf[10];					\
			fgets(buf, 10, stdin); \
			exit(1); \
        } \
    } while (0)
#else
#   define ASSERT(condition, message) do { } while (0)
#endif

#define LEN 10

typedef struct node_t
{
  char c;
  struct node_t* next;
}node_t;

void search_node(node_t* head, char c)
{
  //        printf("%p\n", head->next);
  for(; head->next != NULL; head++)
    {
      //      printf("%c\n", head->c);
      if(head->c == c)
	{
	  printf("found %c AT %p\n", head->c, head);
	  break;
	}
    }
  if(head->next == NULL)
    {
      printf("Err, not found.\n");
    }
}

void p_range(node_t* head, int start, int end)
{
  ASSERT(start < LEN, "start bigger than len");
  ASSERT(end < LEN, "end bigger than len");
  ASSERT(start < end, "start > end");

  start--;
  head = (head + start);
  node_t* end_ = (head + end);
 for(; head->next != NULL && head != end_; head++)
    {
      printf("range :%c\n", head->c);      
    }
}

void free_l(node_t** p)
{
  /* node_t* head = *p; */
  /* for(; head->next != NULL; head++) */
  /*   { */
  /*     head->c = 0; */
      
  /*   } */
  memset(*p, 0, LEN*sizeof(node_t));
  *p = NULL;
}

int main() 
{
  node_t* head = (node_t*) calloc(LEN, sizeof(node_t));

  node_t* org = head;
  head->c = 'A';
  head->next = (org+1);
  head->c = 'B';
  head->next = ++head;
  head->c = 'C';
  head->next = ++head;
  head->c = 'D';
  head->next = ++head;
  head->c = 'E';
  head->next = ++head;

  search_node(org, 'B');

  p_range(org, 2, 4);

  free_l(&org);
  
  /* char s[100]; */
  /* while (!feof(stdin)) */
  /*   { */
  /*     scanf("%s", s); */
  /*     printf("->%s\n", s); */
  /*   } */

return 0; 
} 

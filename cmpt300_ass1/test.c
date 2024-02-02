#include "list.h"

#include <stdio.h>


void print(List* Plist)
{
	Node*temp = Plist->head;
	while(temp!= NULL)
		{
			printf("%d ", *((int*)temp->value));
			temp = temp->next;
		}
		printf(" backwards: ");
	temp = Plist->tail;
	while (temp != NULL)
	{
			printf("%d ", *((int*)temp->value));
			temp = temp->prev;
	}



	printf("\n");
}




void red()
{

	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=7;
	 List* l1 = List_create();
	 List_insert_before(l1, &a);
	  List_insert_before(l1, &b);
	   List_insert_before(l1, &c);
	   List* l2 = List_create();
	   List_insert_before(l2, &d);
		 List_insert_before(l2, &e);
		  List_insert_before(l2, &f);
		  List_insert_after(l2,&g);
	print(l1);
	print(l2);
	List_concat(l2,l1);
	print(l2);
	//List_free(l2,frees());

	print(l2);
	//return 0;
}
void test()
{
	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=7;
	 List* l1 = List_create();
	 List_insert_before(l1, &a); // 1
	  List_insert_before(l1, &b); // 2 1
	   List_insert_before(l1, &c); // 3 2 1

	   List_next(l1);
	    List_insert_before(l1, &d); // 4
		 List_insert_before(l1, &e); // 5 4
		  List_insert_before(l1, &f); // 6 5 4
		  List_insert_after(l1,&g); // 6 7 5 4

	print(l1);
	printf("current item is: %d\n",*((int*)List_curr(l1)));
	printf("L1 number of elements: %d\n", List_count(l1));
	printf("item removed: %d\n",*( (int*)List_trim(l1)) );
	printf("item removed: %d\n",*( (int*)List_trim(l1)) );
	printf("item removed: %d\n",*( (int*)List_trim(l1)) );
	printf("item removed: %d\n",*( (int*)List_trim(l1)) );
	printf("item removed: %d\n",*( (int*)List_trim(l1)) );
	printf("item removed: %d\n",*( (int*)List_trim(l1)) );
	printf("item removed: %d\n",*( (int*)List_trim(l1)) );
	printf("item removed: %p\n",List_trim(l1));
	 List_insert_before(l1, &a);
	  List_insert_before(l1, &b);
	   List_insert_before(l1, &c);

	   List_next(l1);
	    List_insert_before(l1, &d);
		 List_insert_before(l1, &e);
		  List_insert_before(l1, &f);
		  List_insert_after(l1,&g);

	print(l1);
	//printf("current item is: %d\n",*((int*)List_curr(l1)));
	printf("L1 number of elements: %d\n", List_count(l1));
}

void remove_test()
{
	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=7;
	 List* l1 = List_create();
	 List_insert_before(l1, &a);
	  List_insert_before(l1, &b);
	   List_insert_before(l1, &c);

	   List_next(l1);
	    List_insert_before(l1, &d);
		 List_insert_before(l1, &e);
		  List_insert_before(l1, &f);
		  List_insert_after(l1,&g);

	print(l1);
	printf("current item is: %d\n",*((int*)List_curr(l1)));
	printf("L1 number of elements: %d\n", List_count(l1));
	printf("item removed: %d\n",*( (int*)List_remove(l1)) );
	printf("item removed: %d\n",*( (int*)List_remove(l1)) );
	print(l1);
	printf("current item is: %d\n",*((int*)List_curr(l1)));
	printf("L1 number of elements: %d\n", List_count(l1));
	// expect 7 to be removed and 5 to be the current node
	printf("------------------------------------------\n\n");
	List_first(l1);
	print(l1);
	printf("current item is: %d\n",*((int*)List_curr(l1)));
	printf("L1 number of elements: %d\n", List_count(l1));
	printf("item removed: %d\n",*( (int*)List_remove(l1)) );
	printf("item removed: %d\n",*( (int*)List_remove(l1)) );
	printf("current item is: %d\n",*((int*)List_curr(l1)));
	printf("L1 number of elements: %d\n", List_count(l1));
	print(l1);
	printf("------------------------------------------\n\n");
	List_last(l1);

	print(l1);
	printf("current item is: %d\n",*((int*)List_curr(l1)));
	printf("L1 number of elements: %d\n", List_count(l1));
	printf("item removed: %d\n",*( (int*)List_remove(l1)) );
	List_prev(l1);
	printf("item removed: %d\n",*( (int*)List_remove(l1)) );
	//printf("current item is: %d\n",*((int*)List_curr(l1))); will cause a segfault cuz node is at null
	printf("L1 number of elements: %d\n", List_count(l1));
	print(l1);
}

void test2_list_insert_before()
{
	   List* l1 = List_create();

    // Print the initial count and list
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);


    // Insert number of elements into the list
    int f = 4;
    void* m = &f;
    int p = 5;
    void* z = &p;

    List_insert_before(l1, m);
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);

    List_insert_before(l1, z);
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);

    // Insert more number of elements
    int x = 8;


    List_insert_before(l1, &x);
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);

    // Insert another element after the first one
    int a = 1;
    void* b = &a;

    List_insert_before(l1, b);
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);

    // Insert an element after the last one
    int c = 10;
    void* d = &c;



	List_next(l1);
	printf("current item is: %d\n",*((int*)List_curr(l1)));
    List_insert_before(l1, d);
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);



}

void test1_list_insert_after()
{
	  List* l1 = List_create();

    // Print the initial count and list
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);
	List_next(l1);
	printf("%d\n",l1->bounds);

    // Insert number of elements into the list
    int f = 4;
    void* m = &f;
    int p = 5;
    void* z = &p;

    List_insert_after(l1, m);
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);

    List_insert_after(l1, z);
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);

    // Insert more number of elements
    int x = 8;
    void* y = &x;

    List_insert_after(l1, y);
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);

    // Insert another element after the first one
    int a = 1;
    void* b = &a;

    List_insert_after(l1, b);
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);

    // Insert an element after the last one



	List_first(l1);
	printf("%d\n",l1->bounds);
	List_prev(l1);
	//printf("the value of current: %d\n",*((int*)List_curr(l1)));
	printf("%d\n",l1->bounds);


    //List_insert_after(l1, d);
    printf("L1 number of elements: %d\n", List_count(l1));
    print(l1);

}


void free2(void* pItem) {
    // Cast pItem to int* and free the memory
	 printf("%d ", *((int*)pItem));
    pItem = 0;
}


bool search(void* pItem, void* pComparisonArg){
    if((void*)pItem == pComparisonArg){
        return 1;
    }
    return 0;
}

void create()
{
	List* l1;
	List* l2 = List_create();
	for (int i = 0; i<11; i++ )
	{
		l1 = List_create();
	}
	if (l1 == NULL)
	{
		printf("success\n");
	}
	if (l2 != NULL)
	{
		printf("success\n");
	}
	List_free(l2,free2);
	l1 = List_create();
	if (l1 != NULL)
	{
		printf("success\n");
	}

}

void append()
{
	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=7;
	List* l1 = List_create();
	List_append(l1,&a);
	List_append(l1,&b);
	List_append(l1,&c);
	List_append(l1,&d);
	List_append(l1,&e);
	print(l1);
	// should print in that order
	for (int i = 0; i < 100; i++)
	{
	List_append(l1,&f);
	print(l1);
	printf("current item is: %d\n",*((int*)List_curr(l1)));
	printf("L1 number of elements: %d\n", List_count(l1));

	} // should have 6 total duplicates at the end
	List_free(l1,free2);
	printf("L1 number of elements: %d\n", List_count(l1));
	List* l2 = List_create();
	for (int i = 0; i < 100; i++)
	{
	List_append(l2,&f);
	print(l2);
	printf("current item is: %d\n",*((int*)List_curr(l1)));
	printf("L1 number of elements: %d\n", List_count(l1));

	}

}

void prepend()
{
	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=7;
	List* l1 = List_create();
	List_prepend(l1,&a);
	List_prepend(l1,&b);
	List_prepend(l1,&c);
	List_prepend(l1,&d);
	List_prepend(l1,&e);
	print(l1);
	// should print in that order
	for (int i = 0; i < 100; i++)
	{
	List_prepend(l1,&f);
	print(l1);
	printf("current item is: %d\n",*((int*)List_curr(l1)));
	printf("L1 number of elements: %d\n", List_count(l1));

	} // should have 6 total duplicates at the end
	List_free(l1,free2);
	printf("L1 number of elements: %d\n", List_count(l1));
	List* l2 = List_create();

	for (int i = 0; i < 100; i++)
	{
	List_prepend(l2,&f);
	print(l2);
	printf("current item is: %d\n",*((int*)List_curr(l2)));
	printf("L1 number of elements: %d\n", List_count(l2));

	}
}

void List_insert_aft_before()
{
	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=0;
	List* l1 = List_create();
	for (int i = 0; i<6; i++)
	{
		List_append(l1,&g);
		List_prepend(l1,&g);
	}
	print(l1);
	List_last(l1);
	printf("current item is: %d\n",*((int*)List_curr(l1)));
		for (int i = 0; i<6; i++)
		{
			List_insert_before(l1,&a);
			List_prev(l1);
		}
		List_next(l1);
	print(l1);

	for (int i = 0; i<6; i++)
		{
			List_insert_after(l1,&b);
			List_next(l1);
		}
		print(l1);
	List_free(l1,free2);
	print(l1);
	// testing out of bound inserts
	l1 = List_create();
	for (int i = 0; i<6; i++)
	{
		List_append(l1,&g);
		List_prepend(l1,&g);
	}
	List_first(l1);
	List_prev(l1);
	List_insert_after(l1,&b); // 2 should be at front
	List_last(l1);
	List_next(l1);
	List_insert_after(l1,&b); // 2 should be at back
	List_first(l1);
	List_prev(l1);
	List_insert_before(l1,&c); // 3 should be at front
	List_last(l1);
	List_next(l1);
	List_insert_before(l1,&c); // 3 should be at back
	print(l1);



}

void move_current()
{
	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=0;
	List* l1 = List_create();
	List_insert_before(l1, &a); // 1
	  List_insert_before(l1, &b); // 2 1
	   List_insert_before(l1, &c); // 3 2 1

	   List_next(l1);
	    List_insert_before(l1, &d); // 3 4 2 1
		 List_insert_before(l1, &e); // 3 5 4 2 1
		  List_insert_before(l1, &f); // 3 6 5 4 2 1
		  List_insert_after(l1,&g); // 3 6 0 5 4 2 1
		  print(l1);
		  List_first(l1);
		  List_prev(l1);
		  for (int i = 0; i < 10; i++)
		  {
			if (List_curr(l1) == NULL)
			{
				printf("...\n");

			}
			else
				printf("current item is: %d\n",*((int*)List_curr(l1)));
			List_next(l1);
		  }
	printf("-----------------------------------------------\n");
			List_last(l1);
		  List_next(l1);
		  for (int i = 0; i < 10; i++)
		  {
			if (List_curr(l1) == NULL)
			{
				printf("...\n");

			}
			else
				printf("current item is: %d\n",*((int*)List_curr(l1)));

			List_prev(l1);
		  }

}

void removes()
{
	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=0;
	List* l1 = List_create();
	List_remove(l1);
		List_insert_before(l1, &a); // 1
	  List_insert_before(l1, &b); // 2 1
	   List_insert_before(l1, &c); // 3 2 1

	   List_next(l1);
	    List_insert_before(l1, &d); // 3 4 2 1
		 List_insert_before(l1, &e); // 3 5 4 2 1
		  List_insert_before(l1, &f); // 3 6 5 4 2 1
		  List_insert_after(l1,&g); // 3 6 0 5 4 2 1
		  print(l1);
		  List_first(l1);
		  List_prev(l1);
		  List_remove(l1);
		  print(l1);
		  List_last(l1);
		  List_next(l1);
		 List_remove(l1);
		  print(l1);


}

void trim()
{
	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=0;
	List* l1 = List_create();
	List_trim(l1);
	List_insert_before(l1, &a); // 1
	List_insert_before(l1, &b); // 2 1
	List_append(l1,&c); // 2 1 3
	List_prepend(l1,&e); // 5 2 1 3
	List_next(l1);
	List_insert_after(l1,&e); // 5 2 5 1 3
	List_prepend(l1,&e);
	List_prev(l1);
	print(l1);
	printf("%d\n",List_curr(l1) == NULL);
	List_trim(l1);
	print(l1);
	printf("%d\n",List_curr(l1) == NULL);
	List_next(l1);
	printf("%d\n",List_curr(l1) == NULL);
	List_trim(l1);
	print(l1);
	List_insert_before(l1, &a); // 1
	List_insert_before(l1, &b); // 2 1
	List_append(l1,&c); // 2 1 3
	List_prepend(l1,&e); // 5 2 1 3
	List_next(l1);
	List_insert_after(l1,&e); // 5 2 5 1 3
	List_prepend(l1,&e);
	print(l1);
	List_next(l1);
	List_next(l1);
	List_next(l1);
	List_trim(l1);
	print(l1);
	printf("__________________\n");
	List_free(l1,free2);

}

void compare()
{
	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=0;
	List* l1 = List_create();
	List_trim(l1);
	List_insert_before(l1, &a); // 1
	List_insert_before(l1, &b); // 2 1
	List_append(l1,&c); // 2 1 3
	List_prepend(l1,&e); // 5 2 1 3
	List_next(l1);
	List_insert_after(l1,&e); // 5 2 5 1 3
	printf("was it found: %p\n",List_search(l1,search,&c));
	printf("was it found: %d\n",List_search(l1,search,&g));
	List_free(l1,free2);
	l1 = List_create();
	printf("was it found: %p\n",List_search(l1,search,&c));

	List_trim(l1);
	List_insert_before(l1, &a); // 1
	List_insert_before(l1, &b); // 2 1
	List_append(l1,&c); // 2 1 3
	List_prepend(l1,&e); // 5 2 1 3
	List_next(l1);
	List_insert_after(l1,&e); // 5 2 5 1 3
	print(l1);
	printf("L1 number of elements: %d\n", List_count(l1));
	printf("current item is: %d\n",*((int*)List_curr(l1)));
	printf("was it found: %p\n",List_search(l1,search,&b)); // should not be found
	List_first(l1);
	List_prev(l1);
	printf("was it found: %p\n",List_search(l1,search,&b)); // should not be found
}

void concat()
{
	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=0;
	List* l1 = List_create();
	List_trim(l1);
	List_insert_before(l1, &a); // 1
	List_insert_before(l1, &b); // 2 1
	List_append(l1,&c); // 2 1 3
	List_prepend(l1,&e); // 5 2 1 3
	List_next(l1);
	List* l2 = List_create();
	List_concat(l1,l2);

	print(l2);
	print(l1);
	for (int i = 0; i<9; i++)
	{
		l2 = List_create();
	}
	List_insert_before(l2, &a); // 1
	print(l2);
	List_concat(l2,l1);

	print(l2);
	print(l1);
	List_free(l1,free2);
	List_free(l2,free2);
	l2 = List_create();
	l1 = List_create();
	List_concat(l1,l2);

	print(l2);
	print(l1);

	l2 = List_create();
}

void cat()
{
	int a = 1, b=2,c=3, d=4, e=5, f=6 , g=0;
	List* l1 = List_create();
	List_trim(l1);
	List_insert_before(l1, &a); // 1
	List_insert_before(l1, &b); // 2 1
	List_append(l1,&c); // 2 1 3
	List_prepend(l1,&e); // 5 2 1 3
	List_next(l1);
	print(l1);
	List* l2 = List_create();
	List_concat(l2,l1);
	
	print(l2);
	print(l1);
	List* l3 = List_create();
	List_append(l3,&g);

	List_concat(l2,l3);
	print(l2);


}

int main(){
	//create();
	//append();
	//prepend();
	//List_insert_aft_before();
	//move_current();
	//test();
	//red();
	//remove_test();
	//removes();
	//test2_list_insert_before();
	//test1_list_insert_after();
	//compare();
	cat();
	//trim();
    return 0;
}

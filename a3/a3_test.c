#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "a3.h"

Name name1;
Name name2;
Name name3;
Name name4;

void init()
{
  srand(time(NULL));

  name1.first = "Alyssa";
  name1.middle = "Mary";
  name1.last = "Antle";

  name2.first = "Ben";
  name2.middle = "Ivan";
  name2.last = "Bitdiddle";

  name3.first = "Cassie";
  name3.middle = "Maria";
  name3.last = "Charstrup";

  name4.first = "Daniel";
  name4.last = "Diamond";
}


void start_test(const char *test)
{
  static int count = 1;
  printf("Test #%d: %s\n\n", count++, test);
}

void end_test()
{
  printf("\n--------------------------------\n\n");
}


void test_big()
{
  start_test("Print Big");

  big(&name1);
  big(&name2);
  big(&name4);

  end_test();
}

void test_last()
{
  start_test("Print Last");

  last(&name2);
  last(&name4);

  end_test();
}

void test_reg()
{
  start_test("Print Reg");

  reg(&name3);
  reg(&name4);

  end_test();
}

void test_mid()
{
  start_test("Print Mid");

  mid(&name4);
  mid(&name1);

  end_test();
}

void test_small()
{
  start_test("Print Small");

  small(&name4);
  small(&name2);

  end_test();
}

void test_fmt()
{
  start_test("Print Fmt");

  formatName(&name1, 'B');
  formatName(&name1, 'L');
  formatName(&name1, 'R');
  formatName(&name1, 'M');
  formatName(&name1, 'S');

  formatName(&name4, 'B');
  formatName(&name4, 'L');
  formatName(&name4, 'R');
  formatName(&name4, 'M');
  formatName(&name4, 'S');

  end_test();
}


void test_fmt_array(){
  start_test("Format Array");
  
  printf("This test will be added\n");

  end_test(); 
}


int main(void)
{
  init();
  
  test_big();
  test_last();
  test_reg();
  test_mid();
  test_small();
  test_fmt();
  
  test_fmt_array(); 

  printf("More tests will be added; feel free to add your own!\n"); 
  
  return EXIT_SUCCESS;
}


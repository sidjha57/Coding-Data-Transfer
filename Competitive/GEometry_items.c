#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Geometry;

void initRectangle(struct Geometry **object);
void initSquare(struct Geometry **object);
void initCircle(struct Geometry **object);
void initLine(struct Geometry **object);

void printGeometry(struct Geometry* object);

void freeGeometry(struct Geometry* object);

#define SCANF_FMT_CIRCLE    "%f %f %f"
#define SCANF_FMT_RECTANGLE "%f %f %f %f"
#define SCANF_FMT_SQUARE    "%f %f %f"
#define SCANF_FMT_LINE      "%f %f %f %f"


#define PRINTF_FMT_CIRCLE    "Circle with center at %f, %f and radius %f\n"
#define PRINTF_FMT_RECTANGLE "Rectangle with corner at (%f, %f) with width %f and height %f\n"
#define PRINTF_FMT_SQUARE    "Square with corner at (%f, %f) and side %f\n"
#define PRINTF_FMT_LINE      "Line from (%f, %f) to (%f, %f)\n"

struct Geometry {
  float x1,x2,x3,x4;
  int type;
};

void initRectangle(struct Geometry **object) {
    (*object)->type = 0;
    scanf(SCANF_FMT_RECTANGLE,&(*object)->x1,&(*object)->x2,&(*object)->x3,&(*object)->x4);

  }
  void initSquare(struct Geometry **object){
    (*object)->type = 1;
    scanf(SCANF_FMT_SQUARE,&(*object)->x1,&(*object)->x2,&(*object)->x3);
  }
  void initCircle(struct Geometry **object){
    (*object)->type = 2;
    scanf(SCANF_FMT_CIRCLE,&(*object)->x1,&(*object)->x2,&(*object)->x3);
  }
  void initLine(struct Geometry **object){
    (*object)->type = 3;
    scanf(SCANF_FMT_LINE,&(*object)->x1,&(*object)->x2,&(*object)->x3,&(*object)->x4);
  }
  
  void printGeometry(struct Geometry* object) {
    if(object->type == 0)
    {
      printf(PRINTF_FMT_RECTANGLE,object->x1,object->x2,object->x3,object->x4);
    }
    else if(object->type == 1)

    {
      printf(PRINTF_FMT_SQUARE,object->x1,object->x2,object->x3);
    }
    else if(object->type == 2)
    {
      printf(PRINTF_FMT_CIRCLE,object->x1,object->x2,object->x3);
    }
    else if(object->type == 3)
    {
      printf(PRINTF_FMT_LINE,object->x1,object->x2,object->x3,object->x4);
    }
  }
  
  void freeGeometry(struct Geometry* object){
    free(object);
  }


int main()
{
  int n;
  struct Geometry **object;
  scanf("%d", &n);
  printf("%d geometric items\n", n);

  object = (struct Geometry **)(malloc(n*sizeof(struct Geometry*)));

  for(int i = 0; i < n; i++)
  {
    char objectType[40];
    scanf("%s", objectType);
    object[i] = (struct Geometry *) malloc(sizeof(struct Geometry *));
    if(!strcmp(objectType, "Rectangle"))
    {
      initRectangle(&object[i]);
    }
    else if (!strcmp(objectType, "Square"))
    {
      initSquare(&object[i]);
    }
    else if(!strcmp(objectType, "Circle"))
    {
      initCircle(&object[i]);
    }
    else if(!strcmp(objectType, "Line"))
    {
      initLine(&object[i]);
    }
    else
    {
      printf("Unknown geometric type %s\n", objectType);
      exit(1);
    }

  }
  
  for(int i = 0; i < n; i++)
  {
    printGeometry(object[i]);
  }
  
  for(int i = 0; i < n; i++)
  {
    freeGeometry(object[i]);
  }

  free(object);
}

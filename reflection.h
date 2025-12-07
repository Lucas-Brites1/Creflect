#ifndef REFLECTION_H
#define REFLECTION_H

typedef unsigned long long t_size;
#define REFLECT_OFFSET(TYPE, MEMBER) ((t_size) & ((TYPE *)0)->MEMBER)

#define REFLECT_GET(PTR, OFFSET, TYPE) \
  (*(TYPE *)reflect_ptr_add(PTR, OFFSET))

#define REFLECT_SET(PTR, OFFSET, TYPE, VALUE) \
  (REFLECT_GET(PTR, OFFSET, TYPE) = VALUE)

static inline void *reflect_ptr_add(void *ptr, t_size offset)
{
  return (void *)((char *)ptr + offset);
}

typedef enum
{
  REFLECT_TYPE_STRING,
  REFLECT_TYPE_CHAR,
  REFLECT_TYPE_INTEGER,
  REFLECT_TYPE_DOUBLE,
  REFLECT_TYPE_BOOL,
  REFLECT_TYPE_OBJECT,
  REFLECT_TYPE_ARRAY_STRING,
  REFLECT_TYPE_ARRAY_INT,
  REFLECT_TYPE_ARRAY_DOUBLE,
  REFLECT_TYPE_ARRAY_OBJECT
} t_reflect_kind;

typedef struct
{
  const char *name;
  t_reflect_kind type;
  t_size offset;
} t_reflect_field;

typedef struct
{
  const char *name;
  t_size size;
  unsigned int field_count;
  t_reflect_field *fields;
} t_reflect_object;

#endif

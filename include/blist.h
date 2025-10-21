#ifndef _BLIST_H_
#define _BLIST_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _blist {
  void *contents;
  struct _blist *prev;
  struct _blist *next;
} blist;

blist *blist_create(void);
void blist_append(blist *, const void *);
void blist_prepend(blist *, const void *);
void blist_delete(const blist *);
void blist_traverse(blist *, int (*)(void *));

#ifdef __cplusplus
}
#endif

#endif /* defined _BLIST_H_ */

/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"

SymbolTable::SymbolTable()
{
    size=0;
    root=NULL;
}
SymbolTable::~SymbolTable()
{
    delete root;
}
void SymbolTable::insert(string k, UnlimitedRational* v)
{
        if (root==NULL)
        {
            root=new SymEntry(k,v);
            size++;
            return;
        }
    SymEntry* t=root;
    SymEntry* u=root;
    while(t!=NULL)
    {
        if(t->key==k)
        {
            return;
        }
        else if(t->key>k)
        {
            u=t;
            t=t->left;
        }
        else
        {
            u=t;
            t=t->right;
        }
    }
    if(u->key>k)
    {
        u->left=new SymEntry(k,v);
    }
    else
    {
        u->right=new SymEntry(k,v);
    }
    size++;
    return;
}
void SymbolTable::remove(string k)
{
    SymEntry* t=root;
    while(t!=NULL)
    {
        if(t->key==k)
        {
            
            return;
        }
        else if(t->key>k)
        {
            t=t->left;
        }
        else
        {
            t=t->right;
        }
    }
    return;

}
UnlimitedRational* SymbolTable::search(string k)
{
    SymEntry* t=root;
    while(t!=NULL)
    {
        if(t->key==k)
        {
            UnlimitedRational* res=new UnlimitedRational(t->val->get_p(),t->val->get_q());
            return res;
        }
        else if(t->key>k)
        {
            t=t->left;
        }
        else
        {
            t=t->right;
        }
    }
    return NULL;
}
int SymbolTable::get_size()
{
    return size;
}

SymEntry* SymbolTable::get_root()
{
    return root;
}

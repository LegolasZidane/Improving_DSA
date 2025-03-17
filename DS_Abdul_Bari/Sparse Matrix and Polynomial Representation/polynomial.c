#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

void create(struct Poly *p)
{

    printf("\nNumber of terms\n");
    scanf("%d", &p->n);

    p->terms = (struct Term *)malloc((p->n)*sizeof(struct Term));
    printf("\nEnter coeff then exponent\n");
    for(int i = 0; i < p->n; i++ )
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);

}

struct Poly * add(struct Poly p1, struct Poly p2)
{

    int i, j, k;
    i=j=k=0;
    struct Poly *p = (struct Poly *)malloc(sizeof(struct Poly));
    p->terms = (struct Term *)malloc((p1.n + p2.n)*sizeof(struct Term));

    while( i < p1.n && j < p2.n )
    {
        if( p1.terms[i].exp > p2.terms[j].exp )
            p->terms[k++] = p1.terms[i++];
        else if( p1.terms[i].exp < p2.terms[j].exp )
            p->terms[k++] = p2.terms[j++];
        else
        {
            p->terms[k].exp = p1.terms[i].exp;
            p->terms[k++].coeff = p1.terms[i++].coeff + p2.terms[j++].coeff;
        }
    }
    for(; i < p1.n ; i++ )
        p->terms[k++] = p1.terms[i];
    for(; j < p2.n ; j++ )
        p->terms[k++] = p2.terms[j];
    
    p->n = k;
    return p;

}

void display(struct Poly p)
{
    for(int i = 0; i < p.n ; i++ )
        printf("%dx^%d +", p.terms[i].coeff, p.terms[i].exp);
    printf("\n");
}

int main()
{
    struct Poly p1, p2, *p;
    
    create(&p1);
    create(&p2);

    p = add(p1, p2);

    printf("\nFirst Polynomial\n");
    display(p1);
    printf("\nSecond Polynomial\n");
    display(p2);
    printf("\nFinal Polynomial\n");
    display(*p);



    return 0;
}
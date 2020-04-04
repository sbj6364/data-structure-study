#include <stdio.h>

typedef struct
{
	float real;
	float imag;
	float abs;
}cm;

cm add(cm x, cm y)
{
	cm a;
	a.real = x.real + y.real;
	a.imag = x.imag + y.imag;
	return a;
}
cm sub(cm x, cm y)
{
	cm a;
	a.real = x.real - y.real;
	a.imag = x.imag - y.imag;
	return a;
}
void abs_val(cm* p1, cm* p2, cm* p3)
{
    cm tmp;
    p1->abs = p1->real * p1->real + p1->imag * p1->imag;
    p2->abs = p2->real * p2->real + p2->imag * p2->imag;
    p3->abs = p3->real * p3->real + p3->imag * p3->imag;
    if (p1->abs > p2->abs){
        if (p1->abs > p3->abs){
            if (p2->abs > p3->abs)
            {
                p2->real = p3->real, p2->imag = p3->imag;
            }
        }
        else  p1->real = p3->real, p1->imag = p3->imag;
    }
    else{
        if (p2->abs > p3->abs){
            if (p1->abs > p3->abs) {
                p1->real = p2->real, p1->imag = p2->imag;
                p2->real = p3->real, p2->imag = p3->imag;
            }
            else{
                tmp.real = p1->real, tmp.imag = p1->imag;
                p1->real = p2->real, p1->imag = p2->imag;
                p2->real = tmp.real, p2->imag = tmp.imag;

            }
        }
        else{
            tmp.real = p1->real, tmp.imag = p1->imag;
            p1->real = p3->real, p1->imag = p3->imag;
            p2->real = tmp.real, p2->imag = tmp.imag;
        }
    }
}

int main()
{
    cm x, y, z;
    cm ans1, ans2;

    scanf("%f %f", &x.real, &x.imag);
    scanf("%f %f", &y.real, &y.imag);
    scanf("%f %f", &z.real, &z.imag);

    abs_val(&x, &y, &z);
 
    ans1 = add(x, y);
    ans2 = sub(x, y);

    printf("%.1f%+.1fi", ans1.real, ans1.imag);
    printf("\n%.1f%+.1fi", ans2.real, ans2.imag);

	return 0;
}

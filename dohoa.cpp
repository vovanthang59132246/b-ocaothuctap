#include <stdio.h>
#include <math.h>


#define PARENT(i) ((i-1) / 2)
#include<stdio.h>
#include<iostream>
using namespace std;
#define LINE_WIDTH 70

int main() {
    int tree[1000];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> tree[i];
	}
    int print_pos[n];
    int i, j, k, pos, x=1, level=0;

    print_pos[0] = 0;
    for(i=0,j=1; i<n; i++,j++) {
        pos = print_pos[PARENT(i)] + (i%2?-1:1)*(LINE_WIDTH/(pow(2,level+1))+1);

        for (k=0; k<pos-x; k++) printf("%c",i==0||i%2?' ':'-');
        printf("%d",tree[i]);

        print_pos[i] = x = pos+1;
        if (j==pow(2,level)) {
            printf("\n");
            cout << endl;
            level++;
            x = 1;
            j = 0;
        }
    }
    return 0;
}

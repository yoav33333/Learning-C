#include "LinkedList.c"
#include <stdlib.h>
#include <stdio.h>

int main(){

	struct LinkedList L;
    L.init = init;
    L.init(&L);
    L.addAtEnd(L.Head, 6);
	L.addAtStart(&L.Head,8);
	L.addAtStart(&L.Head, 4);
	L.addAtEnd(L.Head, 7);
    L.addAtPos(&L.Head, 50, 3);
    L.pointList(L.Head);
    L.RemoveAtPos(&L, 2);
	L.pointList(L.Head);
    L.changeNodePose(&L, 0, 3);
    printf("Change: ");
    L.pointList(L.Head);
    L.rotateListBy(&L, 3);
    printf("Rotate\n");
    L.pointList(L.Head);
    printf("change 780 in 0\n");
    L.changeVal(&L, 780, 3);
    L.pointList(L.Head);
    printf(" Pos3: %d\n", L.getPointAtPos(&L, 3)->data);
    printf(" Length: %d\n", L.length(L.Head));
    L.free(&L);
    return 0;
}
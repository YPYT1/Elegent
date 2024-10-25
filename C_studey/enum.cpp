//
// Created by Liam on 2024/9/23.
//

#include <cstdio>
#include "enum.h"


int main() {
    enum color{
        red =1,
        green,
        blue
    };
    enum color favoriter_color;
    printf("Enter you favoriter cole 1.red,2.grenn,3.blue\n");
    scanf("%u",&favoriter_color);
    switch (favoriter_color) {
        case red:
            printf("Is red");
            break;
        case blue:
            printf("Is blue");
            break;
        case green:
            printf("Is green");
            break;
        default:
            printf("color is null");
    }
    return 0;
}
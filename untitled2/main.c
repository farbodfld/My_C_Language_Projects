#include <stdio.h>

int main() {
    float weight,height,BMI;
    scanf("%f %f",&weight,&height);
    BMI = weight/(height)*(height);
    if(BMI<18.5)
        printf("bmi = %0.2f\n, َUnderWeight");
    if(18.5<=BMI<25)
        printf("bmi = %0.2f\n,Normal");
    if(25<=BMI<30)
        printf("bmi = %0.2f\n,OverWeight");
    if(30<=BMI)
        printf("bmi = %0.2f\n,Obese");
    return 0;
}
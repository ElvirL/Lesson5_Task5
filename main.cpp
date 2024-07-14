/*
Задание 5. Усложнение задачи про кирпич
Что нужно сделать
Напишите программу, которая проверяет, можно ли первую коробку положить внутрь второй.

Условие:
В модуле вы разобрали, как написать программу для проверки, удастся ли поместить кирпич определённых размеров в определённое прямоугольное отверстие.
Теперь представьте, что у вас есть две коробки. Одна размером A ? B ? C, а другая — M ? N ?K.
Напишите программу, которая по шести данным числам A, B, C, M, N, K проверяет, можно ли первую коробку положить внутрь второй.
Коробки можно как угодно переворачивать, но одна коробка должна помещаться в другую целиком.

Советы и рекомендации
• Одна коробка в другую должна помещаться по всем трём измерениям.
• Постарайтесь сделать свою программу по возможности лаконичнее.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> get_sort_sides(int a, int b, int c){
    vector<int> v;
    if (a >= b && a>=c){
        v.push_back(a);
        if (b>=c){
            v.push_back(b);
            v.push_back(c);
        } 
        else{
            v.push_back(c);
            v.push_back(b);
        }

    } else if (b>=a && b>=c){
        v.push_back(b);
        if (a>=c){
            v.push_back(a);
            v.push_back(c);
        } 
        else {
            v.push_back(c);
            v.push_back(a);
        }

    } else if (c>=a && c>b){
        v.push_back(c);
        if (a>=b){
            v.push_back(a);
            v.push_back(b);
        }
        else {
            v.push_back(b);
            v.push_back(a);
        }
    }

    return v;
}

bool is_contain(vector<int> v1, vector<int> v2){
    for (size_t i=0; i<v1.size(); ++i){
        if (v1[i] <= v2[i]){
            return false;
        }
    }
    return true;
}

int main(){
    setlocale(LC_ALL, "Russian");
    int a,b,c, m, n,k;
    cout << "Введите стороны первой коробки через пробел: ";
    cin >> a >> b >> c;
    cout << "Введите стороны второй коробки через пробел: ";
    cin >> m >> n >> k;

    if (is_contain(get_sort_sides(a,b,c), get_sort_sides(m,n,k)) || is_contain(get_sort_sides(m,n,k), get_sort_sides(a,b,c))){
        cout << "Можно положить одну коробу внутрь другой коробки" << endl;
    } else {
        cout << "Нельзя положить одну коробу внутрь другой коробки" << endl;
    }
    

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_String(){
    char* str = (char*)malloc(1);
    if(str == NULL){
        printf("memory did not allocate");
    }//проверка на выделение памяти
    char buf[11];//создаем буффер
    int n, size = 0;
    *str = '\0';//изначально пустая строка
    do{
        n = scanf("%10[^\n]", buf);//считываем 10 символов и загоняем их в буфер
        if(n < 0){//если было нажат ctrl+z
            free(str);//очищаем выделенную под память строку
            str = NULL;//делаем в стр заглушку
            continue;//выходим из цикла
        }
        if(n == 0)
            scanf("%*c");//если значение было считано но произошла ошибка(например несоответствие типов)
        else{
            size += (int)strlen(buf);//считаем длину строки
            str = (char*)realloc(str, size + 1);//перевыделяем память размера size+1 для нуль символа
            strcat(str, buf);//конкатенируем строку из буфера с изначальной строкой
        }
    }while(n > 0);
    if(*(str + strlen(str) - 1) == ' '){//удаление пробелов в конце строки
        for(int i = strlen(str) - 1; *(str + i) == ' '; i--)
            *(str+i) = '\0';
    }
    return str;
}

char* result(char* string1, char* string2){
  int n1, n2;//счетчики длины слова
  char* str1 = string1;// первая строка
  char buffer[1000];//первый буфер символов
  char* str2 = string2;//вторая строка
  int numofw1 =0;//номер слова в первом цикле
  int numofw2 = 0;//номер слова во втором цикле

  char* b = (char*) malloc ((strlen(str1)+ strlen(str2))* sizeof(char));//выделяем память под строку-результат
  if (b == NULL){//если система не дала нам память, выходим
    printf("OS did not give us memory for b || str1 || str2");
    return "off!";
  }
  while(str1 != '\0' || str2 != '\0'){//начинаем обработку строки, если хоть одна строка != концу входим в цикл
    if(*str1 ==' '){//если 1ая строка начинается с пробелом, переходим к след ячейке памяти
      str1++;
      n1 = 0;}
    else if(*str1 == '\0'){//если строка закончилась будем скипать ее пока не закончится вторая
      continue;
    }
    else{//если начало вводиться слово
      while *str1 !=' '{ //пока не дошли до пробела, то есть пока идет слово, считываем его
        buffer1 = buffer+ (*str1);//заносим в буффер
        str1++;//переходим к след букве
        ++n1;//увеличиваем длину слова на единицу
        if (n1>999){ //если одно слово больше 1000 символов программа ругается
          printf("Good job! Your word is over 1000 symbols, you broke my program");
          return "fk u";
        }
      }
    ++numofw1;
    if numofw1 % 2 ==1{//если это слово нечетное, добавляем его в результирующую строку с пробелом
      *b = *b+buffer+" ";
    }
    buffer = "";//обнуляем первый буфер
    n1 = 0;//обнуляем кол-во букв в слове
    }

    if(*str2 ==' '){
        str2++;
        n2 = 0;
    }

  }







}



int main ()
{

  char* str1;
  char* str2;
  int* sizestr;
  int strings = 0;
  char* str1 = "!";
  char* str2 = "!";
while(*str1 != EOF || *str2 !=EOF){
    printf("Enter string 1: ");
    str1 = get_String();
    printf("Enter string 2: ");
    str2 = get_String();
    if(*str1 == '\0' || *str2 == '\0'){
        continue;}
   char* b = result(str1, str2);
    printf("Final: %s", b);
    free(b);
};
}
system("pause");
return 0;
}
/*  while(*a != EOF){




    printf("Enter the line number 1 --> ");
    str1 = get_String();
    if(*a == '\0') {
            continue;
            free(a);
            }
        printf("Enter the line number 2 --> ");
        str2 = get_String();
        printf("%s\n",str1 );
      }*/
